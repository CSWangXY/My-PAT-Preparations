#include <iostream>
using namespace std;

struct Fraction
{
    long long up;
    long long down;
};

//求解最大公因数
long long gcb(long long  a, long long b)
{
    if(b==0)
    return a;
    else return gcb( b, a%b);
}
//化简
Fraction Simplify(Fraction a)
{
    if(a.down<0)
    {
        a.up*=-1;
        a.down*=-1;
    }
    if(a.up == 0)
    a.down = 1;
    else 
    {
        long long x = gcb(a.up,a.down);
        a.up /= x;
        a.down /= x;

    }
    return a;
}


int main()
{
    int n;//分数个数
    cin>>n;
    Fraction temp;
    Fraction ans;
    
    ans.up=0;
    ans.down=1;
    char s='/';
    for(int i=0;i<n;i++)
    {
        cin>>temp.up>>s>>temp.down;
        int p  = ans.down * temp.down;
        int q  = ans.up*temp.down + ans.down*temp.up;
        ans.down = p;
        ans.up = q ;
        Simplify(ans);
    }
    if(ans.down==1)
    cout<<ans.up;
    else if(ans.up/ans.down>=1 || ans.up/ans.down <=-1)
    {
        cout<<ans.up/ans.down;
        ans.up = ans.up-abs(ans.up/ans.down)*ans.down;
        ans = Simplify(ans);
        if(ans.up != 0)
        cout<<" "<<ans.up<<"/"<<ans.down;
    }
    else if(ans.up == 0)
    cout<<"0";
    else 
    {
        ans =Simplify(ans);
        cout<<ans.up<<"/"<<ans.down;
    }
}