int sw = 11; //botão
int xPin = A2; //analógico X
int yPin = A1; //analógico Y

//roda direita
int motor_a1 = 5;
int motor_a2 = 9;

//roda esquerda
int motor_b1 = 2;
int motor_b2 = 4;

void setup()
{
  
  pinMode(sw, INPUT_PULLUP); //define o sw(pino 11) como entrada
  pinMode(3, OUTPUT); //define o pino 3 como saída
  pinMode(xPin, INPUT);
  pinMode(yPin, INPUT);
  pinMode(motor_a1, OUTPUT); // define EN1 como saída
  pinMode(motor_a2, OUTPUT); // define EN2 como saída
  pinMode(motor_b1, OUTPUT); // define EN3 como saída
  pinMode(motor_b2, OUTPUT); // define EN4 como saída

  Serial.begin(9600);
}

void loop()
{

  int valor_botao = digitalRead(sw);
  int xVal = analogRead(xPin);
  int yVal = analogRead(yPin);

  buzzer(); //"buzina"
  movements(); //movimentos básicos

  Serial.print(" x = ");
  Serial.print(xVal);
  Serial.println();

  Serial.print("    y = ");
  Serial.print(yVal);
  delay(100);

}

void buzzer()
{

  int valor_botao = digitalRead(sw); 

  if(valor_botao == HIGH){

   digitalWrite(3, LOW);

  } else {

    digitalWrite(3, HIGH);

  }
}

void movements(){

  int xVal = analogRead(xPin);
  int yVal = analogRead(yPin);

  //frente
  if(yVal < 10){

    digitalWrite(motor_a1, LOW);
    digitalWrite(motor_a2, HIGH);
    digitalWrite(motor_b1, LOW);
    digitalWrite(motor_b2, HIGH);

  }

  //ré
  if(yVal > 900){

    digitalWrite(motor_a1, HIGH);
    digitalWrite(motor_a2, LOW);
    digitalWrite(motor_b1, HIGH);
    digitalWrite(motor_b2, LOW);

  }

  //esquerda
  if(xVal < 10){

    digitalWrite(motor_a1, LOW);
    digitalWrite(motor_a2, HIGH);
    digitalWrite(motor_b1, HIGH);
    digitalWrite(motor_b2, LOW);

  }

  //direita
  if(xVal > 900){

    digitalWrite(motor_a1, HIGH);
    digitalWrite(motor_a2, LOW);
    digitalWrite(motor_b1, LOW);
    digitalWrite(motor_b2, HIGH);

  }

  //parar
  if(xVal >= 450 && xVal <= 550 && yVal >= 450 && yVal <= 550){

    digitalWrite(motor_a1, HIGH);
    digitalWrite(motor_a2, HIGH);
    digitalWrite(motor_b1, HIGH);
    digitalWrite(motor_b2, HIGH);

  }

}