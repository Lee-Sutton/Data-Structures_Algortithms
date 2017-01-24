def Partition(alist, low, high):
    # Start by setting the left wall
    left = low + 1

    # Set the pivot value to be the first value in the list
    pivot = alist[low]

    # Now run through the array moving values to the left of the wall if needed
    i = low
    while i < high:
        if alist[i] < pivot:
            # Swap the values
            temp = alist[i]
            alist[i] = alist[left]
            alist[left] = temp
            left = left + 1
        i = i + 1

    # Now swap the pivot to its final location
    alist[low] = alist[left - 1]
    alist[left - 1] = pivot
    return left - 1


def Quicksort(alist, low, high):
    if (low < high):
        # find the pivot location
        pivot_location = Partition(alist, low, high)

        # Call quicksort on the unsorted portions
        Quicksort(alist, low, pivot_location)
        Quicksort(alist, pivot_location + 1, high)


def main():
    test_array = [0,4,5,6,2,7,8, -2, 27, 0, 0, 0, 12]
    Quicksort(test_array, 0, len(test_array))
    print test_array

if __name__ == '__main__':
    main()