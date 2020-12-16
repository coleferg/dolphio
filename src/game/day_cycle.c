#include "types.h"
#include "config.h"

#include "game/level_update.h"
#include "game/area.h"
#include "level_table.h"

#define CHANGE_TRANSITION_LENGTH (ONE_MINUTE * 45)
#define R_TRANSITION_LENGTH_SUNRISE (ONE_MINUTE * 0) //  0 min after
#define G_TRANSITION_LENGTH_SUNRISE (ONE_MINUTE * 15)  // 0 min after
#define B_TRANSITION_LENGTH_SUNRISE (ONE_MINUTE * 8)  // 8 min after

#define R_TRANSITION_LENGTH_SUNSET (ONE_MINUTE * 15) //  0 min after
#define G_TRANSITION_LENGTH_SUNSET (ONE_MINUTE * 0)  // 0 min after
#define B_TRANSITION_LENGTH_SUNSET (ONE_MINUTE * 8)  // 8 min after

#define SUNRISE_START (DAYTIME_START - CHANGE_TRANSITION_LENGTH)
#define SUNRISE_END (SUNRISE_START + CHANGE_TRANSITION_LENGTH + G_TRANSITION_LENGTH_SUNRISE)

#define SUNSET_START (FULL_DAY_LENGTH - CHANGE_TRANSITION_LENGTH)
#define SUNSET_END (NIGHT_START + R_TRANSITION_LENGTH_SUNSET)

f32 gDayAmtR = 1.0f;
f32 gDayAmtG = 1.0f;
f32 gDayAmtB = 1.0f;


unsigned char get_interpolated_color(unsigned char a, unsigned char b, f32 colorStrength) {
    f32 additive = colorStrength * ((f32) a - (f32) b);
    return (unsigned char) b + additive;
}

u8 get_interpolated_color_u8(u8 a, u8 b, f32 colorStrength) {
    f32 additive = colorStrength * ((f32) a - (f32) b);
    return (u8) (b + additive);
}

signed char get_interpolated_angle(signed char a, signed char b, f32 colorStrength) {
    f32 additive = colorStrength * ((f32) a - (f32) b);
    return (signed char) b + additive;
}

void set_color_strengths() {
    s16 isSunrise = (gGlobalClock > SUNRISE_START && gGlobalClock < SUNRISE_END);
    s16 isSunset = !isSunrise && (gGlobalClock > SUNSET_START || gGlobalClock < SUNSET_END);

    if (!isSunrise && !isSunset) {
        gDayAmtR = gIsNight ? 0.0f : 1.0f;
        gDayAmtG = gIsNight ? 0.0f : 1.0f;
        gDayAmtB = gIsNight ? 0.0f : 1.0f;
    } else {
        f32 rNumerator;
        f32 gNumerator;
        f32 bNumerator;
        f32 rDenominator;
        f32 gDenominator;
        f32 bDenominator;

        if (isSunset) {
            rNumerator = (gGlobalClock < R_TRANSITION_LENGTH_SUNSET)
                ? CHANGE_TRANSITION_LENGTH + gGlobalClock
                : gGlobalClock - SUNSET_START;
            rDenominator = (f32) (CHANGE_TRANSITION_LENGTH + R_TRANSITION_LENGTH_SUNSET);

            gNumerator = (gGlobalClock < G_TRANSITION_LENGTH_SUNSET)
                ? CHANGE_TRANSITION_LENGTH + gGlobalClock
                : gGlobalClock - SUNSET_START;
            gDenominator = (f32) (CHANGE_TRANSITION_LENGTH + G_TRANSITION_LENGTH_SUNSET);

            bNumerator = (gGlobalClock < B_TRANSITION_LENGTH_SUNSET)
                ? CHANGE_TRANSITION_LENGTH + gGlobalClock
                : gGlobalClock - SUNSET_START;
            bDenominator = (f32) (CHANGE_TRANSITION_LENGTH + B_TRANSITION_LENGTH_SUNSET);

        } else {
            rNumerator = gGlobalClock - SUNRISE_START;
            gNumerator = gGlobalClock - SUNRISE_START;
            bNumerator = gGlobalClock - SUNRISE_START;
            rDenominator = (f32) (CHANGE_TRANSITION_LENGTH + R_TRANSITION_LENGTH_SUNRISE);
            gDenominator = (f32) (CHANGE_TRANSITION_LENGTH + G_TRANSITION_LENGTH_SUNRISE);
            bDenominator = (f32) (CHANGE_TRANSITION_LENGTH + B_TRANSITION_LENGTH_SUNRISE);
        }

        gDayAmtR = rNumerator / rDenominator;
        gDayAmtG = gNumerator / gDenominator;
        gDayAmtB = bNumerator / bDenominator;

        if (isSunset) {
            gDayAmtR = gDayAmtR * -1.0f + 1.0f;
            gDayAmtG = gDayAmtG * -1.0f + 1.0f;
            gDayAmtB = gDayAmtB * -1.0f + 1.0f;
        }

        gDayAmtR = MIN(1.0f, MAX(gDayAmtR, 0.0f));
        gDayAmtG = MIN(1.0f, MAX(gDayAmtG, 0.0f));
        gDayAmtB = MIN(1.0f, MAX(gDayAmtB, 0.0f));
    }
}

void use_day_cycle_Lights0(Lights0 *srcLights, Lights0 *dayLights, Lights0 *nightLights) {
    // Ambient
    srcLights->a.l.col[0] = get_interpolated_color(dayLights->a.l.col[0], nightLights->a.l.col[0], gDayAmtR);
    srcLights->a.l.col[1] = get_interpolated_color(dayLights->a.l.col[1], nightLights->a.l.col[1], gDayAmtG);
    srcLights->a.l.col[2] = get_interpolated_color(dayLights->a.l.col[2], nightLights->a.l.col[2], gDayAmtB);
}

void use_day_cycle_Lights1(Lights1 *srcLights, Lights1 *dayLights, Lights1 *nightLights) {
    // Ambient
    srcLights->a.l.col[0] = get_interpolated_color(dayLights->a.l.col[0], nightLights->a.l.col[0], gDayAmtR);
    srcLights->a.l.col[1] = get_interpolated_color(dayLights->a.l.col[1], nightLights->a.l.col[1], gDayAmtG);
    srcLights->a.l.col[2] = get_interpolated_color(dayLights->a.l.col[2], nightLights->a.l.col[2], gDayAmtB);

    // Directional Light 1
    srcLights->l[0].l.col[0] = get_interpolated_color(dayLights->l[0].l.col[0], nightLights->l[0].l.col[0], gDayAmtR);
    srcLights->l[0].l.col[1] = get_interpolated_color(dayLights->l[0].l.col[1], nightLights->l[0].l.col[1], gDayAmtG);
    srcLights->l[0].l.col[2] = get_interpolated_color(dayLights->l[0].l.col[2], nightLights->l[0].l.col[2], gDayAmtB);

    // Directional Light 1 Angle
    srcLights->l[0].l.dir[0] = get_interpolated_angle(dayLights->l[0].l.dir[0], -70, gDayAmtR);
    srcLights->l[0].l.dir[1] = get_interpolated_angle(dayLights->l[0].l.dir[1], -20, gDayAmtG);
    srcLights->l[0].l.dir[2] = get_interpolated_angle(dayLights->l[0].l.dir[2], -70, gDayAmtB);
}

void use_day_cycle_Lights2(Lights2 *srcLights, Lights2 *dayLights, Lights2 *nightLights) {
    // Ambient
    srcLights->a.l.col[0] = get_interpolated_color(dayLights->a.l.col[0], nightLights->a.l.col[0], gDayAmtR);
    srcLights->a.l.col[1] = get_interpolated_color(dayLights->a.l.col[1], nightLights->a.l.col[1], gDayAmtG);
    srcLights->a.l.col[2] = get_interpolated_color(dayLights->a.l.col[2], nightLights->a.l.col[2], gDayAmtB);

    // Directional Light 1
    srcLights->l[0].l.col[0] = get_interpolated_color(dayLights->l[0].l.col[0], nightLights->l[0].l.col[0], gDayAmtR);
    srcLights->l[0].l.col[1] = get_interpolated_color(dayLights->l[0].l.col[1], nightLights->l[0].l.col[1], gDayAmtG);
    srcLights->l[0].l.col[2] = get_interpolated_color(dayLights->l[0].l.col[2], nightLights->l[0].l.col[2], gDayAmtB);
    
    // Directional Light 1 Angle
    srcLights->l[0].l.dir[0] = get_interpolated_angle(dayLights->l[0].l.dir[0], -70, gDayAmtR);
    srcLights->l[0].l.dir[1] = get_interpolated_angle(dayLights->l[0].l.dir[1], -20, gDayAmtG);
    srcLights->l[0].l.dir[2] = get_interpolated_angle(dayLights->l[0].l.dir[2], -70, gDayAmtB);

    // Directional Light 2
    srcLights->l[1].l.col[0] = get_interpolated_color(dayLights->l[1].l.col[0], nightLights->l[1].l.col[0], gDayAmtR);
    srcLights->l[1].l.col[1] = get_interpolated_color(dayLights->l[1].l.col[1], nightLights->l[1].l.col[1], gDayAmtG);
    srcLights->l[1].l.col[2] = get_interpolated_color(dayLights->l[1].l.col[2], nightLights->l[1].l.col[2], gDayAmtB);

    // Directional Light 2 Angle
    srcLights->l[1].l.dir[0] = get_interpolated_angle(dayLights->l[1].l.dir[0], -70, gDayAmtR);
    srcLights->l[1].l.dir[1] = get_interpolated_angle(dayLights->l[1].l.dir[1],   0, gDayAmtG);
    srcLights->l[1].l.dir[2] = get_interpolated_angle(dayLights->l[1].l.dir[2], -55, gDayAmtB);
}

void run_day_cycle() {
#if FALSE
	switch(gCurrLevelNum) {
        case LEVEL_CASTLE_GROUNDS:
            if (gCurrAreaIndex == 1) {
                day_cycle_castle_grounds();
            }
            break;
        case LEVEL_BOWSER_1:
            break;
    }
#endif
}