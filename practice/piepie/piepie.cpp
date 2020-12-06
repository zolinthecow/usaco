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

int BPos[2 * mxN], EPos[2 * mxN];

int EHalf2[mxN], BHalf1[mxN];
int EHalfPos[mxN], BHalfPos[mxN];

vi adjList[2 * mxN];

bool bCompare(const int& a, const int& b) {
    return BHalf1[a] < BHalf1[b];
}
bool eCompare(const int& a, const int& b) {
    return EHalf2[a] < EHalf2[b]; 
}

int main () {
    setIO("piepie");	
    cin >> N >> D;
    for (int i = 1; i <= 2 * N; i++) {
        cin >> B[i] >> E[i];
        BPos[i] = i; EPos[i] = i;
        if (i <= N) {
            BHalf1[i] = B[i];
            BHalfPos[i] = i;
        } else {
            EHalf2[i - N] = E[i];
            EHalfPos[i - N] = i - N;
        }
    }
    sort(BHalfPos + 1, BHalfPos + N + 1, bCompare);
    sort(EHalfPos + 1, EHalfPos + N + 1, eCompare);
    for (int i = 1; i <= N; i++) cout << BHalf1[BHalfPos[i]] << " ";
    cout << "\n";
    cout << *lower_bound(BHalfPos + 1, BHalfPos + N + 1, 6, bCompare) << "\n";
    cout << EHalf2[*lower_bound(EHalfPos + 1, EHalfPos + N + 1, 5, eCompare)] << "\n";
    for (int i = 1; i <= N; i++) {
        int curE = 0;
        while (curE < N) {
            int pos = lower_bound(EHalfPos + curE + 1, EHalfPos + N + 1, E[i], eCompare) - EHalfPos;
            if (EHalf2[EHalfPos[pos]] > E[i] + D) break;
            adjList[pos + N].pb(i);
            curE = pos + 1;
        }
        int curB = 0;
        while (curB < N) {
            int pos = lower_bound(BHalfPos + curB + 1, BHalfPos + N + 1, B[i + N], bCompare) - BHalfPos;
            cout << pos << " " << BHalf1[BHalfPos[pos]] << " " << B[i + N] << "\n";
            if (BHalf1[BHalfPos[pos]] > B[i + N] + D) break;
            adjList[pos].pb(i + N);
            curB = pos + 1;
        }
    }
    for (int i = 1; i <= 2 * N; i++) {
        cout << i << ": ";
        for (auto it : adjList[i]) {
            cout << it << " ";
        }
        cout << "\n";
    }
}
