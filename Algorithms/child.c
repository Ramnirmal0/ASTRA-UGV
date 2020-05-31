begin{
	#include hex_key_pair
	#include access_key_pair
	RF24Network network(radio);
	void activate_detection_coil(){
		long unsigned int cTime = millis();
		char buzState = 0;
		if (cTime < pTime + 10)
		{
		  if (diff > 0)
			buzState = 1;
		  else if (diff < 0)
			buzState = 2;
		}
		if (cTime > pTime + buzPeriod)
		{
		  if (diff > 0)
			buzState = 1;
		  else if (diff < 0)
			buzState = 2;
		  pTime = cTime;
		}
		if (buzPeriod > 300)
		  buzState = 0;
		if (buzState == 0)
		{
		  noTone(buz);
		}
		else if (buzState == 1)
		{
		  tone(buz, 2000);
		}
		else if (buzState == 2)
		{
		  tone(buz, 500);
		}
	}
	void execute_master_cmd(){
		define module_setup();
	}
	void main{
		network.update();
		activate_detection_coil();
		while(network.avaialable()){
			Listen_radio();
			cipher_code=network.read();
			swarm_code=decode(cipher_code,hex_key,access_key_pair);
		}
		if(swarm_safe_state==true){
			if(swarm_code==swarm_cmd){
				execute_master_cmd();
			}
		}
	}
	
}