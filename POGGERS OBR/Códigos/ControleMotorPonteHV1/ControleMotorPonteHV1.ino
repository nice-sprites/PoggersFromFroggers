int pino1 = 11;
int pino2 = 12;
int pino3 = 7;
int pino4 = 8;

void setup () {
  pinMode (pino1, OUTPUT);
  pinMode (pino2, OUTPUT);
  pinMode (pino3, OUTPUT);
  pinMode (pino2, OUTPUT);
}
void loop (){
  motor_left();
  delay (2000);

  motor_right();
  delay (2000);
}

void motor_left(){
  digitalWrite (pino1, LOW);
  digitalWrite (pino2, HIGH);
} 
void motor_right (){
  digitalWrite (pino3, LOW);
  digitalWrite (pino4, HIGH);
}
