#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define SIZE 100
void create_ptr(int** ptr, int n)
{
    while(!(*ptr))
    {
        *ptr = (int*)malloc(n*sizeof(int));
    }
    printf("carete succ.%p\n",*ptr);
}

void print_arr(int* ptr, int n)
{
    while(n--)
    {
        printf(" %d", *ptr++);
    }
    printf("\n");
}

void fill_rand_num(int* ptr, int n)
{
    if(0==n)
    {
        return;
    }

    int i=0;
    srand(time(NULL));
    while(i<n)
    {
        int r = rand()%SIZE;
        *ptr++ = r;
        i++;
    }

    printf("fill succ.\n");
}

int bin_search(int* ptr, int n)
{
    int aim = rand()%SIZE;
    printf("rand aim num: %d\n", aim);

    int* begin = ptr;
    int* end   = ptr+n-1;
    int* mid   = begin+n/2;
    while(begin<=end)
    {
        if(*mid == aim)
        {
             return *mid;
        }
        else if(*mid < aim) 
        {
            begin = mid+1;
            mid = begin +(end - begin)/2;
        }
        else
        {
            end = mid -1;
            mid = begin + (end - begin)/2;
        }
    }
    return -1;
}

int comp(const void* a, const void* b)
{
    return *(int*)a > *(int*)b;
}

int main()
{
    int num=0;
    printf("input array size: ");
    while((scanf("%d",&num))!=EOF)
    {
        int *ptr_arr = NULL; 
        create_ptr(&ptr_arr, num);
        if(ptr_arr)
        {
            fill_rand_num(ptr_arr, num);
            print_arr(ptr_arr, num);
            qsort(ptr_arr,num, sizeof(int), comp);
            print_arr(ptr_arr, num);
            printf("found: %d\n",bin_search(ptr_arr, num));
            free(ptr_arr);
            ptr_arr = NULL;
        }
        printf("input array size: ");
    }
    return 0;
}