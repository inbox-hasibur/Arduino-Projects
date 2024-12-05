// Rail-cross System
#include <Servo.h>
Servo s;  
int pos=0;

int T=A3, E=A4;  // T=TrigerPin E=EchoPin
float Distance, Duration;

void setup(){
  pinMode(T, OUTPUT);
  pinMode(E, INPUT);
  Serial.begin(9600);
  s.attach(4);
}

void loop() {
  digitalWrite(T, LOW);    delay(2);
  digitalWrite(T, HIGH);   delayMicroseconds(10);
  digitalWrite(T, LOW);
  Duration= pulseIn(E, HIGH);
  Distance= (Duration*0.034)/2;
  s.write(180);
  if(Distance<50){
    s.write(180);       
    delay(1000);
  } else {
    s.write(0);   
    delay(400);
  }
  Serial.print("The Distance is = ");
  Serial.print(Distance);
  Serial.print("cm\n");
  delay(100);
}
