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

int forwardButton(struct buttonData button)
{
  if((button.type == 'B')&&(button.number == 2))
  {
    return 1;
  } else return 0;
}

int reverseButton(struct buttonData button)
{
  if((button.type == 'B')&&(button.number == 4))
  {
    return 1;
  } else return 0;
}

int leftButton(struct buttonData button)
{
  if((button.type == 'B')&&(button.number == 7))
  {
    return 1;
  } else return 0;
}

int rightButton(struct buttonData button)
{
  if((button.type == 'B')&&(button.number == 8))
  {
    return 1;
  } else return 0;
}

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
