/*
┌────────────────────────┐
│   pgm_io.c             │
├────────────────────────┤
│ #include "pgm_io.h"    │
│                        │
│ Implementation of:     │
│ - pgm_read_image()     │
│ - pgm_save_image()     │
└────────────────────────┘
*/
#include "pgm_io.h"
#include <stdio.h>
#include <stdlib.h>

PGMImage *pgm_read_image(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (!fp) {
        fprintf(stderr, "error %s\n", filename);
        return NULL;}

    fclose(fp);
    return NULL;  
}

int pgm_save_image(const char *filename, const PGMImage *img) {
    FILE *fp = fopen(filename, "wb");
    if (!fp) {
        fprintf(stderr, "error %s\n", filename);
        return 0;
    }

    fclose(fp);
    return 1;
}
