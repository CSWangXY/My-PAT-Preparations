#include <iostream>
#include <stack>
#include <cstring>
#include <algorithm>
using namespace std;

struct node
{
    int data;
    node* lchild;
    node* rchild;
};

int pre[35],in[35],post[35];
int n;//用于记录节点个数

node* create(int preL, int preR, int inL, int inR)
{
    if(preL>preR)
    return NULL;
    node* root = new node;
    root->data=pre[preL];
    int k;
    for(k=inL;k<=inR;k++)
    {
        if(in[k]==pre[preL])
            break;
    }
    int LeftNum=k-inL;
    root->lchild = create(preL+1,preL+LeftNum,inL,k-1);
    root->rchild = create(preL+LeftNum+1,preR,k+1,inR);
    return root;
}

int num = 0;
int postorder(node* root)
{
    if(root == NULL)
    {return 0;}
    postorder(root->lchild);
    postorder(root->rchild);
    cout<<root->data;
    num++;
    if(num<n)
    cout<<" ";
}


int main()
{
    cin>>n;
    char str[5];
    stack<int> st;
    int x;
    int PreCount=0;
    int InCount=0;
    for(int i=0;i<2*n;i++)
    {
        cin>>str;
        if(strcmp(str,"Push")== 0)
        {
            cin>>x;
            pre[PreCount]=x;
            PreCount++;
            st.push(x);
        }
        else
        {
            in[InCount]=st.top();
            InCount++;
            st.pop();
        }
    }
    node* root = create(0,n-1,0,n-1);
    postorder(root);
}