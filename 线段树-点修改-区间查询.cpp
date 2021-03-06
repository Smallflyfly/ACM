#include <stdio.h>
#include <string.h>

#define min(a, b) a < b ? a : b
#define max(a, b) a > b ? a : b

const int maxN = 10001;

int tree[maxN<<2];
int c[maxN];
int lazy[maxN<<2];

int n;

void pushUp(int rt) {
	tree[rt] = tree[rt<<1] + tree[rt<<1|1];
	// tree[rt] = min(tree[rt<<1], tree[rt<<1|1]); // 维护区间最小值 
	// tree[rt] = max(tree[rt<<1], tree[rt<<1|1]); // 维护区间最大值 
}

void build(int rt, int l, int r) {
	if (l == r) {
		tree[rt] = c[l];
		return;
	}
	int mid = (l + r) / 2;
	build(rt<<1, l, mid);
	build(rt<<1|1, mid+1, r);
	pushUp(rt);
}

void set(int index, int t) {
	c[index] = t;
	memset(tree);
	// rebuild 
	build(1, 1, n);
} 

int main(){
	int m;
	while(scanf("%d%d", &n, &m) != EOF) {
		memset(tree, 0, sizeof(tree));
		memset(c, 0, sizeof(c));
		memset(lazy, 0, sizeof(lazy));
		for(int i=0; i<n; i++) scanf("%d", &c[i]);
		build(1, 1, n);
	}	
} 