#include <LiquidCrystal.h>
 
LiquidCrystal lcd(12,11,5,4,3,2); 


int h; 
int m; 
int s; 
int flag; 
int bandeira;
int TIME; 
const int hs=8; 
const int ms=9; 
int state1; 
int state2; 

int horacomida1 = 9;
int minutocomida1 = 30;
int horacomida2 = 19;
int minutocomida2 = 40;  //Tempos que depois serão definidos pelo módulo Wi-Fi
int setartempo = 0;

int dia = 31;
int meses = 12;
int ano = 2017;
int transicao = 0;

void setup() 
{ 
 lcd.begin(16,2);
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
if(flag<12)lcd.print("AM"); 
if(flag==12)lcd.print("PM"); 
if(flag>12)lcd.print("PM"); 
if(flag==24)
{
  flag=0;
  transicao++;
}
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
 flag=flag+1;
 bandeira ++;
} 

if(h==13) 
{ 
 h=1; 
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
 
lcd.setCursor(10,0);
lcd.print (horacomida1);
lcd.print (":");
lcd.print (minutocomida1);
flag = horacomida1;
if(flag<12)lcd.print("AM"); 
if(flag==12)lcd.print("PM"); 
if(flag>12)lcd.print("PM");

lcd.setCursor(0,1);
lcd.print (dia);
lcd.print("/");
lcd.print(meses);
lcd.print("/");
lcd.print(ano);
lcd.print("  ");
lcd.print(bandeira);


if(setartempo == 0)
{ 
 h=11; //No lugar do 9, se bota o valor da hora setada
 bandeira=23; //No lugar do 9, se bota o valor da hora setada
 flag=23;
 if(flag<12)lcd.print("AM"); 
 if(flag==12)lcd.print("PM"); 
 if(flag>12)lcd.print("PM"); 
 if(flag==24)
 {
  flag=0;
  transicao=transicao+1;
 }

 if(bandeira==24)
{
  bandeira=0;
  transicao++;
}
 if(h==13)h=1; 
 s=50; 
 m=59; //No lugar do 59, se bota o valor dos minutos setada
 setartempo++;
}

if(bandeira==24)
{
  bandeira=0;
  transicao++;
}

}
