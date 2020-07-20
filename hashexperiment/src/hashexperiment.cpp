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
#define INF 1000000007
#define ha 10385987
#define hs 10385719

ll hsh(int n, char a){
	return ((1ll * a * hs + ha) % INF) * pow(2, n);
}

int main() {
	ifstream fin;
	ofstream fout;
	fin.open("censor.in");
	fout.open("censor.out");
	string word, censor;
	cin>>word>>censor;
	ll censor_hash=0;
	for(int i=0; i<(int)censor.length(); i++){
		censor_hash+=hsh(i, censor[i]);
	}
	string build="";
	vector<ll> buildHash(1, 0);
	//int count=0;
	vi count;
	int othercount=0;
	for(int i=0; i<(int)word.length(); i++){
		build+=word[i];
		buildHash.push_back(buildHash.back()+hsh(othercount, build[othercount]));
		if(build.length()<censor.length()+1){
			count.push_back(0);
		}else{
			count.push_back(count.back()+1);
		}
		if(build.length()>=censor.length()){
			ll test=(buildHash[buildHash.size()-1]-buildHash[buildHash.size()-censor.length()-1])/pow(2, count.back());
			if(censor_hash==test && build.substr(build.size() - censor.size()) == censor){
				build.erase(build.length()-censor.length(), censor.length());
				buildHash.resize(buildHash.size()-censor.size());
				//count-=censor.size();
				count.resize(count.size()-censor.size());
				othercount-=censor.size();
			}
		}
		othercount++;
	}
	cout<<build<<endl;
	fin.close();
	fout.close();
}
