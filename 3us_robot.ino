/*Obstacle avoidance robot with three ultrasonic sensors
 * https://srituhobby.com
 */
//Include the motor driver library
//Define the sensor pins
#define S1Trig 7
#define S2Trig 6
#define S3Trig 5
#define S1Echo 4
#define S2Echo 3
#define S3Echo 2
//Set the speed of the motor

void setup() {
  Serial.begin(9600);
  //Set the Trig pins as output pins
  pinMode(S1Trig, OUTPUT);
  pinMode(S2Trig, OUTPUT);
  pinMode(S3Trig, OUTPUT);
  //Set the Echo pins as input pins
  pinMode(S1Echo, INPUT);
  pinMode(S2Echo, INPUT);
  pinMode(S3Echo, INPUT);
  pinMode(13,OUTPUT);   //left motors forward
  pinMode(12,OUTPUT);   //left motors reverse
  pinMode(11,OUTPUT);   //right motors forward
  pinMode(10,OUTPUT);
  //Set the speed of the motors
}

void loop() {
  int centerSensor = sensorTwo();
  int leftSensor = sensorOne();
  int rightSensor = sensorThree();
// Check the distance using the IF condition
  if (8 >= centerSensor) {
    //Stop();
    Serial.println("Stop");
    delay(1000);
    if (leftSensor > rightSensor) {
      //left();
      Serial.println("Left");
      delay(500);
    } else {
      //right();
      Serial.println("Right");
      delay(500);
    }
  }
  Serial.println("Forward");
  //forward();
}

//Get the sensor values
int sensorOne() {
  //pulse output
  digitalWrite(S1Trig, LOW);
  delayMicroseconds(4);
  digitalWrite(S1Trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(S1Trig, LOW);

  long t = pulseIn(S1Echo, HIGH);//Get the pulse
  int cm = t / 29 / 2; //Convert time to the distance
  return cm; // Return the values from the sensor
}

//Get the sensor values
int sensorTwo() {
  //pulse output
  digitalWrite(S2Trig, LOW);
  delayMicroseconds(4);
  digitalWrite(S2Trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(S2Trig, LOW);

  long t = pulseIn(S2Echo, HIGH);//Get the pulse
  int cm = t / 29 / 2; //Convert time to the distance
  return cm; // Return the values from the sensor
}

//Get the sensor values
int sensorThree() {
  //pulse output
  digitalWrite(S3Trig, LOW);
  delayMicroseconds(4);
  digitalWrite(S3Trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(S3Trig, LOW);

  long t = pulseIn(S3Echo, HIGH);//Get the pulse
  int cm = t / 29 / 2; //Convert time to the distance
  return cm; // Return the values from the sensor
}

/*******************Motor functions**********************/
void forward() {
  digitalWrite(12,HIGH);
  digitalWrite(10,HIGH);
}
void left() {
  digitalWrite(11,HIGH);
}
void right() {
  digitalWrite(13,HIGH);
}
void Stop() {
  digitalWrite(13,LOW);
  digitalWrite(12,LOW);
  digitalWrite(11,LOW);
  digitalWrite(10,LOW);
}
