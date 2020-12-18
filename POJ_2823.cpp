#include<iostream>
#include<cstdio>
using namespace std;
int n,k,a[1000001],q[1000001];

int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
        scanf("%d",a+i);
    int h=1,t=0;
    for(int i=1;i<=n;i++)
    {
        while(h<=t&&a[i]<=a[q[t]])
            t--;
        q[++t]=i;
        while(h<=t&&q[t]-q[h]>=k)
            h++;
        if(i>=k)
            printf("%d ",a[q[h]]);
    }
    printf("\n");
    h=1,t=0;
    for(int i=1;i<=n;i++)
    {
        while(h<=t&&a[i]>=a[q[t]])
            t--;
        q[++t]=i;
        while(h<=t&&q[t]-q[h]>=k)
            h++;
        if(i>=k)
            printf("%d ",a[q[h]]);
    }
    printf("\n");
    return 0;
}
