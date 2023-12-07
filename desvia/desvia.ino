#include <Ultrasonic.h>
#include <Servo.h>

long baixo;
long cima;
Servo servoMotor;

#define motor1Pino1  4
#define motor1Pino2  5
#define motor2Pino1  6
#define motor2Pino2  7
#define PinoServo    8

Ultrasonic ultrassombaixo(13, 12);
Ultrasonic ultrassomcima(11, 10);

void setup() {
  Serial.begin(9600);

  // Configurando os pinos como saídas
  pinMode(motor1Pino1, OUTPUT);
  pinMode(motor1Pino2, OUTPUT);
  pinMode(motor2Pino1, OUTPUT);
  pinMode(motor2Pino2, OUTPUT);

  // Inicializa o objeto Servo e associa ao pino correto
  servoMotor.attach(PinoServo);
}

void andarFrente() {
  // Motor 1 para a frente
  digitalWrite(motor1Pino1, HIGH);
  digitalWrite(motor1Pino2, LOW);

  // Motor 2 para a frente
  digitalWrite(motor2Pino1, HIGH);
  digitalWrite(motor2Pino2, LOW);
}

void virarDireita() {
  // Motor 1 para a frente
  digitalWrite(motor1Pino1, HIGH);
  digitalWrite(motor1Pino2, LOW);

  // Motor 2 para trás
  digitalWrite(motor2Pino1, LOW);
  digitalWrite(motor2Pino2, HIGH);

  delay(1000);  // Ajuste este valor conforme necessário para girar pelo tempo desejado
  pararMotores();
}

void pararMotores() {
  // Parar motor 1
  digitalWrite(motor1Pino1, LOW);
  digitalWrite(motor1Pino2, LOW);

  // Parar motor 2
  digitalWrite(motor2Pino1, LOW);
  digitalWrite(motor2Pino2, LOW);
}

void loop() {
  baixo = ultrassombaixo.Ranging(CM);
  cima = ultrassomcima.Ranging(CM);

  Serial.print("Distância Baixo = ");
  Serial.print(baixo);
  Serial.println("cm");
  delay(1000); //Intervalo de 1 segundo

  Serial.print("Distância Cima = ");
  Serial.print(cima);
  Serial.println("cm");
  delay(1000); //Intervalo de 1 segundo

  // Verifica se ambos os sensores detectam um objeto a uma distância de até 15 cm
  iint margemDetecaoObjeto = 15;

  // Verifica se algum dos sensores detecta um objeto a uma distância menor ou igual à margem
  if ((baixo > 0 && baixo <= margemDetecaoObjeto) || (cima > 0 && cima <= margemDetecaoObjeto)) {
    virarDireita(); // Vira à direita se um objeto estiver próximo
  } else {
    andarFrente(); // Move para frente se não houver objetos próximos
    servoMotor.write(90); // Ajuste o ângulo do servo conforme necessário
  }
}
}
