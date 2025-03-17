#include "arduino.h"


#include "gpio.h"

#include <stdio.h>
#include <stdlib.h>
#include <usbd_cdc_if.h>
#include "tim.h"
#include "stm32f4xx_hal_tim.h"

#define ADC_MAX 4095.0 //12bit adc
#define ADC_MAX_VOLTAGE 3.3
#define R1 20100
#define R2 1990
#define MODULE_TIMES (R1+R2)/R2

#define CELL_MAX 13.8
#define CELL_MIN 11.1
#define CELL 2
#define TARGET_CAPACITY 90
#define P 10;



extern "C"{

    int co2;
    int tvoc = -1;
    float temp,humid;
    float voltage;
    int capacity;
    int16_t pwm;

    const float BATTERY_MAX = CELL_MAX * CELL;
    const float BATTERY_MIN = CELL_MIN * CELL;
    const float BATTERY_RANGE = BATTERY_MAX - BATTERY_MIN;

    uint8_t rxBuf[1];
    uint8_t relayDelay;
    void SetWaterHearterPower(uint32_t pwm)
    {
        __HAL_TIM_SetCompare(&htim4, TIM_CHANNEL_4, pwm);
    }

    void setup(){
       
        SetWaterHearterPower(0);
    }

  

    void loop(){
        
        // CDC_Transmit_FS((uint8_t*)"hello\n",6);
        HAL_GPIO_TogglePin(LED_GPIO_Port,LED_Pin);
        HAL_Delay(1000);
    } 
    void Read()
    {
        HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin, GPIO_PIN_RESET);


        // int v1 = tvoc / 1000;
        // int v2 = (tvoc - v1 * 1000) / 10;

        // int te1 = temp;
        // int te2 = abs(temp - te1) * 100;

        // int h1 = humid;
        // int h2 = (humid - h1) * 100;

        // int vo1 = voltage;
        // int vo2 = (voltage - vo1) *100;

        // capacity = (voltage - BATTERY_MIN) * 100 / BATTERY_RANGE;

        pwm += (capacity - TARGET_CAPACITY) * P;
        pwm = pwm > 20000 ? 20000:pwm;
        pwm = pwm < 0 ? 0:pwm;

        SetWaterHearterPower(pwm);

        // char buf[100];
        // auto len = sprintf(buf, 
        //     "CO2:%d ppm TVOC:%d.%d ppm T:%d.%02d H:%d.%02d%% B:%d.%02dv %d%% WH:%d.%02d%% %s:%s:%s:%s \r\n",
        //     // "B:%d.%02dv %d%% WaterHeater:%d.%02d%%\r\n",
          
        //                 capacity,
        //                 pwm / 100,pwm - (pwm / 100 * 100)
        //                    );

        // HAL_UART_Transmit_IT(&huart3, (uint8_t *)buf, len);
        HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin, GPIO_PIN_SET);
        
    }

}