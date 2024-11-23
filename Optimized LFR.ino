#define Ims 5
#define lmf 6
#define lmb 7
#define rmf 8
#define rmb 9
#define rms 10
int s[6];
int base [6] = {1, 2, 4, 8, 16, 32);
int sensor;
void setup() {
pinMode(1mf, OUTPUT);
pinMode(1mb, OUTPUT);
pinMode(rmf, OUTPUT);
pinMode(rmb, OUTPUT);
// motor(250, 250); //run all the motor forward at full speed
}
void loop() {
reading();
if (sensor == 0b001100) motor (250, 250);
else if (sensor = 0b001000) motor (200, 250);
else if (sensor == 0b100000) motor(0, 200);
}
