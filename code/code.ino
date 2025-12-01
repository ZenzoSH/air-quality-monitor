// Air Quality Monitor - IoT Project
// Group 3 - CSE(AI) D

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <DHT.h>

// ===== WiFi & Blynk Credentials =====
char auth[] = "YOUR_BLYNK_AUTH_TOKEN";  // Replace with your token
char ssid[] = "YOUR_WIFI_SSID";          // Replace with your WiFi name
char pass[] = "YOUR_WIFI_PASSWORD";      // Replace with your WiFi password

// ===== Sensor Setup =====
#define DHTPIN D4        // DHT11 connected to D4
#define DHTTYPE DHT11    
DHT dht(DHTPIN, DHTTYPE);

#define MQ135PIN A0      // MQ135 connected to A0

// ===== Timer =====
BlynkTimer timer;

void setup() {
  Serial.begin(115200);
  Serial.println("Air Quality Monitor Starting...");
  
  // Initialize DHT sensor
  dht.begin();
  
  // Connect to Blynk
  Blynk.begin(auth, ssid, pass);
  
  // Set timer to send data every 2 seconds
  timer.setInterval(2000L, sendSensorData);
  
  Serial.println("System Ready!");
}

void sendSensorData() {
  // Read sensors
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();
  int airQuality = analogRead(MQ135PIN);
  
  // Check if readings are valid
  if (isnan(humidity) || isnan(temperature)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
  
  // Send to Blynk
  Blynk.virtualWrite(V1, temperature);
  Blynk.virtualWrite(V2, humidity);
  Blynk.virtualWrite(V3, airQuality);
  
  // Print to Serial Monitor
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.print("°C | Humidity: ");
  Serial.print(humidity);
  Serial.print("% | Air Quality: ");
  Serial.println(airQuality);
}

void loop() {
  Blynk.run();
  timer.run();
}