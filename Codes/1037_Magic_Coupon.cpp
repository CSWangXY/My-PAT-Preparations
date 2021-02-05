#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int NC,NP;
    int A[100010];
    int B[100010];
    cin>>NC;
    for(int i=0;i<NC;i++)
    cin>>A[i];
    cin>>NP;
    for(int i=0;i<NP;i++)
    cin>>B[i];
    sort(A,A+NC);
    sort(B,B+NP);
    int ans=0;
    int i=0;
    while(i<NC && i<NP && A[i]<0&&B[i]<0)
    {ans+=A[i]*B[i];i++;}
    i=NC-1;
    int j=NP-1;
    while(i>=0 && j>=0 && A[i]>0 &&B[i]>0)
    {ans+=A[i]*B[i];i--;j--;}
    cout<<ans;
}
