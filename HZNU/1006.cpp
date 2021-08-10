//
// Created by smallflyfly on 2021/8/4.
//

#include <stdio.h>

int main() {
    int n;
    long long x, a;
    int count = 1;
    while (scanf("%d %lld", &n, &x) != EOF) {
        int flag = 0;
        printf("Case %d:\n", count++);
        for (int i = 0; i < n; ++i) {
            scanf("%lld", &a);
            if (a != x) {
                if (flag == 0) {
                    printf("%lld", a);
                } else {
                    printf(" %lld", a);
                }
                flag ++;
            }
        }
        if (!flag) {
            printf("Empty!\n\n");
        } else {
            printf("\n\n");
        }
    }

    return 0;
}