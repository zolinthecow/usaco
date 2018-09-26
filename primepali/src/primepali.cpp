/*
ID: colinzh3
PROG: pprime
LANG: C++
 */
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

vector<long long> generatePalindromes(long long min, long long max){
	vector<long long> results;
	int maxdigits=0, mindigits=0;
	int temp1=max;
	do{
		maxdigits++;
		temp1/=10;
	}while(temp1);
	int temp2=min;
	do{
		mindigits++;
		temp2/=10;
	}while(temp2);
	if(max>9){
		for(int i=min; i<10; i++){
			results.push_back(i);
		}
	}else{
		for(int i=min; i<max; i++){
			results.push_back(i);
		}
	}
	if(maxdigits>=2&&mindigits<=2){
		for(int i=1; i<10; i++){
			long long result2;
			result2=i*10+i;
			results.push_back(result2);
		}
	}
	if(maxdigits>=3&&mindigits<=3){
		for(int i=1; i<10; i++){
			long long result3;
			for(int j=0; j<10; j++){
				result3=i*100+j*10+i;
				results.push_back(result3);
			}
		}
	}
	if(maxdigits>=4&&mindigits<=4){
		for(int i=1; i<10; i++){
			long long result4;
			for(int j=0; j<10; j++){
				result4=i*1000+j*100+j*10+i;
				results.push_back(result4);
			}
		}
	}
	if(maxdigits>=5&&mindigits<=5){
		for(int i=1; i<10; i++){
			long long result5;
			for(int j=0; j<10; j++){
				for(int k=0; k<10; k++){
					result5=i*10000+j*1000+k*100+j*10+i;
					results.push_back(result5);
				}
			}
		}
	}
	if(maxdigits>=6&&mindigits<=6){
		for(int i=1; i<10; i++){
			long long result6;
			for(int j=0; j<10; j++){
				for(int k=0; k<10; k++){
					result6=i*100000+j*10000+k*1000+k*100+j*10+i;
					results.push_back(result6);
				}
			}
		}
	}
	if(maxdigits>=7&&mindigits<=7){
		for(int i=1; i<10; i++){
			long long result7;
			for(int j=0; j<10; j++){
				for(int k=0; k<10; k++){
					for(int l=0; l<10; l++){
						result7=i*1000000+j*100000+k*10000+l*1000+k*100+j*10+i;
						results.push_back(result7);
					}
				}
			}
		}
	}
	if(maxdigits>=8&&mindigits<=8){
		for(int i=1; i<10; i++){
			long long result8;
			for(int j=0; j<10; j++){
				for(int k=0; k<10; k++){
					for(int l=0; l<10; l++){
						result8=i*10000000+j*1000000+k*100000+l*10000+l*1000+k*100+j*10+i;
					}
					results.push_back(result8);
				}
			}
		}
	}
	if(maxdigits>=9&&mindigits<=9){
		for(int i=1; i<10; i++){
			long long result9;
			for(int j=0; j<10; j++){
				for(int k=0; k<10; k++){
					for(int l=0; l<10; l++){
						for(int m=0; m<10; m++){
							result9=i*100000000+j*10000000+k*1000000+l*100000+m*10000+l*1000+k*100+j*10+i;
						}
						results.push_back(result9);
					}
				}
			}
		}
	}
	return results;
}
string *stringToStringArray(string a){
	int length=a.length();
	string *result;
	result=new string[length];
	for(int i=0; i<length; i++){
		string temp=a.substr(i, 1);
		result[i]=temp;
	}
	return result;
}
bool checkPrime(long long a){
	if(a<=1){
		return false;
	}else if(a<=3){
		return true;
	}else if(a%2==0||a%3==0){
		return false;
	}
	long long i=5;
	while(i*i<=a){
		if(a%i==0||a%(i+2)==0){
			return false;
		}
		i+=6;
	}
	return true;
}
int main() {
	ifstream fin;
	ofstream fout;
	fin.open("pprime.in");
	fout.open("pprime.out");
	long long front, back;
	fin>>front>>back;
	vector<long long>palindromes=generatePalindromes(front, back);
	for(vector<long long>::iterator it=palindromes.begin(); it!=palindromes.end(); it++){
		if(checkPrime(*it)&&*it>=front&&*it<=back){
			fout<<*it<<endl;
		}
	}
	fin.close();
	fout.close();
}
