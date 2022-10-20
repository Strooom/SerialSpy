#include "Arduino.h"

void setup() {
    Serial.begin(115200);
    Serial.flush();
    delay(1000);
    Serial.println("\n\nSerialSpy started\n\n");
    Serial2.begin(115200);
    Serial3.begin(115200);
}

void loop() {
    while (Serial3.available() > 0) {
        char lastCharacter;
        lastCharacter = Serial3.read();
        switch (lastCharacter) {
            case '?':
            case '!':
            case '~':
                Serial.println(lastCharacter);
                break;
            case 0x18:
                Serial.printf("0x%02x\n", lastCharacter);
                break;
            case 0x0A:
            case 0x0D:
                Serial.println("");
                break;
            default:
                if ((lastCharacter <= 32) || (lastCharacter >= 127)) {
                    Serial.printf("0x%02x ", lastCharacter);
                } else {
                    Serial.print(lastCharacter);
                }
                break;
        }
    }

    while (Serial2.available() > 0) {
        char lastCharacter;
        lastCharacter = Serial2.read();
        switch (lastCharacter) {
            case 0x0A:
                Serial.println("LF");
                break;
            case 0x0D:
                Serial.println("CR");
                break;
            default:
                if ((lastCharacter <= 32) || (lastCharacter >= 127)) {
                    Serial.printf("0x%02x ", lastCharacter);
                } else {
                    Serial.print(lastCharacter);
                }
                break;
        }
    }
}
