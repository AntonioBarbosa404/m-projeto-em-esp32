#include <Arduino.h>
#include <WiFi.h>

const char* ssid = "SEU_SSID";
const char* password = "SUA_SENHA";

const int botaoPin = 2;
const int ledPin = 13;

void setup() {
  Serial.begin(115200);
  pinMode(botaoPin, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);
  
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi conectado!");
}

void loop() {
  static unsigned long tempoAnterior = 0;
  static bool botaoPressionado = false;
  
  unsigned long tempoAtual = millis();
  
  if (tempoAtual - tempoAnterior >= 3000) {
    tempoAnterior = tempoAtual;
    
    int estadoBotao = digitalRead(botaoPin);
    if (estadoBotao == LOW) {
      botaoPressionado = true;
    } else {
      botaoPressionado = false;
    }
    
    if (botaoPressionado) {
      digitalWrite(ledPin, HIGH);
      // Envia dados para o arquivo PHP
      enviarDadosPHP("pressionado");
    } else {
      digitalWrite(ledPin, LOW);
      // Envia dados para o arquivo PHP
      enviarDadosPHP("nao pressionado");
    }
  }
}

void enviarDadosPHP(const char* estado) {
  // Implemente a função para enviar dados para o arquivo PHP
  // Utilize WiFiClient para comunicação HTTP
  // Envie o estado do botão como parâmetro
}
