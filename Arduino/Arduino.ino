//Definindo os pinos
#define echoPin A1 //Pino ECHO do sensor no pino analógica A1
#define trigPin A0 //Pino TRIG do sensor no pino analógica A0
#define LEDR 13 // Pino 13 digital correspondente ao led vermelho
#define LEDA 12 // Pino 12 digital correspondente ao led amarelo
#define LEDV 11 // Pino 11 digital correspondente ao led verde
#define ALARME 2 // Pino 2 digital correspondente ao buzzer

//variáveis  para o sensor ultrassonico
long duracao;
long HR_dist = 0;
int minimumRange = 5; //tempo de resposta do sensor
int maximumRange = 200;
int output = 0;
int sensorValue = 0;

// Inicialização do Arduino
void setup() {
  Serial.begin(9600); // inicializa a comunicação serial para mostrar dados     
  pinMode(trigPin, OUTPUT); //define o pino TRIG como saída
  pinMode(echoPin, INPUT);  //define o pino ECHO como entrada
  pinMode(LEDR,OUTPUT);     //define o LEDR como saida
  pinMode(LEDV,OUTPUT);     //define o LEDV como saida 
  pinMode(LEDA,OUTPUT);
  pinMode(ALARME,OUTPUT);   //define o buzzer como saida
  
}

void loop() {
  sensorValue = analogRead(A2);
  output = map(sensorValue, 0, 1023, 0, 255); 
  Serial.println(output);
  delay(100);
  if(output <= 85){
    digitalWrite(LEDV,HIGH);    //Liga o led verde
    digitalWrite(LEDA,LOW);     //Desliga o led amarelo
    digitalWrite(LEDR,LOW);  //Desliga o led vermelho
    
  }else if(output >85 && output <= 128){
    digitalWrite(LEDV,LOW);    //Desliga o led verde
    digitalWrite(LEDA,HIGH);     //Liga o led amarelo
    digitalWrite(LEDR,LOW);  //Desliga o led vermelho
  }else{
    digitalWrite(LEDV,LOW);    //Desliga o led verde
    digitalWrite(LEDA,LOW);     //Desliga o led amarelo
    digitalWrite(LEDR,HIGH);  //Liga o led vermelho
  }
  if( Distancia() < 30){ //Verifica se existe algum objeto a menos de 30 centimetors do sensor
    digitalWrite(ALARME,HIGH);  //Liga o buzzer
  }else{
    digitalWrite(ALARME,LOW); //Desliga o buzzer
  }
}

// Função para calcular a distância do objeto  
int Distancia() {
  digitalWrite(trigPin, LOW); //não envia som (limpeza de ruidos)
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH); //envia som
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW); //não envia o som e espera o retorno do som enviado
  duracao = pulseIn(echoPin, HIGH); //Captura a duração em tempo do retorno do som.
  HR_dist = duracao / 56; //Calcula a distância
  //Serial.println(HR_dist);
  return HR_dist;//Exibe na Serial a distância
}
