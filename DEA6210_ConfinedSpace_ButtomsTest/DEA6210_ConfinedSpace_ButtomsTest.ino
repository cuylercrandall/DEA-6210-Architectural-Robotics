int clockwise = 2;
int counterclockwise = 4;
int modeButtom = 3;
bool cwState = false;
bool ccwState = false;
bool modeState = false;

void setup() {
  // Initialize serial communication at 9600 bits per second:
  Serial.begin(9600);

  // Initializes pins to input/output and to needed values
  pinMode(clockwise, INPUT);
  pinMode(counterclockwise, INPUT);
  pinMode(modeButtom, INPUT);
  pinMode(6,OUTPUT);
  digitalWrite(6,HIGH);
  //pinMode(7,OUTPUT);
  //digitalWrite(7,LOW);
}

void loop() {
  // Read input pins
  for (int i=0; i<10; i++){
    cwState = cwState || (digitalRead(clockwise)==HIGH);
    ccwState = ccwState || (digitalRead(counterclockwise)==HIGH);
    modeState = modeState || (digitalRead(modeButtom)==HIGH);
    delay(200);
  }


  // Display output based on pin states
  if ((cwState && ccwState) || (!cwState && !ccwState)){
    // If both directions, do nothing
    Serial.println("Doing nothing");
  } else if (cwState && modeState){
    // If clockwise and mode switched, move the secondary servo clockwise
    Serial.println("Secondary clockwise");
  } else if (ccwState && modeState){
    // If counterclockwise and mode switched, move the secondary servo counterclockwise
    Serial.println("Secondary counterclockwise");
  } else if (cwState && !modeState){
    // If clockwise and mode switched, move the primary servo clockwise
    Serial.println("Primary clockwise");
  } else if (ccwState && !modeState){
    // If counterclockwise and mode switched, move the primary servo counterclockwise
    Serial.println("Primary counterclockwise");
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
  bool cwState = false;
  bool ccwState = false;
  bool modeState = false;
}
