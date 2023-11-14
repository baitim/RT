#include <stdio.h>
#include <math.h>

#include "Math.h"

int main()
{
    const int H = 45;
    const int W = 120;
    const int X_C = H / 2;
    const int Y_C = W / 2;
    const int COUNT_STEPS = 6000;
    
    const char gradient[] = " .:/1?498@";
    int count_colors = sizeof(gradient) - 2;

    char picture[H * W + 1];
    picture[H * W] = '\0';

    const double attitude = 1.2;
    const double radius = 0.25f;

    for (int step = 0; step < COUNT_STEPS; step++) {
        for (int i = 0 ; i < H; i++) {
            for (int j = 0; j < W; j++) {
                Vect v = Vect(i, j) / Vect(H, W) - 0.5f;

                v = v + Vect(cos(step / 600.0f), sin(step / 600.0f)) * 0.25f;

                v.y *= attitude;

                double distance = v.len();

                int color = radius / distance;
                color = MAX(0, MIN(count_colors, color));

                if (distance < radius)  picture[i * W + j] = gradient[color];
                else                    picture[i * W + j] = gradient[color];
            }
        }
        printf("%s\n", picture);
    }
    return 0;
}