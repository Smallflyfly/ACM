//
// Created by smallflyfly on 2021/8/3.
//

#include <stdio.h>

int main() {
    int T;
    long long a, b;
    long long k;
    int mod = 998244353;
    long long an, bn;
    scanf("%d", &T);
    while (T--) {
        scanf("%lld %lld %lld", &a, &b, &k);
        long long kt = k;
        long long t = 1;
        k = (k / 2) % mod;
        long long base = 2;
        while (k) {
            if (k & 1) {
                t = (t * base) % mod;
            }
            k = k >> 1;
            base = (base * base) % mod;
        }
//        printf("%lld\n", t);
        an = (t * a % mod) % mod;
        bn = (t * b % mod) % mod;

        if (kt % 2 == 0) {
            printf("%lld %lld\n", an, bn);
        } else {
            long long san = (an + bn) % mod;
            long long sbn = (an - bn + mod) % mod;
            printf("%lld %lld\n", san, sbn);
        }
    }
    return 0;
}