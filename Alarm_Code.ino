

// defines pins numbers
const int trigPin = 9;
const int echoPin = 10;

const int buzzer = 3;
const int ledpin = 7;
const int armPin = 2; 

// defines variables
long duration;
int distance;

void setup() {
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  Serial.begin(9600); // Starts the serial communication
  pinMode(buzzer, OUTPUT);
  pinMode( ledpin, OUTPUT);
  pinMode( armPin, OUTPUT); 
}

void loop() {
  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(100);
  digitalWrite(trigPin, LOW);

  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);

  // Calculating the distance
  distance = duration * 0.034 / 2;

  // Prints the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.println(distance);


  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  boolean play = distance <= 25;
  if (play) {
    for(int i =0; i< 120; i++) {
      digitalWrite( armPin, LOW);
      tone(buzzer, 2000, 500);
      delay(100);

      digitalWrite(ledpin, HIGH);
      delay(100);
      digitalWrite( ledpin, LOW);
      delay(100);
    }
  }
  else{
    digitalWrite( armPin, HIGH);
  }
}
