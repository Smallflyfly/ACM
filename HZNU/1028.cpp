//
// Created by smallflyfly on 2021/8/5.
//

#include <map>
#include <iostream>

using namespace std;

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int c;
        long long n;
        int m;
        map<int, long long, greater<int>> mp;
        scanf("%d", &c);
        for (int i = 0; i < c; ++i) {
            scanf("%lld %d", &n, &m);
            if (mp.find(m) != mp.end()) {
                mp[m] += n;
            } else {
                mp.insert(make_pair(m, n));
            }
        }
        map<int, long long>::iterator it;
        it = mp.begin();
        int t1 = 0;
        if (it->second != 0) {
            if (it->second != 1) {
                if (it->second == -1) {
                    printf("-");
                }else {
                    printf("%lld", it->second);
                }
                t1 ++;
            }
            if (it->first != 0) {
                if (it->first != 1) {
                    printf("x^%d", it->first);
                    t1++;
                } else {
                    printf("x");
                    t1 ++;
                }
            }
        }
        long long zero = it->second;
        it ++;
        int p = 0;
        for (; it != mp.end(); it++) {
            int flag = 0;
            if (it->second != 0) {
                if (it->second != 1) {
                    if (it->second > 0 && t1 != 0) {
                        printf("+");
                        t1++;
                    }
                    flag = 1;
                    if (it->second == -1) {
                        printf("-");
                    } else {
                        printf("%lld", it->second);
                    }
                    p = 1;
                    t1++;
                }
                if (it->first != 0) {
                    if (flag == 0) {
                        if (it->second > 0 && t1 != 0) {
                            printf("+");
                            t1++;
                        }
                    }
                    if (it->first != 1) {
                        printf("x^%d", it->first);
                        t1++;
                    } else {
                        printf("x");
                        t1++;
                    }
                    p = 1;
                }
            }
        }
        if (p == 0 && zero == 0) {
            printf("0");
        }
        printf("\n");
    }

    return 0;
}