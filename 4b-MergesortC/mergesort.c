#include <stdio.h>
#include <stdlib.h>

// Display function to display the input array
void array_display(int* array, int size){
    int i;
    // Print the values in the array to the screen
    for(i = 0; i < size; i++){
        printf("%i ", array[i]);
    }
    printf("\n");

    return;
}

// Merge function
// This function will merge the two arrays from the mergesort function
// int* left - pointer to the left array
// int left_size - size of the left array
// int* right - pointer to the right half to be merged
// int right_size - size of the right array
// Returns: int* sorted_array - a pointer to the sorted array
void merge(int* array, int* left, int left_size, int* right, int right_size){
    // initialize indices
    int i = 0;
    int j = 0;
    int k = 0;
    printf("calling merge function on the two arrays: \n");
    printf("The left array ");
    array_display(left, left_size);
    printf("The right array ");
    array_display(right, right_size);

    while((i < left_size) && (j < right_size)){
        if(left[i] < right[j]){
            array[k] = left[i];
            k++;
            i++;
        }
        else{
            array[k] = right[j];
            k++;
            j++;
        }
    }

    // If there are values left in the left half, we append them to sorted array
    while(i < left_size){
        array[k] = left[i];
        k++;
        i++;
    }

    // If there are values left in the right half, we append them to the sorted array
    while(j < right_size){
        array[k] = right[j];
        k++;
        j++;
    }
    printf("The merged array: ");
    array_display(array, left_size + right_size);
    return;
}

// create a function to perform mergesort on an input array
// Inputs: integer array to be sorted, size of array
// Returns: pointer to sorted integer array
void Mergesort(int* array, int size){
    // Declare variables
    int* left;
    int* right;
    int left_size;
    int right_size;
    int i;
    printf("Mergesort function called on: ");
    array_display(array, size);
    // Calculate the middle
    int middle = size / 2;

    // Check if the size of the array is 1, then it is already sorted
    if (size <= 1){
        // Print statements for testing
        printf("Reached base case\n");
        return;
    }

    // If the array is larger than 2, split the array and send back to mergesort
    // Calculate left and right size
    left_size = middle;
    right_size = size - middle;

    // Allocate memory for the left and right halves of the arrays
    left = malloc(sizeof(int)*left_size);
    right = malloc(sizeof(int)*right_size);

    // Copy the array into the left half
    for(i=0; i < left_size; i++){
        left[i] = array[i];
    }

    // Copy the array into the right half
    for(i=middle; i < size; i++){
        right[i - middle] = array[i];
    }

    // Allow the user to see how the splitting is occuring
    printf("After splitting\n");
    printf("The left half: ");
    array_display(left, left_size);
    printf("The right half: ");
    array_display(right, right_size);

    // Call mergesort on the left and right halves
    Mergesort(left, left_size);
    Mergesort(right, right_size);

    // Merge the two together
    merge(array, left, left_size, right, right_size);

    // Free up allocated memory
    free(left);
    free(right);
    return;
}

int main(int argc, char const *argv[])
{
    // Declare variables
    int i;

    // Test the input 
    int test_array[] = {1, 4, 5, 6, 7, 9, 8, 10, 7, 0, 23, -8, 29, -20};
    Mergesort(test_array, 14);

    // print the sorted array
    printf("The sorted array:\n");
    array_display(test_array, 14);

    return 0;
}










