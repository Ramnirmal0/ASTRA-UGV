#include <RF24Network.h>
#include <RF24.h>
#include <SPI.h>
#include <Servo.h>
Servo arm_finger;
Servo arm_palm;
Servo arm_wrist;
Servo docker;

int const POWER_LED = 5;
int const TRASMITTER_LED = 3;
int const RECIEVER_LED = 4;


int docking_val = 0;
int undocking_val = 100;
int wrist_left_val = 0;
int wrist_right_val = 100;
int palm_up_val = 0;
int palm_down_val = 100;
int finger_open_val = 0;
int finger_close_val = 100;


int IN1 = 53 , IN2 = 51 , IN3 = 49 , IN4 = 47;  //L298N 1
int IN5 = 52 , IN6 = 50 , IN7 = 48 , IN8 = 46;  //L298N 2
int IN9 = 13 , IN10 = 12 , IN11 = 11 , IN12 = 10;  //L298N 3


RF24 radio(7, 8);              // nRF24L01 (CE,CSN)
RF24Network network(radio);      // Include the radio in the network
const uint16_t this_node = 01;   // Address of our node in Octal format ( 04,031, etc)
const uint16_t master00 = 00;    // Address of the other node in Octal format
const uint16_t node012 = 012;
void setup() {
  SPI.begin();
  radio.begin();
  network.begin(90, this_node); //(channel, node address)
  radio.setDataRate(RF24_2MBPS);   // (servo pin)
  pinMode(TRASMITTER_LED, OUTPUT);
  pinMode(RECIEVER_LED, OUTPUT);
  pinMode(POWER_LED, OUTPUT);
  digitalWrite(POWER_LED,HIGH);
  Serial.begin(9600);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  pinMode(IN5, OUTPUT);
  pinMode(IN6, OUTPUT);
  pinMode(IN7, OUTPUT);
  pinMode(IN8, OUTPUT);

  pinMode(IN9, OUTPUT);
  pinMode(IN10, OUTPUT);
  pinMode(IN11, OUTPUT);
  pinMode(IN12, OUTPUT);

  arm_finger.attach(17);
  arm_palm.attach(16);
  arm_wrist.attach(15);
  docker.attach(14);



}

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

void docking()
{
  Serial.println("Docking command");
  docker.write(docking_val);
}
void undocking()
{
  Serial.println("Undocking command");
  docker.write(undocking_val);
}
void wrist_left()
{
  Serial.println("wrist left command");
  arm_wrist.write(wrist_left_val);
}
void wrist_right()
{
  Serial.println("wrist down command");
  arm_wrist.write(wrist_right_val);
}
void palm_up()
{
  Serial.println("palm up command");
  arm_palm.write(palm_up_val);
}
void palm_down()
{
  Serial.println("palm down command");
  arm_palm.write(palm_down_val);
}
void finger_open()
{
  Serial.println("finger open command");
  arm_finger.write(finger_open_val);
}
void finger_close()
{
  Serial.println("finger down command");
  arm_finger.write(finger_close_val);
}

void backward() {
  Serial.println("backward command" );
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);

  digitalWrite(IN5, LOW);
  digitalWrite(IN6, HIGH);
  digitalWrite(IN7, HIGH);
  digitalWrite(IN8, LOW);

  digitalWrite(IN9, LOW);
  digitalWrite(IN10, HIGH);
  digitalWrite(IN11, HIGH);
  digitalWrite(IN12, LOW);
}
void forward() {
  Serial.println("Forward command" );
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);

  digitalWrite(IN5, HIGH);
  digitalWrite(IN6, LOW);
  digitalWrite(IN7, LOW);
  digitalWrite(IN8, HIGH);

  digitalWrite(IN9, HIGH);
  digitalWrite(IN10, LOW);
  digitalWrite(IN11, LOW);
  digitalWrite(IN12, HIGH);
}
void right() {
  Serial.println("right command" );
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);

  digitalWrite(IN5, LOW);
  digitalWrite(IN6, HIGH);
  digitalWrite(IN7, LOW);
  digitalWrite(IN8, HIGH);

  digitalWrite(IN9, LOW);
  digitalWrite(IN10, HIGH);
  digitalWrite(IN11, LOW);
  digitalWrite(IN12, HIGH);
}
void left()
{
  Serial.println("left command" );
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);

  digitalWrite(IN5, HIGH);
  digitalWrite(IN6, LOW);
  digitalWrite(IN7, HIGH);
  digitalWrite(IN8, LOW);

  digitalWrite(IN9, HIGH);
  digitalWrite(IN10, LOW);
  digitalWrite(IN11, HIGH);
  digitalWrite(IN12, LOW);
}
void stopme()
{
  Serial.println("stop command" );
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);

  digitalWrite(IN5, LOW);
  digitalWrite(IN6, LOW);
  digitalWrite(IN7, LOW);
  digitalWrite(IN8, LOW);

  digitalWrite(IN9, LOW);
  digitalWrite(IN10, LOW);
  digitalWrite(IN11, LOW);
  digitalWrite(IN12, LOW);

}


void backlight()
{
  Serial.println("ACK : This feature is not installed");
}

void exhaust()
{
  Serial.println("ACK : This feature is not installed");
}

void loop()
{
  network.update();
  //===== Receiving =====//
  while ( network.available() ) {     // Is there any incoming data?
    RF24NetworkHeader header;
    char incomingData;
    network.read(header, &incomingData, sizeof(incomingData)); // Read the incoming data
    
    if (header.from_node == 'x')
    {
      stopme();
      receiver_led();

    }

    if (header.from_node == 'b')
    {
      const char code = 'b';
      RF24NetworkHeader header3(node012);     // (Address where the data is going)
      bool ok = network.write(header3, &code, sizeof(code)); // Send the data
      Serial.println("ACK << Swarm Emergency shutdown transmitted");
      transmitter_led();

    }

    if (header.from_node == 'w')
    {
      forward();
      receiver_led();
      
    }

    if (header.from_node == 'a')
    {
      left();
      receiver_led();
      
    }

    if (header.from_node == 's')
    {
      backward();
      receiver_led();
    }

    if (header.from_node == 'd')
    {
      right();
      receiver_led();
    }

    if (header.from_node == '5')
    {
      finger_open();
      receiver_led();
    }

    if (header.from_node == '0')
    {
      finger_close();
      receiver_led();
    }

    if (header.from_node == '8')
    {
      palm_up();
      receiver_led();
    }

    if (header.from_node == '2')
    {
      palm_down();
      receiver_led();
    }

    if (header.from_node == '4')
    {
      wrist_left();
      receiver_led();
    }

    if (header.from_node == '6')
    {
      wrist_right();
      receiver_led();
    }

    if (header.from_node == '+')
    {
      docking();
      receiver_led();
    }

    if (header.from_node == '-')
    {
      undocking();
      receiver_led();
    }

    if (header.from_node == 'n')
    {
      backlight();
      receiver_led();

    }

    if (header.from_node == 'm')
    {
      exhaust();
      receiver_led();
    }



    if (header.from_node == 'i')
    {
      const char code = 'i';
      RF24NetworkHeader header3(node012);     // (Address where the data is going)
      bool ok = network.write(header3, &code, sizeof(code)); // Send the data
      Serial.println("ACK << Swarm formward transmitted");
      transmitter_led();

    }

    if (header.from_node == 'j')
    {
      const char code = 'j';
      RF24NetworkHeader header3(node012);     // (Address where the data is going)
      bool ok = network.write(header3, &code, sizeof(code)); // Send the data
      Serial.println("ACK << Swarm left transmitted");
      transmitter_led();
    }

    if (header.from_node == 'l')
    {
      const char code = 'l';
      RF24NetworkHeader header3(node012);     // (Address where the data is going)
      bool ok = network.write(header3, &code, sizeof(code)); // Send the data
      Serial.println("ACK << Swarm right transmitted");
      transmitter_led();

    }

    if (header.from_node == 'k')
    {
      const char code = 'k';
      RF24NetworkHeader header3(node012);     // (Address where the data is going)
      bool ok = network.write(header3, &code, sizeof(code)); // Send the data
      Serial.println("ACK << Swarm backward transmitted");
      transmitter_led();

    }

    if (header.from_node == 'f')
    {
      const char code = 'f';
      RF24NetworkHeader header3(node012);     // (Address where the data is going)
      bool ok = network.write(header3, &code, sizeof(code)); // Send the data
      Serial.println("ACK << Swarm self destruct transmitted");
      transmitter_led();

    }

    if (header.from_node == 'g')
    {
      const char code = 'g';
      RF24NetworkHeader header3(node012);     // (Address where the data is going)
      bool ok = network.write(header3, &code, sizeof(code)); // Send the data
      Serial.println("ACK << Swarm retreat transmitted");
      transmitter_led();

    }

    if (header.from_node == 'h')
    {

      const char code = 'h';
      RF24NetworkHeader header3(node012);     // (Address where the data is going)
      bool ok = network.write(header3, &code, sizeof(code)); // Send the data
      Serial.println("ACK << Swarm attack transmitted");
      transmitter_led();

    }
  }
}
