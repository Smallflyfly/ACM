//
// Created by smallflyfly on 2021/8/9.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        vector<int> nums;
        int i;
        for (i = 0; i < n; ++i) {
            nums.push_back(i+1);
        }
        for (i = 0; i < nums.size()-1; ++i) {
            printf("%d",nums[i]);
        }
        printf("%d\n", nums[i]);
        vector<int> nums_c = nums;
        while (next_permutation(nums.begin(), nums.end())) {
            for (i = 0; i < nums.size()-1; ++i) {
                printf("%d",nums[i]);
            }
            printf("%d\n", nums[i]);
            nums_c = nums;
        }
        for (i = 0; i < nums_c.size()-1; ++i) {
            printf("%d",nums_c[i]);
        }
        printf("%d\n", nums_c[i]);
        while (prev_permutation(nums_c.begin(), nums_c.end())) {
            for (i = 0; i < nums_c.size()-1; ++i) {
                printf("%d",nums_c[i]);
            }
            printf("%d\n", nums_c[i]);
        }
        printf("\n");
    }

    return 0;
}