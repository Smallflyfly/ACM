//
// Created by smallflyfly on 2021/8/12.
//

#include <stdio.h>
#include <string.h>

long long a[41];

long long getSum(long long t, long long n) {
    return t + 2 * n;
}

void getResult() {
    a[0] = 3;
    a[1] = 9;
    a[2] = 21;
    long long at1 = 1;
    long long an1 = 3;
    long long bt1 = 1;
    long long bn1 = 2;
    for (int i = 3; i < 40; ++i) {
        long long tmp = an1;
        an1 = getSum(at1, an1);
        at1 = tmp;
        tmp = bn1;
        bn1 = getSum(bt1, bn1);
        bt1 = tmp;
        a[i] = 3 * an1 + 6 * bn1;
    }
}

int main() {
    int n;
    memset(a, 0, sizeof(a));
    getResult();
    while (scanf("%d", &n) != EOF) {
        printf("%lld\n", a[n-1]);
    }
    return 0;
}