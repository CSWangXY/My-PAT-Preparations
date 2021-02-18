#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

struct node
{
    int lchild;
    int rchild;
}Node[15];

bool NotRoot[15]={false};
int n,num=0;//n为节点个数，num为当前已经输出的节点个数

void print(int id)
{
    cout<<id;
    num++;
    if(num<n)
    cout<<" ";
    else cout<<endl;
}

void InOrder(int root)
{
    if(root == -1)
    return ;
    InOrder(Node[root].lchild);
    print(root);
    InOrder(Node[root].rchild);
}

void BFS(int root)
{
    queue<int> q;
    q.push(root);
    while(!q.empty())
    {
        int now=q.front();
        q.pop();
        print(now);
        if(Node[now].lchild!= -1)
        q.push(Node[now].lchild);
        if(Node[now].rchild != -1)
        q.push(Node[now].rchild);
    }
}

void postorder(int root)
{
    if(root ==-1)
        return ;
    postorder(Node[root].lchild);
    postorder(Node[root].rchild);
    swap(Node[root].lchild,Node[root].rchild);

}

int StrToNum(char c)
{
    if(c =='-')
    return -1;
    else
    {
        NotRoot[c-'0'] = true;
        return c-'0';
    }
}

int FindRoot()
{
    for(int i=0;i<n;i++)
    {
        if(NotRoot[i]==false)
        return i;
    }
}

int main()
{
    char lchild,rchild;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>lchild>>rchild;
        Node[i].lchild = StrToNum(lchild);
        Node[i].rchild = StrToNum(rchild);
    }
    int root = FindRoot();
    postorder(root);
    BFS(root);
    InOrder(root);
}