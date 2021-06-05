#include<iostream>
using namespace std;
void fcfs(float bt[][3],int n)
{
    float sum=0,average1,average2;
    float btsum[n];
    btsum[0]=bt[0][0];
    for(int i=1;i<n;i++)
    {
        btsum[i]=bt[i][0]+btsum[i-1];
    }
    float btsum0[n+1];
    btsum0[0]=0;
    for(int i=1;i<=n;i++)
    {
        btsum0[i]=btsum[i-1];
    }
    int choice2;
    cout<<"Enter Choice(1=Waiting Time| 2=Turnout Time): ";
    cin>>choice2;
    switch(choice2)
    {
    case 1:
        for(int i=0;i<n;i++)
        {
            cout<<"Waiting Time for process "<<i+1<<": "<<btsum0[i]<<endl;
            sum=sum+btsum0[i];
        }
        average1=sum/n;
        cout<<"Average waiting time= "<<average1<<endl;
        break;
    case 2:
        for(int i=1;i<=n;i++)
        {
            cout<<"Turnout Time for process "<<i<<": "<<btsum0[i]<<endl;
            sum=sum+btsum0[i];
        }
        average2=sum/n;
        cout<<"Average turnout time= "<<average2<<endl;
    }
}
/*void sjf()
{
    int min_ind=0;
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(bt[min_ind]>bt[j])
            {
                min_ind=j;
            }
        }
        if(bt[min_ind]>bt[i])
        {
            float temp=bt[min_ind];
            bt[min_ind=bt[i];
            bt[i]=temp;
        }

    }
}*/
void priority_scheduling(float bt[][3],int n)
{
    int priority_array[n][2];
    cout<<"Enter the priority of each element: ";
    for(int j=0;j<n;j++)
    {
        cin>>bt[j][1];
    }
    for(int j=1;j<=n;j++)
    {
        for(int i=0;i<n;i++)
        {
            if(bt[i][1]==j)
            {
                priority_array[j-1][0]=bt[i][1];
                priority_array[j-1][1]=i+1;
            }
        }
     }
     int choice2;
     cout<<"Enter choice(1=Waiting Time| 2=Turnout Time)";
     cin>>choice2;
     float sum=0,average1,average2;
     float btsum[n];
     btsum[0]=priority_array[0][0];
     for(int i=1;i<n;i++)
     {
         btsum[i]=priority_array[i][0]+btsum[i-1];
     }
     float btsum0[n+1];
     btsum0[0]=0;
     for(int i=1;i<=n;i++)
     {
         btsum0[i]=btsum[i-1];
     }
     switch(choice2)
     {
     case 1:
        for(int j=1;j<=n;j++)
        {
            for(int i=0;i<n;i++)
            {
                if(priority_array[i][1]==j)
                {
                    cout<<"Waiting Time for process "<<j<<": "<<btsum0[i]<<endl;
                }
            }
        }
        average1=sum/n;
        cout<<"Average waiting time= "<<average1<<endl;
        break;
     case 2:
        for(int j=1;j<=n;j++)
        {
            for(int i=0;i<n;i++)
            {
                if(priority_array[i][1]==j)
                {
                    cout<<"Turnout Time for process "<<j<<": "<<btsum0[i+1]<<endl;
                }
            }
        }
        average2=sum/n;
        cout<<"Average turnout time= "<<average2<<endl;
    }
}
int main()
{
    int n;
    cout<<"Enter the number of processes: ";
    cin>>n;
    float bt[n][3];
    for(int i=0;i<n;i++)
    {
        cout<<"Enter the Burst Time for process "<<i+1<<": ";
        cin>>bt[i][0];
    }

    int choice;
    cout<<"\nEnter Choice(1=First Come First Serve |2=Shortest Job First| 3=Priority Scheduling| 4=Round Robbin): ";
    cin>>choice;
    cout<<endl;
    switch(choice)
    {
    case 1:
        fcfs(bt,n);
        break;
    /*case 2:
        sjf();
        break;*/
    case 3:
        priority_scheduling(bt,n);
        break;
    /*case 4:
        Round_robbin();
        break;*/
    }
    return 0;
}

