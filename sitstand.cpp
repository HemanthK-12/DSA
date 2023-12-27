#include <bits/stdc++.h>
using namespace std;

int main() {
    // freopen("sitin.txt","r",stdin);
    // freopen("sitout.txt","w",stdout);

    int r,c,n;
    cin >>r>>c;
    cin >>n;
    if(r*c<=n)
    {
        cout<<r*c<<" "<<(n-r*c)<<endl;
    }
    else
    {
        cout<<n<<" 0"<<endl;
    }

    return 0;
}
