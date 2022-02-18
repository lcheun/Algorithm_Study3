#include <stdio.h>
using namespace std;

bool visited = {false, };
bool isPeak = true;
int N, M, ans, farm[100][70], visit[100][70];
int dy[] = { 1, 1, 1, 0, 0, -1, -1, -1 };
int dx[] = { 1, 0, -1, 1, -1, 1, 0, -1 };

void DFS(int y, int x){
	for(int i=0; i<8; i++){
		int ny = y + dy[i];
		int nx = x + dx[i];
		if( ny < 0 || ny >= N || nx < 0 || nx >= M ) continue;
		// 인접 칸에 더 높은 봉우리가 있는가?
		if( farm[y][x] < farm[ny][nx] ) isPeak = false;
		// 해당하는 산봉우리들을 탐색
		if( visited[ny][nx] || farm[y][x] != farm[ny][nx] ) continue;
		visited[ny][nx] = true;
		DFS(ny,nx);
	}
	return ;
}
int main(void){
	cin >> N >> M;
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			cin >> farm[i][j];
		}
	}
	int answer = 0;
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
		if(!visited[i][j] ){
			isPeak = true;
			DFS(i, j);
			if( isPeak ) answer += 1;
			}
		}
	}
	cout << answer ;
	return 0;
}
