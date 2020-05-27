int data;
void setup() {
Serial.begin(9600);
pinMode(13,OUTPUT);
}

void loop() {
  if(Serial.available()){
    data=Serial.read();
    if(data == '1')
    {
      Serial.println("The code recived from Visual Basic ");
      digitalWrite(13,HIGH);
    }
    if(data == '0')
    {
      Serial.println("the error in identifying the code ");
      digitalWrite(13,LOW);
    }
  }

}
