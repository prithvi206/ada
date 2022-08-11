#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define X 10
#define Y 100
#define INCRE 10
int count=0;

void search(int key,int a[] ,int n)
{
    int f=0;
    int l=n-1;
    int m;
    count=0;
    while(f<=l)
    {
        m= (f+l)/2;
        count++;
        if(a[m]==key)
        {

            printf("found at positon %d\n",m+1);
             printf("Count=%d\n",count);
            return;
        }
        else if(a[m]<key)
        {
            f=m+1;
        }
        else
        {
           l=m-1;
        }
    }
    if(f>l)
    {
          printf("\nElement not found\n");
           printf("Count=%d\n",count);
    }
}



int main()
{
    FILE *fp1,*fp2,*fp3;
    system("rm b_best.txt");
    system("rm b_worst.txt");
    system("rm b_avg.txt");
    fp1=fopen("b_best.txt","a");
    fp2=fopen("b_worst.txt","a");
    fp3=fopen("b_avg.txt","a");
    srand(time(0));
    int *a;

     int key,i,n;

     for(n=X;n<Y;n+=INCRE)
     {
      a= (int *)malloc(X*sizeof(int));
      i=0;
      while(i!=n)
      {
        a[i]=i+1;
        printf("%d ",a[i]);
            i++;
      }
       //best case
       key=a[(n-1)/2];
       search(key,a,n);
       fprintf(fp1,"%d\t%d\n",n,count);

       //worst case
        key=a[0];
        search(key,a,n);
        fprintf(fp2,"%d\t%d\n",n,count);

       //average case
        key=a[((n-1)/2)-5];
        search(key,a,n);
        fprintf(fp3,"%d\t%d\n",n,count);

    }


     fclose(fp1);
    fclose(fp2);
    fclose(fp3);
    return 0;


   
}