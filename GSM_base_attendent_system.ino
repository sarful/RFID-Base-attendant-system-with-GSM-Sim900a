#include <SoftwareSerial.h>

SoftwareSerial GPRS(8,9);
boolean state, lastState;
boolean state1, lastState1;
boolean state2, lastState2;
boolean state3, lastState3;

void setup()
{
  pinMode(2, INPUT_PULLUP);
      pinMode(3, INPUT_PULLUP);
          pinMode(4, INPUT_PULLUP);
            pinMode(5, INPUT_PULLUP);
  state = digitalRead(2);
  lastState = state;
       state1 = digitalRead(3);
  lastState1 = state1;
              state2 = digitalRead(4);
  lastState2 = state2;
            state3 = digitalRead(5);
  lastState3 = state3;
  
  GPRS.begin(9600);
  Serial.begin(9600);
  
  GPRS.println("AT+CMGF=1");
  
  delay(1000);
}

void loop()
{
  while(GPRS.available()) {
    Serial.write(GPRS.read());
  }

  lastState = state;
     state = digitalRead(2);
        lastState1 = state1;
                state1 = digitalRead(3);
                 lastState2 = state2;
                       state2 = digitalRead(4);
                        lastState3 = state3;
                            state3 = digitalRead(5);
  
  if ( state != lastState ) {
    sendSMS();
  }

       if ( state1 != lastState1 ) {
    sendSMS1();
  }
            if ( state2 != lastState2 ) {
              sendSMS2();
            }
            if ( state3 != lastState3 ) {
              sendSMS3();
            }
            
  
  delay(500);
}

void sendSMS() {
 
 //GPRS.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
  // delay(1000);  // Delay of 1000 milli seconds or 1 second

  GPRS.println("AT+CMGS=\"+8801723673803\"\r"); // Replace x with mobile number
  delay(500);
  

  GPRS.println(" This is SAKIB");// The SMS text you want to send
  delay(100);
   GPRS.println((char)26);// ASCII code of CTRL+Z
  delay(500);
  //GPRS.write( 0x1a ); // ctrl+Z character
  
  //delay(500);
}

void sendSMS1() {
 
 //GPRS.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
 // delay(1000);  // Delay of 1000 milli seconds or 1 second

  GPRS.println("AT+CMGS=\"+8801723673803\"\r"); // Replace x with mobile number
  delay(1000);

  GPRS.println(" This is MOSTAKIN");// The SMS text you want to send
  delay(100);
   GPRS.println((char)26);// ASCII code of CTRL+Z
  delay(100);
  //GPRS.write( 0x1a ); // ctrl+Z character
  
  //delay(500);
}

void sendSMS2() {
 
 //GPRS.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
 // delay(1000);  // Delay of 1000 milli seconds or 1 second

  GPRS.println("AT+CMGS=\"+8801723673803\"\r"); // Replace x with mobile number
  delay(1000);

  GPRS.println(" This is SUKUMAR");// The SMS text you want to send
  delay(100);
   GPRS.println((char)26);// ASCII code of CTRL+Z
  delay(100);
  //GPRS.write( 0x1a ); // ctrl+Z character
  
 // delay(500);
}
void sendSMS3() {
 
 //GPRS.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
 // delay(1000);  // Delay of 1000 milli seconds or 1 second

  GPRS.println("AT+CMGS=\"+8801723673803\"\r"); // Replace x with mobile number
  delay(1000);

  GPRS.println(" This is Hasssan");// The SMS text you want to send
  delay(100);
   GPRS.println((char)26);// ASCII code of CTRL+Z
  delay(100);
  //GPRS.write( 0x1a ); // ctrl+Z character
  
  //delay(500);
}
