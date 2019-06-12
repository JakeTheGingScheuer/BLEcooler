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

int main(void)
{
  UNITY_BEGIN();
    RUN_TEST(whenGetInputTypeReturnsCharacterRelated);
    RUN_TEST(whenButtonNumberIs5IsUpReturnsTrue);
  return UNITY_END();
}
