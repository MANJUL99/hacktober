#include <iostream>
#include <bits/stdc++.h>
using namespace std;

string toup(char ch){
	char ch1;
	string S="";
	if(int(ch)>=97&&int(ch)<=122){
		ch1=char(int(ch)-25-7);
		S+=ch1;
	}
	else{
		S+=ch;
	}
	
	return S;
}

string tolow(char ch){
	char ch1;
	string S="";
	if(int(ch)>=65&&int(ch)<=90){
		ch1=char(int(ch)+25+7);
		S+=ch1;
	}
	else S+=ch;
	return S;
}

int main(){
	int T=0;
	cin>>T;
	cin.ignore();
	string S;
	while(T--){
		getline(cin,S);
//		cout<<S;
		string S1="";int count=0;
		for(int i=S.length()-1;i>=0;i--){
			if(S[i]==' ')continue;			
			if(i-1>=0){
				if(S[i-1]==' '){
					if(count==0){
						S1=toup(S[i])+S1;
						count++;
					}
					else{
						S1=toup(S[i])+". "+S1;
						count++;
					}
				}	
				else{
					if(count==0){
						S1=tolow(S[i])+S1;
					}
//					else{
						
//					}
					
				}
			}
			else{
				if(count==0){
					S1=toup(S[i])+S1;
				}
				else{
					S1=toup(S[i])+". "+S1;
				}
			}
		}
		cout<<S1<<"\n";
	}
}
