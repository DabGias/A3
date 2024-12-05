#define SENSOR_ESQ 9
#define SENSOR_DIR 8

#define ENA 13
#define ENB 2

#define IN1 11
#define IN2 10
#define IN3 6
#define IN4 5

void setup() {
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);

  digitalWrite(ENA, HIGH);
  digitalWrite(ENB, HIGH);

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  
  pinMode(SENSOR_ESQ, INPUT);
  pinMode(SENSOR_DIR, INPUT);
  
  Serial.begin(9600);
}

void ativaRoda(String roda);
void inverteRoda(String roda);
void freiaRoda(String roda);

void loop() {
  int sensorEsq = digitalRead(SENSOR_ESQ);
  int sensorDir = digitalRead(SENSOR_DIR);

  Serial.print("Sensor esquerdo: ");
  Serial.println(sensorEsq);

  Serial.print("Sensor direito: ");
  Serial.println(sensorDir);

  if (sensorEsq == 0 && sensorDir == 1) {
    inverteRoda("direita");
    ativaRoda("esquerda");
  } else if (sensorEsq == 1 && sensorDir == 0) {
    inverteRoda("esquerda");
    ativaRoda("direita");
  } else if (sensorEsq == 1 && sensorDir == 1) {
    freiaRoda("ambas");
  } else if (sensorEsq == 0 && sensorDir == 0) {
    ativaRoda("ambas");
  }
}

void ativaRoda(String roda) {
  if (roda.equals("esquerda")) {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
  } else if (roda.equals("direita")) {
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
  } else if (roda.equals("ambas")) {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
  }
}

void inverteRoda(String roda) {
  if (roda.equals("esquerda")) {
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
  } else if (roda.equals("direita")) {
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
  } else if (roda.equals("ambas")) {
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
  }
}

void freiaRoda(String roda) {
  if (roda.equals("esquerda")) {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
  } else if (roda.equals("direita")) {
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
  } else if (roda.equals("ambas")) {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
  }
}
