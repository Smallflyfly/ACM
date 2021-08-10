//
// Created by smallflyfly on 2021/8/4.
//

#include <iostream>

using namespace std;

int main() {
    int n;
    while (cin >> n && n != 0) {
        int a;
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            cin >> a;
            sum += a;
        }
        cout << sum << endl;
    }
}