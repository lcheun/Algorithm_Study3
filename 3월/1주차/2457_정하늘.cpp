#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>

using namespace std;

int startDay = 301, endDay = 1130;
int ans = 0;

bool cmp(pair<int, int> a, pair<int, int> b) {
	if (a.first == b.first) {
		return a.second < b.second;
	}
	else return a.first < b.first;
}

int main() {
	//ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n;
	scanf("%d", &n);

	vector <pair<int, int>> flowers;
	for (int i = 0; i < n; i++) {
		int startMonth, startDay, endMonth, endDay;
		scanf("%d%d%d%d", &startMonth, &startDay, &endMonth, &endDay);
		flowers.push_back({ startMonth * 100 + startDay, endMonth * 100 + endDay });
	}

	sort(flowers.begin(), flowers.end(), cmp);
	int max_ = 0;
	for (int i = 0; i < n; i++) {
		if (flowers[i].first >= flowers[i].second) continue;
		if (flowers[i].first > startDay) {
			startDay = max_;
			ans++;
			max_ = flowers[i].second;
		}
		else {
			max_ = max(max_, flowers[i].second);
		}	
		if (startDay > endDay) break;
	}

	if (startDay <= endDay) {
		if (flowers[n - 1].first <= startDay) {
			startDay = max_;
			ans++;
		}//마지막이 flowers[i].first <= startDay 일 때
	}

	if (startDay <= endDay) printf("0\n");
	else printf("%d\n", ans);
}


/*
2457. 공주님의 정원
https://www.acmicpc.net/problem/2457

문제
오늘은 공주님이 태어난 경사스러운 날이다. 왕은 이 날을 기념하기 위해 늘 꽃이 피어있는 작은 정원을 만들기로 결정했다.

총 N개의 꽃이 있는 데, 꽃은 모두 같은 해에 피어서 같은 해에 진다. 하나의 꽃은 피는 날과 지는 날이 정해져 있다. 예를 들어, 5월 8일 피어서 6월 13일 지는 꽃은 5월 8일부터 6월 12일까지는 꽃이 피어 있고, 6월 13일을 포함하여 이후로는 꽃을 볼 수 없다는 의미이다. (올해는 4, 6, 9, 11월은 30일까지 있고, 1, 3, 5, 7, 8, 10, 12월은 31일까지 있으며, 2월은 28일까지만 있다.)

이러한 N개의 꽃들 중에서 다음의 두 조건을 만족하는 꽃들을 선택하고 싶다.

공주가 가장 좋아하는 계절인 3월 1일부터 11월 30일까지 매일 꽃이 한 가지 이상 피어 있도록 한다.
정원이 넓지 않으므로 정원에 심는 꽃들의 수를 가능한 적게 한다.
N개의 꽃들 중에서 위의 두 조건을 만족하는, 즉 3월 1일부터 11월 30일까지 매일 꽃이 한 가지 이상 피어 있도록 꽃들을 선택할 때, 선택한 꽃들의 최소 개수를 출력하는 프로그램을 작성하시오.

입력
첫째 줄에는 꽃들의 총 개수 N (1 ≤ N ≤ 100,000)이 주어진다. 다음 N개의 줄에는 각 꽃이 피는 날짜와 지는 날짜가 주어진다. 하나의 날짜는 월과 일을 나타내는 두 숫자로 표현된다. 예를 들어서, 3 8 7 31은 꽃이 3월 8일에 피어서 7월 31일에 진다는 것을 나타낸다.

출력
첫째 줄에 선택한 꽃들의 최소 개수를 출력한다. 만약 두 조건을 만족하는 꽃들을 선택할 수 없다면 0을 출력한다.
*/