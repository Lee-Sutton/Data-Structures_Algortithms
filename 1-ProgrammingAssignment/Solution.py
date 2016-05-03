# Author: Lee Sutton
# Solution to programming assignment 1

# An inverse number in a list is defined as a number in the list such that
# List[i] > List[j] where i < j
# This function uses the mergeSort algorithmm to count the number of
# inverse numbers in the given array
def InversionCount(alist):
    print("Splitting ",alist)

    # Define a variable to hold the number of inversions that occur when merging
    MergeInversions = 0

    # Define variables to hold the total number of inverses that have occured
    # This will include inversions from the left and right half
    # Initialize this value to 0
    totalInversions = 0

    # The base case if the length of the list is 1
    # return 0 for the number of inversions
    if len(alist) <=1:
        return 0

    # Calculate the midpoint in the list
    mid = len(alist)//2

    # Split the list in half
    lefthalf = alist[:mid]
    righthalf = alist[mid:]

    # Recursively send the lefthalf and right half to the InversionCount()
    # Store the number of inversions from the left and right half
    LeftInversions = InversionCount(lefthalf)
    RightInversions = InversionCount(righthalf)

    # Run through each half of the arrays combining using the mergeSort algorithmm
    i=0
    j=0
    k=0

    # Run through the left and right half lists comparing the values at each index
    while i < len(lefthalf) and j < len(righthalf):

        # If the left half is less than the number in the right half store the left half number
        # Do not increment the inversion count
        if lefthalf[i] <= righthalf[j]:
            alist[k]=lefthalf[i]
            i=i+1
        # If the right half is less than the number in the left half store the right half number
        # Increment the inversion counter by how many numbers are left in the left half side
        else:
            alist[k]=righthalf[j]
            j=j+1
            MergeInversions = MergeInversions + len(lefthalf) - i

        # Increment K to keep moving through aList
        k=k+1

    # Run through the rest of the left and right halves if these numbers are still left over
    while i < len(lefthalf):
        alist[k]=lefthalf[i]
        i=i+1
        k=k+1

    while j < len(righthalf):
        alist[k]=righthalf[j]
        j=j+1
        k=k+1

    print("Merging ",alist)
    print("The number of merge inversions from this list was: ", MergeInversions)
    # add up the total number of inversions
    totalInversions = MergeInversions + LeftInversions + RightInversions
    # Return the total number of inversions, from the left + right + mergeSort
    print("The total number of inversions from this list was: ", totalInversions)
    return totalInversions

###############################################################################################


# alist = [54,26,93,17,77,31,44,55,20]
# alist = [54,26,100,93]

# open the integerarray text file and store it as the list to sort
text_file = open("/Users/Lee/Algorithms/1-ProgrammingAssignment/Test.txt", "r")
list1 = text_file.readlines()

# convert all the values in list1 to integers
int_list = [int(i) for i in list1]

Inversions = InversionCount(int_list)
print("The Sorted list: ", int_list)
print("The number of Inversions: ", Inversions)
