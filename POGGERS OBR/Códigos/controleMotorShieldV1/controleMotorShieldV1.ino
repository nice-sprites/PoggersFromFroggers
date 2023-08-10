#include <AFMotor.h>

AF_DCMotor motor1(1);
AF_DCMotor motor2(2);

void setup() {
  // put your setup code here, to run once:

  motor1.setSpeed(0); // 0 a 255
  motor2.setSpeed(0);

}

void loop() {
  // put your main code here, to run repeatedly:
  motor1.setSpeed(120);
  motor1.run(FORWARD);

  motor2.setSpeed(120);
  motor2.run(FORWARD);

}
