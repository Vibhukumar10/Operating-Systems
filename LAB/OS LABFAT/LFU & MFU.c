#include<stdio.h>
#include<stdlib.h>
int lfu();
int mfu()
{
    int hit=0,miss=0,i,j,noPages,noFrames,min;
    int frames[10],pages[20];
    int flag=0,flag1=0,flag2=0;
    int flagFound=0;
    int count=0;
    int frameAge[50],frameFREQ[50];
    printf("enter number of frames\n");
    scanf("%d",&noFrames);
    printf("enter number of pages\n");
    scanf("%d",&noPages);
    printf("enter the page string ");

    for(i=0;i<noPages;i++)
    {
        scanf("%d",&pages[i]);
    }
    for(i=0;i<noFrames;i++)
    {
        frames[i]=-1;
        frameAge[i]=-1;
    }
    for(j=0;j<noFrames;j++)
       frameFREQ[j]=0;
    for(j=0;j<noPages;j++)
    {
        int index;
        printf(" page:%d   ",pages[j] );
        flagFound=0,flag=0,flag2=0;
        for(i=0;i<noFrames;i++)
        {
            if(frames[i]==pages[j])
            {
                flagFound=1;
                flag=1;
                index=i;
                printf("hit ");
                hit++;
                break;
            }
        }
        if(flagFound==0)          //if frame not found and empty frame avalible
        {
            for(i=0;i<noFrames;i++)
            {
                if(frames[i]==-1)
                {
                    frames[i]=pages[j];
                    flag=1;
                    count++;
                    frameAge[i]=count;
                    miss++;
                    frameFREQ[i]=1;
                    printf("miss ");
                    break;
                }
            }
            if(flag==0)
            {
                int bestmfu=0;
                for(i=0;i<noFrames;i++)
                {
                    if(frameFREQ[i]>frameFREQ[bestmfu])
                        bestmfu=i;
                }
                frames[bestmfu]=pages[j];
                miss++;
                printf("miss ");
                frameFREQ[bestmfu]=1;
            }
        }  //FLAG FOUND ends
        else
        {
            frameFREQ[index]++;
        }
        for(i=0;i<noFrames;i++)
        {
            printf("   %d ",frames[i]);
        }
        printf("\n");
    }
    //printf("number of hits %d\n",hit);
    //printf("number of miss %d\n",miss);
    float faults;
    faults=noPages-hit;
    printf("\n\nPage Faults:\t%d\n",faults);
    printf("Page Hit:\t%d\n",hit);
    //printf("Page Miss:\t%d\n",miss);
    float hitratio;
    float hitt=hit;
    float pagess=noPages;
    hitratio=hitt/pagess;
    printf("Hit Ratio:\t%.2f\n",hitratio);
    float missratio;
    missratio=1-hitratio;
    printf("Miss Ratio:\t%.2f\n\n\n",missratio);
}
int lfu()
{
    int total_frames, total_pages, hit = 0;
    int pages[25], frame[10], arr[25], time[25];
    int m, n, page, flag, k, minimum_time, temp;
    printf("Enter Total Number of Pages: ");
    scanf("%d", &total_pages);
    printf("Enter Total Number of Frames: ");
    scanf("%d", &total_frames);
    for(m = 0; m < total_frames; m++)
    {
          frame[m] = -1;
    }
    for(m = 0; m < 25; m++)
    {
          arr[m] = 0;
    }
    printf("Enter Values of Reference String\n");
    for(m = 0; m < total_pages; m++)
    {
          printf("Enter Value No.[%d]:\t", m + 1);
          scanf("%d", &pages[m]);
    }
    printf("\n");
    for(m = 0; m < total_pages; m++)
    {
          arr[pages[m]]++;
          time[pages[m]] = m;
          flag = 1;
          k = frame[0];
          for(n = 0; n < total_frames; n++)
          {
                if(frame[n] == -1 || frame[n] == pages[m])
                {
                      if(frame[n] != -1)
                      {
                            hit++;
                      }
                      flag = 0;
                      frame[n] = pages[m];
                      break;
                }
                if(arr[k] > arr[frame[n]])
                {
                      k = frame[n];
                }
          }
          if(flag)
          {
                minimum_time = 25;
                for(n = 0; n < total_frames; n++)
                {
                      if(arr[frame[n]] == arr[k] && time[frame[n]] < minimum_time)
                      {
                            temp = n;
                            minimum_time = time[frame[n]];
                      }
                }
                arr[frame[temp]] = 0;
                frame[temp] = pages[m];
          }
          for(n = 0; n < total_frames; n++)
          {
                printf("%d\t", frame[n]);
          }
          printf("\n");
    }
    float faults;
    faults=total_pages-hit;
    printf("\n\nPage Faults:\t%d\n",faults);
    printf("Page Hit:\t%d\n",hit);
    float hitratio;
    float hitt=hit;
    float pagess=total_pages;
    hitratio=hitt/pagess;
    printf("Hit Ratio:\t%.2f\n",hitratio);
    float missratio;
    missratio=1-hitratio;
    printf("Miss Ratio:\t%.2f\n\n\n",missratio);
    return 0;
}
int main()
{
	int ch;
	do{
		printf("1.LFU\n2.MFU\n3.Exit\n");
		//printf("for mfu press '2'\n");
		printf("Enter your choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				lfu();
                break;
			case 2:
				mfu();
                break;
            case 3:
                exit(0);
                break;
			default:
				printf("invalid choice");
                break;
		}
	}while(1);
}

