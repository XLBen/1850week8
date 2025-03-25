/*
┌────────────────────────┐
│   main.c               │
├────────────────────────┤
│ #include "pgm_image.h" │
│ #include "pgm_io.h"    │
│ #include "pgm_process.h"│
│ #include "pgm_display.h"│
│                        │
│ int main() {           │
│   // Program logic     │
│ }                      │
└────────────────────────┘
*/
// src/main.c
#include "include/pgm_image.h"
#include "include/pgm_io.h"
#include "include/pgm_process.h"
#include "include/pgm_display.h"
#include <stdio.h>

int main() {
    int choice;
    PGMImage *img = NULL;
    PGMImage *processed_img = NULL;
    char filename[256];
    while (1) {
        pgm_display_menu();
        choice = pgm_get_user_choice();
        switch (choice) {
            case 1:
                printf("Enter program name:");
                scanf("%s", filename);
                img = pgm_read_image(filename);
                if (img) {pgm_print_info(img);}
                break;
            case 2:
                if (img) {
                    printf("enter the program name you want save:");
                    scanf("%s", filename);
                    if (pgm_save_image(filename, img)) {printf("saved\n");
                    }
                break;
            case 3:
                if (img) {
                    processed_img = pgm_invert_colors(img);
                    printf("turned\n");
                    pgm_print_info(processed_img);
                    pgm_print_pixels(processed_img);
                    pgm_free_image(processed_img);
                }
                break;
            case 4:
                if (img) {
                    processed_img = pgm_rotate_image(img);
                    printf("spined\n");
                    pgm_print_info(processed_img);
                    pgm_print_pixels(processed_img);
                    pgm_free_image(processed_img);
                }
                break;
            case 5:
                pgm_free_image(img);
                printf("quited\n");
                return 0;
            default:
                printf("error\n");
                break;
        }
    }
    return 0;
}
