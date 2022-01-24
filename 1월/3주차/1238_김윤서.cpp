#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>

using namespace std;

vector<pair<int, int> > v[1001];
int dist[1001];
int time[1001];
			
void dijkstra(int start) {
	priority_queue<pair<int, int> > pq;
	dist[start] = 0;
	pq.push(make_pair(0, start));
			
	while (pq.empty() == 0) {
		int cost = -pq.top().first;
		int s = pq.top().second;
		pq.pop();
			
		for (auto each : v[s]) {
			int next = each.first;
			int nextCost = each.second;
			
			if (dist[next] > cost + nextCost) {
				dist[next] = cost + nextCost;
				pq.push(make_pair(-dist[next], next));
			}
		}
	}
}
int main(){ 
	int n, m, x;
	scanf("%d %d %d", &n, &m, &x);

	for (int i = 0; i < m; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		v[a].push_back({ b,c });
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) dist[j] = 1234567890; //초기화
		dijkstra(i); // 출발지에서 각 도착지 x로 가는 시간
		time[i] = dist[x];
	}

	for (int i = 1; i <= n; i++) dist[i] = 1234567890;

	dijkstra(x); //도착지 x에서 출발지로 가는 시간
	for (int i = 1; i <= n; i++) {
		time[i] += dist[i];
	}

	sort(time + 1, time + n + 1);
	printf("%d\n", time[n]);

	return 0;
}
