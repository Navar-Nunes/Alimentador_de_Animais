void setup() 
{
  Serial.begin(57600);
  while(!Serial)
  {;}

  Serial.println("Teste de serial");

  mySerial.begin(4800);
  mySerial.println("Funcionando");
}

void loop() 
{
  if (mySerial.available())
  {
    Serial.write(mySerial.read());
  }

  if (Serial.available())
  {
    mySerial.write(Serial.read());
  }
}
