class Solution:
    def countCompleteDayPairs(self, hours: List[int]) -> int:
        count = [0] * 24
        result = 0

        for hour in hours:
            complementary = (24 - hour % 24) % 24
            result += count[complementary]
            count[hour % 24] += 1
        return result