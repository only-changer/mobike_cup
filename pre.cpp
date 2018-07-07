#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
using namespace std;
class location
{
public:
    double x;
    double y;

    location (double xx,double yy) : x(xx),y(yy)
    {}
};
location geode(string s)
{
    int shu[500],ans[50];
    char ch[50];
    char da[40]="0123456789bcdefghjkmnpqrstuvwxyz";
    for (int i = 0;i < s.length();++i)
        ch[i] = s[i];
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
    location loc(x,y);
    return loc;
}
string Trim(string& str)
{
 str.erase(0,str.find_first_not_of(" \t\r\n"));

 str.erase(str.find_last_not_of(" \t\r\n") + 1);

 return str;
}

int main()
{
    ifstream fin("train.csv");
    ofstream out;
    out.open("data.csv", ios::out); 
    string line; 
    int k = 0;
    while (getline(fin, line)) 
    {
        ++k;
        if (k % 100000 == 0)
            cout<<k<<endl;
        istringstream sin(line); 
        vector<string> fields; 
        string field;
        while (getline(sin, field, ',')) 
        {
            fields.push_back(field); 
        }

        for (int i = 0;i < fields.size();++i)
            out<<fields[i]<<',';
        if (k > 1)
        {
            location ls = geode(fields[fields.size() - 2]);
            location le = geode(fields[fields.size() - 1]);
            out<<ls.x<<','<<ls.y<<','<<le.x<<','<<le.y<<endl;  
        }else
        {
            out<<"start_x"<<','<<"start_y"<<','<<"end_x"<<','<<"end_y"<<endl;
        }
    }
    out.close();
    return 0;
}