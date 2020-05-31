begin{
	#include hex_key_pair
	#include access_key_pair
	RF24Network network(radio);
	void listen_radio(){
		swarm_status=network.read();
		update(Swarm_safe_state);
		mine_detection();
		update(mine_detection_status);
	}
	void master_state(){
		sensor_readings();
		update(master_safe_state);
	}
	void mine_detection(){
		if(mine_detection_status==true){
			RF24NetworkHeader radio(modem_addrx);
			bool ok = network.write(radio, status);
		}
	}
	void execute_master_cmd(){
		define module_setup();
	}
	void execute_arm_cmd(){
		define module_setup();
	}
	void execute_util_cmd(){
		define module_setup();
	}
	void main{
		network.update();
		while(network.available){
			Listen_radio();
			cipher_code=network.read();
			master_code=decode(cipher_code,hex_key,access_key_pair);
			if(master_safe_state==true){
				if (master_code== master_cmd){
					execute_master_cmd();
				}
				else if (master_code==swarm_cmd){
					if(swarm_safe_state==true){
						RF24NetworkHeader radio(swarm_node_addrx);
						bool ok = network.write(radio, swarm_cmd);
					}
					else{
						warning();
					}
				}
				else if (master_code==arm_cmd){
					execute_arm_cmd();
				}
				else if(master_code==util_cmd){
					execute_util_cmd();
				}
				else{
					IOExceptionHandler();
				}
			}
		}
	}	
}