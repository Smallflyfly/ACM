//
// Created by smallflyfly on 2021/8/4.
//

#include <stdio.h>

int a[67];

void fib() {
    a[0] = 1;
    a[1] = 2;
    for (int i = 2; i < 67; ++i) {
        a[i] = a[i-1] + a[i-2];
    }
}

int main() {
    fib();
    int n;
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        printf("%d\n", a[n-1]);
    }

}