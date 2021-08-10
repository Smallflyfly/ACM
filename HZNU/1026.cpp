//
// Created by smallflyfly on 2021/8/5.
//

#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    int T;
    int n,q;
    char s[51], qs[51];
    int score;
    map<string, int> sp;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%s %d", &s, &score);
            sp.insert(map<char*, int>::value_type(s, score));
//            cout << s << " " << score << endl;
        }
        scanf("%d", &q);
        while (q--) {
            scanf("%s", &qs);
            if (sp.find(qs) != sp.end()) {
                printf("%d\n", sp[qs]);
            } else {
                printf("error\n");
            }
        }
    }

    return 0;
}