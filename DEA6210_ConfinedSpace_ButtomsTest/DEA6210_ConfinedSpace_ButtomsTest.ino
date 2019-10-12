int clockwise = 11;
int counterclockwise = 13;
int modeButtom = 12;
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
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  // Read input pins
  cwState = digitalRead(clockwise);
  ccwState = digitalRead(counterclockwise);
  modeState = digitalRead(modeButtom);

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
  
  // Status
  Serial.println(digitalRead("Clockwise Pin: "+clockwise));
  Serial.println(digitalRead("Counterclockwise Pin: "+counterclockwise));
  Serial.println(digitalRead("Mode Pin: "+modeButtom));

  // Heartbeat
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);  

  // Reset input pins
  cwState = LOW; 
  ccwState = LOW;
  modeState = LOW;
}
