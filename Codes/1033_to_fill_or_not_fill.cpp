#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

struct Station
{
    double distance;
    double price;
}sta[510];

bool cmp(Station a,Station b)
{
    return a.distance<b.distance;
}
int main()
{
    int Cmax,D,Davg,N;
    cin>>Cmax>>D>>Davg>>N;
    for(int i=0;i<N;i++)
    cin>>sta[i].price>>sta[i].distance;
    sta[N].price=0;
    sta[N].distance=D;
    sort(sta,sta+N,cmp);
    if(sta[0].distance!=0)
    cout<<"The maximum travel distance = 0.00";
    else
    {
        int now=0;
        double ans=0.0,nowTank=0.0,MAX=Cmax*Davg;//总的花费，当前油量，满油行驶距离
        while (now<N)
        {
            int k=-1;
            double minprice=1000000000.0;
            for(int i=now+1;(i<=N&&(sta[i].distance-sta[now].distance)<=MAX);i++)
            {
                if(sta[i].price<minprice)
                {
                    minprice=sta[i].price;
                    k=i;
                    if(minprice<sta[now].price)
                    break;
                }
            }
            if(k==-1) break;
            double need=(sta[k].distance-sta[now].distance)/Davg;
            if(minprice<sta[now].price)
            {
                if(nowTank<need)
                {
                    ans+=(need-nowTank)*sta[now].price;
                    nowTank=0;
                }
                else nowTank-=need;
            }
            else
            {
                ans+=(Cmax-nowTank)*sta[now].price;
                nowTank=Cmax-need;
            }
            now=k;
        }
        if(now==N)
        cout<<fixed<<setprecision(2)<<ans;
        else cout<<"The maximum travel distance = "<<fixed<<setprecision(2)<<sta[now].distance+MAX;
    }
     
}