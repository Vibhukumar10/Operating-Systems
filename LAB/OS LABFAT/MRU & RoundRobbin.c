#include<stdio.h>
int p[50];
int hit=0;
int i,j,k;
int total_page_faults=0;

int Checking_for_hit(int data)
{
    hit=0;
    for(j=0; j<cache_frames; j++)
    {
    if(p[j]==data)
    {
    hit=1; // If page frame is present in the cached memory then hit -> 1
    break;
    }
    }
    return hit;
}

int Index_hit(int data) // Returns the index of the page frame which is already present in the cache memory and was called
{
    int index_of_hit;
    for(k=0; k<cache_frames; k++)
    {if(p[k]==data)
    {
    index_of_hit=k;
    break;
    }
    }
    return index_of_hit;
}

void round_robin_page_replacement()
{
    int refrence_bit_array[50]; // Reference bit for each page frame
    int page_remove_index=0; // Points towards the page frame to be
    removed
    total_page_faults=0; // Initially the number of page faults are 0
    for(i=0; i<cache_frames; i++)
    p[i]=0; // Array storing the page frames in the caches memory
    for(i=0; i<cache_frames; i++)
    refrence_bit_array[i]=0; // Initializing reference bit for each page
    frame as 0
    for(i=0; i<n; i++)
    {
    printf("\nFor %d:",in[i]);
    if(Checking_for_hit(input_array[i])) // If the page is present in the
    cache memory
    {
    printf("There is NO page fault for this page frame\n");
    int hitindex=Index_hit(in[i]);
    refrence_bit_array[hitindex]=1; // Updating the reference bit ot 1
    int a = 0;
    for(a=0;a<cache_frames;a++)
    {
    printf("%d", p[a]);
    }
    printf("\n");
    for (a=0;a<cache_frames;a++)
    {
    printf("%d ",usedbit[a]);}
    printf("\n");
    }
    else // If the page called is not present in the memory
    {
    printf("There is a page fault for this page frame\n");
    total_page_faults++;
    if(refrence_bit_array[page_remove_index]==1)
    {
    do
    {
    refrence_bit_array[page_remove_index]=0;
    page_remove_index++;
    if(page_remove_index==nf)
    page_remove_index=0;
    }
    while(refrence_bit_array[page_remove_index]!=0);
    }
    if (refrence_bit_array[page_remove_index]==0)
    {
    p[page_remove_index]=input_array[i];
    refrence_bit_array[page_remove_index]=1;
    page_remove_index++;
    }
    printf("\n");
    }
    if(page_remove_index==nf)
    page_remove_index=0;
    int a = 0;
    for(a=0;a<cache_frames;a++)
    {
    printf("%d", p[a]);
    }
    printf("\n");
    for (a=0;a<cache_frames;a++)
    {
    printf("%d ", refrence_bit_array[a]);
    }}
    printf("Total no of page faults:%d \n",total_page_faults); // Displays the total number of page faults
}

int main()
{
    int  n, frames[10], input_array[30], temp[10], flag1, flag2, flag3, i, j, k, pos, max, faults = 0,cache_frames;
    printf("Please enter number of frames: ");
    scanf("%d", &cache_frames);
    printf("Please enter number of pages: ");
    scanf("%d", &n);
    float pagesss=n;
    printf("Please enter the pages to be input in the requiered sequence");
    for(i = 0; i < n; ++i)
    {
        scanf("%d", &input_array[i]);

    }

    for(i = 0; i < cache_frames; ++i){
        frames[i] = -1;
    }
    for(i = 0; i < no_of_input_array; ++i){
        flag1 = flag2 = 0;
        for(j = 0; j < cache_frames; ++j){
            if(frames[j] == input_array[i]){
                flag1 = flag2 = 1;
                break;

            }
        }
        if(flag1 == 0){
            for(j = 0; j < cache_frames; ++j){
                if(frames[j] == -1){
                    faults++;
                    frames[j] = input_array[i];
                    flag2 = 1;
                    break;
                }
            }
        }
        if(flag2 == 0){
            flag3 =0;
            for(j = 0; j < cache_frames; ++j){
                temp[j] = -1;
                for(k = i + 1; k < n; ++k){
                    if(frames[j] == input_array[k]){
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
                for(j = 1; j < cache_frames; ++j){
                    if(temp[j] > max){
                        max = temp[j];
                        pos = j;
                    }
                }
            }
			frames[pos] = input_array[i];
			faults++;
        }
        printf("\n");
        for(j = 0; j < cache_frames; ++j){
            printf("%d\t", frames[j]);
        }
    }
    printf("\n\nTotal Page Faults using most recently used algorithm(MRU) is = %d", faults);
    float hit;
    float miss=faults/pagesss;
    hit=1-miss;
    printf("\nHit Ratio= %.2f",hit);
    printf("\nMiss Ratio= %.2f",miss);
    round_robin_page_replacement();
    return 0;
}
