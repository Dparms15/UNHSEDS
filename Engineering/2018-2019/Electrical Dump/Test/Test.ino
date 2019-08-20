int pwmPin = 5;    // motor connected to digital pin 5
int in1 = 3;
int in2 = 6;

const byte interruptPin = 2;
int count = 1;


void setup() {
  // put your setup code here, to run once:
  pinMode(9, OUTPUT);
  pinMode(10 , INPUT);
  pinMode(11 , INPUT);
  pinMode(3 , OUTPUT);
  pinMode(6 , OUTPUT);
  pinMode(5 , OUTPUT); 
  Serial.begin(9600); 
  
  // prime the interrupt pins
  pinMode(interruptPin, INPUT_PULLUP);
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
  
}

void loop() {
  
  if (digitalRead(10) == LOW && digitalRead(11) == LOW) {
    Serial.print("Waiting for go signal\n");
  }
  
  else if (digitalRead(10) == HIGH && digitalRead(11) == LOW ) {
    Serial.print("Igniting\n");
    digitalWrite(9, HIGH);                //Igniter 
    delay(100);
    //digitalWrite(9, LOW);
    delay(3400);                          //Delay for burn

    // HALF OPEN
    digitalWrite(in1, HIGH);              //Direction --> Reverse
    analogWrite(pwmPin, 255);             //digitalWrite(pwmPin, HIGH);           //Speed
    Serial.print("Opening\n");
    delay(1300);                          //For how long
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    delay(10000);
    
    // FULLY OPEN
    Serial.println("Done Opening");                                       //Serial.print("Full Open\n");
    digitalWrite(in1, HIGH);
    analogWrite(pwmPin, 255);
    delay(600);
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);

    //FULLY CLOSING
    digitalWrite(in2, HIGH);
    analogWrite(pwmPin, 255);
    delay(2000);
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    
    //delay(180000);
    //digitalWrite(in1, LOW);
    //digitalWrite(in2, HIGH);
    Serial.print("Closed\n");
    //delay(1500);
    //digitalWrite(in1, LOW);
    //digitalWrite(in2, LOW);
    count++;
  }

  while (digitalRead(11) == HIGH) {
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    delay(1500);
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    break;
  }
  }
