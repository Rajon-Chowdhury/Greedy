
#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false)
struct node{
   int t,ty,id;
   bool operator<(const node &b){
       return (t!=b.t?t<b.t : ty<b.ty);
    }
};
int main(){
      fastio;
      int t;
      cin>>t;
      while(t--){
      int n;
      cin>>n;
      vector<node>v;
      for(int i=0;i<n;i++){
        int p,q;
        cin>>p>>q;
        node a1,b1;
        a1.t=p;
        b1.t=q;
        a1.ty=1;
        b1.ty=-1;

        a1.id=i;
        b1.id=i;
        v.push_back(a1);
        v.push_back(b1);
      }
      if(v[0].t>v[2].t){
        swap(v[0].id,v[2].id);
        swap(v[1].id,v[3].id);
      }
      sort(v.begin(),v.end());
      int total_room=0;
      int cnt=0;
      for(int i=0;i<v.size();i++){
         node cur=v[i];
         if(cur.ty==1) cnt++;
         else cnt--;
         total_room=max(total_room,cnt);
      }
      bool flag=1;
      int vis[n+2]={0};
      cnt=0;
      for(int i=0;i<v.size();i++){
        node cur=v[i];
        if(cur.ty==-1){
            cnt--;
            flag|=vis[cur.id];
        }
        else{
            vis[cur.id]=cur.id==0?0:flag;
            flag=!(++cnt==total_room);
        }
      }
      cout<<total_room+(!vis[1])<<endl;
      }
}
