#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

struct Node
{
    int address;
    int key;
    int next;
    bool flag;
}node[100010];

bool cmp(Node a,Node b)
{
    if(a.flag==false || b.flag == false)
    return a.flag>b.flag;
    else return a.key <b.key;
}

int main()
{
    int num,BeginAddr,addr;
    cin>>num>>BeginAddr;
    for(int i=0;i<100010;i++)
    node[i].flag=false;
    for(int i=0;i<num;i++)
    {
        cin>>addr>>node[addr].key>>node[addr].next;
        node[addr].address=addr;
    }
    int count=0;
    for(int p=BeginAddr;p!= -1;p=node[p].next)
    {
        node[p].flag=true;
        count++;
    }
    sort(node,node+100010,cmp);
    if(count != 0)
    {
    cout<<count<<" ";
    cout<<setfill('0')<<setw(5)<<node[0].address<<endl;
    for(int i=0;i<count-1;i++)
    {
        cout<<setfill('0')<<setw(5)<<node[i].address<<" ";
        cout<<node[i].key<<" ";
        cout<<setfill('0')<<setw(5)<<node[i+1].address<<endl;
    }
    cout<<setfill('0')<<setw(5)<<node[count-1].address<<" ";
    cout<<node[count-1].key<<" ";
    cout<<"-1"<<endl;
    }
    else cout<<"0 -1";
}