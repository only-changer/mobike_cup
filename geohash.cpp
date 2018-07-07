#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int main()
{
    int shu[500],ans[50];
    char ch[50];
    char da[40]="0123456789bcdefghjkmnpqrstuvwxyz";
    scanf("%s",ch);
    int ll=strlen(ch);
    for (int i=0;i<ll;i++)
    {
        for (int j=0;j<32;j++)
        {
            if (da[j]==ch[i])
            {
                ans[i]=j;
                break;
            }
        }
    }
    for (int i=0;i<ll;i++)
    {
        int j=5*i;
        shu[j]=ans[i]&16;
        shu[j+1]=ans[i]&8;
        shu[j+2]=ans[i]&4;
        shu[j+3]=ans[i]&2;
        shu[j+4]=ans[i]&1;
    }
    ll*=5;
    double x,y,l,r,m;
    l=-90.0;r=90.0;
    for (int i=1;i<ll;i+=2)
    {
        m=(l+r)/2.0;
        if (shu[i]==0)
            r=m;
        else
            l=m;
    }
    x=(l+r)/2.0;
    l=-180.0;r=180.0;
    for (int i=0;i<ll;i+=2)
    {
        m=(l+r)/2.0;
        if (shu[i]==0)
            r=m;
        else
            l=m;
    }
    y=(l+r)/2.0;
    printf("%.6lf %.6lf\n",x,y);
}