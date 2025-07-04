#include <Servo.h>

#define RAIN_SENSOR_PIN A0 // Arduino pin connected to rain sensor's pin
#define SOIL_SENSOR_PIN A1 // Arduino pin connected to soil sensor's pin
#define SERVO_PIN       9  // Arduino pin connected to servo motor's pin

Servo servo; // create servo object to control a servo

// variables will change:
int angle = 0;
int rain_state;
int soil_state;

void setup() 
{
  Serial.begin(9600);                // initialize serial
  pinMode(RAIN_SENSOR_PIN, INPUT);    // set Arduino pin to input mode
  pinMode(SOIL_SENSOR_PIN, INPUT);    // set Arduino pin to input mode
  servo.attach(SERVO_PIN);            // attaches the servo on pin 9 to the servo object
  servo.write(angle);
  rain_state = analogRead(RAIN_SENSOR_PIN);
  soil_state = analogRead(SOIL_SENSOR_PIN); 
}

void loop() {
  rain_state = analogRead(RAIN_SENSOR_PIN);
  soil_state = analogRead(SOIL_SENSOR_PIN);

  if (soil_state < 550 && rain_state > 700 && rain_state < 500) // soil moisture wet and rain is medium
  {
    servo.write(30);
  }
  else if (soil_state < 550 && rain_state < 500) // soil moisture wet and rain is high
  {
    servo.write(30);
  }
  else if (soil_state > 850 && rain_state > 700) // soil moisture is dry and rain is low
  {
    servo.write(60);
  }
  else if ((soil_state >= 550 && soil_state <= 850) && rain_state > 700) // soil moisture is normal and rain is low
  {
    servo.write(60);
  }
  else if ((soil_state >= 550 && soil_state <= 850) && (rain_state >= 500 && rain_state <= 700)) // soil moisture is normal and rain is medium
  {
    servo.write(90);
  }
  else if ((soil_state >= 550 && soil_state <= 850) && rain_state < 500) // soil moisture is normal and rain is high
  {
    servo.write(90);
  }
  else 
  {
   
   servo.write(0);
  }
}
