//
// Created by smallflyfly on 2021/8/9.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int n, q;
        int a;
        vector<int> nums;
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a);
            nums.push_back(a);
        }
        sort(nums.begin(), nums.end());
        scanf("%d", &q);
        while (q--) {
            int b;
            scanf("%d", &b);
            bool flag = binary_search(nums.begin(), nums.end(), b);
            if (flag) {
                printf("Yes\n");
            } else {
                printf("No\n");
            }
        }
    }

    return 0;
}