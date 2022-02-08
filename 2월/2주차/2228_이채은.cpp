#include <stdio.h> 
#include <algorithm>

using namespace std; 

int N, M;
int arr[101], dp[101][51]; 

int calc(int a, int b) { 
	if (b == 0) return 0; 
	if (a <= 0) return -100000000; 
	if (dp[a][b] != -1) return dp[a][b]; 

	int sum = 0;

	dp[a][b] = calc(a - 1, b); 

	for (int i = a; i > 0; i--) {
		sum += arr[i];
		int tmp = calc(i - 2, b - 1) + sum; 
		dp[a][b] = max(tmp, dp[a][b]);
	} 

	return dp[a][b];
} 

int main() { 
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; i++) { 
		scanf("%d", &arr[i]);
		for (int j = 1; j <= N / 2; j++) { 
			dp[i][j] = -1;
		}
	}

	printf("%d\n", calc(N, M));
}
