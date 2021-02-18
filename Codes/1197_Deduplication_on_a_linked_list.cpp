#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;
const int maxn = 100010;

struct Node
{
    int address;
    int data;
    int next;
    int order;
}node[maxn];

bool IsExisted[1008]={false};
bool cmp(Node a,Node b)
{
    return a.order<b.order;
}

int main()
{
    for(int i=0;i<maxn;i++)
    node[i].order=22222222;
    int BeginAddr,n;
    cin>>BeginAddr>>n;
    int addr;
    int validCount=0;
    int deleteCount = 0;
    for(int i=0;i<n;i++)
    {
        cin>>addr>>node[addr].data>>node[addr].next;
        node[addr].address=addr;
       
    }
    for(int p=BeginAddr;p != -1;p=node[p].next)
    {
         if(IsExisted[abs(node[p].data)]==false)
        {
            IsExisted[abs(node[p].data)]= true;
            node[p].order=validCount;
            validCount++;
        }
        else
        {
             node[p].order=11111111+deleteCount;
             deleteCount++;
        }
    }
    sort(node,node+maxn,cmp);
    for(int i=0;i<validCount-1;i++)
    {
        cout<<setfill('0')<<setw(5)<<node[i].address<<" ";
        cout<<node[i].data<<" ";
        cout<<setfill('0')<<setw(5)<<node[i+1].address<<endl;
    }
    cout<<setfill('0')<<setw(5)<<node[validCount-1].address<<" ";
    cout<<node[validCount-1].data<<" ";
    cout<<"-1"<<endl;
    for(int i=validCount;i<validCount+deleteCount-1;i++)
    {
        cout<<setfill('0')<<setw(5)<<node[i].address<<" ";
        cout<<node[i].data<<" ";
        cout<<setfill('0')<<setw(5)<<node[i+1].address<<endl;
    }
    cout<<setfill('0')<<setw(5)<<node[validCount+deleteCount-1].address<<" ";
    cout<<node[validCount+deleteCount-1].data<<" ";
    cout<<"-1"<<endl;
}

