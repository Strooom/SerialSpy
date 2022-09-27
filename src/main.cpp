#include "msgbuffer.h"
#include "Arduino.h"

msgBuffer buffer2;
msgBuffer buffer3;

void setup()
{
  Serial.begin(115200);
  Serial.flush();
  delay(1000);
  Serial.println("\n\nSerialSpy started\n\n");
  Serial2.begin(115200);
  Serial3.begin(115200);
}

void loop()
{
  while (Serial2.available() > 0)
  {
    char lastCharacter;
    lastCharacter = Serial2.read();
    if (lastCharacter == '\n')
    {
      buffer2.buffer[buffer2.level] = 0x00;
      Serial.printf("MCU -->> PC : %s", buffer2.buffer);
      buffer2.level = 0;
    }
    else
    {
      buffer2.buffer[buffer2.level] = lastCharacter;
      buffer2.level++;
    }
  }

  while (Serial3.available() > 0)
  {
    char lastCharacter;
    lastCharacter = Serial3.read();
    if (lastCharacter == '\n')
    {
      buffer3.buffer[buffer3.level] = 0x00;
      Serial.printf("  MCU <<-- PC : %s", buffer3.buffer);
      buffer3.level = 0;
    }
    else
    {
      buffer3.buffer[buffer3.level] = lastCharacter;
      buffer3.level++;
    }
  }
}
