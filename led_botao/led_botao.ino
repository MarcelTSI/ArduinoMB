#define botao 7
#define led 10
boolean ligado = false;

// C++ code
//
void setup()
{
  pinMode(botao, INPUT);
  pinMode(led, OUTPUT);
  Serial.begin(9600);
}

void loop(){

  
  
  if (digitalRead(botao) == HIGH) {

    digitalWrite(led, HIGH);
    Serial.println("pressionado");
    
  } else {
    digitalWrite(led, LOW);	
    Serial.println("nao pressionado");
  }
  }