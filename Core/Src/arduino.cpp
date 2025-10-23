#include "arduino.h"


#include "gpio.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <usbd_cdc_if.h>

#include "heater.h"

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

    void setup(){
       SetWaterHearterPower(0);
       heaterResetCounter = 5;
    }

    void loop(){
        if(heaterResetCounter == 0){
            SetWaterHearterPower(0);
            HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin, GPIO_PIN_SET);
        }
        else{
            heaterResetCounter--;
            HAL_GPIO_TogglePin(LED_GPIO_Port,LED_Pin);
        }
        
        HAL_Delay(1000);
    } 

}