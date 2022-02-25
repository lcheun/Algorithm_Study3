#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> dp(100001);

int main(){
	int n, fn, cnt=0;
	vector<int> answer;
	
	// dp 테이블 세팅 
	dp[0] = 0; 
	dp[1] = 1;
	for(int i=2; i<=40; i++){
		dp[i] = dp[i-1] + dp[i-2];
	}
	cin>>n;
	for(int i=0; i<n; i++){
		scanf("%d", &fn);
		answer.push_back(find(dp.begin()+2, dp.end(), fn) - dp.begin());
		cnt++;
	}
	for(int i=0; i<cnt; i++){
		printf("%d\n", answer[i]);
	}

	return 0;
}
