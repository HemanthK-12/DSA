#include<stdio.h>
int arraysum(int arr[],int p,int q){
    int sum=0;
    for(int i=p;i<=q;i++){
        sum=sum+arr[i];
    }
    return sum;
}

int main(){
    int n,q;
    
    scanf("%d %d",&n,&q);
    int arr[n];
    for(int i=1;i<=n;i++){
        scanf("%d",&arr[i]);
    }
    int arr2[q],arr3[q];
    for(int i=0;i<q;i++){
        scanf("%d %d",&arr2[i],&arr3[i]);
    }
    for(int i=0;i<q;i++){
        printf("%d\n",arraysum(arr,arr2[i],arr3[i]));
    }

}