#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){ 
	Solution ottl;
	int n,k,sum;
	int front, back;
	vector<int> children;
	cin>>n>>k;
	
	cin>>back; //첫번째 원소 받기 
	for(int i=1; i<n; i++){
		front = back; // 뒤로 한 칸씩 밀기 
		cin>>back;
		children.push_back(back-front); // 인접한 값끼리의 차이를 저장함  
	}
	//차이가 가장 작은 n-k 개를 골라낸다 
	sort(children.begin(), children.end()); // 정렬 후
	for(int i=0; i<n-k; i++){
		sum += children[i];  //앞에서 n-k개만큼 뽑아서 더함
	}
	cout<<sum;
	return 0;
}
