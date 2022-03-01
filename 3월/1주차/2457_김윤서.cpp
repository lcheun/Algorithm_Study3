#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//꽃이 피는 날짜가 앞인 순으로 정렬
bool cmp(vector<pair<int, int>>& a, vector<pair<int, int>>& b) {
	if (a[0].first == b[0].first) {
		return a[0].second < b[0].second;
	}
	return a[0].first < b[0].first;
}

//날짜 비교 더 큰 날짜 return
pair<int, int> day_compare(pair<int, int>& a, pair<int, int>& b) {
	if (a.first < b.first)
		return b;
	else if(a.first == b.first){
		if (a.second < b.second)
			return b;
	}
	return a;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//입력
	int N;
	cin >> N;
	vector<vector<pair<int, int>>> day;
	for (int i = 0; i < N; i++) {
		int s_m, s_d, e_m, e_d;
		cin >> s_m >> s_d >> e_m >> e_d;
		vector<pair<int, int>> v;
		v.push_back(make_pair(s_m, s_d));
		v.push_back(make_pair(e_m, e_d));
		day.push_back(v);
	}

	sort(day.begin(), day.end(), cmp); //정렬

	int count = 0;
	pair<int, int> temp_s = { 3,1 }; //3월 1일
	pair<int, int> temp_e = { 12, 1 };
	pair<int, int> temp = { 1,1 };
	int check = 0;

	for (int i = 0; i < N; i++) {
		//기준 위치보다 빠를경우
		if (day_compare(temp_s, day[i][0]) == temp_s) {
			temp = day_compare(temp, day[i][1]);
			//11월 30일 이후
			if (day_compare(temp, temp_e) == temp) {
				check = 1;
				break;
			}
		}
		//기준 위치보다 이후일 때
		else {
			temp_s = temp; //기준 위치 temp로 변경
			count++; //종류 하나 증가
			//기준 위치보다 다음 꽃의 날짜가 앞에 있을 때 
			if (day_compare(temp_s, day[i][0]) == temp_s) {
				temp = day[i][1];
				//12월 1일보다 날짜가 뒤일 때
				if (day_compare(temp, temp_e) == temp) {
					check = 1;
					break;
				}
			}
			//기준 위치보다 다음 꽃의 날짜가 뒤에 있을 때 
			else
				break;
		}
	}

	if (check == 0)
		cout << "0"<<endl;
	else
		cout << count + 1 <<endl;


	return 0;
}
