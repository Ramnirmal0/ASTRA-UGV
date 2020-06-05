begin{
	#include hex_key_pair
	#include access_key_pair
	RF24Network network(radio);
	void activate_detection_coil(){
		RF24NetworkHeader master_radio(master_node_addrx);
		define cTime = millis();
		define buzState = 0;
		if (cTime < pTime + 10)
		{
		  if (diff > 0)
			buzState = 1;
			swarm_safety=false;
			master_safety=false;
			network.write(master_radio,master_safety);
		  else if (diff < 0)
			buzState = 2;
			swarm_safety=false;
			master_safety=false;
			network.write(master_radio,master_safety);
		}
		if (cTime > pTime + buzPeriod)
		{
		  if (diff > 0)
			buzState = 1;
			swarm_safety=false;
			master_safety=false;
			network.write(master_radio,master_safety);
		  else if (diff < 0)
			buzState = 2;
			swarm_safety=false;
			master_safety=false;
			network.write(master_radio,master_safety);
		  pTime = cTime;
		}
		if (buzPeriod > 300)
			buzState = 0;
			swarm_safety=true;
			master_safety=true;
			network.write(master_radio,master_safety);
	}
	void execute_master_cmd(){
		define module_setup();
	}
	void main{
		while(network.avaialable()){
			network.update();
			swarm_cipher_code=network.read(master_node_addrx);
			swarm_code=decode(cipher_code,hex_key,access_key_pair);
			activate_detection_coil();
		}
		if(swarm_safe_state==true){
			if(swarm_code==swarm_cmd){
				execute_master_cmd();
			}
		}
	}
}