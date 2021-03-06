#include<stdio.h>
#include<string.h>

const int maxN = 10000;
int a[maxN<<2], c[maxN<<2], lazy[maxN<<2];

int n, m;

void build(int rt, int l, int r) {
	if(l==r) {
		a[rt] = c[l];
		return;
	}
	int mid = (l + r) / 2;
	build(rt<<1, l, mid);
	build(rt<<1|1, mid+1, r);
	
	a[rt] = a[rt<<1] + a[rt<<1|1];
}

void update(int rt, int l, int r, int t) {
	a[rt] += (r - l + 1) * t;
	lazy[rt] += t;
	return;
}

void pushDown(int rt, int l, int r) {
	int mid = (l + r)/ 2;
	update(rt<<1, l, mid, lazy[rt]);
	update(rt<<1|1, mid+1, r, lazy[rt]);
	lazy[rt] = 0;
	return;
}

void modify(int rt, int l, int r, int start, int end, int t) {
	if(l>=start && r <= end) {
		a[rt] += (r-l+1) * t;
		lazy[rt] += t;
		return;
	}
	pushDown(rt, l, r);
	int mid = (l + r) / 2;
	if (start <= mid) modify(rt<<1, l, mid, start, end, t);
	if (end > mid) modify(rt<<1|1, mid+1, r, start, end, t);
	a[rt] = a[rt<<1] + a[rt<<1|1];
	return;
}

int query(int rt, int l, int r, int start, int end) {
	if(l>=start && r<=end) return a[rt];
	pushDown(rt, l, r);
	int mid = (l + r) / 2;
	if (start > mid) return query(rt<<1|1, mid+1, r, start, end);
	if (end <= mid) return query(rt<<1, l, mid, start, end);
	return query(rt<<1, l, mid, start, end) + query(rt<<1|1, mid+1, r, start, end);
}

int main(){
	while(scanf("%d%d", &n, &m) != EOF) {
		int flag, l, r;
		memset(a, 0, sizeof(a));
		memset(c, 0, sizeof(c));
		memset(lazy, 0, sizeof(lazy));
		for(int i=1; i<=n; i++) scanf("%d", &c[i]);
		build(1, 1, n);
		for(int i=0; i<m; i++) {
			scanf("%d%d%d", &flag, &l, &r);
			if(flag == 1) {
				// modify one element
				int t;
				scanf("%d", &t);
				modify(1, 1, n, l, r, t);
			}
			if (flag == 2) {
				int res = query(1, 1, n, l, r);
				printf("%d\n", res);
			}
		}
	}
	
	return 0;	
} 