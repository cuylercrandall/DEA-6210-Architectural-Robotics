#include <Servo.h>

int clockwise = 2;
int counterclockwise = 4;
int modeButtom = 3;
bool cwState = false;
bool ccwState = false;
bool modeState = false;
int pos = 0;
Servo contServo;
Servo angServo;


void setup() {
  // Initialize serial communication at 9600 bits per second:
  Serial.begin(9600);

  // Initializes pins to input/output and to needed values
  pinMode(clockwise, INPUT);
  pinMode(counterclockwise, INPUT);
  pinMode(modeButtom, INPUT);
  pinMode(6,OUTPUT);
  digitalWrite(6,HIGH);
  pinMode(7,OUTPUT);
  digitalWrite(7,LOW);

  // Initializes servo output pins
  contServo.attach(9);
  angServo.attach(10);
}

void loop() {
  // Read input pins
  cwState = (digitalRead(clockwise)==HIGH);
  ccwState || (digitalRead(counterclockwise)==HIGH);
  modeState || (digitalRead(modeButtom)==HIGH);
  for (int i=0; i<10; i++){
    cwState = cwState || (digitalRead(clockwise)==HIGH);
    ccwState = ccwState || (digitalRead(counterclockwise)==HIGH);
    modeState = modeState || (digitalRead(modeButtom)==HIGH);
    delay(200);
  }

  //Cont. Servo Values: Forward = 180, Reverse = 0, Stop = 90
  //Ang. Servo Values: 0 or 180 (only)
  
  // Display output based on pin states
  if ((cwState && ccwState) || (!cwState && !ccwState)){
    // If both directions, do nothing
    Serial.println("Doing nothing");
    contServo.write(90);
    
  } else if (cwState && modeState){
    // If clockwise and mode switched, move the secondary servo clockwise
    Serial.println("Secondary clockwise");
    
  } else if (ccwState && modeState){
    // If counterclockwise and mode switched, move the secondary servo counterclockwise
    Serial.println("Secondary counterclockwise");
    
  } else if (cwState && !modeState){
    // If clockwise and mode switched, move the primary servo clockwise
    Serial.println("Primary clockwise");
    contServo.write(180);
    
  } else if (ccwState && !modeState){
    // If counterclockwise and mode switched, move the primary servo counterclockwise
    Serial.println("Primary counterclockwise");
    contServo.write(0);
    
  }

  if(cwState){
    Serial.println("CW Pin High");
  }
  if(ccwState){
    Serial.println("CCW Pin High");
  }
  if(modeState){
    Serial.println("Mode Pin High");
  }
  
  // Reset pin states
  cwState = false;
  ccwState = false;
  modeState = false;
}
