#include<stdio.h>
int main()
{

        int i;
        printf("hello before fork \n");
        printf("i : %d\n",i);

        i=fork();
        printf("\n");

        if(i==0)
        {

                printf("Child has started\n\n");
                printf("child printing first time \n");

                printf("getpid : %d getppid : %d \n",getpid(),getppid());
                sleep(5);
                printf("\nchild printing second time \n");
                printf("getpid : %d getppid : %d \n",getpid(),getppid());
        }
        else
        {
                printf("parent has started\n");
                printf("getpid : %d  getppid : %d \n",getpid(),getppid());
                printf("\n");

        }

        printf("Hi after fork i : %d\n",i);

        return 0;


}
