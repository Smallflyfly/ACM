//
// Created by fangpc on 2021/8/12.
//

class Shop {
public:
    int price;
    int num;

    Shop(int price, int num) : price(price), num(num) {}
};


#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

#define min(a, b) a < b ? a : b

bool cmp(const Shop &p1, const Shop &p2) {
    return p1.price < p2.price;
}

int main() {
    int m, n;
    while (scanf("%d %d", &m, &n) !=EOF ) {
        int a, b;
        vector<Shop> shopes;
        for (int i = 0; i < n; ++i) {
            scanf("%d %d", &a, &b);
            Shop p(a, b);
            shopes.push_back(p);
        }
        sort(shopes.begin(), shopes.end(), cmp);
        int ans = 0;
        for (int i = 0; i < shopes.size(); ++i) {
            int num = min(m, shopes[i].num);
            m -= num;
            ans += num * shopes[i].price;
            if (m == 0) {
                break;
            }
        }
        printf("%d\n", ans);
    }

    return 0;
}