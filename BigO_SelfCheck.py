# Self Check problem for Big O notation section

'''
Write two Python functions to find the minimum number in a list. The first 
function should compare each number to every other number on the list. 
O(n2)O(n2). The second function should be linear O(n)O(n).
'''

# First function compares each number to every other number in the list
def TotalCompare(given_list):
    # initialize the minimum number to the first value in the list
    minimum = given_list[0]
    
    for i in given_list:
        # check the value at i with every other value in the list
        for j in given_list:
            # if the value is less than the current minumum assign it to
            # the minimum value
            if i < minimum:
                minimum = i

    # return the minimum value
    return minimum
    

# Now run through the numbers only once to find the minimum
def FindMin(given_list):
    # initialize the minimum number to the first value in the list
    minimum = given_list[0]
    
    for i in given_list:
        # check the value at i with every other value in the list
        if i < minimum:
            minimum = i
    # Return the minimum value
    return minimum
        
########################################################################
                
# Test the functions down here
given_list = [1,2,3,4,5,6,7,8,9,0,10,11,12,13,14,15];

print(TotalCompare(given_list)) 
print(FindMin(given_list))