//https://www.acmicpc.net/problem/2157
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define MAX 4005
using namespace std;

//도시 개수 N, 도시개수 최댓값 M, 항공로개수 K 
int n,m,k, ans;
//목적지(dest), 기내식점수(weight)를 [src]번째 벡터에 pair로 저장 
vector<vector<pair<int, int>>> adj; 

int dp[301][301];

int main() {
	
	scanf("%d %d %d", &n,&m,&k);  
	adj.resize(n+1);
	
	for(int i=0; i<k; ++i){
		int src, dest, weight;
		scanf("%d %d %d", &src, &dest, &weight); //출발지, 목적지, 기내식점수 
		if(src > dest) continue;
		adj[src].push_back({dest, weight}); //목적지(dest), 기내식점수(weight)를 [src]번째 벡터에 pair로 저장 
	}
	//시작점 노드 정보 
	for(int i=0; i<adj[1].size(); ++i){
		int next = adj[1][i].first; //노드 번호
		int weight = adj[1][i].second; //기내식 점수
		dp[next][2] = max(dp[next][2].weight); //
	}
	//2번째 끝까지의 노드 정보 저장 
	for(int i=2; i<=m; ++i){
		for(int cur=1; cur<=n; ++cur){
			if(dp[cur][i] != 0){
				for(int j=0; j<adj[cur].size()); ++j){
					int next = adj[cur][i].first;
					int weight = adj[cur][i].second; //기내식 점수
					
					dp[next][i+1] = max(dp[next][i+1], dp[cur][i] + weight);
				}
			}
		}
	}
	for(int i=2; i<=m; ++i) ans = max(ans, dp[n][i]); //최댓값 찾기 
	cout<<ans;
	
	return 0;
}
