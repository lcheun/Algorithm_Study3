/// 크루스칼 알고리즘을 이용한 최소 스패닝 트리(MST) 구현

#define INF 987654321
#define MAX 101
#define ll long long
using namespace std;

typedef pair<double, double> p;
bool cmp(pair<double, p > a, pair<double, p>  b) {
	return a.first < b.first;
}
struct DisjointSet {
	vector<int> parent, rank;
	DisjointSet(int n) : parent(n), rank(n + 1) {
		for (int i = 0; i < n; ++i)
			parent[i] = i;
	}
	int find(int u) {
		if (parent[u] == u)return u;
		return parent[u] = find(parent[u]);
	}

	void merge(int u, int v) {
		u = parent[u]; v = parent[v];
		if (u == v) return;
		if (rank[u] > rank[v]) swap(u, v);

		parent[u] = v;
		if (rank[u] == rank[v]) rank[v]++;
	}
};

int N; 
p cord[MAX];
// cost, node, node
vector<pair<double, p>> vc;
double dist(p a, p b) {
	return sqrt((a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second));
}

double kruskal() {
	double ret = 0;

	sort(vc.begin(), vc.end());
	DisjointSet sets(N + 1);

	for (int i = 0; i < vc.size(); ++i) {
		double cost = vc[i].first;
		int u = vc[i].second.first; int v = vc[i].second.second;
		if (sets.find(u) == sets.find(v)) continue;
		sets.merge(u, v);
		ret += cost;
	}
	return ret;
}
int main(){
	cin >> N;
	for (int i = 0; i < N; ++i)
		cin >> cord[i].first >> cord[i].second;


	for (int i = 0; i < N; ++i) 
		for(int j = i + 1; j <N;++j){
			vc.push_back({ dist(cord[i], cord[j]),{ i, j} });
	}
	
	cout << kruskal()<< endl;
	return 0;

}
