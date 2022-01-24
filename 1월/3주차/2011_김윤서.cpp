#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
	public:
		int countCase(int num){
			int cnt = 0;	
			if(num <10) return 1;
			if(num%100 < 26) return cnt+ countCase(num/100)+ countCase(num/10);		
			else return cnt + countCase(num/10);
		}
};
int main(){ 
	Solution ottl;
	int num;
	cin>>num;
	//if(isdigit(num)!=0) cout<<0; //숫자가 아닌 경우 
	cout << (ottl.countCase(num) % 1000000);	
	
	return 0;
}
