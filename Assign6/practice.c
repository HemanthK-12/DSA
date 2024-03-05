#include<stdio.h>
void merge()
{
    int n1=mid-l+1;
    int n2=r-mid;
    int left[n1],right[n2];

    for(int i=0;i<n1;i++)
    {
        left[i]=arr[l+i];
    }
    for(int i=0;i<n2;i++)
    right[i]=arr[mid+j+1];

    int i=0,j=0,k=l;
    while(i<n1&&j<n2)
    {
        if(left[i]<=right[j])
        arr[k++]=left[i++];
        else
        arr[k++]==right[j++];
    }
    while(i<n1)
    arr[k++]=left[i++];
    while(j<n2)
    arr[k++]==right[j++];
}
void mergesort()
{
    int mid=(l+r)/2;
    mergesort(arr,l,mid);
    mergesort(arr,mid+1,r);
    merge(arr,l,mid,r);
}