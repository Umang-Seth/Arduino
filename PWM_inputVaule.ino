#define RCPin 2
volatile long StartTime = 0;
volatile long CurrentTime = 0;
volatile long Pulses = 0;
int PulseWidth = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(RCPin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(RCPin),PulseTimer, CHANGE);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Pulses < 2000){
    PulseWidth = Pulses;
  }
  Serial.println(PulseWidth);
}

void PulseTimer(){
  CurrentTime = micros();
  if (CurrentTime > StartTime){
    Pulses = CurrentTime - StartTime;
    StartTime = CurrentTime;  
  }
}
