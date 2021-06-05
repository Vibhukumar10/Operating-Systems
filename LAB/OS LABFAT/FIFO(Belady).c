#include<stdio.h>
#include<stdlib.h>
int fifo()
{
      int referenceString[50], pageFaults = 0, m, n, s, pages, frames;
      printf("\nEnter the number of Pages: ");
      scanf("%d", &pages);
      float pagesss=pages;
      printf("\nEnter reference string values:\n");
      for(m = 0; m < pages; m++)
      {
            printf("Value No. [%d]:\t", m + 1);
            scanf("%d", &referenceString[m]);
      }
      printf("\n What are the total number of frames:\t");
      {
            scanf("%d", &frames);
      }
      int temp[frames];
      for(m = 0; m < frames; m++)
      {
            temp[m] = -1;
      }
      for(m = 0; m < pages; m++)
      {
            s = 0;
            for(n = 0; n < frames; n++)
            {
                  if(referenceString[m] == temp[n])
                  {
                        s++;
                        pageFaults--;
                  }
            }
            pageFaults++;
            if((pageFaults <= frames) && (s == 0))
            {
                  temp[m] = referenceString[m];
            }
            else if(s == 0)
            {
                  temp[(pageFaults - 1) % frames] = referenceString[m];
            }
            printf("\n");
            for(n = 0; n < frames; n++)
            {
                  printf("%d\t", temp[n]);
            }
      }
      printf("\n\nTotal Page Faults: %d", pageFaults);
      float faults=pageFaults;
      float miss=faults/pagesss;
      float hit=1-miss;
      printf("\nHit ratio: %.2f",hit);
      printf("\nMiss ratio: %.2f\n\n",miss);
      return 0;
}


int main()
{
	int ch;
	do{
		printf("1.FIFO\n2.Exit\nEnter your choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				fifo();
                break;
            case 2:
                exit(0);
                break;
			default:
				printf("invalid\n");
                break;
		}
	}while(1);
}
