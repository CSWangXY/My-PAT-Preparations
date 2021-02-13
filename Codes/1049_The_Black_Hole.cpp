#include <iostream>
#include  <algorithm>
using namespace std;

bool cmp(int a,int b)
{return a>b;}

void To_Array(int a,int b[])
{
    int temp=1000;
    for(int i=0;i<4;i++)
    {
        b[i]=a/temp;
        a -= b[i]*temp; 
        temp /=10;
    }
}
int  To_Int(int a[])
{
    int ans=0;
    int x=1000;
    for(int i=0;i<4;i++)
    {
        ans+=a[i]*x;
        x /= 10;
    }
    return ans;
}



int main()
{
int n;
cin>>n;
int num[5]={0};
int temp,left,right;
while (true)
{
    temp = n;
    To_Array(n,num);
    sort(num,num+4,cmp);
    left=To_Int(num);
    for(int i=0;i<4;i++)
    cout<<num[i];
    cout<<"-";
    sort(num,num+4);
    for(int i=0;i<4;i++)
    cout<<num[i];
    right = To_Int(num);
    n = left -right;
    cout<<" = ";
    To_Array(n,num);
    for(int i=0;i<4;i++)
    cout<<num[i];
    cout<<endl;
    if(n==0||n==6174) break;
     
}
}