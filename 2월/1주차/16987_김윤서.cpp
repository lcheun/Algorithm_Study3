#include <iostream>
#include <algorithm>
using namespace std;

int n;
int dur[8];
int weight[8];

int solve(int target)
{
	if (target == n)
	{
		int sum = 0;
		for (int i = 0; i < n; ++i)
			if (dur[i] <= 0)
				sum++;

		return sum;
	}
	if (dur[target] <= 0)
		return solve(target + 1);
	
	bool check = false;
	int ret = 0;
	for (int cand = 0; cand < n; ++cand)
	{
		if (target == cand) continue;
		if (dur[cand] <= 0) continue;
		check = true;

		dur[target] -= weight[cand];
		dur[cand] -= weight[target];

		ret = max(ret, solve(target + 1));

		dur[target] += weight[cand];
		dur[cand] += weight[target];

	}
	if (!check)
	{
		return solve(target + 1);
	}
	return ret;
}
int main()
{
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> dur[i] >> weight[i];
	}

	cout << solve(0) << "\n";
}
/* [입력]
3
8 5
1 100
3 5
[출력] 
3
*/
