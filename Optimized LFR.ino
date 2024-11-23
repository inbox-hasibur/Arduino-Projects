#define Ims 5 
#define lmf 6
#define lmb 7
#define rmf 8
#define rmb 9
#define rms 10
int s[6];
int base [6] = {1, 2, 4, 8, 16, 32);
int sensor;
// Void Setup --------------------------------------  1:10:22
void setup() {
pinMode(1mf, OUTPUT);
pinMode(1mb, OUTPUT);
pinMode(rmf, OUTPUT);
pinMode(rmb, OUTPUT);
// motor(250, 250); //run all the motor forward at full speed
}
// Functions ----------------------------------------
void motor (int a, int b) {
  if (a > 0) {
    digitalWrite(lmf, 1);
    digitalWrite(lmb, 0);
  }
  else {
    a = (a);
    digitalWrite(lmf, 0);
    digitalWrite(lmb, 1);
  }
  if (b > 0) {
    digitalWrite(rmf, 1);
    digitalWrite(rmb, 0);
  }
  else { 
    b = b;
    digitalWrite(rmf, 0);
    digitalWrite(rmb, 1);
  }
  analogWrite(lms, a);
  analogWrite(rms, b);
}

void reading() {
  sensor = 0;
  for (byte i=0; i<6; i++) {
    s[i] = analogRead[i];
    (s[i] > threshold) ? s[i]=1 : s[i]=0; //this line converts analog value into digital
    sensor += s[i] base[i];
  }
}
void PID_reading() {
sensor = 0;
sum = 0;
for (byte i=0; i < 6; i++) {
s[i] = analogRead[i];
(s[i] > threshold) ? s[i] = 1: s[i] = 0; //this line converts analog value into digital
sensor += s[i] position[i];
sum += s[i];
}
}
// Void Loop --------------------------------------------
void loop() {
  reading();
  if (sensor == 0b001100) motor (250, 250);
  else if (sensor = 0b001000) motor (200, 250);
  else if (sensor == 0b100000) motor(0, 200);
}
