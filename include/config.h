#ifndef CONFIG_H
#define CONFIG_H

/**
 * @file config.h
 * A catch-all file for configuring various bugfixes and other settings
 * (maybe eventually) in SM64
 */

// Bug Fixes
// --| US Version Nintendo Bug Fixes
/// Fixes bug where obtaining over 999 coins sets the number of lives to 999 (or -25)
#define BUGFIX_MAX_LIVES (0 || VERSION_US || VERSION_EU || VERSION_SH)
/// Fixes bug where the Boss music won't fade out after defeating King Bob-omb
#define BUGFIX_KING_BOB_OMB_FADE_MUSIC (0 || VERSION_US || VERSION_EU)
/// Fixes bug in Bob-Omb Battlefield where entering a warp stops the Koopa race music
#define BUGFIX_KOOPA_RACE_MUSIC (0 || VERSION_US || VERSION_EU || VERSION_SH)
/// Fixes bug where Piranha Plants do not reset their action state when the
/// player exits their activation radius.
#define BUGFIX_PIRANHA_PLANT_STATE_RESET (0 || VERSION_US || VERSION_EU || VERSION_SH)
/// Fixes bug where sleeping Piranha Plants damage players that bump into them
#define BUGFIX_PIRANHA_PLANT_SLEEP_DAMAGE (0 || VERSION_US || VERSION_SH)
/// Fixes bug where it shows a star when you grab a key in bowser battle stages
#define BUGFIX_STAR_BOWSER_KEY (0 || VERSION_US || VERSION_EU)

// Screen Size Defines
// #define SCREEN_WIDTH 640
// #define SCREEN_HEIGHT 480

// #define SCREEN_WIDTH 640
// #define SCREEN_HEIGHT 360

#define DEFAULT_SCREEN_WIDTH 320

#ifndef TARGET_N64
#define SCREEN_WIDTH 320
#define SCREEN_HEIGHT 240

#else
#define SCREEN_WIDTH 424 // 320 for console
#define SCREEN_HEIGHT 240
#endif


#define NIGHT_START 0
#define DAYTIME_START 10800 //   6 minutes rt ||  9 hours game time
#define DAY_LENGTH 18000 //     10 minutes rt || 15 hours game time
#define FULL_DAY_LENGTH (DAYTIME_START + DAY_LENGTH) // 28800 || 16 minutes
#define ONE_MINUTE 20
#define ONE_HOUR 1200
// #define GAME_TIME_START 12000
#define GAME_TIME_START 27000
// 9pm - 6am is night


// Border Height Define for NTSC Versions
#define BORDER_HEIGHT 0

#endif // CONFIG_H
