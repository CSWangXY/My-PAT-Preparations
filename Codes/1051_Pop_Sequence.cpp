#include <iostream>
#include <stack>
using namespace std;
int arr[1010];
stack<int> st;

int main()
{
    int m,n,T;
    cin>>m>>n>>T;
    while(T--)
    {
        while(!st.empty())
        {
            st.pop();
        }
        for(int i=1;i<=n;i++)
        {
            cin>>arr[i];
        }
        int current = 1 ;
        bool flag = true;
        for(int i=1; i<=n;i++)
        {
            st.push(i);
            if(st.size()>m)
            {
                flag=false;
                break;
            }
            while(! st.empty()&& st.top()== arr[current])
            {
                st.pop();
                current++;
            }
        }
        if(st.empty() == true && flag == true)
        cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}