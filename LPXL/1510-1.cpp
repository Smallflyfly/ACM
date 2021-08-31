#include <stdio.h>
#include <string.h>

int g[101][101];
int visit[101];
int n;

void DFS(int p, int node) {
	if (node == n) return;
	for (int i=1; i<=n; i++) {
		if (!visit[i] && g[p][i]) {
			printf("-%d", i);
			visit[i] = 1;
			DFS(i, node+1);
		}
	}
	return;
}

int main(int argc, char *argv[])
{
	while(scanf("%d", &n) != EOF) {
		memset(g, 0, sizeof(g));
		memset(visit, 0, sizeof(visit));
		for (int i=1; i<=n; i++) {
			for (int j=1; j<=n; j++) {
				scanf("%d", &g[i][j]);
			}
		}
		printf("1");
		visit[1] = 1;
		DFS(1, 1);
		printf("\n");
	}
	
	return 0;
}