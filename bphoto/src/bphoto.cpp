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

class FenwickTree{
private: vi ft;
public: FenwickTree(int n) {ft.assign(n + 1, 0); }
	int rsq(int b) {
		int sum = 0;
		for (; b; b -= (b & (-b))) sum += ft[b];
		return sum;
	}
	void adjust(int k, int v) {
		for (; k < (int)ft.size(); k += (k & (-k))) ft[k] += v;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ifstream fin;
	ofstream fout;
	fin.open("bphoto.in");
	fout.open("bphoto.out");
	int N;
	fin >> N;
	vi nums;
	map<int, int> indices;
	for (int i = 0; i < N; i++) {
		int temp;
		fin >> temp;
		nums.push_back(temp);
	}
	vi sortedNums(nums.begin(), nums.begin() + N);
	sort(sortedNums.begin(), sortedNums.end(), greater<int>());
	for (int i = 0; i < N; i++) {
		indices[sortedNums[i]] = i;
	}
	FenwickTree ft(N);
	int ans = 0;
	for (int i = 0; i < N; i++) {
		int li = ft.rsq(indices[nums[i]] + 1);
		int ri = indices[nums[i]] - li;
		ft.adjust(indices[nums[i]] + 1, 1);
		if ((li * 2 < ri) || (ri * 2 < li)) ans++;
	}
	fout << ans << endl;
	fin.close();
	fout.close();
}
