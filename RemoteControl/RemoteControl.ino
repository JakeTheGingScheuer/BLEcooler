#include <SPI.h>
#include "Adafruit_BLE_UART.h"
#include "UARTServiceConfig.h"

//motor one
#define ENA 3
#define IN1 4
#define IN2 5
// motor two
#define ENB 6
#define IN3 7
#define IN4 8

#define ADAFRUITBLE_REQ 10
#define ADAFRUITBLE_RDY 2
#define ADAFRUITBLE_RST 9

#define BLE_READPACKET_TIMEOUT 50

Adafruit_BLE_UART UARTService = Adafruit_BLE_UART(ADAFRUITBLE_REQ, ADAFRUITBLE_RDY, ADAFRUITBLE_RST);
aci_evt_opcode_t lastBTLEstatus, BTLEstatus;
uint8_t readPacket(Adafruit_BLE_UART *ble, uint16_t timeout);
extern uint8_t packetbuffer[];

int buttonPressed()
{
  if((packetbuffer[1] == 'B') && (packetbuffer[3])){
    return 1;
  }else return 0;
}

void hault() 
{
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

void goForward()
{
  analogWrite(ENA, 255);
  analogWrite(ENB, 255);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void backUp()
{
  analogWrite(ENA, 255);
  analogWrite(ENB, 255);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void goLeft()
{
  analogWrite(ENA, 80);
  analogWrite(ENB, 255);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void goRight()
{
  analogWrite(ENA, 255);
  analogWrite(ENB, 80);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  
}
void setup()
{
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENB, OUTPUT);

  while (!Serial) delay(1);
  Serial.begin(9600);

  bool serviceOn = UARTService.begin();

  UARTService.setDeviceName("Kühler");
}

void loop()
{
  
  UARTService.pollACI();
  BTLEstatus = UARTService.getState();
  uint8_t packetLength = readPacket(&UARTService, BLE_READPACKET_TIMEOUT);
  if (packetLength == 0) return;

  uint8_t buttNumb = packetbuffer[2]-'0';
  boolean pressed = packetbuffer[3] - '0';

  if(pressed) {
    switch (buttNumb) {
      case 2:
        goForward();
        break;
      case 4:
        backUp();
        break;
      case 7:
        goRight();
        break;
      case 8:
        goLeft();
        break;
    }
  } else hault();
}
