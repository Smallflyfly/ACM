//
// Created by smallflyfly on 2021/8/4.
//

#include <iostream>
#include <string.h>

using namespace std;

int main() {
    char str[10001];
    while (gets(str)) {
        int a = 0, b = 0;
        if (strcmp(str, "p") == 0) break;
        for (int i = 0; str[i] != '\0'; ++i) {
            if (str[i] != '{' && str[i] != '}') {
                continue;
            }
            if (str[i] == '{') {
                a++;
            } else {
                b++;
            }
        }
        if (a == b) {
            printf("paired\n");
        } else {
            printf("unpaired\n");
        }
    }
    return 0;
}