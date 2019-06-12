#include "../../unity/unity.h"
#include "./MotorControlls.h"

unsigned char fakePacketBuffer[] = {'!','B','5','1'};

void whenButtonPressIsPassedAPacketBufferItStoresValuesInStruct()
{
  struct buttonData button = buttonPressed(fakePacketBuffer);
  TEST_ASSERT_TRUE(button.type == 'B');
  TEST_ASSERT_EQUAL(button.number, 5);
  TEST_ASSERT_TRUE(button.pressed);
}

void whenIsUpButtonIsCalledAndIsReturnTrue()
{
  struct buttonData button = buttonPressed(fakePacketBuffer);
  TEST_ASSERT_TRUE(isUpButton(button));
}

int main(void)
{
  UNITY_BEGIN();
    RUN_TEST(whenButtonPressIsPassedAPacketBufferItStoresValuesInStruct);
    RUN_TEST(whenIsUpButtonIsCalledAndIsReturnTrue);
  return UNITY_END();
}
