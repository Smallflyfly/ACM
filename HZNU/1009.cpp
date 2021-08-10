//
// Created by smallflyfly on 2021/8/4.
//

#include <stdio.h>
#include <algorithm>

using namespace  std;

int main() {
    int n;
    int a[200];
    while (scanf("%d", &n) != EOF && n) {
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
        }
        sort(a, a+n);
        int j = 0;
        for (int i = 1; i < n; ++i) {
            if (a[i] != a[j]) {
                j++;
                a[j] = a[i];
            }
        }
        printf("%d\n", j+1);
        for (int i = 0; i < j; ++i) {
            printf("%d ", a[i]);
        }
        printf("%d\n\n", a[j]);
    }
    return 0;
}