from typing import List


class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        table = {}
        for i, n in enumerate(nums):
            x = target - n
            if x in table:
                return [table[x], i]
            table[n] = i


def main():
    nums = [2, 5, 7, 11]
    target = 9
    print(Solution().twoSum(nums, target))


if __name__ == "__main__":
    main()
