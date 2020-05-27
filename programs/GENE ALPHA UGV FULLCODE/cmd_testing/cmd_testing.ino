#include <RF24Network.h>
#include <RF24.h>
#include <SPI.h>
char data;

RF24 radio(7, 8);               // nRF24L01 (CE,CSN)
RF24Network network(radio);      // Include the radio in the network
const uint16_t this_node = 00; /*CMD ADDRESS*/  // Address of this node in Octal format ( 04,031, etc)
const uint16_t node01 = 01;    /*MOTHER ADDRESS*/  // Address of the other node in Octal format
const uint16_t node012 = 012;  /*CHILD ADDRESS*/
const uint16_t node022 = 022;
int radar_analog = 0;



void setup() {
  SPI.begin();
  radio.begin();
  network.begin(90, this_node);  //(channel, node address)
  radio.setDataRate(RF24_2MBPS);
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
    radar_analog = incomingData;
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

    }

    if (data == 'b')
    {
      const char code = 'b';
      RF24NetworkHeader header2(node01);     // (Address where the data is going)
      bool ok = network.write(header2, &code, sizeof(code)); // Send the data
      Serial.println("ACK << Swarm Emergency shutdown activated");

    }


    if (data == 'w')
    {
      const char code = 'w';
      RF24NetworkHeader header2(node01);     // (Address where the data is going)
      bool ok = network.write(header2, &code, sizeof(code)); // Send the data
      Serial.println("ACK << UGV forward Cheat activated");

    }

    if (data == 'a')
    {
      const char code = 'a';
      RF24NetworkHeader header2(node01);     // (Address where the data is going)
      bool ok = network.write(header2, &code, sizeof(code)); // Send the data
      Serial.println("ACK << UGV left Cheat activated");

    }
    if (data == 's')
    {
      const char code = 's';
      RF24NetworkHeader header2(node01);     // (Address where the data is going)
      bool ok = network.write(header2, &code, sizeof(code)); // Send the data
      Serial.println("ACK << UGV backward Cheat activated");

    }

    if (data == 'd')
    {
      const char code = 'd';
      RF24NetworkHeader header2(node01);     // (Address where the data is going)
      bool ok = network.write(header2, &code, sizeof(code)); // Send the data
      Serial.println("ACK << UGV right Cheat activated");

    }

    if (data == '5')
    {
      const char code = '5';
      RF24NetworkHeader header2(node01);     // (Address where the data is going)
      bool ok = network.write(header2, &code, sizeof(code)); // Send the data
      Serial.println("ACK << Arm open Cheat activated");

    }

    if (data == '0')
    {
      const char code = '0';
      RF24NetworkHeader header2(node01);     // (Address where the data is going)
      bool ok = network.write(header2, &code, sizeof(code)); // Send the data
      Serial.println("ACK << Arm close Cheat activated");

    }

    if (data == '8')
    {
      const char code = '8';
      RF24NetworkHeader header2(node01);     // (Address where the data is going)
      bool ok = network.write(header2, &code, sizeof(code)); // Send the data
      Serial.println("ACK << Palm up Cheat activated");

    }
    if (data == '2')
    {
      const char code = '2';
      RF24NetworkHeader header2(node01);     // (Address where the data is going)
      bool ok = network.write(header2, &code, sizeof(code)); // Send the data
      Serial.println("ACK << Palm down Cheat activated");

    }

    if (data == '4')
    {
      const char code = '4';
      RF24NetworkHeader header2(node01);     // (Address where the data is going)
      bool ok = network.write(header2, &code, sizeof(code)); // Send the data
      Serial.println("ACK << Wrist X axis Cheat activated");

    }
    if (data == '6')
    {
      const char code = '6';
      RF24NetworkHeader header2(node01);     // (Address where the data is going)
      bool ok = network.write(header2, &code, sizeof(code)); // Send the data
      Serial.println("ACK << Wrist Y axis Cheat activated");

    }

    if (data == '+')
    {
      const char code = '+';
      RF24NetworkHeader header2(node01);     // (Address where the data is going)
      bool ok = network.write(header2, &code, sizeof(code)); // Send the data
      Serial.println("ACK << Docking Cheat activated");

    }

    if (data == '-' )
    {
      const char code = '-';
      RF24NetworkHeader header2(node01);     // (Address where the data is going)
      bool ok = network.write(header2, &code, sizeof(code)); // Send the data
      Serial.println("ACK << Undocking Cheat activated");

    }

    if (data == 'n')
    {
      const char code = 'n';
      RF24NetworkHeader header2(node01);     // (Address where the data is going)
      bool ok = network.write(header2, &code, sizeof(code)); // Send the data
      Serial.println("ACK << Backlight Cheat activated");

    }

    if (data == 'm')
    {
      const char code = 'm';
      RF24NetworkHeader header2(node01);     // (Address where the data is going)
      bool ok = network.write(header2, &code, sizeof(code)); // Send the data
      Serial.println("ACK << Exhaust Cheat activated");

    }


    // SWARM CONTROL


    if (data == 'i')
    {
      const char code = 'i';
      RF24NetworkHeader header2(node01);     // (Address where the data is going)
      bool ok = network.write(header2, &code, sizeof(code)); // Send the data
      Serial.println("ACK << Swarm forward Cheat activated");

    }

    if (data == 'j')
    {
      const char code = 'j';
      RF24NetworkHeader header2(node01);     // (Address where the data is going)
      bool ok = network.write(header2, &code, sizeof(code)); // Send the data
      Serial.println("ACK << Swarm left Cheat activated");

    }

    if (data == 'l')
    {
      const char code = 'l';
      RF24NetworkHeader header2(node01);     // (Address where the data is going)
      bool ok = network.write(header2, &code, sizeof(code)); // Send the data
      Serial.println("ACK << Swarm right Cheat activated");

    }

    if (data == 'k')
    {
      const char code = 'k';
      RF24NetworkHeader header2(node01);     // (Address where the data is going)
      bool ok = network.write(header2, &code, sizeof(code)); // Send the data
      Serial.println("ACK << Swarm backward Cheat activated");

    }

    if (data == 'f')
    {
      const char code = 'f';
      RF24NetworkHeader header2(node01);     // (Address where the data is going)
      bool ok = network.write(header2, &code, sizeof(code)); // Send the data
      Serial.println("ACK << Self destruct Cheat activated");

    }
    if (data == 'g')
    {
      const char code = 'g';
      RF24NetworkHeader header2(node01);     // (Address where the data is going)
      bool ok = network.write(header2, &code, sizeof(code)); // Send the data
      Serial.println("ACK << Retreat Cheat activated");

    }
    if (data == 'h')
    {
      const char code = 'h';
      RF24NetworkHeader header2(node01);     // (Address where the data is going)
      bool ok = network.write(header2, &code, sizeof(code)); // Send the data
      Serial.println("ACK << Attack Cheat activated");

    }
  }
}
