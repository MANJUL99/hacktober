#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
	int T=0;
	cin>>T;
	while(T--){
		long long int n=0;
		cin>>n;
		//vector<int>a(n);
		int i=0;
		int temp=0;
		while(i<n){
			cin>>temp;
			i++;
		}
		long long int ans=n*(n-1)/2;		
		cout<<ans<<"\n";		
	}
	return 0;

}
