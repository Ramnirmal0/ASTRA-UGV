
#include <RF24Network.h>
#include <RF24.h>
#include <SPI.h>
char data;
int const POWER_LED = 5;
int const TRASMITTER_LED = 4;
int const RECIEVER_LED = 3;
RF24 radio(7, 8);               // nRF24L01 (CE,CSN)
RF24Network network(radio);      // Include the radio in the network
const uint16_t this_node = 00;   // Address of this node in Octal format ( 04,031, etc)
const uint16_t node01 = 01;      // Address of the other node in Octal format
const uint16_t node012 = 012;
const uint16_t node022 = 022;


void transmitter_led()
{
  digitalWrite(TRASMITTER_LED, HIGH);
  delay(10);
  digitalWrite(TRASMITTER_LED, LOW);
  delay(10);

}

void receiver_led()
{
  digitalWrite(RECIEVER_LED, HIGH);
  delay(10);
  digitalWrite(RECIEVER_LED, LOW);
  delay(10);
}

void setup() {
  SPI.begin();
  radio.begin();
  network.begin(90, this_node);  //(channel, node address)
  radio.setDataRate(RF24_2MBPS);
  pinMode(POWER_LED, OUTPUT);
  pinMode(TRASMITTER_LED, OUTPUT);
  pinMode(RECIEVER_LED, OUTPUT);
  digitalWrite(POWER_LED, HIGH);
  Serial.begin(9600);
}
void loop() {
  network.update();
  //===== Receiving =====//
  while ( network.available() )
  { // Is there any incoming data?
    RF24NetworkHeader header;
    unsigned long incomingData;
    network.read(header, &incomingData, sizeof(incomingData));
    receiver_led();// Read the incoming data
  }

  //===== Sending =====//

  if (Serial.available())
  {
    char data = Serial.read();
    if (data == 'm')
    {
      unsigned long outgoing1 = 1;
      RF24NetworkHeader header2(node01);     // (Address where the data is going)
      bool ok = network.write(header2, &outgoing1, sizeof(outgoing1)); // Send the data
      Serial.println("m executed");

    }
    if (data == 'd')
    {
      unsigned long outgoing2 = 2;
      RF24NetworkHeader header4(node012);    // (Address where the data is going)
      bool ok3 = network.write(header4, &outgoing2, sizeof(outgoing2)); // Send the data
      Serial.println("d executed");
    }
  }
}
