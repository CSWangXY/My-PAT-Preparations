#include <iostream>
#include <algorithm>
using namespace std;
int a[100010];

int BinarySearch(int i,long long x, int n)//在i+1到n-1之间查找第一个大于x的数
{
    int mid;
    if(a[n-1]<=x) return n ;//所有数都不大于x，返回n
    int l=i+1,r=n-1;
    while (l<r)
    {
        mid=(l+r)/2;
        if(a[mid]<=x) l=mid+1;
        else r=mid;
    }
    return l;
}

int main()
{
    int N,p;
    cin>>N>>p;
    for(int i=0;i<N;i++)
        cin>>a[i];
    sort(a,a+N);
    int ans=0;
    for(int i=0;i<N;i++)
    {
        long long temp=a[i]*p;
        int j=BinarySearch(i,temp,N);
        ans=max(ans,j-i);
    }
    cout<<ans;
}