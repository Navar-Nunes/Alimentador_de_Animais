#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position
int prevenido = 2;

void setup()
{
  myservo.attach(10);  // attaches the servo on pin 9 to the servo object
  myservo.write (0);
}

void loop()
{
  for (pos = 0; pos <= 50; pos += 1)
  {
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(40);                       // waits 15ms for the servo to reach the position
  }

  delay(1000);
  
  for (pos = 50; pos >= 20; pos -= 1)
  { 
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }

  for (pos = 20; pos <= 30; pos += 1)
    {
      myservo.write(pos);
      delay(15);
    }

    for (pos = 30; pos >= 20; pos -= 1)
    {
      myservo.write(pos);
      delay(20);
    }

  for (pos = 20; pos >= 0; pos -= 1)
  {
    myservo.write(pos);
    delay(15);
  }
  
  delay(2000);
}

