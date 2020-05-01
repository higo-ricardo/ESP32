/******************************************************************************************
   COPYRIGHT (c) 2019  Higo Melo
   *****************************************************************************************/
#include <WiFi.h>

//-------- Configurações de Wi-fi-----------
const char * ssid = "";
const char * password = "";
int pinLED = 2;

void setup()
{
  Serial.begin(115200);
  pinMode(pinLED, OUTPUT);
  digitalWrite(pinLED, 1);


  //---- Tenta conectar a rede Wi-Fi ----
  WiFi.begin(ssid, password);
  Serial.printf("Conectando em %s ", ssid);

  //---- Enquanto estiver conectando ----
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.println(".");
    delay(500);
    digitalWrite(pinLED, !digitalRead(pinLED));
  }

  Serial.printf("Esp32 conectado em %s", ssid);
  Serial.println();

}


void loop()
{
  if (WiFi.status() == WL_CONNECTED)
  {
    Serial.print("IP Adress: ");
    Serial.println(WiFi.localIP());
    Serial.println();
    digitalWrite(pinLED, 1);
    delay(5000);
    digitalWrite(pinLED, 0);
  }

  else
  {
    Serial.println("Verifique a conexão com a Internet!");
  }
  delay(5000);
}
