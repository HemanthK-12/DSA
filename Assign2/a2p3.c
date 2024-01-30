#include <stdio.h>
int pivot(int a[],int n1,int n2){
    int start=n1;
    int end=n2-1;
    int mid;
    while(start<end){
        mid=(start+end)/2;
        if(a[mid]>=a[0]){
            start=mid+1;
        }
        else{
            end=mid;
        }
       
}
 return start;
}
int binary(int a[],int n1,int n2){
    int start=n1;
    int end=n2-1;
    while(start<=end){
        int mid=start+(end-start)/2;
        if(a[mid]==7){
            return mid;
        }
        else if(a[mid]<7){
            start=mid+1;
        }
        else{
            end=mid-1;
        }
    }
    return -1;

}
int main(){
    int n;
    scanf("%d",&n);
    int k=n-1;
    int arr[k];
    for(int i=0;i<k;i++){
        scanf("%d",&arr[i]);
    }
    int p1=pivot(arr,0,n);
    if(binary(arr,0,p1)){
        printf("%d",binary(arr,0,p1));
    }
    else if(binary(arr,p1,n)){
        printf("%d",binary(arr,p1,n));
    }
    else{
        printf("%d",-1);
    }
}