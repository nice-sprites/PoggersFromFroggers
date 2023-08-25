const int irPins[2] = {12, 13};
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
  for (int i = 0; i <= 1; i++)
  {pinMode(irPins[i], INPUT);}

  Serial.begin(9600);


}
void loop (){
    scanD();
    check();
    //go();

    /*motor_left();
    stopmeR();
    delay(2000);
    motor_right();
    stopmeL();
    delay(2000);*/
}


void motor_left(){
  analogWrite (motor11, 30);
  analogWrite (motor12, 0);
}

void motor_right (){
  analogWrite (motor21, 30);
  analogWrite (motor22, 0);
}

void go()
{
    Serial.println("                         forward ");
     analogWrite(motor21, 30);
     analogWrite(motor22, 0);
     
     analogWrite(motor11, 30);
     analogWrite(motor12, 0);
 
}


void stopme()
{
     Serial.println("                         stop");

     digitalWrite(motor11, LOW);
     digitalWrite(motor12, LOW);

     digitalWrite(motor21, LOW);
     digitalWrite(motor22, LOW);
 
} 

void stopmeR()
{
     Serial.println("                         stop");

     digitalWrite(motor21, LOW);
     digitalWrite(motor22, LOW);
 
} 

void stopmeL()
{
     Serial.println("                         stop");

     digitalWrite(motor11, LOW);
     digitalWrite(motor12, LOW);
} 


void scanD()
{
  for ( byte count = 0; count < 2;count++ )
{
  irSensorDigital[count] = digitalRead(irPins[count]);
  //Serial.print(irSensorDigital[count]);

}
  
  //Serial.print("|");
  //Serial.println(".");
  delay (50);
}
void check(){    
     switch (irSensors) {
     
      /* case(B0000):
       go();
       delay(20);
       break;

       case(B1000):
       motor_left();
       stopmeR();
       delay(20);
       break;

       case(B1100):
       motor_left();
       stopmeR();
       delay(20);
       break;

       case(B0110):
       go();
       delay(20);
       break;

       case(B0011):
       motor_right();
       stopmeL();
       delay(20);
       break;

       case(B0001):
       motor_right();
       stopmeL();
       delay(20);
       break;

       case(B1111):
       stopme();
       delay(20);
       break; */
        

        case(B00):
        go();
        delay(60);
        break;

        case(B01):
        motor_left();
        stopmeR();
        delay(60);
        break;

        case(B10):
        motor_right();
        stopmeL();
        delay(60);
        break;

        case(B11):
        go();
        delay(60);
        break;


     default:
     stopmeL();
     stopmeR();
     delay(60);
     
  }
}
