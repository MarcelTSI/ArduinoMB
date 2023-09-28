#define botao 3
#define ledvermelho 2
#define ledverde 4
#define trigger 7
#define echo 6
#define buzzer 8

bool sistemaLigado = true;
unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 50;

void setup() {
  Serial.begin(9600);
  pinMode(botao, INPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(ledvermelho, OUTPUT);
  pinMode(ledverde, OUTPUT);
  pinMode(trigger, OUTPUT); // Modificamos para saída para enviar o pulso
  pinMode(echo, INPUT);     // Modificamos para entrada para receber o pulso
}

void loop() {
  // Verificação do botão
  int botaoEstado = digitalRead(botao);
  if (botaoEstado == HIGH && (millis() - lastDebounceTime) > debounceDelay) {
    lastDebounceTime = millis();
    sistemaLigado = !sistemaLigado; // Inverte o estado do sistema
    if (!sistemaLigado) {
      digitalWrite(ledvermelho, LOW); // Desliga o LED vermelho
      noTone(buzzer);                 // Desliga o buzzer
    }
  }

  if (sistemaLigado) {
    // Leitura da distância
    digitalWrite(trigger, LOW);
    delayMicroseconds(2);
    digitalWrite(trigger, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigger, LOW);
    float distancia = pulseIn(echo, HIGH) / 58.0; // Converte o tempo do pulso em distância em cm

    // Exibir a distância no Serial Monitor
    Serial.print("Distancia: ");
    Serial.print(distancia);
    Serial.println(" cm");

    // Verificação da distância e controle dos LEDs e buzzer
    if (distancia > 10) {
      digitalWrite(ledvermelho, LOW);
      digitalWrite(ledverde, HIGH);
      noTone(buzzer); // Para o buzzer
    } else {
      digitalWrite(ledvermelho, HIGH);
      digitalWrite(ledverde, LOW);
      tone(buzzer, 1000); // Liga o buzzer com um tom de 1000 Hz
    }
  } else {
    digitalWrite(ledvermelho, LOW); // Desliga o LED vermelho
    digitalWrite(ledverde, LOW);     // Desliga o LED verde
    noTone(buzzer);                 // Desliga o buzzer
  }
}
