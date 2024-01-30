#include <stdio.h>
void spiral(int a[][1000],int n){
    int startrow=0;
    int endrow=n-1;
    int startcol=0;
    int endcol=n-1;
    int static count=1;
    while(startrow<=endrow && startcol<=endcol){
        for(int i=startcol;i<=endcol;i++){
            a[startrow][i]=count;
            count++;
        }
        startrow++;
        for(int i=startrow;i<=endrow;i++){
            a[i][endcol]=count;
            count++;
        }
        endcol--;
        for(int i=endcol;i>=startcol;i--){
            a[endrow][i]=count;
            count++;
        }
        endrow--;
        for(int i=endrow;i>=startrow;i--){
            a[i][startcol]=count;
            count++;
        }
        startcol++;
        


    }
}

int main(){
    int n;
    scanf("%d",&n);
    int a[1000][1000];
    spiral(a,n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }

}