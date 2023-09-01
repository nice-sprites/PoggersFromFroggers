int sensor[2] = {A1,A2};
int sensorval[2];

int esquerdo1 = 11;
int direito1 = 6;
int esquerdo2 = 10;
int direito2 = 9;

int velocidade;
int velocidade2;



void setup(){
  pinMode(sensor[1], INPUT);
  pinMode(sensor[2], INPUT);

  pinMode(esquerdo1, OUTPUT);
  pinMode(direito1, OUTPUT);
  pinMode(esquerdo2, OUTPUT);
  pinMode(direito2, OUTPUT);

  Serial.begin(9600);
}

void loop(){
  scan();
  check();

}

void scan(){

  for(int i=0; i<2; i++){
  sensorval[i] = analogRead(sensor[i]);
  Serial.print(sensorval[i]);
  Serial.print(" | ");
  
  }
  Serial.println(" ");
      delay(300);

}

void check(){

  if(sensorval[1] > 500 && sensorval[2] < 500){

    esquerda();
  }
  else if(sensorval[1] < 500 && sensorval[2] > 500){

    direita();
  }
  else if(sensorval[1] < 500 && sensorval[2] < 500){

    andarFrente();
  }
  else if(sensorval[1] > 500 && sensorval[2] > 500){

    parar();
  }
  else{

    parar();
    Serial.println("Erro!");
  }
  delay(30);


}

void esquerda(){

  analogWrite(esquerdo1, 100);
  analogWrite(esquerdo2, 0);
  analogWrite(direito1, 0);
  analogWrite(direito2, 0);

}

void direita(){

  analogWrite(esquerdo1, 0);
  analogWrite(esquerdo2, 0);
  analogWrite(direito1, 100);
  analogWrite(direito2, 0);

}

void andarFrente(){

  analogWrite(esquerdo1, 90);
  analogWrite(esquerdo2, 0);
  analogWrite(direito1, 90);
  analogWrite(direito2, 0);

}

void parar(){

  analogWrite(esquerdo1, 0);
  analogWrite(esquerdo2, 0);
  analogWrite(direito1, 0);
  analogWrite(direito2, 0);

}