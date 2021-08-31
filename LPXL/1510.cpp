#include <stdio.h>
#include <string.h>

int n;
int g[101][101];
int visit[101];

void DFS(int p) {
    if (p == n-1) {
        return;
    }
    for (int i=1; i<n; i++) {
        if (!visit[i] && g[p][i]) {
            printf("-%d", i+1);
            visit[i] = 1;
            DFS(i);
        }
    }
    return;
}

int main() {
    while(scanf("%d", &n) != EOF) {
        memset(g, 0, sizeof(g));
        memset(visit, 0, sizeof(visit));
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                scanf("%d", &g[i][j]);
            }
        }
        printf("1");
        visit[0] = 1;
        DFS(0);
        printf("\n");

    }
}
/**

1-3-6-5-4-7-2-8-9-13-10-11-18-14-12-15-17-20-19-16-25-22-26-2
1-3-6-5-4-7-2-8-9-13-10-11-18-14-12-15-17-20-19-16-25-22-26-2

1-2-3-8-6-7-5-4-9-10-14-12-13-11-16-15-18-20-17-19
1-2-3-8-6-7-5-4-9-10-14-12-13-11-16-15-18-20-19-17

1-6-4-3-2-5-8-12-7-9-13-10-14-11-17-19-16-15-18-21-27-22-23-2
1-6-4-3-2-5-8-12-7-9-13-10-14-11-17-19-16-15-18-21-27-22-23-2

1-2-4-3-6-5-10-9-7-11-12-8-17-14-15-13-16-18-19-20-22-21-23-2
1-2-4-3-6-5-10-9-7-11-12-8-17-14-15-13-16-18-19-20-22-21-23-2

**/