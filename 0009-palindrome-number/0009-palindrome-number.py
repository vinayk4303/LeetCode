class Solution:
    def isPalindrome(self, x: int) -> bool:
        a = x
        rev = 0
        while (x > 0):
            rev = rev * 10 + x % 10
            x = x//10
        if rev == a:
            return True
        else:
            return False