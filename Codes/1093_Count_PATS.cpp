#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    int LeftP[100005]={0};
    int RightT[100005]={0};
    int count=0;
    char temp[100005];
    cin>>temp;
    int Len=strlen(temp);
    int Left=0;
    int right=0;
    for(int i=0;i<Len;i++)
    {
        if(temp[i]=='P')
            Left++;
        if(temp[i]=='A')
        {   
            LeftP[count]=Left;
            count++;
        }
     }
    //count=0;
     for(int i=Len-1;i>-1;i--)
    {
        if(temp[i]=='T')
            right++;
        if(temp[i]=='A')
        {   
            RightT[count-1]=right;
            count--;
        }
     }
    int ans=0;
    for(int i=0;i<count;i++)
        ans+=LeftP[i]*RightT[i];
    cout<<ans%1000000007;
    
}