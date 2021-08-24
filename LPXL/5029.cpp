//
// Created by smallflyfly on 2021/8/23.
//

#include <stdio.h>
#include <string.h>
#include <queue>

using namespace std;

int status[101];
int visit[101];
int n;

void BFS() {
    queue<int> que;
    que.push(0);
    visit[0] = 1;
    queue<pair<int, int*>> printQ;
    while (!que.empty()) {
        int t = que.front();
        que.pop();
        for (int i = 0; i < n; ++i) {
            if (!visit[i]) {

            }
        }
    }
}

int main() {
    while (scanf("%d", &n) != EOF) {
        for (int i = 0; i < n; ++i) {
            status[i] = 1;
        }
        BFS();
    }
}