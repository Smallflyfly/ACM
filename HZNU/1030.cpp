//
// Created by smallflyfly on 2021/8/6.
//

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int n, a, q;
        char c;
        int p1, p2;
        vector<int> vec;
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a);
            vec.push_back(a);
        }
        scanf("%d", &q);
        for (int i = 0; i < q; ++i) {
            char ss[2];
            gets(ss);
            scanf("%c", &c);
            if (c == 'P') {
                for (int j = 0; j < vec.size()-1; ++j) {
                    printf("%d ", vec[j]);
                }
                printf("%d\n", vec[vec.size()-1]);
            } else if(c == 'U') {
                scanf("%d %d", &p1, &p2);
                vec.insert(vec.begin()+p1, p2);
            } else {
                scanf("%d", &p1);
                vec.erase(vec.begin()+p1);
            }
        }
        if (T > 0) {
            printf("\n");
        }
    }

    return 0;
}