#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define X 10
#define Y 100
#define INCRE 10

void selectionsort(int arr[],int n,char filename[])
{
    int i,j,min_pos,temp,count=0;
    for(i=0;i<n;i++)
    {
        min_pos=i;
        for(j=i+1;j<n;j++)
        {
            count++;
            if(arr[min_pos]>arr[j])
            {
                min_pos=j;
            }
        }
        temp=arr[min_pos];
        arr[min_pos]= arr[i];
        arr[i]=temp;

    }
    FILE *fp = fopen(filename,"a");
    fprintf(fp,"%d\t%d\n",n,count);
    fclose(fp);
}

void main()
{
    int i,n;
    system("rm -f count_*.txt");
    srand(time(NULL));
    for(n=X;n<Y;n+=INCRE)
    {
     int arr[n];
      for ( i = 0; i < n; i++)
      {
        arr[i]=rand()% n;
      }
      selectionsort(arr,n,"count_average.txt");
      
    }
}