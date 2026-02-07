#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_VEML7700.h>

#ifndef SDA_PIN
#define SDA_PIN 8
#endif

#ifndef SCL_PIN
#define SCL_PIN 9
#endif

Adafruit_SSD1306 display(128, 64, &Wire, -1);
Adafruit_VEML7700 veml;

void setup() {
    Serial.begin(115200);
    delay(200);

    // I2C init
    Wire.begin(SDA_PIN, SCL_PIN);

    // OLED init
    if (!display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR)) {
        Serial.println("Unable to initialize SSD1306");
        while (1) delay(100);
    }
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);

    // VEML7700 init
    if (!veml.begin()) {
        Serial.println("VEML7700 not found");
        while (1) delay(100);
    }

    // Optional tuning
    veml.setGain(VEML7700_GAIN_1);
    veml.setIntegrationTime(VEML7700_IT_100MS);
}

void loop() {
    float luxRaw = veml.readLux();
    int lux = (int)luxRaw;   // integer value

    display.clearDisplay();

    // Top label: "LUX" (small)
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(0, 0);
    display.println("LUX");

    // Big integer value (size 3)
    display.setTextSize(3);
    display.setCursor(0, 16);   // move down a bit from the top
    display.println(lux);

    display.display();
    delay(300);
}
