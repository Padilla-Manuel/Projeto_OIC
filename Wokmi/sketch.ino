#include <WiFi.h>
#include <PubSubClient.h>

// WiFi
const char* ssid = "Wokwi-GUEST";
const char* password = "";

// MQTT
const char* mqtt_server = "broker.hivemq.com";

WiFiClient espClient;
PubSubClient client(espClient);

// LED
const int LED_PIN = 2;

// Controle
String zonaAnterior = "";
int valorAnterior = 0;
unsigned long ultimoMovimento = 0;

// ===== FUNÇÕES =====

void conectarWiFi() {
  Serial.print("Conectando WiFi...");
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nWiFi conectado!");
}

void conectarMQTT() {
  while (!client.connected()) {
    Serial.print("Conectando MQTT...");

    if (client.connect("esp32-veiculo-felipe")) {
      Serial.println("conectado!");
    } else {
      Serial.print("erro: ");
      Serial.println(client.state());
      delay(2000);
    }
  }
}

// ===== SETUP =====

void setup() {
  Serial.begin(115200);

  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);

  conectarWiFi();
  client.setServer(mqtt_server, 1883);
}

// ===== LOOP =====

void loop() {
  if (!client.connected()) {
    conectarMQTT();
  }

  client.loop();

  int valor = analogRead(34);
  String zona;

  if (valor < 1000) {
    zona = "Portaria 1";
  } else if (valor < 2000) {
    zona = "Portaria 2";
  } else if (valor < 3000) {
    zona = "Portaria 3";
  } else {
    zona = "Portaria 4";
  }

  int diferenca = abs(valor - valorAnterior);
  String status;

  if (zonaAnterior == "") {
    status = "INICIANDO";
  } else {
    if (diferenca > 80) {
      ultimoMovimento = millis();
    }

    if (millis() - ultimoMovimento < 3000) {
      status = "EM MOVIMENTO";
    } else {
      status = "PARADO";
    }
  }

   // ===== CONTROLE DO LED =====
  if (status == "PARADO") {
    digitalWrite(LED_PIN, HIGH);
  } else {
    digitalWrite(LED_PIN, LOW);
  }

  // ===== CRIA JSON =====
  String payload = "{";
  payload += "\"zona\":\"" + zona + "\",";
  payload += "\"status\":\"" + status + "\",";
  payload += "\"valor\":" + String(valor);
  payload += "}";

  // ===== ENVIA PARA MQTT =====
  client.publish("smartcampus/veiculo", payload.c_str());

  // ===== DEBUG NO SERIAL =====
  Serial.print("Valor: ");
  Serial.print(valor);
  Serial.print(" | Diferenca: ");
  Serial.print(diferenca);
  Serial.print(" | Zona: ");
  Serial.print(zona);
  Serial.print(" | Status: ");
  Serial.print(status);
  Serial.print(" | LED: ");
  Serial.println(status == "EM MOVIMENTO" ? "ACESO" : "APAGADO");

  Serial.print("Enviado MQTT: ");
  Serial.println(payload);

  zonaAnterior = zona;
  valorAnterior = valor;

  delay(2000);
}