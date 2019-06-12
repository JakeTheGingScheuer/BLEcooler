#include "../../unity/unity.h"
#include "./MotorControlls.h"

unsigned char fakePacketBuffer[] = {'!','B','5','1'};

void whenGetInputTypeReturnsCharacterRelated()
{
  TEST_ASSERT_TRUE(isInputAButton(fakePacketBuffer));
}

int main(void)
{
  UNITY_BEGIN();
    RUN_TEST(whenGetInputTypeReturnsCharacterRelated);
  return UNITY_END();
}
