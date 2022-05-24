#include <Servo.h>
#include <LiquidCrystal.h>
#include "Wire.h"
#define DS1307_ADDRESS 0x68

Servo servo;
int pos = 0;
int boia = 46;
const int rele = 24;
byte horas=0;
byte minutos=0;
//LCD
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
byte zero = 0x00;
void recordPlay(int time_rec);
const int rec = 7;
const int playe = 6;

void setup() {
  servo.attach(10);
  servo.write(90);
  pinMode(boia,INPUT);
  pinMode(rele, OUTPUT);
  Wire.begin();
   //DECLARAÇÕES MONITOR LCD(16 COLUNAS X 2 LINHAS)
  lcd.begin(16, 2);
  lcd.setCursor(0,0);
  lcd.print("Ola, eu sou o");
  lcd.setCursor(0, 1);
  lcd.print("Goku");
  //DECLARAÇÃO PINO Grava Voz
  pinMode(rec, OUTPUT);
  pinMode(playe, OUTPUT);
  //SelecionaDataeHora();

}

void SelecionaDataeHora() // Seta a data e a hora do DS1307
{
 byte segundos = 01; // Valores de 0 a 59
 byte minutos = 21; // Valores de 0 a 59
 byte horas = 01; // Valores de 0 a 23
 byte diadasemana = 1; // Valores de 0 a 6 (0=Domingo, 1 = Segunda...)
 byte diadomes = 11; // Valores de 1 a 31
 byte mes = 7; // Valores de 1 a 12
 byte ano = 17; // Valores de 0 a 99
 Wire.beginTransmission(DS1307_ADDRESS);
 // Stop no CI para que o mesmo possa receber os dados
 Wire.write(zero); 
 
 // As linhas abaixo escrevem no CI os valores de 
 // data e hora que foram colocados nas variaveis acima
 Wire.write(ConverteParaBCD(segundos));
 Wire.write(ConverteParaBCD(minutos));
 Wire.write(ConverteParaBCD(horas));
 Wire.write(ConverteParaBCD(diadasemana));
 Wire.write(ConverteParaBCD(diadomes));
 Wire.write(ConverteParaBCD(mes));
 Wire.write(ConverteParaBCD(ano));
 Wire.write(zero); //Start no CI
 Wire.endTransmission(); 
}
 
byte ConverteParaBCD(byte val)
{ 
 // Converte o número de decimal para BCD
 return ( (val/10*16) + (val%10) );
}
 
byte ConverteparaDecimal(byte val) 
{ 
 // Converte de BCD para decimal
 return ( (val/16*10) + (val%16) );
}
 
void MostrarelogioeMotor()
{
 Wire.beginTransmission(DS1307_ADDRESS);
 Wire.write(zero);
 Wire.endTransmission();
 Wire.requestFrom(DS1307_ADDRESS, 7);
 int segundos = ConverteparaDecimal(Wire.read());
  minutos = ConverteparaDecimal(Wire.read());
  horas = ConverteparaDecimal(Wire.read() & 0b111111); 
 int diadasemana = ConverteparaDecimal(Wire.read()); 
 int diadomes = ConverteparaDecimal(Wire.read());
 int mes = ConverteparaDecimal(Wire.read());
 int ano = ConverteparaDecimal(Wire.read());
 // Imprime mensagem na primeira linha do display
 lcd.setCursor(0,0);
 lcd.print("---- PET FEEDER ----");
  
 // Mostra a hora atual no display
 lcd.setCursor(2, 1);
 if (horas < 10)
 {lcd.print("0");}
 lcd.print(horas);
 lcd.print(":");
 if (minutos < 10)
 {lcd.print("0");}
 lcd.print(minutos);
 lcd.print(":");
 if (segundos < 10)
 {lcd.print("0");}
 lcd.print(segundos);
  
 //Mostra o dia da semana no display
 lcd.setCursor(12, 0);
 switch(diadasemana)
 {
 case 0:lcd.print("Dom");
 break;
 case 1:lcd.print("Seg");
 break;
 case 2:lcd.print("Ter");
 break;
 case 3:lcd.print("Qua");
 break;
 case 4:lcd.print("Qui");
 break;
 case 5:lcd.print("Sex");
 break;
 case 6:lcd.print("Sab");
 }
  //servo motor
   if(horas == 06 && minutos == 41 && segundos == 01){
    servo.write(45);
    delay(5000);
    servo.write(90);
    delay(500);
    digitalWrite(playe, HIGH);
    delay(5000);
    }
  }



void loop() {
  if(digitalRead(boia)==HIGH){
    digitalWrite(rele,LOW);
    delay(3000);
  }else{
    digitalWrite(rele,HIGH);
  }
 MostrarelogioeMotor();
 delay(1000);

}


