#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define n 1000000
bool arr[10000000];
vector<ll>prime;
 void seive()
 {
 	int val=sqrt(n)+1;
 	for(int i=2;i<=n;i++)
 	  arr[i]=true;
 	  for(int i=2;i<val;i++)
 	  {
 	  	if(arr[i]==true)
 	  	{
 	  		for(int j=i;i*j<=n;j++)
 	  		{
 	  			arr[i*j]=false;
			}
		   }
	   }
	   for(int i=2;i<=n;i++)
	   {
	   	if(arr[i])
	   	{
	   		prime.push_back(i);
		   }
	   }
 }
 void segment_seive(ll l,ll r)
 {
 	bool isPrime[r-l+1];
 	for(int i=0;i<r-l+1;i++) isPrime[i]=true;
 	if(l==1) isPrime[0]=false;
 	for(int i=0;prime[i]*prime[i]<=r;i++)
 	{
 		int curPrime=prime[i];
 		ll base=(l/curPrime)*curPrime;
 		if(base<l)
 		  base=base+curPrime;
 		  for(ll j=base;j<=r;j+=curPrime)
 		  {
 		  	isPrime[j-l]=false;
	      }
	      if(base==curPrime)isPrime[base-l]=true;
	      
	 }
	 for(int i=0;i<r-l+1;i++)
	 if(isPrime[i])cout<<l+i<<endl;
 }

int main()
{
	seive();
//	for(int i=0;i<prime.size();i++)
//	cout<<prime[i]<<" ";
 int l,r;cin>>l>>r;
 segment_seive(l,r);
 
}
