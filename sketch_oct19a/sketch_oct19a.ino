/* ==================================================================================================

Projeto: Controle de Acesso com RFID
Autor: Danilo Nogueira
Data: 24/10/2019

// ==================================================================================================*/
// --- Declaração Bibliotecas ---

#include <SPI.h>
#include <MFRC522.h>

// --- Declaração das variáveis --
int pino_ss       = 10;
int pino_rst      = 9;
int led_acesso    = 5;
int led_erro      = 6;

MFRC522 mfrc522(pino_ss, pino_rst);  // Criando o objeto do nosso sensor, mfrc522 é tipo controle de ssegurança e comunicação

// =================================================================================================
// --- Configurando o void setup() ---

void setup() 
{
  pinMode(led_acesso, OUTPUT);
  pinMode(led_erro, OUTPUT);
  
  // Iniciando a serial
  Serial.begin(9600);
  SPI.begin(); //quando o sinal ta baixo ele conecta o dispositivo 
  
  // Inicia MFRC522
  mfrc522.PCD_Init(); 
  
  // Mensagens iniciais no serial monitor
  Serial.println("Aproxime o cartao do leitor...");
  Serial.println();
}

// =================================================================================================
// --- Configurando o void loop() ---

void loop() 
{
  // Verifica se algum cartão foi aproximado do sensor
  if ( ! mfrc522.PICC_IsNewCardPresent()) { return; }
  
  // Verifica qual cartão foi lido
  if ( ! mfrc522.PICC_ReadCardSerial()) { return; }
  
  // Mostra UID na serial
  Serial.print("UID da tag :");
  String conteudo= "";
  byte letra;
  
  // --- Escrevendo na serial a UID do cartão --
  for (byte i = 0; i < mfrc522.uid.size; i++) 
  {
     Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
     Serial.print(mfrc522.uid.uidByte[i], HEX);
     
     conteudo.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
     conteudo.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  
  Serial.println();
  Serial.print("Mensagem : ");
  conteudo.toUpperCase();
  
   // Testa se o cartao1 foi lido
  if (conteudo.substring(1) == "D8 4B 12 22" || conteudo.substring(1) == "87 4B DC 8A") {
    if (conteudo.substring(1) == "D8 4B 12 22") {
      // Acende o LED verde e libera o acesso
      digitalWrite(led_acesso, HIGH);
      Serial.println("Cartao1 - Acesso liberado !");
    
      Serial.println();
      delay(2000);
      digitalWrite(led_acesso, LOW);
    } else {
      // Testa se o cartao2 foi lido
      Serial.println("Cartao2 - Acesso negado !!");
      Serial.println();
      
      // Pisca o led vermelho sinalizando um erro de acesso
      for (int i = 1; i < 5; i++) {
        digitalWrite(led_erro, HIGH);
        delay(200);
        digitalWrite(led_erro, LOW);
        delay(200);
      } //for
    } //else 
  } //if
  delay(1000);
}//loop
// ===================================== F I M =========================================
