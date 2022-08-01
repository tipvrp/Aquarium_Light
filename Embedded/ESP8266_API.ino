#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <ArduinoJson.h>

ESP8266WebServer server(1810);

const char *ssid = "true_home2G_4C8";
const char *password = "has397134";

void setup()
{
  Serial.begin(115200);
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  // Print local IP address and start web server
  Serial.println("");
  Serial.println("WiFi connected.");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  server.on("/body",HTTP_POST,
            handleBody); // Associate the handler function to the path
  server.begin();        // Start the server
  Serial.println("Server listening");
}

void loop()
{
  server.handleClient(); // Handling of incoming requests
}

void handleBody()
{
  if (server.hasArg("plain") == false)
  {
    server.send(200, "application/json; charset=utf-8", "Body not received");
    return;
  }
  StaticJsonDocument<200> doc;
  String json = server.arg("plain");
  DeserializationError error = deserializeJson(doc, json);

  // Test if parsing succeeds.
  if (error)
  {
    Serial.print(F("deserializeJson() failed: "));
    Serial.println(error.f_str());
    return;
  }
  int stat = doc["status"];
  const char *data = doc["data"];
  Serial.println(server.arg("plain"));
  Serial.println(stat);
  Serial.println(data);
  server.send(200, "application/json; charset=utf-8", "Ok");
}