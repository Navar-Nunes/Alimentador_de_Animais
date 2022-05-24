#include <Wire.h>
#include <RTClib.h>
//RTC - Real Time Clock
RTC_DS1307 RTC;
//Inicializacao dos modulos 
void setup () {
    //Inicialozacao da serial
    Serial.begin(9600);//Inicializacao da serial
    Wire.begin();//Inicializacao do protocolo wire
    RTC.begin();//Inicializacao do modulo RTC
  //Verifica se o modulo esta funcionando ou nao
  if (! RTC.isrunning()) {
    Serial.println("RTC is NOT running!");
    //Ajusta a data/hora do Clock com a data/hora em que o codigo foi compilado, basta descomentar a linha
    RTC.adjust(DateTime(__DATE__, __TIME__));
  }
}
void loop () {
    DateTime now = RTC.now();//Recuperando a data e hora atual
    Serial.print(now.day(), DEC);//Imprimindo o dia
    Serial.print('/');
    Serial.print(now.month(), DEC);//Recuperando o mes
    Serial.print('/');
    Serial.print(now.year(), DEC);//Recuperando o ano
    Serial.print(' ');
    Serial.print(now.hour(), DEC);//Recuperando a hora
    Serial.print(':');
    Serial.print(now.minute(), DEC);//Reci[erando os minutos
    Serial.print(':');
    Serial.print(now.second(), DEC);//Recuperando os segundos
    Serial.println();
    delay(3000);//A leitura sera repetida a cada 3 segundos
}
