#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    while(n>0){
        int tc;
        cin>>tc;
        int x=0,max=0;
    for(int i=2;i<=(tc);i++)
    {
        int k=(tc/i);
        int sum=(k*i*(k+1)*0.5);
        if(sum>max)
        {
            max=sum;
            x=i;
        }
    }
    cout<<x<<endl;
    n--;
    }
    return 0;
}