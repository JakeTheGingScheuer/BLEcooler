#include "../../../unity/unity.h"
#include "../MotorControlls.h"


void whenButtonPressIsPassedAPacketBufferItStoresValuesInStruct()
{
  unsigned char fakePacketBuffer[] = {'!','B','5','1'};
  struct buttonData button = buttonPressed(fakePacketBuffer);
  TEST_ASSERT_TRUE(button.type == 'B');
  TEST_ASSERT_EQUAL(button.number, 5);
  TEST_ASSERT_TRUE(button.pressed);
}

void whenButton2IsPressedFowardButtonIsTrue()
{
  unsigned char fakePacketBuffer[] = {'!','B','2','1'};
  struct buttonData button = buttonPressed(fakePacketBuffer);
  TEST_ASSERT_TRUE(forwardButton(button));
}

void whenButton4IsPressedReverseButtonIsTrue()
{
  unsigned char fakePacketBuffer[] = {'!','B','4','1'};
  struct buttonData button = buttonPressed(fakePacketBuffer);
  TEST_ASSERT_TRUE(reverseButton(button));
}

void whenButton7IsPressedLeftButtonIsTrue()
{
  unsigned char fakePacketBuffer[] = {'!','B','7','1'};
  struct buttonData button = buttonPressed(fakePacketBuffer);
  TEST_ASSERT_TRUE(leftButton(button));
}

void whenButton8IsPressedRightButtonIsTrue()
{
  unsigned char fakePacketBuffer[] = {'!','B','8','1'};
  struct buttonData button = buttonPressed(fakePacketBuffer);
  TEST_ASSERT_TRUE(rightButton(button));
}

int main(void)
{
  UNITY_BEGIN();
    RUN_TEST(whenButtonPressIsPassedAPacketBufferItStoresValuesInStruct);
    RUN_TEST(whenButton2IsPressedFowardButtonIsTrue);
    RUN_TEST(whenButton4IsPressedReverseButtonIsTrue);
    RUN_TEST(whenButton7IsPressedLeftButtonIsTrue);
    RUN_TEST(whenButton8IsPressedRightButtonIsTrue);

  return UNITY_END();
}
