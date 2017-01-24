# Implement a stack in python
class Stack(object):
    def __init__(self):
        # The stack will be implemented using a python list
        self.stack = []

    def push(self, item):
        # Pushes item to the top of the stack
        self.stack.append(item)

    def pop(self):
        # Remove the top item from the stack
        return self.stack.pop()

    def peek(self):
        # Returns a python list representing the stack
        return self.stack

    def isEmpty(self):
        # Returns true or false based on whether or not
        # the list is empty
        return self.stack == []

    def size(self):
        # Returns the size of the stack
        return len(self.stack)

def main():
    s = Stack()
    print s.isEmpty()
    s.push(4)
    s.push('dog')
    print s.peek()
    s.push(True)
    print s.peek()
    print 'The size is: ' , s.size()
    print 'Is it empty?: ', s.isEmpty()
    s.pop()
    print s.peek()

if __name__ == '__main__':
    main()