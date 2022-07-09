/* Problem Link: https://atcoder.jp/contests/dp/tasks/dp_n */

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007
#define test ll t; scanf("%lld",&t); while(t--)

int main() {
  	int n;
	cin>>n;
	vector<ll>a(n);
	vector<vector<ll>>dp(n,vector<ll>(n)); 
	/* 
	dp[i][j] stores the answer for subarray (i to j)
	dp[i][j] = minimum of dp[i][k]+dp[k+1][j]+Sum of subarray (i to j), where k varies from i to j-1
  	Final answer is stored in dp[0][n-1]
	*/
	for(int i=0;i<n;i++){
	    cin>>a[i];
	    dp[i][i]=0;
	    if(i){
	        dp[i-1][i]=a[i]+a[i-1];
	    }
	}
	for(int i=1;i<n;i++){
	    a[i]+=a[i-1];
	}
	for(int l=2;l<n;l++){
	    for(int i=0;i+l<n;i++){
	        dp[i][i+l]=4000000000000;
	        for(int k=i;k<i+l;k++){
	            dp[i][i+l]=min(dp[i][i+l],dp[i][k]+dp[k+1][i+l]+a[i+l]-(i?a[i-1]:0));
	        }
	    }
	}
	cout<<dp[0][n-1];
	return 0;
}
