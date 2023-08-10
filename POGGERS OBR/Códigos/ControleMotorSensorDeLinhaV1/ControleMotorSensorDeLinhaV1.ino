const int irPins[8] = {A0, A2, A3, A4, A5, 4, 5, 6};
int irSensorDigital[8] = {0,0,0,0,0,0,0,0};
int i,j = 0;
int d = 1000;


int irSensors = B00000000;


int motor11 = 11;
int motor12 = 12;
int motor21 = 7;
int motor22 = 8;


void setup () {
  pinMode (motor11, OUTPUT);
  pinMode (motor12, OUTPUT);
  pinMode (motor21, OUTPUT);
  pinMode (motor22, OUTPUT);


    /* Set-up IR sensor pins as input */
  for (int i = 0; i <= 7; i++)
  {pinMode(irPins[i], INPUT);}




}
void loop (){
    scanD();
    check();
}


void motor_left(){
  digitalWrite (motor11, HIGH);
  digitalWrite (motor12, LOW);
}
void motor_right (){
  digitalWrite (motor21, HIGH);
  digitalWrite (motor22, LOW);
}


void go()
{
    Serial.println("                         forward ");
     digitalWrite(motor21, HIGH);
     digitalWrite(motor22, LOW);
     
     digitalWrite(motor11, HIGH);
     digitalWrite(motor12, LOW);
 
}


/* void stopme()
{
     Serial.println("                         stop");
     analogWrite(motorREnable, motorRSpeed);
     digitalWrite(motorRPin1, LOW);
     digitalWrite(motorRPin2, LOW);
     
     analogWrite(motorLEnable, motorLSpeed);
     digitalWrite(motorLPin1, LOW);
     digitalWrite(motorLPin2, LOW);
 
} */


void scanD()
{
  for ( byte count = 0; count < 8;count++ )
{
  bitWrite(irSensors, count, !digitalRead( irPins[count] ));
}
}
void check(){    
     switch (irSensors) {
     
     case B00000000: // on white paper
     motor_right();
     break;
     
     case B10000000: // leftmost sensor on the line
     motor_right();
     break;
     
     case B01000000:
     motor_right();
     break;
     
     case B00100000:
     motor_right();
     break;
     


     case B00010000:
     motor_right();
     break;
     
     case B00001000:
     motor_left();
     break;    


     case B00000100:
     motor_left();
     break;
     
     case B00000010:
     motor_left();
     break;
     
     case B00000001:
     motor_left();
     break;      
     
     case B11000000:
     motor_right();
     break;
     
     case B01100000:
     motor_right();
     break;


     case B00110000:
     motor_right();
     break;
     
     case B00011000:
     go();
     break;          


     case B00001100:
     motor_left();
     break;


     case B00000110:
     motor_left();
     break;  
     
     case B00000011:
     motor_left();
     break;          
       
     case B11100000:
     motor_right();  
     break;
     
     case B01110000:
     motor_right();
     break;
     
     case B00111000:
     motor_right();
     break;
     
     case B00011100:
     motor_left();
     break;  
     
     case B00001110:
     motor_left();
     break;
   
     case B00000111:
     motor_left();
     break;  
         
     case B11110000:
     motor_right();
     break;
     
     case B01111000:
     motor_right();      
     break;
     
     case B00111100:
     go();
     break;  
     
     case B00011110:
     motor_left();
     break;  
     
     case B00001111:
     motor_left();
     break;  
         
     case B11111000:
     motor_right();
     break;
     
     case B01111100:
     motor_right();
     break;
     
     case B00111110:
     motor_left();
     break;
     
     case B00011111:
     motor_left();
     break;
           
     case B11111100:
     motor_right();
     break;
     
     case B01111110:
     go();
     break;
     
     case B00111111:
     motor_left();
     break;
     
   
     case B11111110:
     motor_right();
     break;
     
     case B01111111:
     motor_left();
     break;  
     
     case B11111111:
      go();        
     
     break;  
   
 
     default:
     
     Serial.print("Unhandled case: ");  
     
  }
}
