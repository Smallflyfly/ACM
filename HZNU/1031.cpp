//
// Created by smallflyfly on 2021/8/9.
//

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int n, b, si, ei;
        int aa, bb, ss;
        vector<int> a;
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &b);
            a.push_back(b);
        }
        scanf("%d %d %d", &aa, &bb, &ss);
        if (aa > bb) {
            printf("0\n");
            continue;
        }
        vector<int>::iterator it;
        si = 0, ei = 0;
        vector<int>::iterator ps, pe;
        it = a.begin();
        while (it != a.end()) {
            if (si == aa) {
                ps = it;
            }
            si ++;
            it ++;
            if (ei == bb) {
                pe = it;
                break;
            }
            ei ++;
        }
        int sum = accumulate(ps, pe, ss);
        printf("%d\n", sum);
    }
}