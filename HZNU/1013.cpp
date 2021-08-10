//
// Created by smallflyfly on 2021/8/4.
//

#include <stdio.h>

int main() {
    int n, m;
    char s[105][105];
    int dirX[3] = {-1, 0, 1};
    int dirY[3] = {-1, 0, 1};
    int flag = 0, count = 1;
    while (scanf("%d %d", &n, &m)) {
        if (n == 0 || m == 0) {
            break;
        }
        if (flag++ > 0) printf("\n");
        for (int i = 0; i < n; ++i) {
            scanf("%s", s[i]);
        }
        printf("Field #%d:\n", count++);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (s[i][j] == '*') {
                    printf("*");
                } else {
                    int num = 0;
                    for (int k = 0; k < 3; ++k) {
                        for (int l = 0; l < 3; ++l) {
                            if (k == 1 && l == 1) continue;
                            int dx = i + dirX[k];
                            int dy = j + dirY[l];
                            if (dx >= 0 && dy >= 0 && dx < n && dy < n) {
                                if (s[dx][dy] == '*') num ++;
                            }
                        }
                    }
                    printf("%d", num);
                }
            }
            printf("\n");
        }
    }
    return 0;
}