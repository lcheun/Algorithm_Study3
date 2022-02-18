#include <stdio.h>

int fibonacci[41][2] = { {1,0}, {0,1}, 0, };
void set() {
    for (int i = 2; i < 41; i++) {
        fibonacci[i][0] = fibonacci[i - 1][0] + fibonacci[i - 2][0];
        fibonacci[i][1] = fibonacci[i - 1][1] + fibonacci[i - 2][1];
    }
}

int main() {
    int T;
    scanf("%d", &T);
    set();
    for (int i = 0; i < T; i++) {
        int n;
        scanf("%d", &n);
        printf("%d %d\n", fibonacci[n][0], fibonacci[n][1]);
    }
    return 0;
}
