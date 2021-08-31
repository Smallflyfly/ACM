#include <stdio.h>
#include <string.h>

int n, m;
int uset[30001];
int rank[30001]; // Ê÷µÄ¸ß¶È/ÖÈ 

int find(int x) {
	while(uset[x] != x) {
		uset[x] = uset[uset[x]];
		x = uset[x];
	}
	return x;
}

void unions(int x, int y) {
	if ((x=find(x)) == (y=find(y))) return;
	if (rank[x] < rank[y]) {
		uset[x] = y;
	} else if (rank[x] > rank[y] ) {
		uset[y] = x;
	} else {
		uset[x] = y;
		rank[y]++;
	}
}

int main() {
	int k, root;
	int x;
	while(scanf("%d%d", &n, &m) != EOF) {
		if (n==0 && m==0) break;
		for (int i=0; i<n; i++) {
			uset[i] = i;
			rank[i] = 1; 
		}
		for(int i=0; i<m; i++) {
			scanf("%d%d", &k, &root);
			for(int j=0; j<k-1; j++) {
				scanf("%d", &x);
				unions(root, x);
			}
		}
		int sum = 1;
		for(int i=1; i<n; i++) {
			if(find(i) == find(0)) {
				sum++;
			}
		}
		printf("%d\n", sum);
	}	
	
	return 0;
}