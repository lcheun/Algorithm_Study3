#include <iostream>
using namespace std;

pair<int, int> dp[10001] = {{0,0}, }; //0의 개수, 1의 개수
void fibo(int n){
	dp[0] = {1,0};
	dp[1] = {0,1};
	for(int i=1; i<n; i++){
		dp[i+1].first = dp[i].first + dp[i-1].first;		
		dp[i+1].second = dp[i].second + dp[i-1].second;		
	}
}
int main() {
	int n;
	cin>>n; 
	for (int i = 0; i < n; i++) {
			int t;
			scanf("%d", &t); // t 입력받고
			fibo(t);
			printf("%d %d\n", dp[t].first, dp[t].second);
		}
}
