#include<bits/stdc++.h>
using namespace std;
#define ll long long
bool compare(const pair<int,int> &a,const pair<int,int> &b)
{
	//cout<<(a.second>b.second)<<" "<<a.second<<" "<<b.second<<endl;
	if (a.second==b.second)
		return a.first<b.first;
	return a.second<b.second;
}
int main(){
     int t,cs=0;
     scanf("%d",&t);
     while(t--){
        int n;
        scanf("%d",&n);
        int a[n],b[n];
        for(int i=0;i<n;i++) scanf("%d",&a[i]);
        for(int i=0;i<n;i++) scanf("%d",&b[i]);
        vector<pair<int,int>>v;
        for(int i=0;i<n;i++){
            if(b[i]!=-1)
               v.push_back(make_pair(a[i],b[i]));
        }
        sort(v.begin(),v.end(),compare);
        vector<int>ans;
        int cur=0;
        for(int i=0;i<v.size();i++){
            if(!ans.empty()){
                if(v[i].second-(v[i].first+cur)>=30){
                    ans.push_back(v[i].first),cur+=v[i].first;
                }
                else if(v[i].second-(v[i].first+cur-ans[ans.size()-1]>=0) &&(cur-ans[ans.size()-1]+v[i].first)<cur){
                    cur-=ans[ans.size()-1];
                    ans.pop_back();
                    ans.push_back(v[i].first);
                    cur+=v[i].first;
                }
            }
            else if(ans.empty()){
                if(v[i].second-v[i].first>=30)
                    ans.push_back(v[i].first),cur=v[i].first;
            }
            sort(ans.begin(),ans.end());
        }
        printf("Case %d: %d\n",++cs,v.size()-ans.size());

     }
}
