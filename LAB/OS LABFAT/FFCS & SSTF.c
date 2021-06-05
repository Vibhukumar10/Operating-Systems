#include<stdio.h>
#include<stdlib.h>
int absolute(int a,int b)
{   int c;
    c=a-b;
    if(c<0)
        return -c;
    else
        return c;
}
int main()
{
    printf("MENU DRIVEN C CODE FOR FCFS AND SSTF DISK SCHEDULING ALGORITHM");
    int choice,m,n,x,start,i,j,pos,min,a[15],count;
    count=0;
    printf("\nEnter the number of cylinders: ");
    scanf("%d",&m);
    printf("\nEnter the number of requests: ");
    scanf("%d",&n);
    printf("\nEnter current position: ");
    scanf("%d",&start);
    printf("\nEnter the request queue: ");
    for(i=0;i<n;i++)
        {scanf("%d",&a[i]);
        if(a[i]>=m)
        {
            printf("\ninvalid input");
            scanf("%d",&a[i]);
        }
    }
    do
    {
        printf("\n\nDISK SCHEDULING ALGORITHMS\n1. FCFS\n2. SSTF\n");
        printf("\nEnter choice :");
        scanf("%d",&choice);
        count=0;
        x=start;
        switch(choice)
        {
            case 1:
                printf("\nFCFS :\n");
                printf("Scheduling services the request in the order that follows:\n%d\t",start);
                for(i=0;i<n;i++)
                {
                    x-=a[i];
                    if(x<0)
                    x=-x;
                    count+=x;
                    x=a[i];
                    printf("%d\t",x);
                }
                printf("\nTotal Head Movement :%d Cylinders",count);
                break;
            case 2:
                printf("\nSSTF :\n");
                printf("Scheduling services the request in the order that follows:\n%d\t",start);
                for(i=0;i<n;i++)
                {
                    min=absolute(a[i],x);
                    pos=i;
                    for(j=i;j<n;j++)
                    if(min>absolute(x,a[j]))
                    {
                        pos=j;
                        min=absolute(x,a[j]);
                    }
                    count+=absolute(x,a[pos]);
                    x=a[pos];
                    a[pos]=a[i];
                    a[i]=x;
                    printf("%d\t",x);
                }
                printf("\nTotal Head Movement: %d Cylinders",count);
                break;
        }
        printf("\nDo you want to continue(1 to continue) :");
        scanf("%d",&choice);
    }while(choice==1);
    printf("VIBHU KUMAR SINGH\n");
    printf("19BCE0215\n");
}
