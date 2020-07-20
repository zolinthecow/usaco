#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<ll>
#define ii pair<ll, ll>
#define vii vector<ii>
#define pb push_back
#define LSOne(S) (S & (-S))

void setIO(string s) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

const int MOD = 1e9 + 7;

int s[10000001];
 
int main()
{
	setIO("spainting");
	int N,M,K;
	cin >> N >> M >> K;
	
	s[0] = 0;
	for(int i=1;i<K;i++)
		s[i] = (M*((long long)s[i-1]) + M)%MOD;
	for(int i=K;i<=N;i++)
		s[i] = (M*((long long)s[i-1]) + MOD - ((M-1)*((long long)s[i-K]))%MOD)%MOD;
 
	int ans = 1;
	for(int i=1;i<=N;i++)
		ans = (M*((long long)ans))%MOD;
	
	cout << (((long long)ans) + MOD - ((long long)s[N]) + s[N-1])%MOD << '\n';
}
