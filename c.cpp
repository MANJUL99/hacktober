#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,m;
	cin>>n>>m;
	int dp[n];
	memset(dp,0,sizeof(dp));
	vector<pair<int,int> >vec;
	for(int i=0;i<m;i++){
		int t,l,r;
		cin>>t>>l>>r;
		l--;
		r--;
		if(t==1)
		{
			dp[l]++;
			dp[r]--;
		}
		else vec.push_back({l,r});
	}
	for(int i=1;i<n;i++)
		dp[i]+=dp[i-1];
	for(int i=0;i<vec.size();i++){
		int l = vec[i].first;
		int r = vec[i].second;
		int cnt =0;
		for(int j=l;j<r;j++){
			if(dp[j]<=0)	cnt++;
		}
		if(cnt==0){
			cout<<"NO\n";
			return 0;
		}
	}
	cout<<"YES\n";
	int ans = n+1;
	cout<<ans<<" ";
	for(int i=1;i<n;i++){
		if(dp[i-1]<=0)	ans--;
		else	ans++;
		cout<<ans<<" ";
	}
	cout<<endl;
	return 0;
}