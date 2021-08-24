//
// Created by smallflyfly on 2021/8/19.
//

#include <stdio.h>
#include <string.h>

#define MAX_COST 0x7ffffff

int n, m;
int g[2001][2001];
int dist[2001];
int visit[2001];

int main() {
    int p, u, v, w;
    while (scanf("%d %d", &n, &m) != EOF) {
        memset(g, 0, sizeof(g));
        memset(dist, 0, sizeof(dist));
        memset(visit, 0, sizeof(visit));
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                g[i][j] = MAX_COST;
            }
        }
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            scanf("%d %d %d %d", &p, &u, &v, &w);
            if (p == 1) {
                ans += w;
                g[u][v] = 0;
                g[v][u] = 0;
            } else {
                if (w < g[u][v]) {
                    g[u][v] = w;
                    g[v][u] = w;
                }
            }
        }
        for (int i = 1; i <= n; ++i) {
            dist[i] = g[i][1];
        }
        int index = 1;
        visit[index] = 1;
        for (int i = 1; i < n; ++i) {
            int min = MAX_COST;
            for (int j = 1; j <= n; ++j) {
                if (!visit[j] && min > dist[j]) {
                    min = dist[j];
                    index = j;
                }
            }
            visit[index] = 1;
            ans += min;
            for (int j = 2; j <= n; ++j) {
                if (g[index][j] < dist[j]) {
                    dist[j] = g[index][j];
                }
            }
        }
        printf("%d\n", ans);
    }
}