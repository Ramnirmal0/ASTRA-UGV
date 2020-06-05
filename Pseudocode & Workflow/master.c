begin{
	#include hex_key_pair
	#include access_key_pair
	RF24Network network(radio);
	void sensor_read(){
		// code related to available sensors
		update(sensor_parameter);
	}
	void master_safety_ack(){
		while(network.available){
		network.update();
		master_safety_ack=network.read(swarm_module_addx);
		if(master_safety==true){
			master_safe_state=true;
		}
		if(master_safety==false){
			master_safe_state=false;
		}
		if(swarm_safety==true){
			swarm_safe_state=true;
		}
		if(swarm_safety==false){
			s_safe_state=false;
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
		while(network.available){
			network.update();
			cipher_code=network.read(command_module_addx);
			master_code=decode(cipher_code,hex_key,access_key_pair);
			Sensor_read();
			if(sensor_parameter==true){
				master_safety_ack();
				if(master_safe_state==true){
					if (master_code== master_cmd){
						execute_master_cmd();
					}
					else if (master_code==swarm_cmd){
						if(swarm_safe_state==true){
							RF24NetworkHeader swarm_radio(swarm_node_addrx);  //mention all available bot 
							encode swarm_ciper_code[]= master_key[] + hex_key[] + access_key[];
							bool ok = network.write(swarm_radio, swarm_cipher_code);
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
}