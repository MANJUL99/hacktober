#include<bits/stdc++.h>
using namespace std;
#define ll long long int
void fast(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
} 
int main()
{
	fast();
	ll q;
	cin>>q;
	while(q--){
		ll n,a,b;
		cin>>n>>a>>b;
		ll inters = a+b-n;
		ll ans = max(a-inters ,b-inters) +1;
		cout<<ans<<"\n";
	}
	return 0;
}