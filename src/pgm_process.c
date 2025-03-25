/*
┌────────────────────────┐
│   pgm_process.c        │
├────────────────────────┤
│ #include "pgm_process.h"│
│                        │
│ Implementation of:     │
│ - pgm_invert_colors()  │
│ - pgm_rotate_image()   │
└────────────────────────┘
*/
// src/pgm_process.c
#include "pgm_process.h"
#include <stdlib.h>

PGMImage *pgm_invert_colors(const PGMImage *img) {
    if (!img) return NULL;
    PGMImage *new_img = pgm_create_image(img->width, img->height, img->max_gray);
    if (!new_img) return NULL;
    for (int i = 0; i < img->width * img->height; i++) {
        new_img->data[i] = img->max_gray - img->data[i];
    }
    return new_img;
}

PGMImage *pgm_rotate_image(const PGMImage *img) {
    if (!img) return NULL;
    PGMImage *new_img = pgm_create_image(img->height, img->width, img->max_gray);
    if (!new_img) return NULL;
    for (int i = 0; i < img->height; i++) {
        for (int j = 0; j < img->width; j++) {
            new_img->data[j * new_img->width + (new_img->width - i - 1)] = img->data[i * img->width + j];
        }
    }
    return new_img;
}
