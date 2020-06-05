begin{
	#include hex_key_pair
	#include access_key_pair
	RF24Network network(radio);
	void main{
		network.update();
		console_key=Serial.read();
		RF24NetworkHeader master_radio(master_node_addrx);
		while ( network.available()){
			RF24NetworkHeader header;
			unsigned long incomingData;
			network.read(radio, incomingData));
			SUART.Serial.out(incomingData);
			Serial.write(log);
		}
		if(console_key==master_key){
			encode ciper_code[]= master_key[] + hex_key[] + access_key[];
			network.write(master_radio,ciper code);
		}
		else if(console_key==swarm_key){
			encode ciper_code[]= swarm_key[] + hex_key[] + access_key[];
			network.write(master_radio,ciper code);
		}
		else if(console_key==arm_key){
			encode ciper_code[]= arm_key[] + hex_key[] + access_key[];
			network.write(master_radio,ciper code);
		}
		else if(console_key==util_key){
			encode ciper_code[]= util_key[] + hex_key[] + access_key[];
			network.write(master_radio,ciper code);
		}
		else(console_key== idle){
			IOExceptionHandler();
		}
	}
}
