//
// Created by smallflyfly on 2021/8/4.
//

#include <stdio.h>

int main() {
    char s[10001];
    int sum = 0;
    while (gets(s)) {
        for (int i = 0; s[i]!='\0'; ++i) {
            if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')) {
                sum ++;
            }
        }
    }
    printf("%d\n", sum);
}