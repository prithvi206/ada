#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define X 10
#define Y 100
#define INCRE 10
int count=0;

void merge(int arr[],int l,int m,int r)
{
    
    int n1= m-l+1;
    int n2= r-m;
    int i,j,k;
    int L[n1],R[n2];
    for(i=0;i<n1;i++)
    {
        L[i]= arr[l+i];
    }
    for(j=0;j<n2;i++)
    {
        R[j]=arr[m+j+1];
    }
i=j=0;
k=l;
while(i<n1 && j<n2)
{
    count++;
if(L[i]<R[j])
{
    arr[k]=L[i];
    i++;

}
else
{
    arr[k]=R[j];
    j++;
}
k++;
}

while(i<n1)
{
    count++;
    arr[k]=L[i];
    i++;
    k++;
}
while(j<n2)
{
    count++;
     arr[k]=R[j];
    j++;
}
}


void Mergesort(int a[],int l,int r)
{
    if(l<r)
    {
       int  m=(l+r)/2;
        Mergesort(a,l,m);
        Mergesort(a,m+1,r);
        merge(a,l,m,r);
    }
}

void main()
{
    int i,n;
    system("rm -f count_*.txt");
    FILE *fp1,*fp2;
    fp1=fopen("count_best.txt","a");
    fp2=fopen("count_average.txt","a");
    srand(time(NULL));
    for(n=X;n<Y;n+=INCRE)
    {
        int arr[n];
        for(i=0;i<n;i++)
        {
            arr[i]=i;
        }
        Mergesort(arr,0,n-1);
        fprintf(fp1,"%d\t%d\n",n,count);
        count=0;
        
        for(i=0;i<n;i++)
        {
            arr[i]=rand()%n;
        }
        Mergesort(arr,0,n-1);
        fprintf(fp2,"%d\t%d\n",n,count);
        count=0;

    }
    fclose(fp1);
    fclose(fp2);
}
