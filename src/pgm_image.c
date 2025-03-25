/*
┌────────────────────────┐
│   pgm_image.c          │
├────────────────────────┤
│ #include "pgm_image.h" │
│                        │
│ Implementation of:     │
│ - pgm_create_image()   │
│ - pgm_free_image()     │
└────────────────────────┘
*/
#include "include/pgm_image.h"
#include <stdio.h>
#include <stdlib.h>

PGMImage *pgm_create_image(int width, int height, int max_gray) {
    PGMImage *img = (PGMImage *)malloc(sizeof(PGMImage));
    if (!img) {
        fprintf(stderr, "error\n");
        return NULL;
    }
    img->width = width;
    img->height = height;
    img->max_gray = max_gray;
    img->data = (unsigned char *)malloc(width * height * sizeof(unsigned char));
    if (!img->data) {
        fprintf(stderr, "error\n");
        free(img);
        return NULL;
    }
    return img;
}

void pgm_free_image(PGMImage *img) {
    if (img) {
        free(img->data);
        free(img);
    }
}

void pgm_print_info(const PGMImage *img) {
    if (img) {
        printf("width:%d, height:%d,max_gray:%d\n", img->width, img->height, img->max_gray);
    }
}
