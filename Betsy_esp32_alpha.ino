int sw = 25;
int xPin = 35;
int yPin = 33;

int vermelho = 11;
int amarelo = 10;
int verde = 12;
int buzzerr = 7;

//sensor
int distancia = 0;

//roda direita
int motor_a1 = 4;
int motor_a2 = 15;

//roda esquerda
int motor_b1 = 2;
int motor_b2 = 14;

//sensor Ultra
long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  // Clear the trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  // Reads the echo pin, and returns the sound wave travel time in microseconds
  return pulseIn(echoPin, HIGH);
}


void setup() {
  //sensorUltra
  pinMode(vermelho, OUTPUT);
  pinMode(amarelo, OUTPUT);
  pinMode(verde, OUTPUT);
  pinMode(buzzerr, OUTPUT);

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

  //vermelho
  distancia = 0.01723 * readUltrasonicDistance(8, 6);
    if (distancia <= 15)
    {
      digitalWrite(vermelho, HIGH);
      digitalWrite(amarelo, LOW);
      digitalWrite(verde, LOW);
      digitalWrite(buzzerr, HIGH);
      delay(150); // Wait for 300 millisecond(s)
      digitalWrite(buzzerr, LOW);
      delay(150); // Wait for 300 millisecond(s)
    } 
    else 
    {
      digitalWrite(vermelho, LOW);
      digitalWrite(amarelo, LOW);
      digitalWrite(verde, LOW);
    }

    //amarelo
    if (distancia == constrain(distancia, 16, 30)) 
    {
      digitalWrite(verde, LOW);
      digitalWrite(vermelho, LOW);
      digitalWrite(amarelo, HIGH);
      digitalWrite(buzzerr, HIGH);
      delay(300); // Wait for 800 millisecond(s)
      digitalWrite(buzzerr, LOW);
      delay(300); // Wait for 800 millisecond(s)
    }


    //verde
    if (distancia >= 31) 
    {
      digitalWrite(verde, HIGH);
      digitalWrite(vermelho, LOW); //petista
      digitalWrite(amarelo, LOW);
      digitalWrite(buzzerr, LOW);

    }

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
