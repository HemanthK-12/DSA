#include <stdio.h>
int difference(int a[],int n){
    int max=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            
            int diff=a[j]-a[i];
            if(diff>max){
                max=diff;
            }

        }
    }
    return max;

}
int main(){
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    printf("%d",difference(a,n));
}