int esquerdo1 = 11;
int direito1 = 6;
int esquerdo2 = 10;
int direito2 = 9;

void setup() {
  // put your setup code here, to run once:
  pinMode(esquerdo1, OUTPUT);
  pinMode(direito1, OUTPUT);
  pinMode(esquerdo2, OUTPUT);
  pinMode(direito2, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  analogWrite(esquerdo1, 150);
  analogWrite(esquerdo2, 0);
  analogWrite(direito1, 150);
  analogWrite(direito2, 0);
  delay(50);

}
