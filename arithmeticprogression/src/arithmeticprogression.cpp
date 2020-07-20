/*
ID: colinzh3
PROG: ariprog
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

struct sequence{
	int start, amount;
};
bool wayToSort(sequence a, sequence b){
	if(a.amount==b.amount){
		return a.start<b.start;
	}else{
		return a.amount<b.amount;
	}
}
vector<sequence> findAllSequences(bool allnum[], int size, int bsquares[], int length){
	vector<sequence> answers;
	//vector<int>::iterator endplace=bisquares.begin()+bisquares.size()-length+1;
	//vector<int>::iterator itplace=bisquares.begin()+bisquares.size()-length+2;
	for(int i=0; i<size-length; i++){//vector<int>::iterator itr=bisquares.begin(); itr!=endplace; itr++){
		//cout<<"working on:"<<*itr<<endl;
		for(int j=i; j<size-length+1; j++){//vector<int>::iterator it=itr; it!=itplace; it++){
			if(i+(length-1)==size||j+(length-1)==size){//itr+(length-1)==bisquares.end()||it+(length-1)==bisquares.end()){
				break;
			}
			int possibleDiff=(bsquares[j+1]-bsquares[i]);//*(it+1))-(*itr);
			bool fail=false;
			int start=j+1;//vector<int>::iterator start=it+1;
			//for(int i=1; i<length; i++){
			for(int k=1; k<length; k++){
				int numToFind=bsquares[i]+possibleDiff*k;//*itr+possibleDiff*i;

				bool find=false;
				/*do{
					if(bsquares[start]==numToFind){//*start==numToFind){
						find=true;
						start++;
						break;
					}
					start++;
				}while(bsquares[start]<=numToFind&&start+1<=size);//*start<=numToFind);*/
				if(allnum[numToFind]){
					find=true;
				}
				if(!find){
					fail=true;
					break;
				}
				/*if(find(start, bisquares.end(), numToFind)==bisquares.end()){
					fail=true;
					break;
				}*/

			}
			if(fail==false&&possibleDiff>0){
				sequence temp;
				temp.start=bsquares[i];//*itr;
				temp.amount=possibleDiff;
				answers.push_back(temp);
			}
		}
	}
	return answers;
}
int main() {
	ifstream fin;
	ofstream fout;
	fin.open("ariprog.in");
	fout.open("ariprog.out");
	vector<int> bisquares;
	int proglength, m;
	fin>>proglength>>m;
	bool *allnum=new bool[((m*m+m*m)+1)*2];
	for(int z=0; z<=(m*m+m*m)*2; z++){
		allnum[z]=false;
	}
	for(int i=0; i<=m ;i++){
		for(int j=0; j<=m; j++){
			if(i==0&&j==0){
				bisquares.push_back(pow(i, 2)+pow(j, 2));
				int bob=pow(i, 2)+pow(j, 2);
				allnum[bob]=true;
			}else if(find(bisquares.begin(), bisquares.end(), pow(i, 2)+pow(j, 2))==bisquares.end()){
				bisquares.push_back(pow(i, 2)+pow(j, 2));
				int bobjohn=pow(i, 2)+pow(j, 2);
				allnum[bobjohn]=true;
			}
		}
	}
	sort(bisquares.begin(), bisquares.end());
	int *bsquares=new int[bisquares.size()];
	int count=0;
	for(vector<int>::iterator bob=bisquares.begin(); bob!=bisquares.end(); bob++){
		bsquares[count]=*bob;
		count++;
	}
	//vector<sequence> allSequences=findAllSequences(bisquares, proglength);
	vector<sequence> allSequences=findAllSequences(allnum, bisquares.size(), bsquares, proglength);
	/*for(vector<int>::iterator it=bisquares.begin(); it!=bisquares.end(); it++){
		cout<<*it<<" ";
	}
	cout<<endl;*/
	sort(allSequences.begin(), allSequences.end(), wayToSort);
	if(allSequences.size()==0){
		fout<<"NONE"<<endl;
	}else{
		for(vector<sequence>::iterator itr=allSequences.begin(); itr!=allSequences.end(); itr++){
			fout<<(*itr).start<<" "<<(*itr).amount<<endl;
		}
	}
	fin.close();
	fout.close();
}
