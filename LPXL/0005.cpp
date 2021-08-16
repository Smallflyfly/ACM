//
// Created by fangpc on 2021/8/12.
//

#include <stdio.h>
#include <string.h>

#define max(a, b) a > b ? a : b

int main() {
    int n, m;
    int weight[31];
    int c[31];
    int dp[201];
    while (scanf("%d %d", &m, &n) != EOF) {
        memset(weight, 0, sizeof(weight));
        memset(c, 0, sizeof(c));
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < n; ++i) {
            scanf("%d %d", &weight[i], &c[i]);
        }
        for (int i = 0; i < n; ++i) {
            for (int w = m; w >=weight[i]; w--) {
                dp[w] = max(dp[w-weight[i]] + c[i], dp[w]);
            }
        }
        printf("%d\n", dp[m]);
    }
}