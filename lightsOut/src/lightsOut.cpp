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
#define INF 10000000
#define MOD 100000000

struct point{
	int x, y;
};

struct vertex{
	point left, right, on;
	int angle, leftLen, rightLen;
	bool exit;
};

int main() {
	ifstream fin;
	ofstream fout;
	fin.open("lightsout.in");
	fout.open("lightsout.out");
	int N;
	cin >> N;
	vector<point> points(N);
	for (int i = 0; i < N; i++) {
		cin >> points[i].x >> points[i].y;
	}
	vector<vertex> vList;
	int perim = 0;
	for (int i = 0; i < N; i++) {
		int left = (i != 0) ? i - 1 : N - 1;
		int right = (i != N - 1) ? i + 1 : 0;
		vertex v;
		v.left = points[left], v.right = points[right], v.on = points[i];
		int angle;
		if (v.right.y == v.on.y) {
			if (v.right.x > v.on.x) angle = (v.left.y < v.on.y) ? 90 : 270;
			else 				 	angle = (v.left.y < v.on.y) ? 270 : 90;
		} else {
			if (v.right.y > v.on.y) angle = (v.left.x < v.on.x) ? 270 : 90;
			else 					angle = (v.left.x < v.on.x) ? 90 : 270;
		}
		v.angle = angle;
		v.leftLen = sqrt(pow(v.left.x - v.on.x, 2) + pow(v.left.y - v.on.y, 2));
		v.rightLen = sqrt(pow(v.right.x - v.on.x, 2) + pow(v.right.y - v.on.y, 2));
		v.exit = (i == 0) ? true : false;
		vList.pb(v);
		perim += v.leftLen;
	}
	vi lenToExit(N, 0);
	int currDist = 0;
	for (int i = 1; i < N; i++) {
		currDist += vList[i].leftLen;
		lenToExit[i] = min(currDist, perim - currDist);
	}
	vector<vertex> possiblePts;
	int ans = 0;
	for (int i = 1; i < N; i++) {
		possiblePts.clear(); possiblePts.insert(possiblePts.begin(), vList.begin(), vList.end());
		int on = i;
		int dist = 0;
		while (possiblePts.size() > 1 && on != 0) {
			int j = 0;
			while (j < (int) possiblePts.size()) {
				if (possiblePts[j].angle != vList[on].angle) possiblePts.erase(possiblePts.begin() + j);
				else 										j++;
			}
			on = (on == N - 1) ? 0 : on + 1;
			j = 0;
			while (j < (int) possiblePts.size()) {
				if (possiblePts[j].leftLen != vList[on].leftLen) possiblePts.erase(possiblePts.begin() + j);
				else 											 j++;
			}
			dist += vList[on].leftLen;
		}
		ans = max(ans, (int) (dist + lenToExit[on] - lenToExit[i]));
	}
	cout << ans << endl;
	fin.close();
	fout.close();
}
