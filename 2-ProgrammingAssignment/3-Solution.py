# -*- coding: utf-8 -*-
 # This script is the solution to problem 3 of programming assignment 2
 # Author: Lee Sutton
 # Date: May 11th, 2016
 # The question read as follows:
'''
GENERAL DIRECTIONS:
===================

DIRECTIONS FOR THIS PROBLEM:

Compute the number of comparisons (as in Problem 1), using the "median-of-three"
pivot rule. [The primary motivation behind this rule is to do a little bit of
extra work to get much better performance on input arrays that are nearly sorted
or reverse sorted.] In more detail, you should choose the pivot as follows.
Consider the first, middle, and final elements of the given array. (If the
array has odd length it should be clear what the "middle" element is; for an
array with even length 2k, use the kth element as the "middle" element. So for
the array 4 5 6 7, the "middle" element is the second one ---- 5 and not 6!)
Identify which of these three elements is the median (i.e., the one whose value
is in between the other two), and use this as your pivot. As discussed in the
first and second parts of this programming assignment, be sure to implement
Partition exactly as described in the video lectures (including exchanging
the pivot element with the first element just before the main Partition subroutine).

EXAMPLE: For the input array 8 2 4 5 7 1 you would consider the first (8),
middle (4), and last (1) elements; since 4 is the median of the set {1,4,8},
 you would use 4 as your pivot element.

SUBTLE POINT: A careful analysis would keep track of the comparisons made in
identifying the median of the three candidate elements. You should NOT do this.
That is, as in the previous two problems, you should simply add m−1 to your
running total of comparisons every time you recurse on a subarray with length m.
'''
# Define a median function to find the median of the given array in the given bounds.
# The function will be used to find the median of the first, last, and middle value
# The function will return the median value and the index in the list
def median(array, Left, Right):
    # Store the length of the array
    arrayLength = Right - Left + 1

    # Check the base case, if the array has a length of two or less return the
    # first value in the array
    if arrayLength < 3:
        return [Left, array[left]]

    # Store the first and last value
    LeftVal = array[Left]
    RightVal = array[Right]

    # The middle value will depend on the length of the array
    # If the array length is odd, Right - Left will be divisible by 2
    # We then take the middle index as the midvalue
    if (Right - Left) % 2 == 0:
        MidVal = array[Left + (Right - Left)/2]
        MidIndex = Left + (Right - Left)/2

    # If the length of the array is even, the Right - Left will be odd
    # We then take the index to the left of the middle
    # ie. [1,2,3,4] => [2] is returned
    if (Right - Left) % 2 == 1:
        MidVal = array[Left + (Right - Left)/2]
        MidIndex = Left + (Right - Left)/2

    print "The three values being checked are: ", LeftVal, MidVal, RightVal
    # Now check to see which value is the median
    # First check if the left most value is the median
    if (LeftVal <= RightVal and LeftVal >= MidVal) or (LeftVal >= RightVal and LeftVal <= MidVal):
        return [Left, LeftVal]

    # Check if the midvalue is the median
    elif (MidVal <= RightVal and MidVal >= LeftVal) or (MidVal >= RightVal and MidVal <= LeftVal):
        return [MidIndex, MidVal]

    # If neither of the two cases above are true, the right most index must be the median
    else:
        return [Right, RightVal]



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
 entire array will then be returned from the function. The function will use the
 median of the first, last, and middle value as the pivot
'''
def QuickSort(array, Left, Right):
    # Print statement for testing
    #print("New QuickSort call on the list: ", array[Left:Right + 1])

    # First check the base case
    # If there is no difference between the right and left limits,
    # return the 0 for the number of comparisons
    if Left >= Right:
        return 0

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
'''
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
'''

# Test the median function
A = [1,2,3,4,5,12,1,6,8,7,7,1]
TestValue = median(A, 0, len(A)-1)
print(TestValue)
