//
// Created by smallflyfly on 2021/8/13.
//

#include <stdio.h>
#include <string.h>
#include <queue>

int n, m;
int map[1001][1001];
int visit[1001];

using namespace std;

void BFS(int x) {
    queue<int> que;
    que.push(x);
    while (!que.empty()) {
        int e = que.front();
        que.pop();
        for (int i = 1; i <= n; ++i) {
            if (visit[i] == 0 && map[e][i] == 1) {
                visit[i] = 1;
                que.push(i);
            }
        }
    }
}

int main() {

    int a, b;
    while (scanf("%d %d", &n, &m) != EOF) {
        memset(map, 0, sizeof(map));
        memset(visit, 0, sizeof(visit));
        int total = 0;
        for (int i = 0; i < m; ++i) {
            scanf("%d %d", &a, &b);
            if (map[a][b] == 0 && a>=1 && a<=n && b>=1 && b<=n) {
                total ++;
            }
            map[a][b] = 1;
            map[b][a] = 1;
        }
        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            if (visit[i] == 1) {
                continue;
            }
            ans ++;
            visit[i] = 1;
            BFS(i);
        }
        int nt = total;
        int ng = ans;
        int ns = n - 1 - (ng - 1);
//        printf("%d %d %d\n", nt, ng, ns);
        printf("%d\n", nt - ns);
    }

    return 0;
}