#include <stdio.h>

int N, M;

int GCD(int x, int y) {
	if (x % y == 0) return y;

	return GCD(y, x % y);
}

int main() {
	scanf("%d %d", &N, &M);
	printf("%d", M - GCD(N, M));
}
