/*
┌────────────────────────┐
│   pgm_display.h        │
├────────────────────────┤
│ #include "pgm_image.h" │
│                        │
│ Function declarations: │
│ - pgm_print_info()     │
│ - pgm_print_pixels()   │
│ - pgm_display_menu()   │
│ - pgm_get_user_choice()│
└────────────────────────┘
*/
#ifndef PGM_DISPLAY_H
#define PGM_DISPLAY_H
#include "pgm_image.h"

void pgm_print_pixels(const PGMImage *img);

void pgm_display_menu(void);

int pgm_get_user_choice(void);

#endif 
