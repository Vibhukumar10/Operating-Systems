#include<stdio.h>
#include<stdlib.h>
int fifo();
int optimal();
int optimal()
{
    int  no_of_pages, frames[10], pages[50], temp[10], flag1, flag2, flag3, i, j, k, pos, max, faults = 0,no_of_frames;
    printf("Enter number of frames: ");
    scanf("%d", &no_of_frames);
    printf("Enter number of pages: ");
    scanf("%d", &no_of_pages);
    float pagesss=no_of_pages;
    printf("Enter page reference string: ");
    for(i = 0; i < no_of_pages; ++i){
        scanf("%d", &pages[i]);

    }

    for(i = 0; i < no_of_frames; ++i){
        frames[i] = -1;
    }
    for(i = 0; i < no_of_pages; ++i){
        flag1 = flag2 = 0;
        for(j = 0; j < no_of_frames; ++j){
            if(frames[j] == pages[i]){
                flag1 = flag2 = 1;
                break;

            }
        }
        if(flag1 == 0){
            for(j = 0; j < no_of_frames; ++j){
                if(frames[j] == -1){
                    faults++;
                    frames[j] = pages[i];
                    flag2 = 1;
                    break;
                }
            }
        }
        if(flag2 == 0){
            flag3 =0;
            for(j = 0; j < no_of_frames; ++j){
                temp[j] = -1;
                for(k = i + 1; k < no_of_pages; ++k){
                    if(frames[j] == pages[k]){
                        temp[j] = k;
                        break;
                    }
                }
            }
            for(j = 0; j < no_of_frames; ++j){
                if(temp[j] == -1){
                    pos = j;
                    flag3 = 1;
                    break;
                }
            }
            if(flag3 ==0){
                max = temp[0];
                pos = 0;
                for(j = 1; j < no_of_frames; ++j){
                    if(temp[j] > max){
                        max = temp[j];
                        pos = j;
                    }
                }
            }
			frames[pos] = pages[i];
			faults++;
        }
        printf("\n");
        for(j = 0; j < no_of_frames; ++j){
            printf("%d\t", frames[j]);
        }
    }
    printf("\n\nTotal Page Faults= %d", faults);
    float hit;
    float miss=faults/pagesss;
    hit=1-miss;
    printf("\nHit Ratio= %.2f",hit);
    printf("\nMiss Ratio= %.2f\n\n",miss);
    return 0;
}
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
		printf("1.OPTIMAL\n2.FIFO\n3.Exit\nEnter your choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				optimal();
                break;
			case 2:
				fifo();
                break;
            case 3:
                exit(0);
                break;
			default:
				printf("invalid\n");
                break;
		}
	}while(1);
}
