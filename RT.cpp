#include <stdio.h>
#include <math.h>

#include "Math.h"

int main()
{
    const int H = 45;
    const int W = 120;
    const int X_C = H / 2;
    const int Y_C = W / 2;
    const int COUNT_STEPS = 1000000;
    
    const char gradient[] = " .:/l1498@";
    int count_colors = sizeof(gradient) - 2;

    char picture[H * W + 1];
    picture[H * W] = '\0';

    const double attitude = 1.2;
    const double radius = 0.45f;

    Vect3 V(-2, 0, 0);

    for (int step = 0; step < COUNT_STEPS; step++) {
        Vect3 light(-1, cos(step * 0.005), sin(step * 0.005));
        light = normalize(light);
        for (int i = 0 ; i < H; i++) {
            for (int j = 0; j < W; j++) {

                Vect2 pos = Vect2(i, j) / Vect2(H, W) - 0.5f;
                pos.y *= attitude;

                Vect3 dir(1, pos); 
                dir = normalize(dir);
                Vect2 intersect = intersection_sphere(V, dir, radius);

                char pixel = ' ';
                if (intersect.x > 0) {
                    Vect3 point = V + dir * intersect.x;
                    point = normalize(point);
                    int color = mul(point, light) * 13.f;
                    color = MAX(0, MIN(count_colors, color));
                    pixel = gradient[color];
                } else {
                    pixel = gradient[0];
                }
                picture[i * W + j] = pixel;
            }
        }
        printf("%s\n", picture);
    }
    return 0;
}