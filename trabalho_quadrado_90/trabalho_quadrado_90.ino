// Definindo os pinos conectados à ponte H
int motor1Pino1 = 4; // Pino de controle do motor 1 - sentido 1
int motor1Pino2 = 5; // Pino de controle do motor 1 - sentido 2
int motor2Pino1 = 6; // Pino de controle do motor 2 - sentido 1
int motor2Pino2 = 7; // Pino de controle do motor 2 - sentido 2

 void setup() {
  // Configurando os pinos como saídas
  pinMode(motor1Pino1, OUTPUT);
  pinMode(motor1Pino2, OUTPUT);
  pinMode(motor2Pino1, OUTPUT);
  pinMode(motor2Pino2, OUTPUT);
}

void loop() {

    delay(5000);

  // Movimento para a frente
  motorFrente();
  delay(2000); // Aguarda por 2 segundos

  // Girar para a direita
  virarDireita();
  delay(1000); // Aguarda por 1 segundo

  // Movimento para frente novamente (lado direito do quadrado)
  motorFrente();
  delay(2000); // Aguarda por 2 segundos

  // Girar para a direita (canto superior direito)
  virarDireita();
  delay(1000); // Aguarda por 1 segundo

  // Movimento para frente novamente (lado superior do quadrado)
  motorFrente();
  delay(2000); // Aguarda por 2 segundos

  // Girar para a direita (canto superior esquerdo)
  virarDireita();
  delay(1000); // Aguarda por 1 segundo

  // Movimento para frente novamente (lado esquerdo do quadrado)
  motorFrente();
  delay(2000); // Aguarda por 2 segundos

  // Girar para a direita (canto inferior esquerdo)
  virarDireita();
  delay(1000); // Aguarda por 1 segundo

  // Movimento para frente novamente (lado esquerdo do quadrado)
  motorFrente();
  delay(2000); // Aguarda por 2 segundos

  // 180º 
  virarDireita();
  delay(2000); // Aguarda por 2 segundos

  // Movimento para a frente
  motorFrente();
  delay(2000); // Aguarda por 2 segundos

  // Girar para a esquerda (lado esquerdo inferior)
  virarEsquerda();
  delay(1000); // Aguarda por 1 segundo

  // Movimento para frente novamente 
  motorFrente();
  delay(2000); // Aguarda por 2 segundos

  // Girar para a esquerda (canto inferior direito)
  virarEsquerda();
  delay(1000); // Aguarda por 1 segundo

  // Movimento para frente novamente (lado superior do quadrado)
  motorFrente();
  delay(2000); // Aguarda por 2 segundos

  // Girar para a esquerda (canto superior direito)
  virarEsquerda();
  delay(1000); // Aguarda por 1 segundo

  // Movimento para frente novamente (lado direito do quadrado)
  motorFrente();
  delay(2000); // Aguarda por 2 segundos

  // Girar para a esquerda (canto superior esquerdo)
  virarEsquerda();
  delay(1000); // Aguarda por 1 segundo

  // Movimento para frente novamente (lado esquerdo do quadrado)
  motorFrente();
  delay(2000); // Aguarda por 2 segundos

  // Parar por um segundo (canto inferior esquerdo)
  parar();
  delay(1000); // Aguarda por 1 segundo
}

void motorFrente() {
  // Motor 1 para a frente
  digitalWrite(motor1Pino1, HIGH);
  digitalWrite(motor1Pino2, LOW);

  // Motor 2 para a frente
  digitalWrite(motor2Pino1, HIGH);
  digitalWrite(motor2Pino2, LOW);
}

void virarDireita() {
  // Motor 1 para frente
  digitalWrite(motor1Pino1, HIGH);
  digitalWrite(motor1Pino2, LOW);

  // Motor 2 para trás
  digitalWrite(motor2Pino1, LOW);
  digitalWrite(motor2Pino2, HIGH);
}

void virarEsquerda() {
  // Motor 1 para frente
  digitalWrite(motor1Pino1, LOW);
  digitalWrite(motor1Pino2, HIGH);

  // Motor 2 para trás
  digitalWrite(motor2Pino1, HIGH);
  digitalWrite(motor2Pino2, LOW);
}

void parar() {
  // Parar motor 1
  digitalWrite(motor1Pino1, LOW);
  digitalWrite(motor1Pino2, LOW);

  // Parar motor 2
  digitalWrite(motor2Pino1, LOW);
  digitalWrite(motor2Pino2, LOW);
}