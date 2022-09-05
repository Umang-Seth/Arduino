#include <Servo.h>
#define RCPin 2



volatile long StartTime = 0;
volatile long CurrentTime = 0;
volatile long Pulses = 0;
int PulseWidth = 0;
int flag = 0;

Servo servo1;
Servo servo2;
Servo servo3;
int pos = 0;




void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(RCPin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt (RCPin), PulseTimer, CHANGE);
  servo1.attach(5);
  servo2.attach(9);
  servo3.attach(10);
  servo1.write(0);
  servo2.write(0);
  servo3.write(0);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Pulses < 2000){
    PulseWidth = Pulses;
  }
  //Serial.println(PulseWidth);
  Serial.println(PulseWidth);
  if (PulseWidth == 1500){
    flag +=1;
    delay(1000);
    switch(flag){
      case 1:
         Servo1();
         delay(1000);
         break;

      case 2:
         Servo2();
         delay(1000);
         break;

      
      case 3:
         Servo3();
         delay(1000);
         break;
   }
   //delay(1000);
  }
}

void PulseTimer (){
  CurrentTime = micros();
  if(CurrentTime > StartTime){
     Pulses = CurrentTime - StartTime;
     StartTime = CurrentTime;
  }
}

void Servo1(){
    servo1.write(60);
    delay(1000);
    servo1.write(0);
    delay(1000);
}

void Servo2(){
    servo2.write(60);
    delay(1000);
    servo2.write(0);
    delay(1000);
}


void Servo3(){
    servo3.write(60);
    delay(1000);
    servo3.write(0);
    delay(1000);
}
