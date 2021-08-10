//
// Created by smallflyfly on 2021/8/4.
//

#include <stdio.h>
#include <algorithm>

using namespace std;

int main() {
    int T;
    int n;
    int a[1001];
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
           scanf("%d", &a[i]);
        }
        sort(a, a+n);
        int p = a[n/2];
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += abs(a[i] - p);
        }
        printf("%d %d\n", p, sum);
    }
}