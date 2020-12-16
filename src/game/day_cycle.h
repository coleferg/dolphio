#ifndef _DAY_CYCLE_H_
#define _DAY_CYCLE_H_

#include <types.h>

extern f32 gDayAmtR;
extern f32 gDayAmtG;
extern f32 gDayAmtB;

extern u8 get_interpolated_color_u8(u8 a, u8 b, f32 colorStrength);
extern void set_color_strengths();
extern void use_day_cycle_Lights0(Lights0 *srcLights, Lights0 *dayLights, Lights0 *nightLights);
extern void use_day_cycle_Lights1(Lights1 *srcLights, Lights1 *dayLights, Lights1 *nightLights);
extern void use_day_cycle_Lights2(Lights2 *srcLights, Lights2 *dayLights, Lights2 *nightLights);
extern void run_day_cycle();

#define DAY_CYCLE_INIT 1
#endif