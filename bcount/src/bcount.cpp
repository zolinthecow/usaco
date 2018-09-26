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

struct types{
	int h, g, j;
};
int main() {
	ifstream fin;
	ofstream fout;
	fin.open("bcount.in");
	fout.open("bcount.out");
	int cows, queriesc;
	fin>>cows>>queriesc;
	vector<types> ids;
	vii queries;
	for(int i=0; i<cows; i++){
		int temp;
		fin>>temp;
		if(i==0){
			types tempa;
			if(temp==1){
				tempa.h=1;
				tempa.g=0;
				tempa.j=0;
			}else if(temp==2){
				tempa.g=1;
				tempa.h=0;
				tempa.j=0;
			}else{
				tempa.j=1;
				tempa.h=0;
				tempa.g=0;
			}
			ids.push_back(tempa);
		}else{
			types tempa;
			tempa.h=ids[i-1].h;
			tempa.g=ids[i-1].g;
			tempa.j=ids[i-1].j;
			if(temp==1){
				tempa.h+=1;
			}else if(temp==2){
				tempa.g+=1;
			}else{
				tempa.j+=1;
			}
			ids.push_back(tempa);
		}
	}
	for(int i=0; i<queriesc; i++){
		ii temp;
		fin>>temp.first>>temp.second;
		queries.push_back(temp);
	}
	for(int i=0; i<queriesc; i++){
		int hcount=0, gcount=0, jcount=0;
		if(queries[i].second == 1){
			hcount=ids[ queries[i].first-1].h;
			jcount=ids[ queries[i].first-1].j;
			gcount=ids[ queries[i].first-1].g;
		/*}else if(queries[i].first == queries[i].second){
			hcount=ids[ queries[i].second-1 ].h - ids[ queries[i].first-2 ].h;
			gcount=ids[ queries[i].second-1 ].g - ids[ queries[i].first-2 ].g;
			jcount=ids[ queries[i].second-1 ].j - ids[ queries[i].first-2 ].j;*/
		}else if(queries[i].first == 1){
			hcount=ids[ queries[i].second-1 ].h;
			gcount=ids[ queries[i].second-1 ].g;
			jcount=ids[ queries[i].second-1 ].j;
		}else{
			hcount=ids[ queries[i].second-1 ].h - ids[queries[i].first-2 ].h;
			gcount=ids[ queries[i].second-1 ].g - ids[queries[i].first-2 ].g;
			jcount=ids[ queries[i].second-1 ].j - ids[queries[i].first-2 ].j;
		}
		fout<<hcount<<" "<<gcount<<" "<<jcount<<endl;
	}
	fin.close();
	fout.close();
}
