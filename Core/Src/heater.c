    #include "heater.h"
    #include "tim.h"

    void SetWaterHearterPower(uint8_t pwm)
    {
        uint32_t p = 20000 * pwm / 255;
        __HAL_TIM_SetCompare(&htim4, TIM_CHANNEL_4, p);
    }