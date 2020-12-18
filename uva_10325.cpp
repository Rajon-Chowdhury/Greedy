#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll gcd(ll a,ll b){while(b){ll x=a%b;a=b;b=x;}return a;}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
int a[17],n,m;
int sum=0;
void func(int idx,long long v,int cnt){
   if(idx==m){
    if(cnt&1)
        sum-=n/v;
    else
        sum+=n/v;
    return;
   }
   if(v>n) return;
   func(idx+1,v,cnt);
   func(idx+1,lcm(v,a[idx]),cnt+1);

}
int main()
{
    while(scanf("%d%d",&n,&m)==2){
        for(int i=0;i<m;i++){
            scanf("%d",&a[i]);
        }
        sum=0;
        func(0,1LL,0);
        printf("%d\n",sum);
    }

}
