#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define X 10
#define Y 100
#define INCRE 10

void insertionsort(int a[],int n, char filename[])
{
    int i,j,count=0;
    int temp;
    for(i=1;i<n;i++)
    {
        temp=a[i];
        for(j=i-1;j>=0;j--)
        {
            count++;
            if(a[j]<temp)
               break;
            a[j+1]=a[j];
        }
        a[j+1]=temp;

    }
    FILE *fp = fopen(filename,"a");
    fprintf(fp,"%d\t%d\n",n,count);
    fclose(fp);

}

void main()
{
    int i,n;
    system("rm -f count_*.txt");
    for(n=X;n<Y;n+=INCRE)
    {
        int arr[n];
        for(i=0;i<n;i++)
        {
            arr[i]=i;
        }
        insertionsort(arr,n,"count_best.txt");
        for(i=0;i<n;i++)
        {
            arr[i]=n-i;
        }
        insertionsort(arr,n,"count_worst.txt");
        for(i=0;i<n;i++)
        {
            arr[i]=rand()%n;
        }
        insertionsort(arr,n,"count_average.txt");
    }
}