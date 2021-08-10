//
// Created by smallflyfly on 2021/8/9.
//

#include <stdio.h>
#include <string.h>

int binary_search(int *dp, int target, int left, int right) {
    int mid;
    while (left <= right) {
        mid = (left + right) / 2;
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
        if (n == 0) {
            printf("0\n");
            continue;
        }
        int a[5001];
        int dp[5001];
        memset(a, 0, sizeof(a));
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
        }
        int len = 1;
        dp[len] = a[0];
        for (int i = 1; i < n; ++i) {
            if (dp[len] <= a[i]) {
                len ++;
                dp[len] = a[i];
            } else {
                int j =  binary_search(dp, a[i], 0, len);
                j++;
                dp[j] = a[i];
            }
        }
        printf("%d\n", len);
    }

    return 0;
}