#include<bits/stdc++.h>
using namespace std;
#define ll long long int
void fast(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
} 
int main()
{
	// fast();
	ll n;
	cin>>n;
	string s;
	cin>>s;
	ll dp[n][26];
	memset(dp,0,sizeof(dp));
	int x = s[0]-'a';
	dp[0][x]++;
	for(int i=1;i<n;i++){
		x = s[i]-'a';
		dp[i][x]++;
		for(int j=0;j<26;j++){
			dp[i][j]+=dp[i-1][j];
		}
	}
	ll q;
	cin>>q;
	while(q--){
		string t;
		cin>>t;
		ll a[26];
		memset(a,0,sizeof(a));
		for(int i=0;i<t.size();i++){
			x = t[i]-'a';
			a[x]++;
		}
		ll low = 0,high =n-1;
		ll ans = -1;
		while(low<=high){
			ll mid = (low+high)/2;
			ll flag=0;
			for(int i=0;i<26;i++){
				if(dp[mid][i]<a[i]){
					flag=1;
					break;
				}
			}
			if(flag==0){
				high =mid-1;
				ans = mid;
			}
			else low =mid+1;
		}
		cout<<ans+1<<"\n";
	}
	return 0;
}