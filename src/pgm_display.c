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
#include "pgm_display.h"
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
    printf("----- PGM 工具菜单 -----\n");
    printf("1. 读取图像\n");
    printf("2. 保存图像\n");
    printf("3. 反转图像\n");
    printf("4. 旋转图像\n");
    printf("5. 退出\n");
}

int pgm_get_user_choice(void) {
    int choice;
    printf("请输入选项：");
    scanf("%d", &choice);
    return choice;
}
