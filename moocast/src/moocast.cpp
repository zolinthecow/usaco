#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ii pair<int, int>
#define dd pair<double, double>
#define vi vector<ll>
#define vd vector<double>
#define vii vector<ii>
#define vdd vector<dd>
#define vs vector<string>
#define ll long long
#define INF 1000000000
#define MOD 1000000007

class UnionFind {                                // OOP style
private:
	vi p, rank, setSize;                           // vi p is the key part
	int numSets;
public:
	UnionFind(int N) {
		p.assign(N, 0); for (int i = 0; i < N; ++i) p[i] = i;
		rank.assign(N, 0);                           // optional speedup
		setSize.assign(N, 1);// optional feature
		numSets = N;// optional feature
	}

	int findSet(int i) {return (p[i] == i) ? i : (p[i] = findSet(p[i]));}
	bool isSameSet(int i, int j) {return findSet(i) == findSet(j);}

	int numDisjointSets() {return numSets;}      // optional
	int sizeOfSet(int i) {return setSize[findSet(i)];} // optional

	void unionSet(int i, int j) {
		if (isSameSet(i, j)) return;              // i and j are in same set
		int x = findSet(i), y = findSet(j);// find both rep items
		if (rank[x] > rank[y]) swap(x, y);// keep x 'shorter' than y
		p[x] = y;// set x under y
		if (rank[x] == rank[y]) ++rank[y];// optional speedup
		setSize[y] += setSize[x];// combine set sizes at y
		--numSets;// a union reduces numSets
	}
};

struct edge{
	int weight, first, second;
};

inline int dist(ii a, ii b) {return pow(a.first - b.first, 2) + pow(a.second - b.second, 2); }

bool edgeSort(edge a, edge b) {
	return a.weight < b.weight;
}

int main() {
	ifstream fin;
	ofstream fout;
	fin.open("moocast.in");
	fout.open("moocast.out");
	int N;
	fin >> N;
	vii cows;
	for (int i = 0; i < N; i++) {
		ii t;
		fin >> t.first >> t.second;
		t.first--, t.second--;
		cows.pb(t);
	}
	vector<edge> EdgeList;
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			int distance = dist(cows[i], cows[j]);
			edge t;
			t.first = i, t.second = j, t.weight = distance;
			EdgeList.pb(t);
		}
	}
	sort(EdgeList.begin(), EdgeList.end(), edgeSort);
	int edgesUsed = 0, on = 0, ans;
	UnionFind UF(N);
	while (edgesUsed != N - 1) {
		edge i = EdgeList[on];
		if (!UF.isSameSet(i.first, i.second)) {
			UF.unionSet(i.first, i.second);
			edgesUsed++;
			ans = i.weight;
		}
		on++;
	}
	fout << ans << endl;
	fin.close();
	fout.close();
}
