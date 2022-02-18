#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>


using namespace std;

int n, m, ans;
int map[110][80], visit[110][80];
int dx[8] = { 1,1,1,0,0,-1,-1,-1 };
int dy[8] = { 1,0,-1,1,-1,1,0,-1 };

bool bfs(int a, int b) {
	bool isPeaks = true;
	queue<pair<int, int>> q;
	q.push({ a,b });
	visit[a][b] = true;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 8; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx > 0 && nx <= n && ny > 0 && ny <= m) {
				if (!visit[nx][ny] && map[nx][ny] == map[x][y]) {
					q.push({ nx,ny });
					visit[nx][ny] = true;
				}//같은 높은 위치인 경우, 주변도 높이를 비교해야 하기 때문에 큐에 삽입
				else if(map[nx][ny] > map[x][y]){
					isPeaks = false;
				}//봉우리가 아니면
			}
		}
	}
	return isPeaks;
}


int main() {
	scanf("%d%d", &n, &m);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (!visit[i][j] && map[i][j] > 0) {
				if (bfs(i, j)) {
					ans++;
				}
				
			}
		}
	}
	printf("%d\n", ans);
}


/*
1245. 농장 관리
https://www.acmicpc.net/problem/1245

문제
농부 민식이가 관리하는 농장은 N×M 격자로 이루어져 있다. 민식이는 농장을 관리하기 위해 산봉우리마다 경비원를 배치하려 한다. 이를 위해 농장에 산봉우리가 총 몇 개 있는지를 세는 것이 문제다.

산봉우리의 정의는 다음과 같다. 산봉우리는 같은 높이를 가지는 하나의 격자 혹은 인접한 격자들의 집합으로 이루어져 있다. (여기서 "인접하다"의 정의는 X좌표 차이와 Y좌표 차이 모두 1 이하일 경우로 정의된다.) 또한 산봉우리와 인접한 격자는 모두 산봉우리의 높이보다 작아야한다.

문제는 격자 내에 산봉우리의 개수가 총 몇 개인지 구하는 것이다.

입력
첫째 줄에 정수 N(1 < N ≤ 100), M(1 < M ≤ 70)이 주어진다. 둘째 줄부터 N+1번째 줄까지 각 줄마다 격자의 높이를 의미하는 M개의 정수가 입력된다. 격자의 높이는 500보다 작거나 같은 음이 아닌 정수이다.

출력
첫째 줄에 산봉우리의 개수를 출력한다.
*/