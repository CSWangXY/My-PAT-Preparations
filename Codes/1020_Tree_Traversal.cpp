#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

struct node
{
    int data;
    node* lchild;
    node* rchild;
};

int pre[35],in[35],post[35];
int n;//节点个数

node* create(int postL,int postR, int inL,int inR)
{
    if(postL >postR)
        return NULL;
    node* root =new node;
    root->data = post[postR];
    int k;
    for( k = inL; k<=inR;k++)
    {
        if(in[k]==post[postR])
            break;
    }
    int numleft=k - inL;
    root->lchild =create(postL,postL+numleft-1,inL,k-1);
    root->rchild = create(postL+numleft,postR-1,k+1,inR);
    return root;
}

int num = 0;
void BFS(node* root)
{
    queue<node*> q;
    q.push(root);
    while(!q.empty())
    {
        node* now = q.front();
        q.pop();
        cout<<now->data;
        num++;
        if(num<n)
        cout<<" ";
        if(now->lchild !=NULL)
        q.push(now->lchild);
        if(now->rchild !=NULL)
        q.push(now->rchild);
    }
}

int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {cin>>post[i];}
    for(int i=0;i<n;i++)
    {cin>>in[i];}
    node* root = create(0,n-1,0,n-1);
    BFS(root);
    return 0;
}