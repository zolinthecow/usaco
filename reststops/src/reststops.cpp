#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <map>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<string> vs;

int L,N,rf,rb;

int x[10000];
int c[100000];
bool isMax[10000];

int main()
{
	cin >> L >> N >> rf >> rb;
	for(int i=0;i<N;i++)
		cin >> x[i] >> c[i];
	int mx = 0;
	for(int i=N-1;i>=0;i--)
		if(c[i] > mx)
		{
			isMax[i] = 1;
			mx = c[i];
		}
	long long ans = 0;
	long long tf = 0;
	long long tb = 0;
	int lastx = 0;
	for(int i=0;i<N;i++) if(isMax[i])
	{
		tf += (x[i] - lastx)*((long long)rf);
		tb += (x[i] - lastx)*((long long)rb);
		ans += (tf - tb)*((long long)c[i]);
		tb = tf;
		lastx = x[i];
	}
	cout << ans << '\n';
}
