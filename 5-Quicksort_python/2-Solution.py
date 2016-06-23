# -*- coding: utf-8 -*-
 # This script is the solution to problem 2 of programming assignment 2
# Author: Lee Sutton
# Date: May 11th, 2016
# The question read as follows:
'''
GENERAL DIRECTIONS:
===================

GENERAL DIRECTIONS AND HOW TO GIVE US YOUR ANSWER:
See the first question.

DIRECTIONS FOR THIS PROBLEM:

Compute the number of comparisons (as in Problem 1), always using the final element
of the given array as the pivot element. Again, be sure to implement the Partition
subroutine exactly as it is described in the video lectures. Recall from the lectures
that, just before the main Partition subroutine, you should exchange the pivot element
(i.e., the last element) with the first element.
'''

# Define a quicksort function to quicksort the given array and count the number
# of comparisons.
'''
 The quicksort function will take in 3 parameters
   1. The array to be Sorted
   2. The left most array index to be sorted
   3. The right most index of the array to be sorted

 The function will call itself Recursively to sort the remaining unsorted parts
 of the array around the pivot. Every time the function is called Recursively,
 we make m - 1 comparisons. The total number of comparisons required to sort the
 entire array will then be returned from the function.
'''
def QuickSort(array, Left, Right):
    # Print statement for testing
    #print("New QuickSort call on the list: ", array[Left:Right + 1])

    # First check the base case
    # If there is no difference between the right and left limits,
    # return the 0 for the number of comparisons
    if Left >= Right:
        return 0

    # Assign the right most element to be the pivot
    Pivot = array[Right]

    # Assign the partition index i to be the left most value
    i = Left

    # Run through the array
    for j in range(Left, Right):
        #print(array)
        #print("The i index: ", i)

        # If the array at j is less than the pivot, we swap it with A[i]
        if array[j] <= Pivot:
            # Temporarily store array[j] so that it can be swapped
            A_j = array[j]
            array[j] = array[i]
            array[i] = A_j
            # Increment the partition index
            i = i + 1

    # After running through the swap loop, move the pivot to the partition index
    array[Right] = array[i]
    array[i] = Pivot
    #print(array)

    # Now call the function Recursively on the left and right halves around the partition
    LeftComparisons = QuickSort(array, Left, i - 1)          # Left half
    RightComparisons = QuickSort(array, i + 1, Right)            # Right half

    # Add m-1 comparisons to the total number of comparisons and return the total
    # number of comparisons
    TotalComparisons = LeftComparisons + RightComparisons + (Right - Left)
    return TotalComparisons

# Main function
# Start by importing the data from the text file
# open the integerarray text file and store it as the list to sort
text_file = open("/Users/Lee/Algorithms/2-ProgrammingAssignment/Integer-array.txt", "r")
list1 = text_file.readlines()

# convert all the values in list1 to integers
A = [int(i) for i in list1]

# A = [5,4,3,6]

Comparisons = QuickSort(A, 0, len(A) - 1)
print("The final sorted array is :", A)
print("The total number of comparisons = ", Comparisons)
