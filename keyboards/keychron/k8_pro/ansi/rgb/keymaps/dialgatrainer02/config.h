#pragma once

//rgb stuff
#define ENABLE_RGB_MATRIX_RIVERFLOW//have to define riverflow first as keychron didnt
#define RGB_MATRIX_DEFAULT_MODE RGB_MATRIX_RIVERFLOW
#define RGB_MATRIX_DEFAULT_HUE 191 //purple

//dragons might break stuff
#define RGB_TRIGGER_ON_KEYDOWN

//optimisations
#define NO_MUSIC_MODE


//configuring features
#define DYNAMIC_MACRO_NO_NESTING
#define MOUSEKEY_INERTIA
#define DOUBLE_TAP_SHIFT_TURNS_ON_CAPS_WORD
#define ONESHOT_TAP_TOGGLE 3
#define ONESHOT_TIMEOUT 5000
//#define FORCE_NKRO nkro doesnt work on wireless so off for now
#undef AUTO_SHIFT_ENABLE
#define SENTENCE_CASE_TIMEOUT 2000
