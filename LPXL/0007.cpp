//
// Created by fangpc on 2021/8/16.
//

#include <stdio.h>
#include <string.h>

#define min(a, b) a < b ? a : b


int len11 = 10001 + 910;
int len22 = 1001 + 910;
int dp[10001 + 910][1001 + 910];

int main() {
        char s1[10001];
        char s2[10001];
        while(scanf("%s", &s1) != EOF) {
            scanf("%s", &s2);
            char ss1[len11];
            char ss2[len22];
            memset(ss1, '\0', sizeof(ss1));
            memset(ss2, '\0', sizeof(ss2));
            memset(dp, 0, sizeof(dp));
            int k = 0;
            for (int i = 0; i < strlen(s1); ++i) {
                if (s1[i] >= 'a' && s1[i] <= 'z') {
                    ss1[k++] = s1[i];
                } else {
                    int n = (int)(s1[i] - '0');
                    while (n--) {
                        ss1[k++] = '#';
                    }
                }
            }
            k = 0;
            for (int i = 0; i < strlen(s2); ++i) {
                if (s2[i] >= 'a' && s2[i] <= 'z') {
                    ss2[k++] = s2[i];
                } else {
                    int n = (int)(s2[i] - '0');
                    while (n--) {
                        ss2[k++] = '#';
                    }
                }
            }
            int len1 = strlen(ss1);
            int len2 = strlen(ss2);
            for (int i = 1; i <= len1; ++i) {
                dp[i][0] = i;
            }
            for (int i = 1; i <= len2; ++i) {
                dp[0][i] = i;
            }
            printf("%s\n", ss1);
            printf("%s\n", ss2);
            for (int i = 1; i <= len1; ++i) {
                for (int j = 1; j <= len2; ++j) {
                    int replace = 0;
                    if (ss1[i-1] == ss2[j-1]) {
                        dp[i][j] = dp[i-1][j-1];
                    } else {
                        if (ss2[j-1] == '#') {
                            if ((j-2 >= 0 && ss2[j-2] != '#') || (j-1==0)) {
                                replace = 1;
                            }
                        } else {
                            if (ss1[i-1] == '#') {
                                if (i-1==0 || (i-2>=0 && ss1[i-2] != '#')) {
                                    replace = 1;
                                }
                            } else {
                                replace = 2;
                            }
                        }
                        int t1 = dp[i-1][j-1]+replace;
                        int t2 = dp[i][j-1]+1;
                        int t3 = dp[i-1][j]+1;
//                        int t4 = min(dp[i-1][j-1]+replace, min(dp[i][j-1]+1, dp[i-1][j]+1));
                        int t4 = min(t2, t3);
                        int t5 = min(t1, t4);
                        dp[i][j] = t5;

                    }
                }
            }
            printf("%d\n", dp[len1][len2]);

        }

        return 0;
}