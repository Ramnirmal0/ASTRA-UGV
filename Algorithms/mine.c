begin{
	define buzzer_pin=5; 
	define fsr_analog_pin=a0 ; 
	define fsr_value=0; 
	void setup (){
		pinmode ( fsr_analog_pin , input ) ; 
		pinmode ( buzzer_pin , output ) ; 
	}
	voidmain(){
		fsr_value =analogRead ( fsr_analog_pin ) ; 
		analogWrite ( buzzer_pin , fsr_value / 4 ) ; 
	}
}