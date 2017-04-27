class BinaryTree(object):
    # BinaryTree class to create a binary tree data structure
    def __init__(self, rootObj):
        self.key = rootObj
        self.left = None
        self.right = None

    def insert_left(self, new_node):
        # This function will insert a new node into
        # the left child location and move the current
        # left child node down the tree if needed
        if self.left == None:
            self.left = BinaryTree(new_node)

        else:
            temp = BinaryTree(new_node)
            temp.left = self.left
            self.left = temp

    def insert_right(self, new_node):
        # This function will insert a new node into
        # the left child location and move the current
        # left child node down the tree if needed
        if self.right == None:
            self.right = BinaryTree(new_node)

        else:
            temp = BinaryTree(new_node)
            temp.right = self.right
            self.right = temp


def pre_order(tree):
    if tree:
        print tree.key
        pre_order(tree.left)
        pre_order(tree.right)


def post_order(tree):
    if tree:
        pre_order(tree.left)
        pre_order(tree.right)
        print tree.key


def main():
    # Build a binary search tree as described in the problem statement
    bin_tree = BinaryTree('a')
    bin_tree.insert_left('b')
    bin_tree.left.insert_right('d')
    bin_tree.insert_right('c')
    bin_tree.right.insert_left('e')
    bin_tree.right.insert_right('f')
    # Display the binary tree
    print '\t\t', bin_tree.key
    print '\t', bin_tree.left.key, '\t\t', bin_tree.right.key
    print '\t  ', bin_tree.left.right.key, '\t   ', bin_tree.right.left.key, '  ', bin_tree.right.right.key

    print "Let's see how pre-order works"
    pre_order(bin_tree)

    print "Let's see how post-order works"
    post_order(bin_tree)


if __name__ == '__main__':
    main()
