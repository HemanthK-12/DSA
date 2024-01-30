#include<stdio.h>
int max_sum(int a[],int n){
    int sum=0;
    int max_sum=a[0];
    for(int i=0;i<n;i++){
        sum+=a[i];
        max_sum=(max_sum>sum)?max_sum:sum;
        if(sum<0){
            sum=0;
        }
    }
    return max_sum;

}
int main(){
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    printf("%d",max_sum(a,n));
}