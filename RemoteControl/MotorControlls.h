#include <string.h>

typedef struct buttonData
{
  char type;
  int number;
  int pressed;
} buttonData;

struct buttonData buttonPressed(unsigned char packetbuffer[])
{
  struct buttonData button;
  button.type = packetbuffer[1];
  button.number = packetbuffer[2]-'0';
  button.pressed = packetbuffer[3]-'0';
  return button;
}

int isUpButton(struct buttonData button)
{
  if((button.type == 'B')&&(button.number == 5))
  {
    return 1;
  } else return 0;
}



//   uint8_t buttnum = packetbuffer[2] - '0';
//   boolean pressed = packetbuffer[3] - '0';
//   if(buttnum == 5) {
//     if (pressed) {
//       digitalWrite(IN1, HIGH);
//       digitalWrite(IN2, LOW);
//       analogWrite(ENA, 200);
//       digitalWrite(IN3, HIGH);
//       digitalWrite(IN4, LOW);
//       analogWrite(ENB, 200);
//     } else {
//       digitalWrite(IN1, LOW);
//       digitalWrite(IN2, LOW);
//       digitalWrite(IN3, LOW);
//       digitalWrite(IN4, LOW);
//     }
//   }
// }
