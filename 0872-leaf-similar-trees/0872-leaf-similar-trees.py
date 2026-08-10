class Solution:
    def leafSimilar(self, root1, root2):

        def get_leaves(node):
            if node is None:
                return []

            # Leaf node
            if node.left is None and node.right is None:
                return [node.val]

            return get_leaves(node.left) + get_leaves(node.right)

        return get_leaves(root1) == get_leaves(root2)