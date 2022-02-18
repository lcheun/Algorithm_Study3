#include <iostream>
#include <algorithm>

using namespace std;
int n,L,R,x,ans=0;
int arr[15];
bool visit[15];

bool cmp(int a, int b) {
    return a>b;
}

void solve(int index, int cnt, int sum) {
    if(cnt>=2) {
        int maxnum, minnum;
// 문제 차이를 구하기 위해 오름차순/내림차순 해서 가장 끝에 있는 것을 구함
        for(int i=0 ; i<n ; i++) {  //오름차순 중 visit true인것
            if(visit[i] == true) {
                maxnum = arr[i];
                break;
            }
        }
        for(int i=n-1 ; i>=0 ; i--) { // 내림차순..
            if(visit[i] == true) {
                minnum = arr[i];
                break;
            }
        }
        if(sum >= L && sum <= R && (maxnum-minnum)>= x) { //조건 적용
            ans++;
        }
    }
    for(int i=index ; i<n ; i++) {
        visit[i] = true;
        solve(i+1, cnt+1, sum+arr[i]); //재귀로 다음 함수로 넘어감
        visit[i] = false;
    }
}

int main() {
    cin >> n >> L >> R >> x;
    for(int i=0 ; i<n ; i++) {
        int a;
        cin >> a;
        arr[i] = a;
    }
    
    sort(arr, arr+n, cmp);

    solve(0, 0, 0);
    

    cout << ans << "\n";

    return 0;
}
