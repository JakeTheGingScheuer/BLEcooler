#include "../../unity/unity.h"
#include "./MotorControlls.h"

unsigned char fakePacketBuffer[] = {'!','B','5','1'};

void whenGetInputTypeReturnsCharacterRelated()
{
  TEST_ASSERT_TRUE(isInputAButton(fakePacketBuffer));
}

void whenButtonNumberIs5IsUpReturnsTrue()
{
  unsigned int buttnum = fakePacketBuffer[2] - '0';
  TEST_ASSERT_TRUE(isUp(buttnum));
}

void whenButtonIsPressedReturnsTrue()
{
  int pressed = fakePacketBuffer[3];
  TEST_ASSERT_TRUE(isPressed(pressed));
}

int main(void)
{
  UNITY_BEGIN();
    RUN_TEST(whenGetInputTypeReturnsCharacterRelated);
    RUN_TEST(whenButtonNumberIs5IsUpReturnsTrue);
    RUN_TEST(whenButtonIsPressedReturnsTrue);
  return UNITY_END();
}
