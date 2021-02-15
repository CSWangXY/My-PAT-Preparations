#include <iostream>
#include <queue>
using namespace std;

struct mouse
{
    int weight;
    int Rank;
}m[1010];

int main()
{
    int np,ng,order;
    cin>>np>>ng;
    for(int i=0;i<np;i++)
    cin>>m[i].weight;
    queue<int> q;
    for(int i=0;i<np;i++)
    {
        cin>>order;
        q.push(order);
    }
    int temp = np;
    int group;
    while(q.size() != 1)
    {
        if(temp%ng ==0)
        group =temp / ng;
        else group = temp /ng +1;
        for(int i=0;i<group;i++)
        {
            int k=q.front();
            for(int j=0;i<ng;j++)
            {
                if(i*ng +j >=temp) break;
                int front =q.front();
                if(m[front].weight >m[k].weight)
                k=front;
                m[front].Rank = group+1;
                q.pop();
            }
            q.push(k);
        }
        temp = group;
    }
    m[q.front()].Rank = 1;
    for(int i=0;i<np;i++)
    {
        cout<<m[i].Rank;
        if(i<np-1)
        cout<<" ";
    }
}