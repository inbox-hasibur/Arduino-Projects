#define lms 5 
#define lmf 6
#define lmb 7
#define rmf 8
#define rmb 9
#define rms 10

int s[6], sum, avg;
int base [6] = { 1, 2, 4, 8, 16, 32 };
int position[6] = { 1, 2, 3, 4, 5, 6 };
int threshold = 512;
int sensor;

int lbase = 200;
int rbase = 200;
int lmotor, rmotor;
int kp = 50, kd=1000;
int PID;
int error, last_error;

// Void Setup -------------------------------------- + Tech Topia LFR D7 1:17:00
void setup() {
pinMode(lmf, OUTPUT);
pinMode(lmb, OUTPUT);
pinMode(rmf, OUTPUT);
pinMode(rmb, OUTPUT);
// motor(250, 250); //run all the motor forward at full speed
}
// Functions ----------------------------------------+
// Motor Functions -----------------------------
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
  if(a>250) a = 250;
  if(b>250) b = 250;
  analogWrite(lms, a);
  analogWrite(rms, b);
}
// Sensor -----------------------------------------+ (abort)
// Reading ----------------------------------------------
void reading() {
  sensor = 0;
  sum = 0;
  for (byte i=0; i<6; i++) {
    s[i] = analogRead[i];
    (s[i] > threshold) ? (s[i]=1) : (s[i]=0); //this line converts analog value into digital
    sensor += s[i] base[i];
  }
}
// PID Reading --------------------------------------
void PID_reading() {
sensor = 0;
sum = 0;
   for (byte i=0; i<6; i++) {
      s[i] = analogRead[i];
      (s[i] > threshold) ? (s[i]=1) : (s[i]=0); // converts analog value into digital
      sensor += s[i] * position[i];
      sum += s[i];
   }
   avg = sensor / sum;
}
// Void Loop --------------------------------------------+
void loop() {
  
//reading();
  //if (sensor == 0b001100) motor (250, 250);
  //else if (sensor = 0b001000) motor (200, 250);
  //else if (sensor == 0b100000) motor(0, 200);

PID_reading();
  error = 3.5 - avg;
  PID = error * kp+(error-last_error)*kd;
  last_error = error;
  rmotor = rbase - PID;
  lmotor = lbase + PID;
  motor(lmotor, rmotor);
}
