/* 
┌────────────────────────┐
│   pgm_image.h          │
├────────────────────────┤
│ typedef struct {       │
│   int width;           │
│   int height;          │
│   int max_gray;        │
│   unsigned char **...  │
│ } PGMImage;            │
│                        │
│ Function declarations: │
│ - pgm_create_image()   │
│ - pgm_free_image()     │
└────────────────────────┘
*/

#ifndef PGM_IMAGE_H
#define PGM_IMAGE_H

typedef struct {
    int width;          
    int height;         
    int max_gray;       
    unsigned char *data;
} PGMImage;

PGMImage *pgm_create_image(int width, int height, int max_gray);

void pgm_free_image(PGMImage *img);

void pgm_print_info(const PGMImage *img);

#endif 
