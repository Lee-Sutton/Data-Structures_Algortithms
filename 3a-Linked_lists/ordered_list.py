class node(object):
    def __init__(self, item):
        # node class will hold an item and a reference to
        # the next node
        self.item = item
        self.next = None


class OrderedList(object):
    def __init__(self):
        # Initialize with the head to none
        self.head = None
        self.size = 0

    def add(self, item):
        # If the list is empty we add it to the beginning
        if self.head is None:
            self.head = node(item)
            self.size = self.size + 1
            return

        # If the item to be added is smaller than the current
        # head it should take the place of the head
        if self.head.item > item:
            # Store the current head in a temporary variable
            temp_node = self.head
            # Put the new item in place of the head
            self.head = node(item)
            self.head.next = temp_node
            return

        # If the list is not empty
        # Run through list until we either reach the end,
        # or we find a number greater than it in which case,
        # we place it before that node
        current_node = self.head
        while current_node.next != None:
            if current_node.next.item > item:
                # Place the node here to preserve order
                node_to_add = node(item)
                temp_node = current_node.next
                current_node.next = node_to_add
                node_to_add.next = temp_node
                self.size = self.size + 1
                return
            # Move to the next node
            current_node = current_node.next

        # If we leave the while loop, we've reached the end of
        # the list and should add the node at the end
        current_node.next = node(item)
        self.size = self.size + 1

    def display(self):
        # Function to represent the linked list as a string
        current_node = self.head
        while current_node != None:
            print current_node.item
            current_node = current_node.next


# Define main function for testing
def main():
    test_list = OrderedList()
    test_list.add(1)
    test_list.add(2)
    test_list.add(0)
    test_list.add(5)
    test_list.add(4)
    test_list.display()

if __name__ == '__main__':
    main()