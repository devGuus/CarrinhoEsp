#include <ESP8266WiFi.h>

const char* ssid = "CarrinhoESP";
const char* password = "12345678";

#define IN1 D1
#define IN2 D2
#define IN3 D3
#define IN4 D4

WiFiServer server(80);

void setup() {
  Serial.begin(115200);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  WiFi.softAP(ssid, password);
  server.begin();

  Serial.println("Carrinho pronto!");
  Serial.print("Conecte-se à rede WiFi: ");
  Serial.println(ssid);
}

void loop() {
  WiFiClient client = server.available();
  if (!client) return;

  String request = client.readStringUntil('\r');
  client.flush();

  if (request.indexOf("/F") != -1) forward();
  else if (request.indexOf("/B") != -1) backward();
  else if (request.indexOf("/L") != -1) left();
  else if (request.indexOf("/R") != -1) right();
  else if (request.indexOf("/S") != -1) stopMotors();

  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html");
  client.println("");
  client.println("<html><body><h1>Carrinho ESP8266</h1>");
  client.println("<a href=\"/F\">Frente</a><br>");
  client.println("<a href=\"/B\">Ré</a><br>");
  client.println("<a href=\"/L\">Esquerda</a><br>");
  client.println("<a href=\"/R\">Direita</a><br>");
  client.println("<a href=\"/S\">Parar</a><br>");
  client.println("</body></html>");
  delay(10);
}

void forward(){digitalWrite(IN1,HIGH);digitalWrite(IN2,LOW);digitalWrite(IN3,HIGH);digitalWrite(IN4,LOW);}
void backward(){digitalWrite(IN1,LOW);digitalWrite(IN2,HIGH);digitalWrite(IN3,LOW);digitalWrite(IN4,HIGH);}
void left(){digitalWrite(IN1,LOW);digitalWrite(IN2,HIGH);digitalWrite(IN3,HIGH);digitalWrite(IN4,LOW);}
void right(){digitalWrite(IN1,HIGH);digitalWrite(IN2,LOW);digitalWrite(IN3,LOW);digitalWrite(IN4,HIGH);}
void stopMotors(){digitalWrite(IN1,LOW);digitalWrite(IN2,LOW);digitalWrite(IN3,LOW);digitalWrite(IN4,LOW);}
