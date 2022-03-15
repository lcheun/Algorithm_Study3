#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

int N, M, ans = 100000000, chk[3];
vector<int> graph[4001];

void select(int num, int cnt) {
    chk[cnt] = num;

    if (cnt == 2) {
        if (find(graph[chk[2]].begin(), graph[chk[2]].end(), chk[0]) == graph[chk[2]].end()) return;

        int tmp = 0;
        for (int i = 0; i < 3; i++) 
            tmp += graph[chk[i]].size();

        ans = min(ans, tmp - 6);
        return;
    }

    for (int p : graph[num]) {
        if (p < num) continue;
        select(p, cnt + 1);
    }
}

int main() {
    scanf("%d %d", &N, &M);
    for (int i = 0; i < M; i++) {
        int A, B;
        scanf("%d %d", &A, &B);
        graph[A].push_back(B);
        graph[B].push_back(A);
    }
    for (int i = 1; i < N; i++) {
        select(i, 0);
    }
    if (ans == 100000000) printf("-1");
    else printf("%d", ans);
}
