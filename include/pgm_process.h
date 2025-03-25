/*
┌────────────────────────┐
│   pgm_process.h        │
├────────────────────────┤
│ #include "pgm_image.h" │
│                        │
│ Function declarations: │
│ - pgm_invert_colors()  │
│ - pgm_rotate_image()   │
└────────────────────────┘
*/
// include/pgm_process.h
#ifndef PGM_PROCESS_H
#define PGM_PROCESS_H

#include "pgm_image.h"

PGMImage *pgm_invert_colors(const PGMImage *img);

PGMImage *pgm_rotate_image(const PGMImage *img);

#endif 