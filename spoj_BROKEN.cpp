#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    while(true){
        int m;
        cin>>m;
        if(m==0) break;
        string text;
        text="";
        while(text=="") getline(cin,text);
        int n=text.size();
        map<char,int>cnt;
        int un=0;
        int ans=0,len=0,ss=0,i=0;
        while(i<n){
            cnt[text[i]]++;
            if(cnt[text[i]]==1) un++;
            if(un>m){
               ans=max(ans,len);
               if(cnt[text[ss]]==1) un--;
               cnt[text[ss]]--;
               ss++;
            }
            else{
                len++;
            }
            i++;
        }
        if(un<=m) ans=max(ans,len);
        cout<<ans<<endl;
    }

}
