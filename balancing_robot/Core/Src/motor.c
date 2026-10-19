#include "motor.h"
#include "main.h"

#define MOTOR_PWM_MAX 2879

extern TIM_HandleTypeDef htim8;

static int PWM_Limit(int pwm)
{
    if (pwm > MOTOR_PWM_MAX)
        return MOTOR_PWM_MAX;
    else if (pwm < -MOTOR_PWM_MAX)
        return -MOTOR_PWM_MAX;
    else
        return pwm;
}

void Motor_Set(int left, int right)
{
    left = PWM_Limit(left);
    right = PWM_Limit(right);

    if (left > 0) {
        __HAL_TIM_SET_COMPARE(&htim8, TIM_CHANNEL_1, 0);
        __HAL_TIM_SET_COMPARE(&htim8, TIM_CHANNEL_2, left);
    }
    else if (left < 0) {
        __HAL_TIM_SET_COMPARE(&htim8, TIM_CHANNEL_1, -left);
        __HAL_TIM_SET_COMPARE(&htim8, TIM_CHANNEL_2, 0);
    }
    else {
        __HAL_TIM_SET_COMPARE(&htim8, TIM_CHANNEL_1, 0);
        __HAL_TIM_SET_COMPARE(&htim8, TIM_CHANNEL_2, 0);
    }

    if (right > 0) {
        __HAL_TIM_SET_COMPARE(&htim8, TIM_CHANNEL_3, right);
        __HAL_TIM_SET_COMPARE(&htim8, TIM_CHANNEL_4, 0);
    }
    else if (right < 0) {
        __HAL_TIM_SET_COMPARE(&htim8, TIM_CHANNEL_3, 0);
        __HAL_TIM_SET_COMPARE(&htim8, TIM_CHANNEL_4, -right);
    }
    else {
        __HAL_TIM_SET_COMPARE(&htim8, TIM_CHANNEL_3, 0);
        __HAL_TIM_SET_COMPARE(&htim8, TIM_CHANNEL_4, 0);
    }
}
