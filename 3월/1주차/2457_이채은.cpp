#include    <stdio.h>
#include    <vector>
#include    <algorithm>

using namespace std;

int N, idx = -1, tmp, ans, fin = 301;
vector<pair<int, int>> flower;

int main(){
    scanf("%d", &N);

    int sm, sd, em, ed;
    for (int i = 0; i < N; ++i) {
        scanf("%d %d %d %d", &sm, &sd, &em, &ed);
        flower.push_back({ sm * 100 + sd, em * 100 + ed });
    }

    sort(flower.begin(), flower.end());

    bool flag;
    while (fin < 1131 && idx < N) {
        flag = false; idx++;
        for (int i = idx; i < N; ++i) {
            if (flower[i].first > fin) break;
            if (tmp < flower[i].second) {
                flag = true;
                tmp = flower[i].second;
                idx = i;
            }
        }

        if (!flag) {
            ans = 0; break;
        }
        
        fin = tmp;
        ans++;
    }
    
    printf("%d", ans);
}
