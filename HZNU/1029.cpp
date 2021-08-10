//
// Created by smallflyfly on 2021/8/6.
//

#include <iostream>
#include <set>

using namespace std;

int main() {
    int n, a;
    while (scanf("%d", &n) != EOF) {
        set<int> s;
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a);
            s.insert(a);
        }
        printf("%d\n", s.size());
        set<int>::iterator it;
        it = s.begin();
        printf("%d", *it);
        it ++;
        while (it != s.end()) {
            printf(" %d", *it++);
        }
        printf("\n");
    }

    return 0;
}