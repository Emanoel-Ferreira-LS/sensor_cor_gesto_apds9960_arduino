#include <Wire.h>
#include <SparkFun_APDS9960.h>

// Variáveis Globais
SparkFun_APDS9960 apds = SparkFun_APDS9960(); // Cria uma instância do sensor APDS-9960
uint16_t ambient_light = 0; // Variável para armazenar a luz ambiente
uint16_t red_light = 0;     // Variável para armazenar a luz vermelha
uint16_t green_light = 0;   // Variável para armazenar a luz verde
uint16_t blue_light = 0;    // Variável para armazenar a luz azul

void setup() {
    
  // Inicializa a porta serial
  Serial.begin(9600);
  Serial.println();
  Serial.println(F("--------------------------------"));
  Serial.println(F("APDS-9960 - Sensor de Cores"));
  Serial.println(F("--------------------------------"));
  
  // Inicializa o APDS-9960 (configuração I2C e valores iniciais)
  if ( apds.init() ) {
    Serial.println(F("Inicialização do APDS-9960 completa"));
  } else {
    Serial.println(F("Algo deu errado durante a inicialização do APDS-9960!"));
  }
  
  // Inicia o sensor de luz APDS-9960 (sem interrupções)
  if ( apds.enableLightSensor(false) ) {
    Serial.println(F("O sensor de luz está funcionando agora"));
  } else {
    Serial.println(F("Algo deu errado durante a inicialização do sensor de luz!"));
  }
  
  // Aguarda a inicialização e calibração serem concluídas
  delay(500);
}

void loop() {
  
  // Lê os níveis de luz (ambiente, vermelha, verde, azul)
  if (  !apds.readAmbientLight(ambient_light) ||
        !apds.readRedLight(red_light) ||
        !apds.readGreenLight(green_light) ||
        !apds.readBlueLight(blue_light) ) {
    Serial.println("Erro ao ler os valores de luz");
  } else {
    Serial.print("Ambiente: ");
    Serial.print(ambient_light);
    Serial.print(" Vermelha: ");
    Serial.print(red_light);
    Serial.print(" Verde: ");
    Serial.print(green_light);
    Serial.print(" Azul: ");
    Serial.println(blue_light);
  }
  
  // Aguarda 1 segundo antes da próxima leitura
  delay(1000);
}


/*
 No código, não há definição direta dos pinos usados para a comunicação I2C entre o Arduino e o sensor 
 APDS-9960. Isso ocorre porque a biblioteca SparkFun_APDS9960 utiliza os pinos padrão do Arduino para comunicação I2C,
 que são:

Pino SDA (Serial Data): No Arduino Uno, é o pino A4.
Pino SCL (Serial Clock): No Arduino Uno, é o pino A5.
Essa configuração padrão é definida na biblioteca Wire.h, que é incluída no código. Portanto, não é necessário 
especificar explicitamente os pinos de comunicação I2C no código fornecido.
 */
