//
// Created by smallflyfly on 2021/8/11.
//

#include <stdio.h>
#include <math.h>

#define PI 3.1415
#define max(a, b) a > b ? a : b
#define min(a, b) a < b ? a : b

int main() {
    double x1, y1, x2, y2;
    double r1, r2;
    while (scanf("%lf %lf %lf %lf",&x1, &y1, &x2, &y2) != EOF) {
        if (x1 == 0.0 && y1 == 0.0 && x2 == 0.0 && y2 == 0.0) {
            printf("Over!\n");
            break;
        }
        scanf("%lf %lf", &r1, &r2);
        if (r1 == 0.0 || r2 == 0.0) {
            printf("0.00\n");
            continue;
        }
        double d = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
        if (d >= (r1 + r2)) {
            printf("0.00\n");
            continue;
        }
        if (r1 < r2) {
            double tmp = r1;
            r1 = r2;
            r2 = tmp;
        }
        double s1 = PI * r1 * r1;
        double s2 = PI * r2 * r2;
        if (d <= (r1 - r2)) {
            printf("%.2lf\n", s2);
            continue;
        }

        double t1 = (r1 * r1 + d * d - r2 * r2) / (2.0 * r1 * d);
        double t2 = (r2 * r2 + d * d - r1 * r1) / (2.0 * r2 * d);
        double angleA = acos(t1);
        double angleB = acos(t2);
        s1 = r1 * r1 * angleA;
        s2 = r2 * r2 * angleB;
        // 四边形面积
        double s3 = r1 * sin(angleA) * d;
        double s = s1 + s2 - s3;
        printf("%.2lf\n", s);
    }

    return 0;
}