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
#define INF 100000000000
#define MOD 1000000007

struct node{
	int id;
	vector<node*> children;
	bool isFile;
	ll down = 0;
	ll total = 0;
	int nameLen;
	int filesUnder = 0;
};

int N;

int fileAmt = 0;

vector<node> nodes;

void calcDownSum(int on) {
	nodes[on].filesUnder = (nodes[on].isFile) ? 1 : 0;
	for (auto it : nodes[on].children) {
		calcDownSum(it->id);
		nodes[on].filesUnder += nodes[it->id].filesUnder;
		nodes[on].down += nodes[it->id].down + nodes[it->id].filesUnder * (nodes[it->id].nameLen + ((!it->isFile) ? 1 : 0));
	}
}

void calcUpSum(int on, ll plen) {
	nodes[on].total = nodes[on].down + plen;

	ll plenadd = nodes[on].down;
	for (auto it : nodes[on].children) {
		calcUpSum(it->id, plen + plenadd - (nodes[it->id].down + nodes[it->id].filesUnder * (nodes[it->id].nameLen + ((!it->isFile) ? 1 : 0))) + 3 * (fileAmt - it->filesUnder));
	}
}

int main() {
	ifstream fin;
	ofstream fout;
	fin.open("dirtraverse.in");
	fout.open("dirtraverse.out");
	fin >> N;
	vector<vi> childTemp(N);
	for (int i = 0; i < N; i++) {
		node curr;
		string a;
		fin >> a;
		curr.id = i;
		curr.nameLen = a.length();
		int b;
		fin >> b;
		if (b == 0) {
			curr.isFile = true;
			fileAmt++;
		} else {
			curr.isFile = false;
			for (int j = 0; j < b; j++) {
				int c;
				fin >> c;
				c--;
				childTemp[i].pb(c);
			}
		}
		nodes.pb(curr);
	}
	for (int i = 0; i < N; i++) {
		for (auto it : childTemp[i]) {
			nodes[i].children.pb(&nodes[it]);
		}
	}
	calcDownSum(0);
	calcUpSum(0,0);
	ll ans = INF;
	for (int i = 0; i < N; i++) {
		ans = min(ans, nodes[i].total);
	}
	fout << ans << endl;
	fin.close();
	fout.close();
}
