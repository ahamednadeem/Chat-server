/* binary search */

#include<stdio.h>
#include<time.h>   // to comapare the run time of the program


int binary_search(int x, int v[], int len);  

int main() 
{
    time_t start_t, end_t;
    double diff_t;
    
    printf("Starting of the program\n");
    time(&start_t);
   	
    int arr[] = {2, 3, 9, 23, 32, 65, 87, 121, 141, 821, 1231, 2222, 2223, 2234, 2239};
    int res  = binary_search(2239, arr, 15);
    if (res == -1)
    	printf("Element not found \n");
    else
    printf("Fount at position %d \n", res);
    
    time(&end_t);
    diff_t = difftime(end_t, start_t);

    printf("Execution time = %f\n", diff_t);
    return 0;
}

int binary_search(int x, int v[], int len)  //input array must be sorted
{
    int low, high, mid;

    low = 0;
    high = len - 1;
    mid = (low + high) / 2;

    while (low < high && x != v[mid])   //only one test condition inside the loop
    {
        if (x > v[mid])
            low = mid + 1;
        else
            high = mid - 1;

        mid = (low + high) / 2;
    }

    if (x == v[mid])
        return mid + 1;
    else
        return -1;
}
