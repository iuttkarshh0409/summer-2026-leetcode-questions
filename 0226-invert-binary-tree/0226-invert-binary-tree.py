class Solution:
    def invertTree(self, root):
        # Empty tree
        if root is None:
            return None

        # Swap left and right
        root.left, root.right = root.right, root.left

        # Invert both subtrees
        self.invertTree(root.left)
        self.invertTree(root.right)

        return root