#ifndef __HEATER_H__
#define __HEATER_H__

#ifdef __cplusplus
 extern "C" {
#endif

#include <stdint.h>
static uint8_t heaterResetCounter = 0;
void SetWaterHearterPower(uint8_t pwm);
#ifdef __cplusplus
}
#endif

#endif