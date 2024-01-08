#include<stdio.h>

int binary_search(int x, int v[], int len);

int main() 
{
    int arr[] = {2, 3, 9, 23, 32, 65, 87, 121, 141, 821};
    int res  = binary_search(652, arr, 10);
    if (res == -1)
    {
    	printf("Element not found ");
    }
    else
    {
    printf("Fount at position %d", res);
    }
    return 0;
}

int binary_search(int x, int v[], int len) 
{
    int low, high, mid;

    low = 0;
    high = len - 1;
    mid = (low + high) / 2;

    while (low < high && x != v[mid]) 
    {
        if (x > v[mid])
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }

        mid = (low + high) / 2;
    }

    if (x == v[mid])
    {
        return mid + 1;
    }
    else
    {
        return -1;
    }
}
