#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
	int T=0;
	cin>>T;
	while(T--){
		long long int N=0,M=0;
		cin>>N>>M;
		vector<long long int>plate(N);
		int i=0;
		int flag=0;
		while(i<N){
			cin>>plate[i];i++;
		}
		sort(plate.begin(),plate.end());
		long long int sum=0;		
		for(i=N-1;i>=0;i--){
			sum+=plate[i];
			if(sum>=M){
				cout<<N-1-i+1<<"\n";
				flag=1;break;
			}
		}
		if(flag==0)cout<<-1<<"\n";
	}
	return 0;
}
