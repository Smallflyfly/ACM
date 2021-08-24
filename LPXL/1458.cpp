#include <stdio.h>
#include <string.h>

#define MAX_VALUE 0x7fffffff

int price[1001][1001];
int weight[1001][1001];

int dist[1001];
int cost[1001];
int visit[1001];

int n;
int start, end;

int main()
{
    int m;
    while(scanf("%d %d", &n, &m) != EOF)
    {
        if (n == 0 || m == 0)
        {
            break;
        }
        memset(price, 0, sizeof(price));
        memset(weight, 0, sizeof(weight));
        memset(dist, 0, sizeof(dist));
        memset(cost, 0, sizeof(cost));
        memset(visit, 0, sizeof(visit));
        for (int i=0; i<n; i++)
        {
            for (int j=0; j<n; j++)
            {
                weight[i][j] = weight[j][i] = MAX_VALUE;
                price[i][j] = price[j][i] = MAX_VALUE;
            }
        }
        int a, b, d, p;
        for (int i = 0; i<m; i++)
        {
            scanf("%d %d %d %d", &a, &b, &d, &p);
            if (weight[a-1][b-1] > d)
            {
                weight[a-1][b-1] = weight[b-1][a-1] = d;
                price[a-1][b-1] = price[b-1][a-1] = p;
            }
            else if (weight[a-1][b-1] == d && price[a-1][b-1] > p) {
                price[a-1][b-1] = price[b-1][a-1] = p;
            }
        }
        scanf("%d %d", &start, &end);
        start -= 1;
        end -= 1;
        visit[start] = 1;
        for (int i=0; i<n; i++)
        {
            dist[i] = weight[start][i];
            cost[i] = price[start][i];
        }
        int index = start;
        for (int i=1; i<n; i++)
        {
            int minDist = MAX_VALUE;
            int minCost = MAX_VALUE;
            for (int j=0; j<n; j++)
            {
                if(!visit[j])
                {
                    if (minDist > dist[j])
                    {
                        minDist = dist[j];
                        minCost = cost[j];
                        index = j;
                    }
                    else if (minDist == dist[j] && minCost > cost[j])
                    {
                        minCost = cost[j];
                        index = j;
                    }
                }
            }
            visit[index] = 1;
            for (int j=0; j<n; j++)
            {
                if (!visit[j] && weight[index][j] < MAX_VALUE)
                {
                    if (dist[j] > weight[index][j] + dist[index])
                    {
                        dist[j] = weight[index][j] + dist[index];
                        cost[j] = price[index][j] + cost[index];
                    }
                    else if(dist[j] == weight[index][j] + dist[index] && cost[j] > price[index][j] + cost[index])
                    {
                        cost[j] = price[index][j] + cost[index];
                    }
                }
            }
        }
        printf("%d %d\n", dist[end], cost[end]);

    }

    return 0;

}

/**

6 6
1 2 1 2
1 4 2 2
2 3 3 3
3 5 10 5
3 6 5 10
4 6 4 5
1 6

**/
