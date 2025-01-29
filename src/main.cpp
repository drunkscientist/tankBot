#include <Arduino.h>
#include <AccelStepper.h>


const int xyEn = 14;
const int zEn = 26;

const int xDir = 21;
const int xStep = 15;
const int yDir = 23;
const int yStep = 22;
const int zDir = 2;
const int zStep = 3;
const int eDir = 0;
const int eStep = 1;

int pace = 300;
int zip = 200;
char dataIn;
char m;
bool change = false;


// Define some steppers and the pins the will use
AccelStepper LFwheel(1, yStep, yDir);  // (Type:driver, STEP, DIR)
AccelStepper RFwheel(1, eStep, eDir );
AccelStepper LRwheel(1, xStep, xDir );
AccelStepper RRwheel(1, zStep, zDir );


void setup(){  
    pinMode(xyEn, OUTPUT);
    pinMode(zEn, OUTPUT);
    digitalWrite(xyEn, 1);
    digitalWrite(zEn, 1);
  
    LFwheel.setMaxSpeed(10000);
    LFwheel.setAcceleration(zip);
    //LFwheel.moveTo(1000000);
    
    RFwheel.setMaxSpeed(10000);
    RFwheel.setAcceleration(zip);
   // RFwheel.moveTo(7000);

    LRwheel.setMaxSpeed(10000);
    LRwheel.setAcceleration(zip);

    RRwheel.setMaxSpeed(10000);
    RRwheel.setAcceleration(zip);

    Serial.begin(9600);
    Serial1.begin(115200);
    Serial.println("setup complete");
    //pwrChk();
    
    
}





void moveForw(){
  Serial.println("moving forward");
  LFwheel.setSpeed(pace);
  RFwheel.setSpeed(pace);
  RRwheel.setSpeed(pace);
  LRwheel.setSpeed(pace);
  }
void moveBack(){
  Serial.println("moving backward");
  LFwheel.setSpeed(-pace);
  RFwheel.setSpeed(-pace);
  RRwheel.setSpeed(-pace);
  LRwheel.setSpeed(-pace);
  }
void moveLeft(){
  Serial.println("moving left");
  LFwheel.setSpeed(-pace);
  RFwheel.setSpeed(pace);
  RRwheel.setSpeed(-pace);
  LRwheel.setSpeed(pace);
  }
void moveRight(){
  Serial.println("moving right");
  LFwheel.setSpeed(pace);
  RFwheel.setSpeed(-pace);
  RRwheel.setSpeed(pace);
  LRwheel.setSpeed(-pace);
  }
void rotLeft(){
  Serial.println("rotating left");
  LFwheel.setSpeed(-pace);
  RFwheel.setSpeed(pace);
  RRwheel.setSpeed(pace);
  LRwheel.setSpeed(-pace);
  }
void rotRight(){
  Serial.println("rotating right");
  LFwheel.setSpeed(pace);
  RFwheel.setSpeed(-pace);
  RRwheel.setSpeed(-pace);
  LRwheel.setSpeed(pace);
  }
void forwLeft(){
  Serial.println("forward leftishly");
  LFwheel.setSpeed(0);
  RFwheel.setSpeed(pace);
  RRwheel.setSpeed(0);
  LRwheel.setSpeed(pace);
  }
void forwRight(){
  Serial.println("forward rightish");
  LFwheel.setSpeed(pace);
  RFwheel.setSpeed(0);
  RRwheel.setSpeed(pace);
  LRwheel.setSpeed(0);
  }
void backLeft(){
  Serial.println("back leftish");
  LFwheel.setSpeed(-pace);
  RFwheel.setSpeed(0);
  RRwheel.setSpeed(-pace);
  LRwheel.setSpeed(0);
  }
void backRight(){
  Serial.println("back right");
  LFwheel.setSpeed(0);
  RFwheel.setSpeed(-pace);
  RRwheel.setSpeed(0);
  LRwheel.setSpeed(-pace);
  }
void stap(){
  Serial.println("STOP");
  LFwheel.setSpeed(0);
  RFwheel.setSpeed(0);
  RRwheel.setSpeed(0);
  LRwheel.setSpeed(0);
  }


void pwrChk(){
  // Monitor the battery voltage
  int sensorValue = analogRead(A0);
  float voltage = sensorValue * (5.0 / 1023.00) * 3; // Convert the reading values from 5v to suitable 12V i
  Serial.println(voltage);
  // If voltage is below 11V turn on the LED
  if (voltage < 11) {
  
   }
  }

void going(char p){
  switch (p){
      case 56: //8
        moveForw();
       break;

      case 115:  //s for spin
        rotLeft();
       break;

      case 57:  //9
        forwRight();
       break;
       
      case 55:  //7
        forwLeft();
       break;
       
      case 52:  //4
        moveLeft();
       break;

      case 54: //6
        moveRight();
       break;

      case 49:  //1
        backLeft();
       break;

      case 51:  //3
        backRight();
       break;

      case 50:  //2
        moveBack();
       break;
       
      case 53:  //5
        rotRight();
       break;
       
      

      case 116: //t for toggle
        digitalWrite(xyEn, !digitalRead(xyEn));
        digitalWrite(zEn, !digitalRead(zEn));
       
       break;

       default:
        stap();
        Serial.println("stopping");
       break;  
    }
}

void look(){
  if (Serial.available() > 0) {
    Serial.print("reading serial");
    dataIn = Serial.read();
    Serial.println(dataIn);
    
    going(dataIn);
    
    //m = dataIn;
    /*
    if (dataIn == 48) {
     //m = 0;
     stap();
    }
    if (dataIn == 49) {
      going(1);
    }
    if (dataIn == 50) {
      going(2);
    }
    if (dataIn == 51) {
      going(3);
    }
    if (dataIn == 52) {
      going(4);
    }
    if (dataIn == 53) {
      going(5);
    }
    if (dataIn == 54) {
      going(6);
    }
    if (dataIn == 55) {
      going(7);
    }
    if (dataIn == 56) {
      //m = 8;
      moveForw();
    }
    if (dataIn == 57) {
      m = 9;
    }
    if (dataIn == 43) {
      pace += 100;
      Serial.println("speed up");
    }
    if (dataIn == 45){
      pace -= 100;
      Serial.println("slow down");
    }
    if (dataIn == 116) {
       digitalWrite(xyEn, 0);
       digitalWrite(zEn, 0);
    }
    if (dataIn == 117) {
      digitalWrite(xyEn, 1);
      digitalWrite(zEn, 1);
    }
    if (dataIn == 14) {
      m = 14;
    }
*/
   }
   if (Serial1.available()>0){
     Serial.print("serial1 recvd:");
     dataIn = Serial1.read();
     Serial.println(dataIn);
     going(dataIn);

   }

   //if (!Serial.available() >0 || !Serial1.available() > 0 ){
   //  m = 0;
   //}
   
   
   
  }





void loop(){
      
    RRwheel.runSpeed();
    LRwheel.runSpeed();
    LFwheel.runSpeed();
    RFwheel.runSpeed();
    
    look();
    

    /*
    if(change){
      going();
      change = false;
    }
    
    */
   
  //pwrChk();

}





