//
// Created by smallflyfly on 2021/8/4.
//

#include <stdio.h>

int getLen(int n) {
    int l = 0;
    while (n) {
        n /= 10;
        l++;
    }
    return l;
}

int main() {
    int n, m;
    while(scanf("%d %d", &n, &m) != EOF) {
        int n1 = n, m1 = m;
        int l1 = 0, l2 = 0;
        l1 = getLen(n);
        l2 = getLen(m);
        int ll2 = l2;
        if (l1 < l2) {
            printf("-1\n");
            continue;
        }
        long mod = 1;
        while (l2) {
            mod *= 10;
            l2 --;
        }
        int flag = 0;
        int p;
        int count = 0;
        while (n) {
            int t = n % mod;
            if (t == m) {
                flag = 1;
                p = l1 - count - ll2;
            }
            n /= 10;
            count ++;
        }
        if (flag) {
            printf("%d\n", p);
        } else {
            printf("-1\n");
        }
    }
}