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

struct boot{
	int first, second, i;
};

vi tiles;
vector<boot> boots;

bool tilesSort(int a, int b) {
	return tiles[a] > tiles[b];
}

bool bootSort(boot a, boot b) {
	return a.first > b.first;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ifstream fin;
	ofstream fout;
	fin.open("snowboots.in");
	fout.open("snowboots.out");
    int N, B;
    fin >> N >> B;
    tiles.resize(N);
    vi tilesMax;
    for (int i = 0; i < N; i++) {
    	fin >> tiles[i];
    	tilesMax.pb(i);
    }
    sort(tilesMax.begin(), tilesMax.end(), tilesSort);
    vi bootNum;
    for (int i = 0; i < B; i++) {
    	boot t;
    	fin >> t.first >> t.second;
    	t.i = i;
    	boots.pb(t);
    }
    sort(boots.begin(), boots.end(), bootSort);
    vi next(N), prev(N);
    for (int i = 0; i < N; i++) {
    	next[i] = i + 1;
    	prev[i] = i - 1;
    }
    vi ans(B, 0);
    int maxDist = 1;
    int j = 0;
    int maxTile = tilesMax[j];
    for (int i = 0; i < N; i++) {
    	while (maxTile < N && tiles[maxTile] > boots[i].first) {
    		maxDist = max(maxDist, (int) (next[maxTile] - prev[maxTile]));
    		next[prev[maxTile]] = next[maxTile];
    		prev[next[maxTile]] = prev[maxTile];
    		j++;
    		maxTile = tilesMax[j];
    	}
    	if (boots[i].second >= maxDist) ans[boots[i].i] = 1;
    }
    for (auto it : ans) {
    	fout << it << endl;
    }
    fin.close();
    fout.close();
}
