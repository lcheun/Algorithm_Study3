#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isPeak=true;
int N,M;
int farm[100][70]; // n의 범위가 1부터 100까지, M이 1부터 70이므로 최대로 배열을 잡는다
bool visited[100][70] = {false, }; //방문했는지 여부 체크하는 배열 
int dy[] = {1,1,1,0,0,-1,-1,-1};
int dx[] = {-1,0,1,-1,1,-1,0,1};
void DFS(int y, int x){
	int ny,nx;
	for(int i=0; i<8; i++){
		ny = y+dy[i];
		nx = x+dx[i];
		//범위 벗어난 경우 
		if(ny<0 || ny>=N || nx<0 || nx>=N) continue;
		// 주변에 더 높은 봉우리가 있는 경우 
		if(farm[y][x] < farm[ny][nx]) isPeak = false; 
		// 이미 방문했거나, 해당 노드인 경우 
		if(visited[ny][nx] || farm[y][x] != farm[ny][nx]) continue;
		
		visited[ny][nx] = true; //방문 처리
		DFS(ny,nx);
	}
	// 8번 다 처리해서 isPeak이 true이면, 봉우리인 것이므로 cnt++ (이건 메인에서) 
}
int main(){
	int cnt=0;
	cin>>N>>M; 
	for(int i=0; i<N; i++) {
		for(int j=0; j<M; j++){
			scanf("%d", &farm[i][j]);
		}
	}
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			if(!visited[i][j]) {
				isPeak= true;
				DFS(i,j); // i,j를 모두 넣어주면서 옆으로 이동한다 
				if(isPeak) cnt++;
			}
		}
		cout<<cnt;
	}
	return 0;
}
