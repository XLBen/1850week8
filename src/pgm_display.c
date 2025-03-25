/*
┌────────────────────────┐
│   pgm_display.c        │
├────────────────────────┤
│ #include "pgm_display.h"│
│                        │
│ Implementation of:     │
│ - pgm_print_info()     │
│ - pgm_print_pixels()   │
│ - pgm_display_menu()   │
│ - pgm_get_user_choice()│
└────────────────────────┘
*/
// src/pgm_display.c
#include "include/pgm_display.h"
#include <stdio.h>

void pgm_print_pixels(const PGMImage *img) {
    if (!img) return;
    for (int i = 0; i < img->height; i++) {
        for (int j = 0; j < img->width; j++) {
            printf("%3d ", img->data[i * img->width + j]);
        }
        printf("\n");
    }
}

void pgm_display_menu(void) {
    printf("----- PGM menu -----\n");
    printf("1.read\n");
    printf("2.save\n");
    printf("3.turn\n");
    printf("4.spin\n");
    printf("5.quit\n");
}

int pgm_get_user_choice(void) {
    int choice;
    printf("Enter：");
    scanf("%d", &choice);
    return choice;
}
