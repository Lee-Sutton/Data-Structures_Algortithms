class Deque(object):
    def __init__(self):
        # Requires no parameters and returns an empty deque
        # This data structure will use a python list
        self.items = []

    def addFront(self, item):
        # adds item to front of the deque
        self.items.insert(0, item)

    def addRear(self, item):
        # adds item to the rear
        self.items.append(item)

    def removeFront(self):
        # Removes the front item
        self.items.pop(0)

    def removeRear(self):
        # Removes the rear item
        self.items.pop()

    def isEmpty(self):
        # Tests to see whether the deque is empty
        return self.items == []

    def size(self):
        # returns the size of the deque
        return len(self.items)


d = Deque()
print(d.isEmpty())
d.addRear(4)
d.addRear('dog')
d.addFront('cat')
d.addFront(True)
print(d.size())
print(d.isEmpty())
d.addRear(8.4)
print(d.removeRear())
print(d.removeFront())


def palchecker(aString):
    chardeque = Deque()

    for ch in aString:
        chardeque.addRear(ch)

    stillEqual = True

    while chardeque.size() > 1 and stillEqual:
        first = chardeque.removeFront()
        last = chardeque.removeRear()
        if first != last:
            stillEqual = False

    return stillEqual

print(palchecker("lsdkjfskf"))
print(palchecker("radar"))
