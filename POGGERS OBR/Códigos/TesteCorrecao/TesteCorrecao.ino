const int irPins[2] = {13, 12};
int irSensorDigital[2] = {0,0};
int i,j = 0;
int d = 1000;


int irSensors = B00;


int motor11 = 11;
int motor12 = 6;
int motor21 = 10;
int motor22 = 9;


void setup () {
  pinMode (motor11, OUTPUT);
  pinMode (motor12, OUTPUT);
  pinMode (motor21, OUTPUT);
  pinMode (motor22, OUTPUT);


    /* Set-up IR sensor pins as input */
  
  pinMode(irPins[0], INPUT);
  pinMode(irPins[1], INPUT);

  Serial.begin(9600);


}
void loop (){
    scanD();

    if (irSensorDigital[0] == 0 && irSensorDigital[1] == 0){

      analogWrite(motor21, 50);
      analogWrite(motor22, 0);
      analogWrite(motor11, 50);
     analogWrite(motor12, 0);
     delay(120);

    

    }

    if (irSensorDigital[0] == 0 && irSensorDigital[1] == 1){

      analogWrite(motor21, 50);
      analogWrite(motor22, 0);
     delay(120);

     analogWrite(motor11, 0);
     analogWrite(motor12, 0);
     delay(120);

    }

    if (irSensorDigital[0] == 1 && irSensorDigital[1] == 0){
      analogWrite(motor11, 50);
      analogWrite(motor12, 0);
     delay(120);

     analogWrite(motor21, 0);
     analogWrite(motor22, 0);
     delay(120);

    }

}

void scanD()
{
 
  irSensorDigital[0] = digitalRead(irPins[0]);
  irSensorDigital[1] = digitalRead(irPins[1]);
  Serial.print(irSensorDigital[1]);
  Serial.print(irSensorDigital[0]);

  Serial.print("|");
  
  Serial.println(".");
  delay (120);
}