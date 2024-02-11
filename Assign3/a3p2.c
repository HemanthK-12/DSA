#include<stdio.h>
int max_str(char a[],int n)
{
    int visited[256];
    for(int i=0;i<256;i++)
        visited[i]=-1;

    int start=0,result=0;
    for(int i=0;i<n;i++)
    {
        if(visited[a[i]]!=-1 && visited[a[i]]>=start)
            start=visited[a[i]]+1;
        visited[a[i]]=i;
        if(i-start+1>result)
            result=i-start+1;
    }
    return result;
}
int main(){
    int n;
    scanf("%d",&n);
    char a[n];
    scanf("%s",a);
    printf("%d",max_str(a,n));

}