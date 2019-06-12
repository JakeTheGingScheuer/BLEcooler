#include <string.h>

int isInputAButton(unsigned char packetbuffer[])
{
  if (packetbuffer[1] == 'B')
  {
    return 1;
  }
  else return 0;
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
