#include <Servo.h>              // Add library  (Kütüphaneyi Ekleyin)
Servo name_servo;               // Define any servo name  (Servo İsmi Tanımlayın)

void setup()
{  
name_servo.attach (9);          // Define the servo signal pins (PWM 3-5-6-9-10-11) (Servo Sinyal Pini Tanımlayın)
}

void loop()
{
  name_servo.write (0);         // Turned to 0 degrees
}
