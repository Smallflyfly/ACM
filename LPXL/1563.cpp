//
// Created by Smallflyfly on 2021/8/20.
//

#include <stdio.h>
#include <string.h>

#define MAX_COST 0x7fffffff

int g[2501][2501];
int n;
int visit[2501];
int dist[2501];

int main() {
    int c, ts, te;
    int a, b, e;
    while (scanf("%d %d %d %d", &n, &c, &ts, &te) != EOF) {
        memset(visit, 0, sizeof(visit));
        memset(dist, 0, sizeof(dist));
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <=n ; ++j) {
                g[i][j] = g[j][i] = MAX_COST;
            }
        }
        for (int k = 0; k < c; ++k) {
            scanf("%d %d %d", &a, &b, &e);
            if (g[a][b] > e) {
                g[a][b] = g[b][a] = e;
            }
        }
        for (int i = 1; i <n; ++i) {
            if (i == ts) continue;
            dist[i] = g[i][ts];
        }
        int index = ts;
        int ans = 0;
        for (int i = 1; i < n; ++i) {
            int min = MAX_COST;
            for (int j = 1; j <= n; ++j) {
                if(!visit[j] && min > dist[j]) {
                    min = dist[j];
                    index = j;
                }
            }
            ans += min;
            for (int j = 1; j <= n; ++j) {
                if (dist[j] > g[j][index]) {
                    dist[j] = g[j][index];
                }
            }
        }
        printf("%d\n", ans);
    }

    return 0;
}