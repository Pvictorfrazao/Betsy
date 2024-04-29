int sw = 25;
int xPin = 35;
int yPin = 33;

//roda direita
int motor_a1 = 4;
int motor_a2 = 15;

//roda esquerda
int motor_b1 = 2;
int motor_b2 = 14;

void setup() {
  // put your setup code here, to run once:
  pinMode(sw, INPUT_PULLUP);
  pinMode(26, OUTPUT);
  pinMode(xPin, INPUT);
  pinMode(yPin, INPUT);
  pinMode(motor_a1, OUTPUT); // define EN1 como saída
  pinMode(motor_a2, OUTPUT); // define EN2 como saída
  pinMode(motor_b1, OUTPUT); // define EN3 como saída
  pinMode(motor_b2, OUTPUT); // define EN4 como saída


  Serial.begin(9600);
}

void buzzer();
void movements();

void loop() {
  // put your main code here, to run repeatedly:
  int xVal = analogRead(xPin);
  int yVal = analogRead(yPin);

  Serial.print(" x = ");
  Serial.print(xVal);
  Serial.println();

  Serial.print("    y = ");
  Serial.print(yVal);
  delay(100);

  buzzer();
  movements();

}

void buzzer(){

  int valor_botao = digitalRead(sw);

  if(valor_botao == HIGH){

   digitalWrite(26, LOW);

  } else {

    digitalWrite(26, HIGH);

  }

}

void movements(){

  int xVal = analogRead(xPin);
  int yVal = analogRead(yPin);

  //frente
  if(yVal < 250){

    digitalWrite(motor_a1, LOW);
    digitalWrite(motor_a2, HIGH);
    digitalWrite(motor_b1, LOW);
    digitalWrite(motor_b2, HIGH);

  }

  //ré
  if(yVal > 4080){

    digitalWrite(motor_a1, HIGH);
    digitalWrite(motor_a2, LOW);
    digitalWrite(motor_b1, HIGH);
    digitalWrite(motor_b2, LOW);

  }

  //esquerda
  if(xVal < 300){

    digitalWrite(motor_a1, LOW);
    digitalWrite(motor_a2, HIGH);
    digitalWrite(motor_b1, HIGH);
    digitalWrite(motor_b2, LOW);

  }

  //direita
  if(xVal > 4080){

    digitalWrite(motor_a1, HIGH);
    digitalWrite(motor_a2, LOW);
    digitalWrite(motor_b1, LOW);
    digitalWrite(motor_b2, HIGH);

  }

  //parar
  if(xVal >= 2400 && xVal <= 2700 && yVal >= 2490 && yVal <= 2800){

    digitalWrite(motor_a1, HIGH);
    digitalWrite(motor_a2, HIGH);
    digitalWrite(motor_b1, HIGH);
    digitalWrite(motor_b2, HIGH);

  }

}