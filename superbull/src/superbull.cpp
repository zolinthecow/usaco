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
#include <unordered_map>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<string> vs;
#define pb push_back

vi taken;
priority_queue<ii> pq;
vector< vii > adjlist;

void process(int vtx){
	taken[vtx]=1;
	for(int j=0; j<(int)adjlist[vtx].size(); j++){
		ii v=adjlist[vtx] [j];
		if(!taken[v.first]){
			pq.push(ii(v.second, v.first));
		}
	}
}
int main() {
	ifstream fin;
	ofstream fout;
	fin.open("superbull.in");
	fout.open("superbull.out");
	int n;
	fin>>n;
	vi teams(n);
	for(int i=0; i<n; i++){
		fin>>teams[i];
	}
	taken.assign(n, 0);
	for(int i=0; i<n; i++){
		vii weights;
		for(int j=0; j<n; j++){
			ii weight;
			if(j!=i){
				weight.first=j;
				weight.second=teams[i] xor teams[j];
				weights.pb(weight);
			}
		}
		adjlist.pb(weights);
	}
	process(0);
	ll answer=0;
	while(!pq.empty()){
		ii front=pq.top();
		pq.pop();
		if(!taken[front.second]){
			answer+=front.first;
			process(front.second);
		}
	}
	fout<<answer<<endl;
	fin.close();
	fout.close();
}
