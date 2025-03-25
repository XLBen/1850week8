/*
┌────────────────────────┐
│   pgm_io.h             │
├────────────────────────┤
│ #include "pgm_image.h" │
│                        │
│ Function declarations: │
│ - pgm_read_image()     │
│ - pgm_save_image()     │
└────────────────────────┘
*/

#ifndef PGM_IO_H
#define PGM_IO_H

#include "pgm_image.h"

PGMImage *pgm_read_image(const char *filename);

int pgm_save_image(const char *filename, const PGMImage *img);

#endif 
