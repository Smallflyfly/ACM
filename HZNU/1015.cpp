//
// Created by smallflyfly on 2021/8/4.
//

#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int main() {
    int n;
    int a[50];
    int b[50][50];
    while (scanf("%d", &n) && n) {
        memset(b, 0, sizeof(int));
        for (int i = 0; i < n; ++i) {
            memset(a, 0, sizeof(int));
            for (int j = 0; j < n; ++j) {
                scanf("%d", &a[j]);
            }
            sort(a, a+n);
            for (int j = 0; j < n; ++j) {
                b[i][j] = a[j];
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n-1; ++j) {
                printf("%d ", b[i][j]);
            }
            printf("%d\n", b[i][n-1]);
        }
    }
    return 0;
}