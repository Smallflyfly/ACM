//
// Created by fangpc on 2021/8/23.
//

#include <stdio.h>
#include <string.h>

#define MAX_VALUE 0x7fffffff

#define max(a, b) a > b ? a : b

int map[101][101];
int visit[101];
int dist[101];

int main() {
    int n, m;
    while (scanf("%d %d", &n, &m) != EOF) {
        memset(visit, 0, sizeof(visit));
        memset(map, 0, sizeof(map));
        memset(dist, 0, sizeof(dist));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                map[i][j] = map[j][i] = MAX_VALUE;
            }
        }
        int a, b, c;
        for (int i = 0; i < m; ++i) {
            scanf("%d %d %d", &a, &b, &c);
            if (map[a-1][b-1] > c)
                map[a-1][b-1] = map[b-1][a-1] = c;
        }
        for (int i = 1; i < n; ++i) {
            dist[i] = map[0][i];
        }
        dist[0] = 0;
        visit[0] = 1;
        int index = 0;
        for (int i = 1; i < n; ++i) {
            int minDist = MAX_VALUE;
            for (int j = 0; j < n; ++j) {
                if (!visit[j] && minDist > dist[j]) {
                    minDist = dist[j];
                    index = j;
                }
            }
            visit[index] = 1;
            for (int j = 0; j < n; ++j) {
                if (!visit[j] && map[index][j] < MAX_VALUE && dist[j] > map[index][j] + dist[index]) {
                    dist[j] = map[index][j] + dist[index];
                }
            }
        }
        int ans = -99999;
        for (int i = 1; i < n; ++i) {
            ans = max(ans, dist[i]);
        }
        if (ans == MAX_VALUE) {
            printf("-1\n");
        } else {
            printf("%d\n", ans);
        }
    }
    return 0;
}
