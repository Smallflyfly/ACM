//
// Created by smallflyfly on 2021/8/19.
//

#include <stdio.h>
#include <string.h>
#include <queue>
#include <vector>
#include <map>

using namespace std;

int n;
int visit[100001];
map<int, vector<int>> nextMap;

int BFS(int c) {
    queue<pair<int, int>> que;
    pair<int, int> pa(c, 1);
    que.push(pa);
    visit[c] = 1;
    int h;
    while (!que.empty()) {
        pair<int, int> pt = que.front();
        que.pop();
        h = pt.second;
        int t = pt.first;
        vector<int> temp = nextMap[t];
        for (int i = 0; i < temp.size() ; ++i) {
            int x = temp[i];
            if (!visit[x]) {
                pair<int, int> pp(x, h+1);
                que.push(pp);
                visit[x] = 1;
            }
        }
    }
    return h;
}

int main() {
    int p, c;
    int m;
    int a, b;
    while (scanf("%d %d %d", &n, &p, &c) != EOF) {
        memset(visit, 0, sizeof(visit));
        scanf("%d", &m);
        for (int i = 0; i < p; ++i) {
            scanf("%d %d", &a, &b);
            if (nextMap.find(a) != nextMap.end()) {
                nextMap[a].push_back(b);
            } else {
                vector<int> temp;
                temp.push_back(b);
                nextMap.insert(pair<int, vector<int>>(a, temp));
            }
            if (nextMap.find(b) != nextMap.end()) {
                nextMap[b].push_back(a);
            } else {
                vector<int> temp;
                temp.push_back(a);
                nextMap.insert(pair<int, vector<int>>(b, temp));
            }
        }
        int h = BFS(c);
//        printf("%d\n", h);
        printf("%d\n", h+m);
    }

    return 0;
}
