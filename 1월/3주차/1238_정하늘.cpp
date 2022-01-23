#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>
#include<queue>

using namespace std;

vector< pair<int, int> > v[1001];
int dist[1001];
int time[1001];

void Dijkstra(int start) {
	priority_queue<pair<int, int>> pq;
	dist[start] = 0;
	pq.push(make_pair(0, start));

	while (pq.empty() == 0) {
		int cost = -pq.top().first;
		int s = pq.top().second;
		pq.pop();

		for (int i = 0; i < v[s].size(); i++) {
			int next = v[s][i].first;
			int nextCost = v[s][i].second;

			if (dist[next] > cost + nextCost) {
				dist[next] = cost + nextCost;
				pq.push(make_pair(-dist[next], next));
			}
		}
	}
}

int main() {
	//ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, m, x;
	scanf("%d%d%d", &n, &m, &x);

	for (int i = 0; i < m; i++) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		v[a].push_back({ b,c });
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) dist[j] = 1234567890;//초기화
		Dijkstra(i);//각 출발지에서 도착지 x 로 가는 시간
		time[i] = dist[x];
	}

	for (int i = 1; i <= n; i++) dist[i] = 1234567890;

	Dijkstra(x);//도착지 x 로부터 각각의 출발지로 가는 시간
	for (int i = 1; i <= n; i++) {
		time[i] += dist[i];
	}

	sort(time + 1, time + n + 1);
	printf("%d\n", time[n]);
}


/*
1238. 파티
https://www.acmicpc.net/problem/1238

문제
N개의 숫자로 구분된 각각의 마을에 한 명의 학생이 살고 있다.

어느 날 이 N명의 학생이 X (1 ≤ X ≤ N)번 마을에 모여서 파티를 벌이기로 했다. 이 마을 사이에는 총 M개의 단방향 도로들이 있고 i번째 길을 지나는데 Ti(1 ≤ Ti ≤ 100)의 시간을 소비한다.

각각의 학생들은 파티에 참석하기 위해 걸어가서 다시 그들의 마을로 돌아와야 한다. 하지만 이 학생들은 워낙 게을러서 최단 시간에 오고 가기를 원한다.

이 도로들은 단방향이기 때문에 아마 그들이 오고 가는 길이 다를지도 모른다. N명의 학생들 중 오고 가는데 가장 많은 시간을 소비하는 학생은 누구일지 구하여라.

입력
첫째 줄에 N(1 ≤ N ≤ 1,000), M(1 ≤ M ≤ 10,000), X가 공백으로 구분되어 입력된다. 두 번째 줄부터 M+1번째 줄까지 i번째 도로의 시작점, 끝점, 그리고 이 도로를 지나는데 필요한 소요시간 Ti가 들어온다. 시작점과 끝점이 같은 도로는 없으며, 시작점과 한 도시 A에서 다른 도시 B로 가는 도로의 개수는 최대 1개이다.

모든 학생들은 집에서 X에 갈수 있고, X에서 집으로 돌아올 수 있는 데이터만 입력으로 주어진다.

출력
첫 번째 줄에 N명의 학생들 중 오고 가는데 가장 오래 걸리는 학생의 소요시간을 출력한다.
*/