def binary_search(alist, item):
    # takes in an ordered list and an item
    # uses the binary search algorithm to search for
    # the item
    first = 0
    last = len(alist) - 1
    found = False
    print 'First is: ', first
    print 'last is ', last

    # Check if the list is empty. If so that means
    # The item was not found in the list
    if len(alist) < 1:
        print 'Item not found'
        return False

    # Check the middle item in the list
    middle = (last - first) / 2
    print 'Middle is: ', middle
    if alist[middle] == item:
        return True

    # Otherwise check one of either the left or the right
    if item < alist[middle]:
        found = binary_search(alist[first:middle], item)

    if item > alist[middle]:
        found = binary_search(alist[middle:last], item)

    return found


def main():
    testlist = [0, 1, 2, 8, 13, 17, 19, 32, 42, ]
    found = binary_search(testlist, 3)
    print found
    print '\n'
    print 'Now searching for 13'
    print(binary_search(testlist, 13))
    print '\n'
    print 'Now searching for 17'
    print binary_search(testlist, 17)

if __name__ == '__main__':
    main()
