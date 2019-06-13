#include <SPI.h>
#include "MotorControlls.h"
#include "Adafruit_BLE_UART.h"
#include "UARTServiceConfig.h"

// motor one
#define ENA 3
#define IN1 0
#define IN2 1
// motor two
#define ENB 6
#define IN3 4
#define IN4 5

#define ADAFRUITBLE_REQ 8
#define ADAFRUITBLE_RST 9
#define ADAFRUITBLE_RDY 2

#define BLE_READPACKET_TIMEOUT 50

Adafruit_BLE_UART UARTService = Adafruit_BLE_UART(ADAFRUITBLE_REQ, ADAFRUITBLE_RDY, ADAFRUITBLE_RST);
aci_evt_opcode_t lastBTLEstatus, BTLEstatus;
uint8_t readPacket(Adafruit_BLE_UART *ble, uint16_t timeout);
extern uint8_t packetbuffer[];

void forward()
{
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, 240);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENB, 240);
}

void stop()
{
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

void reverse()
{
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  analogWrite(ENA, 200);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENB, 200);
}

void setup()
{
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);

  while (!Serial) delay(1);
  Serial.begin(9600);

  bool serviceOn = UARTService.begin();

  UARTService.setDeviceName("COOLER");
}

void loop()
{
  UARTService.pollACI();
  BTLEstatus = UARTService.getState();
  uint8_t packetLength = readPacket(&UARTService, BLE_READPACKET_TIMEOUT);
  if (packetLength == 0) return;

  struct buttonData buttonData = buttonPressed(packetbuffer);

  if(forwardButton(buttonData)) {
    if (buttonData.pressed) {
      forward();
    } else {
      stop();
    }
  }
  if(rightButton(buttonData))
  {
    analogWrite(ENB, 0);
  }
  if(leftButton(buttonData))
  {
    analogWrite(ENA, 0);
  }
  if(reverseButton(buttonData)) {
    if (buttonData.pressed) {
      reverse();
    } else {
      stop();
    }
  }
}
