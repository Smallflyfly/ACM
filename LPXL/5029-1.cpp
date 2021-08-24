#include<stdio.h>
#include <algorithm>
#include<iostream>
#include<string.h>
#include<vector>
#include<stdlib.h>
#include<math.h>
#include<queue>
#include<deque>
#include<ctype.h>
#include<map>
#include<set>
#include<stack>
#include<string>
#include<algorithm>


#define gcd(a,b) __gcd(a,b)

int main()
{
    int n;
    int status[101];
    while (scanf("%d", &n) != EOF)
    {
        memset(status, 0, sizeof(status));
        printf("%d\n", n);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n-1; j++)
            {
                if (i != j) 
                {
                    status[j] = 1 - status[j];
                }
                printf("%d", status[j]);
            }
            printf("\n");
        }
    }
    return 0;
}