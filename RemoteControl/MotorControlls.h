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
