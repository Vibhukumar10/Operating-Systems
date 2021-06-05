#include<stdio.h>
int main()
{
    int n;
    printf("Enter the number of processes: ");
    scanf("%d",&n);
    float total[n];
    for(int i=0;i<n;i++)
    {
        printf("Enter Total Execution Time for process %d: ",i+1);
        scanf("%f",&total[i]);
    }
    float io1[n];
    float io2[n];
    for(int i=0;i<n;i++)
    {
        io1[i]=(total[i]/10)*2;
        io2[i]=(total[i]/10);
    }


    /*for(int i=0;i<n;i++)
    {
        printf("%d",io1[i]);
    }*/
    float burst[n];
    for(int i=0;i<n;i++)
    {
        burst[i]=total[i]-io1[i]-io2[i];
    }
    float idle=io1[0]+io2[n-1];
    float sumburst=0.0;
    for(int i=0;i<n;i++)
    {
        sumburst+=burst[i];
    }
    float cpuidle=(idle/(idle+sumburst))*100;
    printf("\n\nThe percentage of CPU idle time is: %.2f\n\n",cpuidle);
}
