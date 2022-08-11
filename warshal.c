#include<stdio.h>
int count;
int max(int a,int b)
{
    return a>b?a:b;

}
void warshal(int p[10][10],int n)
{
    int k,i,j;
    for(k=0;k<n;k++)
    {
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                count++;
                p[i][j]=max(p[i][j],p[i][k]&&p[k][j]);
            }
        }

    }
}
void main()
{
 int j,i,n;
  printf("Enter the number of vertices\n");
  scanf("%d",&n);
  int p[n][n];
  printf("Enter the adjacency matrix:\n");
  for(i=0;i<n;i++)
  {
    for(j=0;j<n;j++)
    {
        scanf("%d",&p[i][j]);
    }
  }
  printf("\nInputed matrix:\n");
  for(i=0;i<n;i++)
  {
    for(j=0;j<n;j++)
    {
        printf("%d ",p[i][j]);
    
    }
    printf("\n");
  }
  warshal(p,n);
  printf("\n Transitive closure:\n");
    for(i=0;i<n;i++)
  {
    for(j=0;j<n;j++)
    {
        printf("%d ",p[i][j]);
    
    }
    printf("\n");
  }
  printf("count :%d\n ",count);


}
