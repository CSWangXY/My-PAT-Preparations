#include<iostream>
#include<queue>
using namespace std;

struct node{
    int left;
    int right;
};

int trans(string s)
{
    if(s=="-")
        return -1;
    else
    {
        int ans = 0;
        for(int i=0; i<s.size(); i++)
        {
            ans = ans*10 + s[i] - '0';
        }
        return ans;
    }
}

int main()
{
    int N;
    cin>>N;
    node tree[25];
    bool used[25] = {false};
    for(int i=0; i<N; i++)
    {
        string tmp;
        cin>>tmp;
        int l = trans(tmp);
        tree[i].left = l;
        cin>>tmp;
        int r = trans(tmp);
        tree[i].right = r;
        if(l != -1)
            used[l] = true;
        if(r != -1)
            used[r] = true;
    }
    int root;
    for(int i=0; i<N; i++)
    {
        if(used[i] == false)
        {
            root = i;
            break;
        }
    }
    queue<int> q;
    q.push(root);
    bool flag = true;
    int curr;
    while(!q.empty())
    {
        curr = q.front();
        q.pop();
        if(tree[curr].left!= -1 && tree[curr].right != -1)
        {
            q.push(tree[curr].left);
            q.push(tree[curr].right);
        }
        if(tree[curr].left== -1 && tree[curr].right!= -1)
        {
         flag = false;
         q.push(tree[curr].right);
        }
        if((tree[curr].left != -1&& tree[curr].right== -1)||(tree[curr].left== -1 && tree[curr].right== -1))
        {
            
            if(tree[curr].left != -1&& tree[curr].right== -1)
                q.push(tree[curr].left);
            while(!q.empty())
            {
                if(!(tree[q.front()].left==-1 && tree[q.front()].right==-1))
                   { flag = false;}
                curr = q.front();
                q.pop();
            }
        }
        
    }
    if(flag == true)
        cout<<"YES"<<" "<<curr;
    else
        cout<<"NO"<<" "<<root;

}