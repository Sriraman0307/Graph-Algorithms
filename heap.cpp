//Heapsort Algorithm
#include <stdio.h>
int main()
{
    int heapsize, i, j, mid, temp;
    int heap[18] = {22,9,12,35,36,4,42,33,34,18,39,23,65,30,21,25,24,19};
    heapsize=18;
    printf("No of Elements :%d\n",heapsize);
    printf("Original array : \n");
    for (i = 0; i < heapsize; i++)
        printf("%d\t ", heap[i]);
    
    for (i = 1; i < heapsize; i++)
    {
        j = i;
        do
        {   
        //Create Max heap array 
            mid = (j - 1) / 2;          
            if (heap[mid] < heap[j])   
            {   //Exchange elemenets
                temp = heap[mid];
                heap[mid] = heap[j];
                heap[j] = temp;
            }
            j = mid;
        } while (j!= 0);
    }
 
    printf("\n Heap array : \n");
    for (i = 0; i < heapsize; i++)
        printf("%d\t ", heap[i]);
        
    for (i = heapsize - 1; i >= 0; i--)
    {	// Swap Rightmost leaf element with the Max element 
        temp = heap[0];
        heap[0] = heap[i];    
        heap[i] = temp;
        mid = 0;
        do 
        {
            j = 2 * mid + 1;    
            if ((heap[j] < heap[j + 1]) && j < i-1)
                j++;
            // Performing SiftUp
			if (heap[mid]<heap[j] && j<i)    
            {
                temp = heap[mid];
                heap[mid] = heap[j];
                heap[j] = temp;
            }
            mid = j;
        } while (j < i);
    } 
    printf("\n The sorted array is : \n ");
    for (i = 0; i <heapsize; i++)
       printf("%d\t", heap[i]);
       printf("\n");
    return 0;
   }
