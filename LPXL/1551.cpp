 #include <stdio.h>
 #include <string.h>
 
 int uset[20001];
 int rank[20001];
 
 int n, m;
 
 int find(int x) {
 	while (x != uset[x]) {
	 	uset[x] = uset[uset[x]];
	 	x = uset[x];
	 }
	 return x;
 }
 
 void unions(int x, int y) {
 	if ((x=find(x)) == (y=find(y))) return;
 	if (rank[x] < rank[y]) {
	 	uset[x] = y;
	 } else if (rank[x] > rank[y]) {
 		uset[y] = x;
 	} else {
	 	uset[x] = y;
	 	rank[y]++;
	 }
 	
 }
 
 int main(int argc, char *argv[])
 {
 	int x, y;
	while(scanf("%d%d", &n, &m) != EOF) {
		for (int i=1; i<=n; i++) {
			uset[i] = i;
			rank[i] = 1;
		}
		for (int i=0; i<m; i++) {
			scanf("%d%d", &x, &y);
			unions(x, y);
		}
		int k;
		scanf("%d", &k);
		while(k--) {
			scanf("%d%d", &x, &y);
			if (find(x) == find(y)) {
				printf("Yes\n");
			} else {
				printf("No\n");
			}
		}
	}
 	return 0;
 }