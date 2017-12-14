#include <stdio.h>
#include <assert.h>

/* Implements binary search on the input array
 * Returns: Integer indicating the location of the item
 * being searched for. If the item is not found, -1 is returned
 * */
int binary_search(int *array, int array_size, int item){
    int high = array_size - 1;
    int low = 0;
    int mid; // Initialize in the while loop
    while (low <= high){
        mid = (low + high) / 2;
        if (array[mid] > item){
            high = mid - 1;
        }
        if (array[mid] < item){
            low = mid + 1;
        }
        if (array[mid] == item){
            return mid;
        }
    }
    return -1;
}

int main(){
    // Start with a sorted array 
    int array_size = 5;
    int array [] = {0, 1, 2, 3, 4, 5};
    assert(binary_search(array, array_size, 3) == 3);
    printf("Binary search test passed\n");
}
