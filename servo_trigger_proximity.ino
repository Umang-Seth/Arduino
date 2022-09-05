#include<SoftwareSerial.h>
#include <Servo.h>

SoftwareSerial Serial1(2,3);
Servo myservo;

int pos = 0;
int dist;
int strength;
float temprature;
int check;
int uart[9];
int i;
const int HEADER=0x59;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial1.begin(115200);
  myservo.attach(9);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial1.available())
  {
    if (Serial1.read()==HEADER)
    {
      uart[0]=HEADER;
      if (Serial1.read()==HEADER)
      {
        uart[1]=HEADER;
        for (i=2;i<9;i++)
        {
          uart[i]=Serial1.read();
        }
        check=uart[0]+uart[1]+uart[2]+uart[3]+uart[4]+uart[5]+uart[6]+uart[7];
        if(uart[8]==(check&0xff))
        {
          dist=uart[2]+uart[3]*256;
          Serial.print("Distance=");
          Serial.print(dist);
          Serial.print('\n');
          delay(300);
          
        if(dist<=12)
        {
          myservo.write(90);
          delay(20);
        }
        else
        {
          myservo.write(0);
          delay(20);
        }
        }
      }
    }
  }
}
