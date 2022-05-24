// Pino ligado ao REC do modulo
int pino_rec = 6;
// Pino ligado ao P-E (PLAYE) do modulo
int pino_playe = 7;

void setup()
{ 
  pinMode(pino_rec, OUTPUT);
  pinMode(pino_playe, OUTPUT);
}

void loop()
{
  delay(2000);
  // Inicia a gravacao
  digitalWrite(pino_rec, HIGH);
  delay(10000);
  // Para a gravacao
  digitalWrite(pino_rec, LOW);
  // Aguarda 5 segundos
  delay(3000);
  // Inicial a reproducao
  digitalWrite(pino_playe, HIGH);
  delay(100);
  digitalWrite(pino_playe, LOW);
  // Aguarda 20 segundos e reinicia o processo
  delay(20000);
}  
