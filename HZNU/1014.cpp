//
// Created by smallflyfly on 2021/8/4.
//

#include <stdio.h>

int main() {
    int T;
    long long n, m;
    scanf("%d", &T);
    while (T--) {
        scanf("%lld", &n);
        m = n;
        if (n % 7 == 0) {
            printf("pa\n");
            continue;
        }
        int flag = 0;
        while(n) {
            int a = n % 10;
            if (a == 7) {
                printf("pa\n");
                flag = 1;
                break;
            }
            n /= 10;
        }
        if (!flag) {
            printf("%lld\n", m);
        }
    }

    return 0;
}