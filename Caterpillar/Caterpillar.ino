char firstPin = 0;
char lastPin = 4;

void setup() {                
  Serial.begin(9600);
  for (char pin = firstPin; pin <= lastPin; pin++)
  {
    pinMode(pin, OUTPUT);
  }  
}

void loop() {
  
//  Serial.println("Loading");
//  Loading();
//  delay(2000);
  
  Serial.println("FadeAll");
  FadeAll();
  delay(2000);
  
//  Serial.println("Caterpillar");
//  Caterpillar();
//  delay(2000);
}

void Caterpillar() {
  char length = 3;
  for (char pin = firstPin; pin <= lastPin + length; pin++)
  {
    if (pin <= lastPin) 
    {
      digitalWrite(pin, LOW);
    }
    
    if (pin >= length){
      digitalWrite((pin - length) + 1, HIGH);
    }
    
    delay(500);
  }
}

void Loading() {
  for (char pin = firstPin; pin <= lastPin; pin++)
  {
    Serial.println(pin, DEC);
    digitalWrite(pin, LOW);
    delay(250);
  }
  for (char pin = firstPin; pin <= lastPin; pin++)
  {
    Serial.println(pin, DEC);
    digitalWrite(pin, HIGH);
    delay(250);
  }
}

void FadeAll() {
  
  for (char brightness = 0; brightness < 255; brightness++)
  {  
//    for (char pin = firstPin; pin <= lastPin; pin++)
//    {
      analogWrite(A0, brightness);
//    }
    delay(10);
  }
  
//  for (char brightness = 255; brightness > 0; brightness--)
//  {  
//    for (char pin = firstPin; pin <= lastPin; pin++)
//    {
//      analogWrite(A0, 0);
//    }
//    delay(10);
//  }
}



