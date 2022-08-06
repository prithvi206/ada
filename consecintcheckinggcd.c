//To find the GCD of two non negative integers by consecutive integer checking algorithm

#include<stdio.h>
void main()
{
    int m,n,min,temp1,temp2,count=0,gcd;
    printf("\nEnter the 2 non-negative integers:");
    scanf("%d %d",&m,&n);

    if(m>n)
    {
        min=n;
    }
    else
    {
        min=m;
    }
    while(min!=1)
    {
        temp1 = m%min;
        count++;
        if(temp1==0)
        {
            temp2=n%min;
            count++;
            if(temp2==0)
            {
                gcd=min;
                break;
            }
        }
        min = min-1;
    }
    printf("The gcd is %d\n",gcd);
    printf("The number of operation:%d\n",count);

}