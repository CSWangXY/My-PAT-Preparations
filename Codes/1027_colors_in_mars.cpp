#include <iostream>
using namespace std;

int main()
{
   char ty[13]={'0','1','2','3','4','5','6','7','8','9','A','B','C'};
    int ord[6]={1,0,3,2,5,4};
    char  Z[20]={0};
   int Count=0;
    int Count1;
   int Number;
    char Result[6];
   for(int i=0;i<3;i++)
   {
       cin>>Number;
       if(Number<13)
       {
           Z[Count]=ty[Number];
           Z[Count+1]='0';
           Count+=2;
       }
       else
       {
           do 
           {
           Z[Count++]=ty[Number%13];
           Number/=13;
            }while(Number!=0);        
        }
       Result[Count1]=Z[ord[Count-2]];
       Result[Count1+1]=Z[ord[Count-1]];
       Count1+=2;
       
   }
    cout<<"#";
    for(int i=0;i<6;i++)
        cout<<Result[i];
}
