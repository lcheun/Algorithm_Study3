#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

int N, M, X, ans;
vector<pair<int, int>> map[1001];
int dist[1001], res[1001];

void dijkstra(int node) {

    for (int i = 1; i <= N; i++) dist[i] = 123456789;
    dist[node] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({ 0, node });

    while (!pq.empty()) {
        auto p = pq.top(); pq.pop();

        if (p.first > dist[p.second]) continue;

        for (auto next : map[p.second]) {
            int ncost = p.first + next.first;

            if (ncost < dist[next.second]) {
                dist[next.second] = ncost;
                pq.push({ ncost, next.second });
            }
        }
    }
}

int main() {
    scanf("%d %d %d", &N, &M, &X);

    int s, e, t;
    for (int i = 0; i < M; i++) {
        scanf("%d %d %d", &s, &e, &t);
        map[s].push_back({ t, e });
    }

    for (int i = 1; i <= N; i++) {
        dijkstra(i);
        res[i] = dist[X];
    }

    dijkstra(X);

    for (int i = 1; i <= N; i++) {
        res[i] += dist[i];
        ans = max(ans, res[i]);
    }

    printf("%d", ans);
}
