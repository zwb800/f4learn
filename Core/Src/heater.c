    #include "heater.h"
    #include "tim.h"
    uint8_t heaterResetCounter = 0;

    void HearterSetup(){
        HAL_TIM_PWM_Start(&htim4,TIM_CHANNEL_4);
    }

    void SetWaterHearterPower(uint8_t pwm)
    {
        uint32_t p = 2000 * pwm / 255;
        __HAL_TIM_SetCompare(&htim4, TIM_CHANNEL_4, p);
    }