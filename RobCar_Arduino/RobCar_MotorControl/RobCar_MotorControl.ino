// ***************** PINS **********************
// Ultrasonic Sensor
#define Trigger 12
#define Echo 13

// Front Right Motor (FR)
int FR_f = 7;  // forward (f)
int FR_r = 6;  // reverse (r)

// Front Left Motor (FL)
int FL_f = 9;
int FL_r = 8;

// Rear Right Motor (RR)
int RR_f = 2;
int RR_r = 3;

// Rear Left Motor (RL)
int RL_f = 4;
int RL_r = 5;

// ********************************************

void setup() {
  // Set all motor pins to output
  pinMode(FR_f, OUTPUT);
  pinMode(FR_r, OUTPUT);
  pinMode(FL_f, OUTPUT);
  pinMode(FL_r, OUTPUT);
  pinMode(RR_f, OUTPUT);
  pinMode(RR_r, OUTPUT);
  pinMode(RL_f, OUTPUT);
  pinMode(RL_r, OUTPUT);
  // Set Echo and Trigger for US Sensor
  pinMode(Echo, INPUT);
  pinMode(Trigger, OUTPUT);
  // Serial Initilisation
  Serial.begin(9600);
}

void loop() {
  // Set Trigger LOW
  digitalWrite(Trigger, LOW);
  delayMicroseconds(2);
  
  // Emit high frequency 40kHz sound pulse (i.e. pull the Trigger)
  digitalWrite(Trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(Trigger, LOW);

  // Detect a pulse
  int distance = pulseIn(Echo, HIGH);

  // Speed of sound is: 343 m/s -> 343 x 10^2 cm/s -> 343 x 10^2 x 10^-6 cm/us -> 29.15451895 us/cm
  distance = distance / 29 / 2;  // in cm
  // we divide by 2 to acount for the round trip
  
  // Driving Logic
  if (distance <= 10){
    // Emergency stop
    digitalWrite(FR_f, LOW);
    digitalWrite(FR_r, LOW);
    digitalWrite(FL_f, LOW);
    digitalWrite(FL_r, LOW);
    digitalWrite(RR_f, LOW);
    digitalWrite(RR_r, LOW);
    digitalWrite(RL_f, LOW);
    digitalWrite(RL_r, LOW);
  } else {
    // Forward Drive
    digitalWrite(FR_f, HIGH);
    digitalWrite(FR_r, LOW);
    digitalWrite(FL_f, HIGH);
    digitalWrite(FL_r, LOW);
    digitalWrite(RR_f, HIGH);
    digitalWrite(RR_r, LOW);
    digitalWrite(RL_f, HIGH);
    digitalWrite(RL_r, LOW);
  }
  // Print the distance in inches
  Serial.println(distance);
  
  // Pause for 100 milliseconds
  delay(200);
}
