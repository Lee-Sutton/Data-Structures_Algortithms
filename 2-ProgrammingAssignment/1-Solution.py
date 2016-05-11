# -*- coding: utf-8 -*-
 # This script is the solution to problem 1 of programming assignment 2
 # The question read as follows:

'''
GENERAL DIRECTIONS:
===================

Download the text file here.

The file contains all of the integers between 1 and 10,000 (inclusive, with no repeats) in unsorted order.
The integer in the ith row of the file gives you the ith entry of an input array.

Your task is to compute the total number of comparisons used to sort the given input file by QuickSort.
As you know, the number of comparisons depends on which elements are chosen as pivots, so we'll ask you
to explore three different pivoting rules.
You should not count comparisons one-by-one. Rather, when there is a recursive call on a subarray of
length m, you should simply add m−1 to your running total of comparisons. (This is because the pivot
element is compared to each of the other m−1 elements in the subarray in this recursive call.)

WARNING: The Partition subroutine can be implemented in several different ways, and different implementations
can give you differing numbers of comparisons. For this problem, you should implement the Partition
subroutine exactly as it is described in the video lectures (otherwise you might get the wrong answer).

DIRECTIONS FOR THIS PROBLEM:

For the first part of the programming assignment, you should always use the first
element of the array as the pivot element.

HOW TO GIVE US YOUR ANSWER:
==========================
Type the numeric answer in the space provided.
So if your answer is 1198233847, then just type 1198233847 in the space provided without any space / commas
/other punctuation marks. You have 5 attempts to get the correct answer.
(We do not require you to submit your code, so feel free to use the programming language of your choice,
just type the numeric answer in the following space.)
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
    print("New QuickSort call on the list: ", array[Left:Right + 1])
    # First check the base case
    # If there is no difference between the right and left limits,
    # return the 0 for the number of comparisons
    if Left >= Right:
        return 0

    # Assign the first element to be the pivot
    Pivot = array[Left]

    # Assign the partition index i to be the left most value + 1
    i = Left + 1

    # Run through the array
    for j in range(Left + 1, Right + 1):
        print(array)
        print("The i index: ", i)

        # If the array at j is less than the pivot, we swap it with A[i]
        if array[j] < Pivot:
            # Temporarily store array[j] so that it can be swapped
            A_j = array[j]
            array[j] = array[i]
            array[i] = A_j
            # Increment the partition index
            i = i + 1

    # After running through the swap loop, move the pivot to the partition index
    array[Left] = array[i - 1]
    array[i - 1] = Pivot
    print(array)

    # Now call the function Recursively on the left and right halves around the partition
    QuickSort(array, Left, i - 2)          # Left half
    QuickSort(array, i, Right)      # Right half



# Main function
# Start by testing the function with an input array
A = [7,3,8,9,10,14,7,10,12,1,4,2,7,15,6,4,3,2,6,7,4,6,8,9,0,1]

QuickSort(A, 0, len(A) - 1)
print("The final sorted array is :", A)
