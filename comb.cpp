#include<bits/stdc++.h>
using namespace std;
int modinverse(int a, int m){
    // fermat mod prime number(m) 
  return  pow(a,m-2);
}
int main(){
    int n,k;
    cin>>n>>k;
    // int dp[n+1];
    // dp[0]=1;
    // for(int i=1;i<=n;i++)   dp[i] = dp[i-1]*i;
    // int val = dp[n]/(dp[k]*dp[n-k]);
    // cout<<val<<endl;
    // int dp[n+1][n+1];
    // memset(dp,0,sizeof(dp));
    // for(int i=0;i<=n;i++){
    //     for(int j=0;j<=i;j++){
    //         if(i==0||j==0) {
    //             dp[i][j]=1;
    //             continue;
    //         }
    //         dp[i][j] = dp[i-1][j]+dp[i-1][j-1];
    //     }
    // }
    // for(int i=0;i<=n;i++){
    //     for(int j=0;j<=i;j++){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    // cout<<dp[n][k]<<"\n";
    return 0;
}