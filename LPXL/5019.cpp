//
// Created by smallflyfly on 2021/8/17.
//

#include <stdio.h>
#include <string.h>

int a[20001];
int dp[20001];

int binsearch(int dp[], int target, int left, int right) {
    while (left <= right) {
        int mid = (left + right) / 2;
        if (dp[mid] < target) {
            if (dp[mid+1] > target) {
                return mid;
            } else {
                left = mid + 1;
            }
        } else {
            right = mid - 1;
        }
    }
    return 0;
}

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        memset(a, 0, sizeof(a));
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
        }
        int len = 1;
        dp[len] = a[0];
        for (int i = 1; i < n; ++i) {
            if (a[i] > dp[len]) {
                len ++;
                dp[len] = a[i];
            } else {
                int j = binsearch(dp, a[i], 1, len);
                j++;
                dp[j] = a[i];
            }
        }
        printf("%d\n", len);
    }

    return 0;
}