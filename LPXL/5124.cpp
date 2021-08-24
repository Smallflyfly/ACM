#include <stdio.h>
#include <string.h>

#define max(a, b) a > b ? a : b

#define INF -0x7fffffff

long c[2001], v[2001], dp[50001];

int main() {
    int T;
    long V, m;
    scanf("%d", &T);
    while(T--) {
        scanf("%d %d", &m, &V);
        memset(c, 0, sizeof(c));
        memset(v, 0, sizeof(v));
        memset(dp, 0, sizeof(dp));
        for (int i=0; i<m; i++) {
            scanf("%d %d", &v[i], &c[i]);
        }
        for(long i=0; i<V; i++) {
            dp[i] = INF;
        }
        dp[0] = 0;
        for(int i=0; i<m; i++) {
            for(long j=v[i]; j<=V; j++) {
                dp[j] = max(dp[j], dp[j-v[i]]+c[i]);
            }
        }
        if(dp[V] > 0) {
            printf("%ld\n", dp[V]);
        } else {
            printf("NO\n");
        }
    }
    return 0;
}
