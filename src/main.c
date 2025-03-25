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
#include "pgm_image.h"
#include "pgm_io.h"
#include "pgm_process.h"
#include "pgm_display.h"
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
                printf("请输入要读取的图像文件名：");
                scanf("%s", filename);
                img = pgm_read_image(filename);
                if (img) {
                    printf("图像读取成功！\n");
                    pgm_print_info(img);
                }
                break;
            case 2:
                if (img) {
                    printf("请输入要保存的图像文件名：");
                    scanf("%s", filename);
                    if (pgm_save_image(filename, img)) {
                        printf("图像保存成功！\n");
                    }
                }
                break;
            case 3:
                if (img) {
                    processed_img = pgm_invert_colors(img);
                    printf("图像颜色已反转！\n");
                    pgm_print_info(processed_img);
                    pgm_print_pixels(processed_img);
                    pgm_free_image(processed_img);
                }
                break;
            case 4:
                if (img) {
                    processed_img = pgm_rotate_image(img);
                    printf("图像已旋转！\n");
                    pgm_print_info(processed_img);
                    pgm_print_pixels(processed_img);
                    pgm_free_image(processed_img);
                }
                break;
            case 5:
                pgm_free_image(img);
                printf("退出程序！\n");
                return 0;
            default:
                printf("无效选项，请重新输入！\n");
                break;
        }
    }
    return 0;
}
