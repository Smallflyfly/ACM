//
// Created by fangpc on 2021/8/12.
//

#include <stdio.h>
#include <string.h>
#include <queue>
#include <map>

#define min(a, b) a < b ? a : b;

using namespace std;

int minStep;

int dirX[5] = {0, 1, 0, -1};
int dirY[5] = {1, 0, -1, 0};
int ex, ey;
int n, m;
char mp[101][101];
int visit[101][101];
int sx, sy;

struct node {
    int x, y;
};

void BFS() {
    queue<pair<node, int>> qu;
    node nd;
    nd.x = sx;
    nd.y = sy;
    pair<node, int> pr(nd, 0);
    qu.push(pr);
    visit[sx][sy] = 1;
    int step = 0;
    while (!qu.empty()) {
        node nowNode = qu.front().first;
        step = qu.front().second;
        qu.pop();
        if (nowNode.x == ex && nowNode.y == ey) {
            minStep = step;
            break;
        }
        for (int i = 0; i < 4; ++i) {
            int dx = nowNode.x + dirX[i];
            int dy = nowNode.y + dirY[i];
            if (dx >= 0 && dx < n && dy >= 0 && dy < m && mp[dx][dy] != '#' && visit[dx][dy] == 0) {
                visit[dx][dy] = 1;
                node nextNode;
                nextNode.x = dx, nextNode.y = dy;
                qu.push(pair<node, int>(nextNode, step+1));
            }
        }
    }
}

void DFS(int x, int y, int step) {
    if (x == ex && y == ey) {
        minStep = min(minStep, step);
        return;
    }
    for (int i = 0; i < 4; ++i) {
        int dx = x + dirX[i];
        int dy = y + dirY[i];
        if (dx >= 0 && dx < n && dy >= 0 && dy < m && mp[dx][dy] != '#' && visit[dx][dy] == 0) {
            visit[dx][dy] = 1;
            DFS(dx, dy, step+1);
            visit[dx][dy] = 0;
        }
    }
    return;
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &m);
        memset(mp, '\0', sizeof(mp));
        memset(visit, 0, sizeof(visit));
        minStep = 999999;
        for (int i = 0; i < n; ++i) {
            scanf("%s", &mp[i]);
            for (int j = 0; j < m; ++j) {
                if (mp[i][j] == 'S') {
                    sx = i, sy = j;
                }
                if (mp[i][j] == 'E') {
                    ex = i, ey = j;
                }
            }
        }
        // DFS
//        visit[sx][sy] = 1;
//        DFS(sx, sy, 0);
        BFS();
        if (minStep < 999999) {
            printf("%d\n", minStep);
        } else {
            printf("-1\n");
        }
    }

    return 0;
}