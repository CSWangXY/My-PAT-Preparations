#include <iostream>
using namespace std;
int a[120];


bool IsPrime(int n)
{
    if(n<=1) return false;
    else if(n>=2)
    {
        for(int i=2;i<n;i++)
        if(n%i==0) return false;
    }
    return true;
}


int Trans(int n, int p)
{
    int num=0;
    int ans=0;
    int k=1;
    do 
    {
        a[num]= n%p;
        num++;
        n=n/p;
    } while(n!= 0);
    for(int i=num-1;i>=0;i--)
    {
        ans+=a[i]*k;
        k=k*p;
    }
    return ans;
}


int main()
{
    int n,radix;
    while(cin>>n>>radix)
    {
        if(n<=1)
        break;
        if(IsPrime(n)==false)
        cout<<"No"<<endl;
        else 
        {
            int ans=Trans(n,radix);
            if(IsPrime(ans)==false)
            cout<<"No"<<endl;
            else cout<<"Yes"<<endl;
        }
    }
}