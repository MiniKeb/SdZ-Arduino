char aRedPin = 2;
char aOrangePin = 3;
char aGreenPin = 4;

char bRedPin = 5;
char bOrangePin = 6;
char bGreenPin = 7;

long timestamp;

void setup() {
  Serial.begin(9600);
  for (char pin = 2; pin <= 7; pin++)
  {
    pinMode(pin, OUTPUT);
    digitalWrite(pin, HIGH);
  }

  digitalWrite(aRedPin, LOW);
  digitalWrite(bRedPin, LOW);
}

void loop() {
  Serial.println("Start");
  run(aGreenPin, aOrangePin, aRedPin);
  run(bGreenPin, bOrangePin, bRedPin);
  Serial.println("End");
}

void run(char green, char orange, char red)
{
  switchPin(red, green, 3);
  switchPin(green, orange, 1);
  switchPin(orange, red, 3);
}

void switchPin(char currentPin, char nextPin, int second)
{
  digitalWrite(currentPin, HIGH);
  digitalWrite(nextPin, LOW);
  delay(second * 1000);
}

