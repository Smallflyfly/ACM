//
// Created by smallflyfly on 2021/8/12.
//

#include <stdio.h>

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        int min = 0x7fffffff;
        int max = -0x7fffffff;
        int a;
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a);
            if (a > max) {
                max = a;
            }
            if (a < min) {
                min = a;
            }
        }
        printf("%d %d\n", min, max);
    }
    return 0;
}