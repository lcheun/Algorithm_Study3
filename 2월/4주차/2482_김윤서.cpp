#include <iostream> 
using namespace std; 
int n, k; 
int dp[1002][1002]; 
int main() { 
  cin >> n >> k; 
  for(int i = 0; i <=n ; i++) 
    dp[i][0] = 1; 
  dp[1][1] = 1; 
  for(int i = 2; i <= n; i++) { 
    for(int j = 1; 2 * j <= i + 1; j++) { 
      dp[i][j] = (dp[i-2][j-1] + dp[i-1][j]) % 1000000003; 
    } 
  } 
  cout << (dp[n-3][k-1] + dp[n-1][k]) % 1000000003; 
  return 0; 
}
