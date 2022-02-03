#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>
#include<queue>

using namespace std;

double getDistance(int x, int y, int nx, int ny) {
	double dx = (x - nx)*(x - nx);
	double dy = (y - ny)*(y - ny);

	return sqrt(dx + dy);
}

int main() {
	int n = 0;
	double answer = 0;
	scanf("%d", &n);

	vector<pair<double, double>> pos;

	for (int i = 0; i < n; i++) {
		double a, b;
		scanf("%lf%lf", &a, &b);
		pos.push_back({ a,b });
	}

	vector<pair<int, double>> edge[110];

	for (int i = 0; i < n; i++) {
		double x = pos[i].first;
		double y = pos[i].second;

		for (int j = i + 1; j < n; j++) {
			double nx = pos[j].first;
			double ny = pos[j].second;
			double dist = getDistance(x, y, nx, ny);

			edge[i].push_back({ j,dist });
			edge[j].push_back({ i,dist });
		}
	}

	priority_queue<pair<double, int>> pq;
	int visit[110] = { 0, };

	int len = edge[0].size();
	for (int i = 0; i < len; i++) {
		int nx = edge[0][i].first;
		double dist = edge[0][i].second;

		pq.push({ (-1)*dist, nx });//절댓값이 큰 순으로 정렬해야 하기 때문
	}//0번 별부터 시작
	visit[0] = true;

	while (!pq.empty()) {
		double dist = (-1)*pq.top().first;
		int x = pq.top().second;
		pq.pop();

		if (!visit[x]) {
			visit[x] = true;
			answer += dist;

			int len = edge[x].size();
			for (int i = 0; i < len; i++) {
				int nx = edge[x][i].first;
				double nd = edge[x][i].second;

				if (!visit[nx]) pq.push({ (-1)*nd, nx });
			}
		}
	}

	printf("%.2lf\n", answer);
	
}


/*
4386. 별자리 만들기
https://www.acmicpc.net/problem/4386

문제
도현이는 우주의 신이다. 이제 도현이는 아무렇게나 널브러져 있는 n개의 별들을 이어서 별자리를 하나 만들 것이다. 별자리의 조건은 다음과 같다.

별자리를 이루는 선은 서로 다른 두 별을 일직선으로 이은 형태이다.
모든 별들은 별자리 위의 선을 통해 서로 직/간접적으로 이어져 있어야 한다.
별들이 2차원 평면 위에 놓여 있다. 선을 하나 이을 때마다 두 별 사이의 거리만큼의 비용이 든다고 할 때, 별자리를 만드는 최소 비용을 구하시오.

입력
첫째 줄에 별의 개수 n이 주어진다. (1 ≤ n ≤ 100)

둘째 줄부터 n개의 줄에 걸쳐 각 별의 x, y좌표가 실수 형태로 주어지며, 최대 소수점 둘째자리까지 주어진다. 좌표는 1000을 넘지 않는 양의 실수이다.

출력
첫째 줄에 정답을 출력한다. 절대/상대 오차는 10-2까지 허용한다.

실수버전의 최소스패닝트리(MST)
두 별자리 사이의 거리는 피타고라스로
*/