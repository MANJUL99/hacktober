#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
	int T=0;
	cin>>T;
	while(T--){
		int N=0;
		cin>>N;
		if(360%N==0){
			cout<<"y ";
		}	
		else cout<<"n ";
		if(N<=360){
			cout<<"y ";
		}
		else cout<<"n ";
		if(360-(N-1+1)*(N-1)/2>N-1)cout<<"y\n";
		else cout<<"n\n";
	
	}
	return 0;

}
