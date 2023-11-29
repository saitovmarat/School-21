#include "print.h"

void plot_function(double (*func)(char *, double), char *postfix) {
    int width = 80;
    int height = 25;
    double x_min = 0;
    double x_max = 4 * M_PI;
    double y_min = -1;
    double y_max = 1;

    char matrix[height][width];

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            matrix[i][j] = '.';
        }
    }
    for (int i = 0; i < width; i++) {
        double x_val = x_min + (x_max - x_min) * i / (width - 1);
        double y_val = func(postfix, x_val);
        int y_pixel = round((y_val - y_min) * (height - 1) / (y_max - y_min));
        int x_pixel = round((x_val - x_min) * (width - 1) / (x_max - x_min));
        matrix[height - 1 - y_pixel][x_pixel] = '*';
    }

    for (int i = height - 1; i >= 0; i--) {
        for (int j = 0; j < width; j++) {
            printf("%c", matrix[i][j]);
        }
        printf("\n");
    }
}
