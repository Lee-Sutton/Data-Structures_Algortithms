'''
Example :

Input : [(0, 0), (1, 1), (1, 2)]
Output : 2
It takes 1 step to move from (0, 0) to (1, 1). It takes one more 
step to move from (1, 1) to (1, 2).

This question is intentionally left slightly vague.
Clarify the question by trying out a few cases in the
“See Expected Output” section.
'''


class Solution:
    # @param X : list of integers
    # @param Y : list of integers
    # Points are represented by (X[i], Y[i])
    # @return an integer
    def coverPoints(self, X, Y):
        x_movements = [-1, 0, 1]
        y_movements = [-1, 0, 1]

        # Create a for loop to run through all possible movements
        for i in x_movements:
            for j in y_movements:
   
