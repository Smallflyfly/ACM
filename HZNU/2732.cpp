//
// Created by smallflyfly on 2021/8/11.
//
#include <iostream>
#include <string.h>

int main() {
    int n;
    int a[30001];
    while (scanf("%d", &n) != EOF) {
        memset(a, 0, sizeof(a));
        int nt = 0, pt = 0;
        int maxNt = -0x7fffffff, minNt = 0;
        int maxPt = 0, minPt = 0x7fffffff;
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
            if (a[i] > 0) {
                pt ++;
                if (a[i] > maxPt) {
                    maxPt = a[i];
                }
                if (a[i] < minPt) {
                    minPt = a[i];
                }
            }
            if (a[i] < 0) {
                nt ++;
                if (a[i] > maxNt) {
                    maxNt = a[i];
                }
                if (a[i] < minNt) {
                    minNt = a[i];
                }
            }
        }
        // 分情况  都为正整数   都为负数  有负 有正
        int ans;
        if (nt == 0) {
            ans = minPt;
        } else if (pt == 0) {
            // 奇数个  去掉最大负数  偶数个 去掉最小负数
            if (nt % 2 == 0) {
                ans = minNt;
            } else {
                ans = maxNt;
            }
        } else {
            // 有负 有正
            // 偶数个负数 去掉最小正数
            if (nt % 2 == 0) {
                ans = minPt;
            } else {
                //奇数个负数 去掉最大负数
                ans = maxNt;
            }
        }
        printf("%d\n", ans);
    }
}