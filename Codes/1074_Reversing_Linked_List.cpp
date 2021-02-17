#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

struct Node
{
    int address;
    int data;
    int next;
    int order;
}node[100010];

bool cmp(Node a, Node b)
{
    return a.order <b.order ;
}

int main()
{
    for(int i=0;i<100010;i++)
    {node[i].order=100010;}
    int BeginAddr,NodeCount,K,address;
    cin>>BeginAddr>>NodeCount>>K;
    for(int i=0;i<NodeCount;i++)
    {
        cin>>address>>node[address].data>>node[address].next;
        node[address].address=address;
    }
    //int p=BeginAddr;
    int count=0;//计算有效节点
   for(int p = BeginAddr;p!= -1;p=node[p].next)
    {
        node[p].order = count;
        count++;
    }
    sort(node,node+100010,cmp);
    for(int i=0;i<count/K;i++)
    {
        for(int j=i*K+K-1;j>i*K;j--)
        {
            cout<<setfill('0')<<setw(5)<<node[j].address<<" ";
            cout<<node[j].data<<" ";
            cout<<setfill('0')<<setw(5)<<node[j-1].address<<endl;
        }
        cout<<setfill('0')<<setw(5)<<node[i*K].address<<" ";
        cout<<node[i*K].data<<" ";
        if(i<count/K-1)
        {
            cout<<setfill('0')<<setw(5)<<node[i*K+2*K-1].address<<endl;
        }
        else if(count%K ==0)
       { cout<<"-1"<<endl;}
       else  cout<<setfill('0')<<setw(5)<<node[i*K+K].address<<endl;
    }
    if(count%K !=0)
    {
        for(int j=(count/K)*K;j<count-1;j++)
        {
            
            cout<<setfill('0')<<setw(5)<<node[j].address<<" ";
            cout<<node[j].data<<" ";
            cout<<setfill('0')<<setw(5)<<node[j].next<<endl;
        }
        cout<<setfill('0')<<setw(5)<<node[count-1].address<<" ";
        cout<<node[count-1].data<<" ";
        cout<<node[count-1].next<<endl;

    }
}