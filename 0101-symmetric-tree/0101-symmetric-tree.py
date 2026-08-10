class Solution:
    def isSymmetric(self, root):
        def isMirror(left, right):
            # Both empty → mirror
            if left is None and right is None:
                return True

            # Only one is empty → not mirror
            if left is None or right is None:
                return False

            # Values must match
            if left.val != right.val:
                return False

            # Cross comparison
            return (
                isMirror(left.left, right.right)
                and
                isMirror(left.right, right.left)
            )

        return isMirror(root.left, root.right)