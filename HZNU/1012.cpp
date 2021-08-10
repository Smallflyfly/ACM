//
// Created by smallflyfly on 2021/8/4.
//

#include <stdio.h>
#include <string.h>

int main() {
    int n;
    char s[101][1001];
    memset(s, '\0', sizeof(s));
    while (scanf("%d", &n) != EOF) {
        int count = 0;
        int k = 0;
        char s1[1];
        gets(s1);
        while (gets(s[k])) {
            int len = strlen(s[k]);
            s[k][len] = '\n';
            s[k][len+1] = '\0';
            k++;
//            if (k > 2) break;
        }
        for (int i = 0; i < k; ++i) {
            for (int j = 0; s[i][j] != '\0'; ++j) {
                if (s[i][j] != '\n' && s[i][j] != ' ') {
                    printf("%c", s[i][j]);
                }
                if (s[i][j] == ' ' && count < n) {
                    printf("%c", s[i][j]);
                }
                if (s[i][j] == '\n') {
                    printf("\n\n");
                    count++;
                }
                if (s[i][j] == ' ' && count >= n) {
                    printf("\n\n");
                }
            }
//            printf("\n");
        }
    }
    return 0;
}