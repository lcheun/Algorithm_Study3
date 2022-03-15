//https://www.acmicpc.net/problem/17089
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define MAX 4005
using namespace std;

vector<vector<int>> v(MAX); //각 인원이 가진 친구 관계 배열 
bool isFriend[MAX][MAX]; // [1][2]가 true이면 1과 2는 친구
bool visited[MAX];
int numOfFriend[MAX];

int ans = -1; //최종 결과(세 친구의 최솟값) 
 
void DFS(int x, int start, int cnt, int num) { //
	if(cnt == 3){ //???
		if(!isFriend[start][x]) return; //start랑 x가 친구가 아니면 더이상 보지않음
		int cnt = 0;
		if(ans != -1) ans = min(num-6, ans); //더 작은값이 나오면 갱신 
		else ans = num-6;
		return;
	}
	for(int i=0; i<numOfFriend[x]; i++){ //x의 친구 수만큼 반복 
		int next = v[x][i]; // 친구 탐색 
		if(visited[next]) continue; //이미 방문한 경우는 패스
		DFS(next, start, cnt +1, num + numOfFriend[next]);
		visited[next] = false;
	}
}
int main() {
	
	int N,M;
	cin>>N>>M;
	
	int a,b;
	for(int i=0; i<M; i++){
		cin>>a>>b;
		
		v[a].push_back(b);
		v[b].push_back(a); //a와 b의 친구관계
		
		isFriend[a][b] = true;
		isFriend[b][a] = true;
		
		numOfFriend[a]++;
		numOfFriend[b]++;
	}
	for(int i=1; i<=N; i++){
		if(visited[i]) continue; //방문 이미 했으면 패스 
		visited[i] = true; //방문 처리
		DFS(i, i, 1, numOfFriend[i]);
	}
	cout<<ans;
	
	return 0;
}
