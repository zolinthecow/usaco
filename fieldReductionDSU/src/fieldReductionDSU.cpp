#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <set>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <memory.h>
#include <string>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <cassert>

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;

#define FORN(i, n) for (int i = 0; i <  (int)(n); i++)
#define FOR1(i, n) for (int i = 1; i <= (int)(n); i++)
#define FORD(i, n) for (int i = (int)(n) - 1; i >= 0; i--)
#define FOREACH(i, c) for (typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)

#define MOD 1000000007
#define INF 2000000000

void union_init(int d[], int s) {
	for (int i=0; i < s; i++) {
		d[i]=i;
	}
}
int union_query(int d[], int n) {
	int res=n;
	while (d[res]!=res) {
		res=d[res];
	}
	int m;
	while (d[n]!=n) {
		m=d[n];
		d[n]=res;
		n=m;
	}
	return res;
}
int union_merge(int d[], int x, int y) {
	x=union_query(d,x);
	y=union_query(d,y);
	if (x==y) {
		return -1;
	}
	d[x]=y;
	return 1;
}

const int MAXN = 100010;
int order[MAXN], place[MAXN], u[MAXN], v[MAXN], par[MAXN]; bool res[MAXN];

int N, M;

vector< vector<int> > adj;

int main() {
	cin >> N >> M;
    for (int i = 0; i < (int)M; i++) {
    	cin >> u[i] >> v[i];
    }

    for (int i = 0; i < (int)N; i++)  {
        cin >> order[i];
        place[order[i]] = i;
    }

    adj.resize(N+1);

    for (int i = 0; i < (int)M; i++)  {
        if (place[u[i]] > place[v[i]]) {
        	adj[v[i]].push_back(u[i]);
        } else {
        	adj[u[i]].push_back(v[i]);
        }
    }

    union_init(par, N+1);
    int comps = 0;

    for (int i = N - 1; i >= 0; i--) {
        int uu = order[i]; comps++;

        for (int j = 0; j < (int)adj[uu].size(); j++) {
            int vv = adj[uu][j];
            if (union_query(par, uu) != union_query(par, vv)) {
                union_merge(par, uu, vv);
                comps--;
            }
        }

        res[i] = (comps <= 1);
    }

    for (int i = 0; i < (int)N; i++) {
    	if (res[i]) printf("YES\n"); else printf("NO\n");
    }
    return 0;
}
