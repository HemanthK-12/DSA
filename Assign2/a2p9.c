#include <stdio.h>
int max_prof(int a[],int n){
    if(n==1){
        return 0;
    }
    int max_profit=0;
    for(int i=1;i<n;i++){
        int profit=a[i]-a[i-1];
        if(profit>0){
            max_profit+=profit;
        }
    }
return max_profit;
}
int main(){
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++){
    scanf("%d",&a[i]);
    }
    printf("%d",max_prof(a,n));
}