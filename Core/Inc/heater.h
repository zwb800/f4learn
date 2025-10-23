#ifndef __HEATER_H__
#define __HEATER_H__

#ifdef __cplusplus
 extern "C" {
#endif

#include <stdint.h>
extern uint8_t heaterResetCounter;
void HearterSetup();
void SetWaterHearterPower(uint8_t pwm);
#ifdef __cplusplus
}
#endif

#endif