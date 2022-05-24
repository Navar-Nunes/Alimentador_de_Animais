#include <LiquidCrystal.h>
#include <Servo.h>

Servo myservo;

LiquidCrystal lcd(12,11,5,4,3,2);

const int buzzer = 13;

int pos = 60;    // Variável de posição em ângulos. Ela se inicia em 60 devido a posição do motor para manter a válvula fechada
int viradas = 4;
int balanco = 0;
int limite = 30;

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
int dia = 31;
int meses = 7;
int ano = 2017;
int transicao = 0;

char a[2];


// Pino ligado ao REC do modulo
int pino_rec = 6;
// Pino ligado ao P-E (PLAYE) do modulo
int pino_playe = 7;



void setup()
{

 Serial.begin(9600);
 
 lcd.begin(16,2);
 pinMode(pino_rec, OUTPUT);
 pinMode(pino_playe, OUTPUT);

 myservo.attach(10);  // Porta de dados do servo
 myservo.write(pos);

 pinMode(buzzer,OUTPUT);

Serial.print("Para setar a hora, digite h"); //Comandos temporários para o terminal
Serial.println();
Serial.print("Para setar os minutos, digite m");
Serial.println();
Serial.print("Para setar o dia, digite d");
Serial.println();
Serial.print("Para setar o mes, digite n");
Serial.println();
Serial.print("Para setar o ano, digite a");
Serial.println();
Serial.print("Para a hora de alimentacao 1, digite 1");
Serial.println();
Serial.print("Para setar o minuto de alimentacao 1, digite 2");
Serial.println();
Serial.print("Para a hora de alimentacao 2, digite 3");
Serial.println();
Serial.print("Para a hora o minuto de alimentacao 2, digite 4");
Serial.println();
Serial.print("Para a quantidade de viradas do motor, digite Q");
Serial.println();
Serial.println();
Serial.print("Viradas:");
Serial.println(viradas);
Serial.println();
Serial.println();

}



void loop() 
{ 
lcd.setCursor(0,0); 
s=s+1;
lcd.print(h);    //Inicia a contagem dos segundos, e escreve na primeira linha do LCD
lcd.print(":"); 
lcd.print(m); 
lcd.print(":"); 
lcd.print(s); 
delay(1000); 
lcd.clear();


if(Serial.available())  //Uma área criada para ler os comandos do serial, em um caractere por vez, se o usuário a utilizar
{
  a[0] = Serial.read();
  if(a[0] == 'h')
  {
    Serial.print("Digite o primeiro digito da hora:");
    delay(5000);
    a[0] = Serial.read();
    Serial.println();
    Serial.print("Digite o segundo digito da hora:");
    delay(5000);
    a[1] = Serial.read();
    Serial.println();

    h = atoi(a);
  }
  else if(a[0] == 'H')
  {
    Serial.print("Digite o primeiro digito da hora:");
    delay(5000);
    a[0] = Serial.read();
    Serial.println();
    Serial.print("Digite o segundo digito da hora:");
    delay(5000);
    a[1] = Serial.read();
    Serial.println();

    h = atoi(a);
  }
  else if(a[0] == 'm')
  {
    Serial.print("Digite o primeiro digito dos minutos:");
    delay(5000);
    a[0] = Serial.read();
    Serial.println();
    Serial.print("Digite o segundo digito dos minutos:");
    delay(5000);
    a[1] = Serial.read();
    Serial.println();

    m = atoi(a);
    s = 0;
  }
  else if(a[0] == 'M')
  {
    Serial.print("Digite o primeiro digito dos minutos:");
    delay(5000);
    a[0] = Serial.read();
    Serial.println();
    Serial.print("Digite o segundo digito dos minutos:");
    delay(5000);
    a[1] = Serial.read();
    Serial.println();

    m = atoi(a);
    s = 0;
  }
  else if(a[0] == 'd')
  {
    Serial.print("Digite o primeiro digito do dia:");
    delay(5000);
    a[0] = Serial.read();
    Serial.println();
    Serial.print("Digite o segundo digito do dia:");
    delay(5000);
    a[1] = Serial.read();
    Serial.println();

    dia = atoi(a);
    transicao++;
  }
  else if(a[0] == 'D')
  {
    Serial.print("Digite o primeiro digito do dia:");
    delay(5000);
    a[0] = Serial.read();
    Serial.println();
    Serial.print("Digite o segundo digito do dia:");
    delay(5000);
    a[1] = Serial.read();
    Serial.println();

    dia = atoi(a);
    transicao++;
  }
  else if(a[0] == 'n')
  {
    Serial.print("Digite o primeiro digito do mes:");
    delay(5000);
    a[0] = Serial.read();
    Serial.println();
    Serial.print("Digite o segundo digito do mes:");
    delay(5000);
    a[1] = Serial.read();
    Serial.println();

    meses = atoi(a);
    transicao++;
  }
  else if(a[0] == 'N')
  {
    Serial.print("Digite o primeiro digito do mes:");
    delay(5000);
    a[0] = Serial.read();
    Serial.println();
    Serial.print("Digite o segundo digito do mes:");
    delay(5000);
    a[1] = Serial.read();
    Serial.println();

    meses = atoi(a);
    transicao++;
  }
  else if(a[0] == 'a')
  {
    Serial.print("Digite o primeiro digito do ano:");
    delay(5000);
    a[0] = Serial.read();
    Serial.println();
    Serial.print("Digite o segundo digito do ano:");
    delay(5000);
    a[1] = Serial.read();
    Serial.println();

    ano = atoi(a);
  }
  else if(a[0] == 'A')
  {
    Serial.print("Digite o primeiro digito do ano:");
    delay(5000);
    a[0] = Serial.read();
    Serial.println();
    Serial.print("Digite o segundo digito do ano:");
    delay(5000);
    a[1] = Serial.read();
    Serial.println();

    ano = atoi(a);
  }
  else if(a[0] == '1')
  {
    Serial.print("Digite o primeiro digito da hora:");
    delay(5000);
    a[0] = Serial.read();
    Serial.println();
    Serial.print("Digite o segundo digito da hora:");
    delay(5000);
    a[1] = Serial.read();
    Serial.println();

    horacomida1 = atoi(a);
  }
  else if(a[0] == '2')
  {
    Serial.print("Digite o primeiro digito dos minutos:");
    delay(5000);
    a[0] = Serial.read();
    Serial.println();
    Serial.print("Digite o segundo digito dos minutos:");
    delay(5000);
    a[1] = Serial.read();
    Serial.println();

    minutocomida1 = atoi(a);
  }
  else if(a[0] == '3')
  {
    Serial.print("Digite o primeiro digito da hora:");
    delay(5000);
    a[0] = Serial.read();
    Serial.println();
    Serial.print("Digite o segundo digito da hora:");
    delay(5000);
    a[1] = Serial.read();
    Serial.println();

    horacomida2 = atoi(a);
  }
  else if(a[0] == '4')
  {
    Serial.print("Digite o primeiro digito dos minutos:");
    delay(5000);
    a[0] = Serial.read();
    Serial.println();
    Serial.print("Digite o segundo digito dos minutos:");
    delay(5000);
    a[1] = Serial.read();
    Serial.println();

    minutocomida2 = atoi(a);
  }
  else if(a[0] == 'q')
  {
    Serial.print("Digite o primeiro digito das viradas:");
    delay(5000);
    a[0] = Serial.read();
    Serial.println();
    Serial.print("Digite o segundo digito das viradas:");
    delay(5000);
    a[1] = Serial.read();
    Serial.println();

    viradas = atoi(a);
  }
  
}

if(s==60)  //Regras básicas do tempo
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

if(transicao>0)  //Área usada para a passagem dos meses, dependendo do limite correto de dias de cada um.
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


lcd.setCursor(0,1);  //A data é escrita na 2° linha do LCD
lcd.print (dia);
lcd.print("/");
lcd.print(meses);
lcd.print("/");
lcd.print(ano);

if(horacomida1==h)  //As duas condições para se iniciar o loop do motor
{
  if(minutocomida1==m)
  {
    
    if(s<viradas)
    {
        // Inicial a reproducao
        digitalWrite(pino_playe, HIGH);
        delay(100);
        digitalWrite(pino_playe, LOW);
        delay(2000);

        for (pos = 60; pos <= 150; pos += 1)
        {
          myservo.write(pos);              // tell servo to go to position in variable 'pos'
          delay(40);                       // waits 15ms for the servo to reach the position
        }

        delay(2000);
  
        for (pos = 150; pos >= 110; pos -= 1)
        { 
          myservo.write(pos);              // tell servo to go to position in variable 'pos'
          delay(30);                       // waits 15ms for the servo to reach the position
        }

        for (balanco = 0; balanco <= 4; balanco += 1)
        {

        for (pos = 110; pos <= 150; pos += 1)
        {
          myservo.write(pos);
          delay(30);
        }

        for (pos = 150; pos >= 110; pos -= 1)
        {
          myservo.write(pos);
          delay(30);
        }

        }

        for (pos = 110; pos >= 60; pos -= 1)
        {
          myservo.write(pos);
          delay(15);
        }
  
        delay(1000);
        limite++;
    }

    if(limite>30)  //Caso a ração no depósito esteja acabando
    {
      tone(buzzer,1500);
      lcd.setCursor(0,0);
      lcd.print ("Recarregar");
      delay(10000);
      
      /*Em delay esperamos um segundo para avançar para a próxima linha*/
      noTone(buzzer);
      /*Desligamos o Buzzer*/
      delay(5000);

      tone(buzzer,1500);
      lcd.setCursor(0,0);
      delay(10000);
      noTone(buzzer);
      delay(5000);

      tone(buzzer,1500);
      lcd.setCursor(0,0);
      delay(10000);
      noTone(buzzer);
      delay(5000);
      
      limite = 0;
    }
  }
}

if(horacomida2==h)
{
  if(minutocomida2==m)
  {
    
    if(s<viradas)
    {
        // Inicial a reproducao
        digitalWrite(pino_playe, HIGH);
        delay(100);
        digitalWrite(pino_playe, LOW);
        delay(2000);

        for (pos = 60; pos <= 150; pos += 1)
        {
          myservo.write(pos);              // tell servo to go to position in variable 'pos'
          delay(40);                       // waits 15ms for the servo to reach the position
        }

        delay(2000);
  
        for (pos = 150; pos >= 110; pos -= 1)
        { 
          myservo.write(pos);              // tell servo to go to position in variable 'pos'
          delay(30);                       // waits 15ms for the servo to reach the position
        }

        for (balanco = 0; balanco <= 4; balanco += 1)
        {

        for (pos = 110; pos <= 150; pos += 1)
        {
          myservo.write(pos);
          delay(30);
        }

        for (pos = 150; pos >= 110; pos -= 1)
        {
          myservo.write(pos);
          delay(30);
        }

        }

        for (pos = 110; pos >= 60; pos -= 1)
        {
          myservo.write(pos);
          delay(15);
        }
  
        delay(1000);
        limite++;
    }

    if(limite>30)
    {
      tone(buzzer,1500);
      lcd.setCursor(0,0);
      lcd.print ("Recarregar");
      delay(10000);
      
      /*Em delay esperamos um segundo para avançar para a próxima linha*/
      noTone(buzzer);
      /*Desligamos o Buzzer*/
      delay(5000);

      tone(buzzer,1500);
      lcd.setCursor(0,0);
      delay(10000);
      noTone(buzzer);
      delay(5000);

      tone(buzzer,1500);
      lcd.setCursor(0,0);
      delay(10000);
      noTone(buzzer);
      delay(5000);
      
      limite = 0;
    }
  }
}

if(h<horacomida1)
{
  if(m<minutocomida1)
  {
    lcd.setCursor(11,0);
    lcd.print (horacomida1);
    lcd.print (":");
    lcd.print (minutocomida1);
  }
}
else if(h==horacomida1)
{
  if(m<minutocomida1)
  {
    lcd.setCursor(11,0);
    lcd.print (horacomida1);
    lcd.print (":");
    lcd.print (minutocomida1);
  }
  else
  {
    lcd.setCursor(11,0);
    lcd.print (horacomida2);
    lcd.print (":");
    lcd.print (minutocomida2);
  }
}
else if(h>horacomida2)
{
  if(m>minutocomida2)
  {
    lcd.setCursor(11,0);
    lcd.print (horacomida1);
    lcd.print (":");
    lcd.print (minutocomida1);
  }
  else
  {
    lcd.setCursor(11,0);
    lcd.print (horacomida2);
    lcd.print (":");
    lcd.print (minutocomida2);
  }
}
else if(h==horacomida2)
{
  if(m>minutocomida2)
  {
    lcd.setCursor(11,0);
    lcd.print (horacomida1);
    lcd.print (":");
    lcd.print (minutocomida1);
  }
  else
  {
    lcd.setCursor(11,0);
    lcd.print (horacomida2);
    lcd.print (":");
    lcd.print (minutocomida2);
  }
}
else
{
  lcd.setCursor(11,0);
  lcd.print (horacomida2);
  lcd.print (":");
  lcd.print (minutocomida2);   //Condições para escrever o próximo horário da alimentação no final da 1° linha do LDC
}

}
