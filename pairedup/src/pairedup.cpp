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

int main() {
	ifstream fin;
	ofstream fout;
	fin.open("pairup.in");
	fout.open("pairup.out");
	int a;
	fin>>a;
	vii cows;
	for(int i=0; i<a; i++){
		int b, c;
		fin>>b>>c;
		ii temp;
		temp.first=c, temp.second=b;
		cows.push_back(temp);
	}
	sort(cows.begin(), cows.end());
	int max=0, front=0, back=a-1;
	while(front<=back){
		int smaller=min(cows[front].second, cows[back].second);
		if(front==back){
			smaller/=2;
		}
		if(cows[front].first+cows[back].first>max){
			max=cows[front].first+cows[back].first;
		}
		cows[front].second-=smaller;
		cows[back].second-=smaller;
		if(cows[front].second==0){
			front++;
		}
		if(cows[back].second==0){
			back--;
		}
	}
	fout<<max;
	fin.close();
	fout.close();
}
