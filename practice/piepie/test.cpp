#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using ii = pair<int, int>;
using vii = vector<ii>;

#define pb push_back
#define rsz resize
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

#define mp make_pair

#define LSOne(S) (S & (-S))

const int INF = 1061109567;

void setIO(string name) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((name+".in").c_str(), "r", stdin); 
    //freopen((name+".out").c_str(), "w", stdout);
}

const int mxN = 1e5 + 5;

int N, D;
int B[mxN], E[mxN];

int BPos[mxN], EPos[mxN];

vi adjList[mxN];

bool bCompare(const int& a, const int& b) {
    return B[a] < B[b];
}
bool eCompare(const int& a, const int& b) {
    return E[a] < E[b]; 
}

bool bFind(const int& a, const int& b) {
    return B[BPos[a]] < B[BPos[b]];
}
bool eFind(const int& a, const int& b) {
    return E[EPos[a]] < E[EPos[b]];
}

map<int, int> t;

int main () {
    for (int i = 0; i < 10; i++) {
        t.insert(ii(10 - i, i));
    }    
    map<int, int>::iterator itlow = t.lower_bound(7);
    cout << itlow -> first << " " << itlow -> second << endl;
}
