//
// Created by smallflyfly on 2021/8/4.
//

#include <stdio.h>

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        int x = 2;
        int y = 0;
        int a = 1, b;
        int nn = n;
        for (int i = 0; i < n; ++i) {
            a += y;
            b = a;
            int xx = x;
            for (int j = 0; j < nn-1; ++j) {
                printf("%d ", b);
                b = b + xx;
                xx ++;
            }
            printf("%d\n", b);
            x++;
            y++;
            nn--;
        }
    }

    return 0;
}