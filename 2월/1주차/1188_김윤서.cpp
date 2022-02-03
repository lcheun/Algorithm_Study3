#include <iostream>
#include <algorithm>
#define SWAP(x,y) int tmp=x; x=y; y=tmp;
using namespace std;

int N, M;

int GCD(int x, int y) { 
	if (x % y == 0) return y;

	return GCD(y, x % y); 
}

int main() {
	scanf("%d %d", &N, &M);
	printf("%d", M - GCD(N, M)); // 자른 횟수
}
