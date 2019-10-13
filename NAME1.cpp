#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
	int T=0;
	cin>>T;
	while(T--){
		//int A=0,B=0;
		string A,B;
		cin>>A>>B;
		int N=0;
		cin>>N;
		string C="";
		string temp="";
		int i=0;
//		cin>>N;
		while(i<N){
			cin>>temp;
			C+=temp;
			i++;
		}
		string S=A+B;
		int aS[26]={0};
		for(i=0;i<S.length();i++){
			aS[int(S[i])-97]++;
		}	
		int aC[26]={0};	
		for(i=0;i<C.length();i++){
			aC[int(C[i])-97]++;
		}
		int flag=1;
		for(int i=0;i<26;i++){
			if(aC[i]>aS[i]){
				flag=0;
				break;
			}
		}
		if(flag==1)cout<<"YES\n";
		else cout<<"NO\n";
		
	}
	return 0;
}
