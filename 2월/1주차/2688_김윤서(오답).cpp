#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int dp[640] = {0,}; // 0으로 초기화 

int main(){ 
	
	int T, n;  
	vector<int> dp_value;
	// 초기 세팅 
	dp[0] = 1; //dp[1]=1;
	for(int i=1; i<=10; i++){  
		dp[i] = i + dp[i-1]; // DP[1]~[10] 두자리수일 경우
		for(int j=1; j<=i; j++){
			dp[10+i] += dp[j];  // DP[11]~[20] 세자리수일 경우
		}
	}
	for(int i=21; i<50; i++) { // 그 이상
		dp[i] = dp[i-1] + dp[i-11];
	}
	cin>>T;
	for(int i=0; i<T; i++){
		cin>>n;
		dp_value.push_back(dp[(n-1) * 10]);
	}
	for(int i=0; i<T; i++){
		cout<<dp_value[i]<<endl;
	}

	return 0;
}

/* [입력]
3
2
3
4

[출력] (오답)
55
220
770
*/
