#include <RF24Network.h>
#include <RF24.h>
#include <SPI.h>
char data;
int const POWER_LED = 5;
int const TRASMITTER_LED = 4;
int const RECIEVER_LED = 3;
RF24 radio(7, 8);               // nRF24L01 (CE,CSN)
RF24Network network(radio);      // Include the radio in the network
const uint16_t this_node = 00; /*CMD ADDRESS*/  // Address of this node in Octal format ( 04,031, etc)
const uint16_t node01 = 01;    /*MOTHER ADDRESS*/  // Address of the other node in Octal format
const uint16_t node012 = 012;  /*CHILD ADDRESS*/
const uint16_t node022 = 022;
int radar_analog = 0;

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
    char incomingData[20];
    network.read(header, &incomingData, sizeof(incomingData));
    receiver_led();
    radar_analog = incomingData;
    Serial.println("REQ : Radar value = ");
    Serial.print(radar_analog);
  }

  //===== Sending =====//

  if (Serial.available())
  {
    char data = Serial.read();

    if (data == 'x')
    {
      const char code = 'x';
      RF24NetworkHeader header2(node01);     // (Address where the data is going)
      bool ok = network.write(header2, &code, sizeof(code)); // Send the data
      Serial.println("ACK << U.G.V Emergency shutdown activated");
      receiver_led();
    }

    if (data == 'b')
    {
      const char code = 'b';
      RF24NetworkHeader header2(node012);     // (Address where the data is going)
      bool ok = network.write(header2, &code, sizeof(code)); // Send the data
      Serial.println("ACK << Swarm Emergency shutdown activated");
      transmitter_led();
    }


    if (data == 'w')
    {
      const char code = 'w';
      RF24NetworkHeader header2(node01);     // (Address where the data is going)
      bool ok = network.write(header2, &code, sizeof(code)); // Send the data
      Serial.println("ACK << UGV forward Cheat activated");
      receiver_led();
    }

    if (data == 'a')
    {
      const char code = 'a';
      RF24NetworkHeader header2(node01);     // (Address where the data is going)
      bool ok = network.write(header2, &code, sizeof(code)); // Send the data
      Serial.println("ACK << UGV left Cheat activated");
      receiver_led();
    }
    if (data == 's')
    {
      const char code = 's';
      RF24NetworkHeader header2(node01);     // (Address where the data is going)
      bool ok = network.write(header2, &code, sizeof(code)); // Send the data
      Serial.println("ACK << UGV backward Cheat activated");
      receiver_led();
    }

    if (data == 'd')
    {
      const char code = 'd';
      RF24NetworkHeader header2(node01);     // (Address where the data is going)
      bool ok = network.write(header2, &code, sizeof(code)); // Send the data
      Serial.println("ACK << UGV right Cheat activated");
      receiver_led();
    }

    if (data == '5')
    {
      const char code = '5';
      RF24NetworkHeader header2(node01);     // (Address where the data is going)
      bool ok = network.write(header2, &code, sizeof(code)); // Send the data
      Serial.println("ACK << Arm open Cheat activated");
      receiver_led();
    }

    if (data == '0')
    {
      const char code = '0';
      RF24NetworkHeader header2(node01);     // (Address where the data is going)
      bool ok = network.write(header2, &code, sizeof(code)); // Send the data
      Serial.println("ACK << Arm close Cheat activated");
      receiver_led();
    }

    if (data == '8')
    {
      const char code = '8';
      RF24NetworkHeader header2(node01);     // (Address where the data is going)
      bool ok = network.write(header2, &code, sizeof(code)); // Send the data
      Serial.println("ACK << Palm up Cheat activated");
      receiver_led();
    }
    if (data == '2')
    {
      const char code = '2';
      RF24NetworkHeader header2(node01);     // (Address where the data is going)
      bool ok = network.write(header2, &code, sizeof(code)); // Send the data
      Serial.println("ACK << Palm down Cheat activated");
      receiver_led();
    }

    if (data == '4')
    {
      const char code = '4';
      RF24NetworkHeader header2(node01);     // (Address where the data is going)
      bool ok = network.write(header2, &code, sizeof(code)); // Send the data
      Serial.println("ACK << Wrist X axis Cheat activated");
      receiver_led();
    }
    if (data == '6')
    {
      const char code = '6';
      RF24NetworkHeader header2(node01);     // (Address where the data is going)
      bool ok = network.write(header2, &code, sizeof(code)); // Send the data
      Serial.println("ACK << Wrist Y axis Cheat activated");
      receiver_led();
    }

    if (data == '+')
    {
      const char code = '+';
      RF24NetworkHeader header2(node01);     // (Address where the data is going)
      bool ok = network.write(header2, &code, sizeof(code)); // Send the data
      Serial.println("ACK << Docking Cheat activated");
      receiver_led();
    }

    if (data == '-' )
    {
      const char code = '-';
      RF24NetworkHeader header2(node01);     // (Address where the data is going)
      bool ok = network.write(header2, &code, sizeof(code)); // Send the data
      Serial.println("ACK << Undocking Cheat activated");
      receiver_led();
    }

    if (data == 'n')
    {
      const char code = 'n';
      RF24NetworkHeader header2(node01);     // (Address where the data is going)
      bool ok = network.write(header2, &code, sizeof(code)); // Send the data
      Serial.println("ACK << Backlight Cheat activated");
      receiver_led();
    }

    if (data == 'm')
    {
      const char code = 'm';
      RF24NetworkHeader header2(node01);     // (Address where the data is going)
      bool ok = network.write(header2, &code, sizeof(code)); // Send the data
      Serial.println("ACK << Exhaust Cheat activated");
      receiver_led();
    }


    // SWARM CONTROL


    if (data == 'i')
    {
      const char code = 'i';
      RF24NetworkHeader header2(node012);     // (Address where the data is going)
      bool ok = network.write(header2, &code, sizeof(code)); // Send the data
      Serial.println("ACK << Swarm forward Cheat activated");
      transmitter_led();
    }

    if (data == 'j')
    {
      const char code = 'j';
      RF24NetworkHeader header2(node012);     // (Address where the data is going)
      bool ok = network.write(header2, &code, sizeof(code)); // Send the data
      Serial.println("ACK << Swarm left Cheat activated");
      transmitter_led();
    }

    if (data == 'l')
    {
      const char code = 'l';
      RF24NetworkHeader header2(node012);     // (Address where the data is going)
      bool ok = network.write(header2, &code, sizeof(code)); // Send the data
      Serial.println("ACK << Swarm right Cheat activated");
      transmitter_led();
    }

    if (data == 'k')
    {
      const char code = 'k';
      RF24NetworkHeader header2(node012);     // (Address where the data is going)
      bool ok = network.write(header2, &code, sizeof(code)); // Send the data
      Serial.println("ACK << Swarm backward Cheat activated");
      transmitter_led();
    }

    if (data == 'f')
    {
      const char code = 'f';
      RF24NetworkHeader header2(node012);     // (Address where the data is going)
      bool ok = network.write(header2, &code, sizeof(code)); // Send the data
      Serial.println("ACK << Self destruct Cheat activated");
      transmitter_led();
    }
    if (data == 'g')
    {
      const char code = 'g';
      RF24NetworkHeader header2(node012);     // (Address where the data is going)
      bool ok = network.write(header2, &code, sizeof(code)); // Send the data
      Serial.println("ACK << Retreat Cheat activated");
      transmitter_led();
    }
    if (data == 'h')
    {
      const char code = 'h';
      RF24NetworkHeader header2(node01);     // (Address where the data is going)
      bool ok = network.write(header2, &code, sizeof(code)); // Send the data
      Serial.println("ACK << Attack Cheat activated");
      transmitter_led();
    }
  }
}
