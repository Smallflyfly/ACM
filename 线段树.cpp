#include<stdio.h>
#include<string.h>

const int N = 1000;

int a[] = {0, 1, 3, 5, 7, 9, 11};
int size = 6;

int tree[N] = {0};

void build(int a[], int tree[], int rt, int l, int r) {
	if (l == r) {
		tree[rt] = a[l];
	}
	else {
		int mid = (l + r) / 2;
		int left = 2 * rt;
		int right = 2 * rt + 1;
		build(a, tree, left, l, mid);
		build(a, tree, right, mid+1, r);
		
		tree[rt] = tree[left] + tree[right];
	}
}

void update(int a[], int tree[], int rt, int l, int r, int x, int val) {
	if(l == r) {
		a[x] = val;
		tree[rt] = val;
	}
 	else {
	 	int mid = (l + r) / 2;
	 	int left = 2 * mid;
	 	int right = 2 * mid + 1;
	 	if (x>=l && x<=mid){
	 		update(a, tree, left, l, mid, x, val);
	 	}
 	 	else {
	 	 	update(a, tree, right, mid+1, r, x, val);
	 	 }
	 	 
	 	 tree[rt] = tree[left] + tree[right];
	 }
}


int main() {
	build(a, tree, 1, 1, size);
	for(int i=1; i<=14; i++) {
		printf("tree[%d] = %d\n", i, tree[i]);
	}
	printf("#######################\n");
	update(a, tree, 1, 1, 6, 5, 10);
	for(int i=1; i<=14; i++) {
		printf("tree[%d] = %d\n", i, tree[i]);
	}
	return 0;
	
} 