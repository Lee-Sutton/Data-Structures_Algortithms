# import the time module to time the execution time
import time

import matplotlib.pyplot as plt


# Programming excercises for python's data structure analysis

# 1. Devise an experiment to verify that the list index operator is O(1)

# Create an empty indexTest list 
IndexTest = []

# Start by closing the figures
plt.close("all")

for n in range(1000):
    # Create a test list with size n
    TestList = list(range(n + 1))
    
    # Run the timer test and append it to the index timing list
    start = time.clock()
    FunctionCall = TestList[n]
    end = time.clock()
    # Save the time it took to run the index function
    IndexTest.append(end - start)
    
# Plot the time it takes to index the list as n increases
plt.plot(TestList,IndexTest)
plt.show()

################################################################################################
# 2. Devise an experiment to verify that get item and set item are O(1) for dictionaries.









