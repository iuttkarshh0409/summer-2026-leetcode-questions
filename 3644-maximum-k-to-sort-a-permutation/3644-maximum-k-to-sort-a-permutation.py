
class Solution:
    def sortPermutation(self, nums):
        ans = -1

        for i, x in enumerate(nums):
            if i != x:
                ans &= x

        return max(ans, 0)


# Synced seamlessly with LeetHub Pro
# Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
# Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna