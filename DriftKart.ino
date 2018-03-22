/* 
 *  160 to 400
 *  
 */
#include <Servo.h>

Servo myservo;  // create servo object to control a servo

int potpin = A0;  // analog pin used to connect the potentiometer
int val;    // variable to read the value from the analog pin
int scaledVal = 0;
int btnPin = 7;
bool on = false;

void setup() {
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  pinMode(btnPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  int toggle = digitalRead(btnPin);
  if(toggle == HIGH) {
    on = true;
  } else if(toggle == LOW) {
    on = false;
  }
 
  if(on) {
    Serial.println("POWER ON");
    val = analogRead(potpin);            // reads the value of the potentiometer (value between 0 and 1023)
      // scale it to use it with the servo (value between 0 and 180)
    scaledVal = (val * (400/160.0) - 400)/2;
    if (scaledVal < 0) scaledVal = 0;
    if (scaledVal > 255) scaledVal = 255;
    scaledVal = scaledVal / 2.7 + 95;
    Serial.println(scaledVal);
    myservo.write(scaledVal);                  // sets the servo position according to the scaled value
    delay(15);
  }
  if(!on) {
    scaledVal = 0;
    myservo.write(scaledVal);
    Serial.println("POWER OFF");
}
  
}

