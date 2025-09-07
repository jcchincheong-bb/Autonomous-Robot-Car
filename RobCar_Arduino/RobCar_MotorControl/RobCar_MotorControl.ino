// ***************** PINS **********************
// Front Right Motor (FR)
int motorFRpin1 = 5;
int motorFRpin2 = 4;

// Front Left Motor (FL)
int motorFLpin1 = 3;
int motorFLpin2 = 2;
// ********************************************

void setup() {
  // Set all motor pins to output
  pinMode(motorFRpin1,OUTPUT);
  pinMode(motorFRpin2,OUTPUT);
  pinMode(motorFLpin1,OUTPUT);
  pinMode(motorFLpin2,OUTPUT);

}

void loop() {
  // Test loop to switch diretion after each second [Ryan Chan]
  // Forward for 2 seconds
  digitalWrite(motorFRpin1, HIGH);
  digitalWrite(motorFRpin2, LOW);

  digitalWrite(motorFLpin1, HIGH);
  digitalWrite(motorFLpin2, LOW);
  delay(2000);

  // Stop for 1 sec
  digitalWrite(motorFRpin1, LOW);
  digitalWrite(motorFRpin2, LOW);

  digitalWrite(motorFLpin1, LOW);
  digitalWrite(motorFLpin2, LOW);
  delay(1000);

  // Reverse for 2 secs
  digitalWrite(motorFRpin1, LOW);
  digitalWrite(motorFRpin2, HIGH);

  digitalWrite(motorFLpin1, LOW);
  digitalWrite(motorFLpin2, HIGH);
  delay(2000);

}
