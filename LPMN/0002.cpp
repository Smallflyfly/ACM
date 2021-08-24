//
// Created by smallflyfly on 2021/8/12.
//

#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

bool cmp1(const char *a, const char *b) {
    return strcmp(a, b) < 0;
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int n;
        char *a[25];
        char s[20][25];
        memset(a, '\0', sizeof(a));
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%s", &s[i]);
            a[i] = s[i];
        }
        sort(a, a+n, cmp1);
        for (int i = 0; i < n; ++i) {
            printf("%s\n", a[i]);
        }
    }
    return 0;
}