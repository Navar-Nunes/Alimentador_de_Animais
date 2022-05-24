#include <doxygen.h>
#include <ESP8266.h>
#include <LiquidCrystal.h>
#include <Servo.h>



Servo myservo;

LiquidCrystal lcd(12,11,5,4,3,2); 

int pos = 10;    // Variável de posição em ângulos
int viradas = 2;

int h; 
int m; 
int s; 
int TIME; 
const int hs=8; 
const int ms=9; 
int state1;
int state2;

int horacomida1 = 9;
int minutocomida1 = 30;
int horacomida2 = 19;
int minutocomida2 = 40;  //Tempos que depois serão definidos pelo módulo Wi-Fi
int horacomidaatual = 0;
int minutocomidaatual = 0;
int setartempo = 0;
int dia = 25;
int meses = 7;
int ano = 2017;
int transicao = 0;
char horario1[6];
char horario2[6];
char quantidade[4];


// Pino ligado ao REC do modulo
int pino_rec = 6;
// Pino ligado ao P-E (PLAYE) do modulo
int pino_playe = 7;

String inString = "";
int antipontos=0;
char seriador[6];



void setup() 
{ 
 lcd.begin(16,2);
 pinMode(pino_rec, OUTPUT);
 pinMode(pino_playe, OUTPUT);

 Serial.begin(9600);
 
 horacomidaatual=horacomida1;
 minutocomidaatual=minutocomida1;

 myservo.attach(10);  // Porta de dados do servo
 myservo.write(10);
}

void loop() 
{ 
lcd.setCursor(0,0); 
s=s+1;
lcd.print(h); 
lcd.print(":"); 
lcd.print(m); 
lcd.print(":"); 
lcd.print(s); 
delay(1000); 
lcd.clear(); 

if(s==60)
{ 
 s=0; 
 m=m+1; 
}
 
if(m==60) 
{ 
 m=0; 
 h=h+1; 
} 

if(h==24) 
{ 
 h=0;
 transicao++;
}

if(transicao>0)
{
  dia=dia +1;
  
  if(meses==1)
  {
    if(dia>31)
    {
      dia=1;
      meses=meses + 1;
    }
  }

  if(meses==2)
  {
    if(dia>28)
    {
      dia=1;
      meses=meses + 1;
    }
  }

  if(meses==3)
  {
    if(dia>31)
    {
      dia=1;
      meses=meses +1;
    }
  }

  if(meses==4)
  {
    if(dia>30)
    {
      dia=1;
      meses=meses +1;
    }
  }

  if(meses==5)
  {
    if(dia>31)
    {
      dia=1;
      meses=meses +1;
    }
  }

  if(meses==6)
  {
    if(dia>30)
    {
      dia=1;
      meses=meses +1;
    }
  }

  if(meses==7)
  {
    if(dia>31)
    {
      dia=1;
      meses=meses +1;
    }
  }

  if(meses==8)
  {
    if(dia>31)
    {
      dia=1;
      meses=meses +1;
    }
  }

  if(meses==9)
  {
    if(dia>30)
    {
      dia=1;
      meses=meses +1;
    }
  }

  if(meses==10)
  {
    if(dia>31)
    {
      dia=1;
      meses=meses +1;
    }
  }

  if(meses==11)
  {
    if(dia>30)
    {
      dia=1;
      meses=meses +1;
    }
  }

  if(meses==12)
  {
    if(dia>31)
    {
      dia=1;
      meses=1;
      ano=ano + 1;
    }
  }

  transicao=0;
}


lcd.setCursor(0,1);
lcd.print (dia);
lcd.print("/");
lcd.print(meses);
lcd.print("/");
lcd.print(ano);


if (seriador==(horario1))
{
  while (Serial.available() > 0) 
{
    int inChar = Serial.read();
    
    if (isDigit(inChar)) 
    {
      // convert the incoming byte to a char and add it to the string:
      inString += (char)inChar;
    }
    // if you get a newline, print the string, then the string's value:

    if (antipontos==0)
    {
      horariocomida1=((inString.toInt())*10);
      antipontos++;
    }

    if (antipontos==1)
    {
      horacomida1=(horacomida1+(inString.toInt()));
      antipontos++;
    }

    if (antipontos==2)
    {
      antipontos++;
    }

    if (antipontos==3)
    {
      minutocomida1=((inString.toInt())*10);
      antipontos++;
    }

    if (antipontos==4)
    {
      minutocomida1=(horacomida1+(inString.toInt()))
      antipontos++;
    }
    
    if (inChar == '\n') 
    {
      inString = "";
      antipontos=0;
      break;
    }
}
}
else if (seriador==(horario2))
{
  while (Serial.available() > 0) 
{
    int inChar = Serial.read();
    
    if (isDigit(inChar)) 
    {
      // convert the incoming byte to a char and add it to the string:
      inString += (char)inChar;
    }
    // if you get a newline, print the string, then the string's value:

    if (antipontos==0)
    {
      horariocomida2=((inString.toInt())*10);
      antipontos++;
    }

    if (antipontos==1)
    {
      horacomida2=(horacomida1+(inString.toInt()));
      antipontos++;
    }

    if (antipontos==2)
    {
      antipontos++;
    }

    if (antipontos==3)
    {
      minutocomida2=((inString.toInt())*10);
      antipontos++;
    }

    if (antipontos==4)
    {
      minutocomida2=(horacomida1+(inString.toInt()))
      antipontos++;
    }
    
    if (inChar == '\n') 
    {
      inString = "";
      antipontos=0;
      break;
    }
}
}
else if (seriador==(quantidade))
{
    int inChar = Serial.read();
    
    if (isDigit(inChar)) 
    {
      // convert the incoming byte to a char and add it to the string:
      inString += (char)inChar;
    }

    viradas=((inString.toInt())/100);
}

if(horacomida1==h)
{
  if(minutocomida1==m)
  {
    horacomidaatual=horacomida2;
    minutocomidaatual=minutocomida2;
    
    if(s<viradas)
    {
        // Inicial a reproducao
        digitalWrite(pino_playe, HIGH);
        delay(100);
        digitalWrite(pino_playe, LOW);
        delay(2000);

        for (pos = 10; pos <= 60; pos += 1)
        {
          myservo.write(pos);
          delay(40);
        }

        delay(1000);
  
        for (pos = 60; pos >= 30; pos -= 1)
        { 
          myservo.write(pos);              // tell servo to go to position in variable 'pos'
          delay(15);                       // waits 15ms for the servo to reach the position
        }

        for (pos = 30; pos <= 40; pos += 1)
        {
          myservo.write(pos);
          delay(15);
        }

        for (pos = 40; pos >= 30; pos -= 1)
        {
          myservo.write(pos);
          delay(20);
        }

        for (pos = 30; pos >= 10; pos -= 1)
        {
          myservo.write(pos);
          delay(15);
        }
  
        delay(1000);
    }
  }
}

if(horacomida2==h)
{
  if(minutocomida2==m)
  {
    horacomidaatual=horacomida1;
    minutocomidaatual=minutocomida1;
    
    if(s<viradas)
    {
        // Inicial a reproducao
        digitalWrite(pino_playe, HIGH);
        delay(100);
        digitalWrite(pino_playe, LOW);
        delay(2000);

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
  
        delay(1000);
    }
  }
}

if(h>horacomida1)
{
  if(h<horacomida2)
  {
    horacomidaatual=horacomida2;
    minutocomidaatual=minutocomida2;
  }

  if(h==horacomida2)
  {
    if (m<minutocomida2)
    {
      horacomidaatual=horacomida2;
      minutocomidaatual=minutocomida2;
    }
    else
    {
      horacomidaatual=horacomida1;
      minutocomidaatual=minutocomida1;
    }
  }
}
else if(h>horacomida2)
{
   horacomidaatual=horacomida1;
   minutocomidaatual=minutocomida1;
}
else if(h==horacomida1)
  {
    if(m<minutocomida1)
    {
      horacomidaatual=horacomida1;
      minutocomidaatual=minutocomida1;
    }
    else
    {
      horacomidaatual=horacomida2;
      minutocomidaatual=minutocomida2;
    }
  }

lcd.setCursor(11,0);
lcd.print (horacomidaatual);
lcd.print (":");
lcd.print (minutocomidaatual);

}
