#include <stdio.h>
#include <stdlib.h>

int A, B;

int calc_total() {
    if (A <= 200) {
        return A / 2;
    }
    else if (A <= 29900) {
        return (A - 200) / 3 + 100;
    }
    else if (A <= 4979900) {
        return (A - 29900) / 5 + 10000;
    }
    else {
        return (A - 4979900) / 7 + 1000000;
    }
}

int calc_price(int w) {
    if (w <= 100) {
        return w * 2;
    }
    else if (w <= 10000) {
        return 200 + (w - 100) * 3;
    }
    else if (w <= 1000000) {
        return 200 + 29700 + (w - 10000) * 5;
    }
    else {
        return 200 + 29700 + 4950000 + (w - 1000000) * 7;
    }
}

int main() {
    while (true) {
        scanf("%d %d", &A, &B);
        if (A == 0 && B == 0) break;
        int val = calc_total(), l = 0, r = val / 2, mid = r / 2;
        while (l <= r) {
            mid = (l + r) / 2;

            int s = calc_price(mid), n = calc_price(val - mid);
            int diff = abs(s - n);
            if (diff < B) {
                r = mid - 1;
            }
            else if (diff > B) {
                l = mid + 1;
            }
            else {
                printf("%d\n", s);
                break;
            }
        }
    }
}
