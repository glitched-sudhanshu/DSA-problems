/**
 * Question:
 * https://leetcode.com/problems/subsets-ii/description/
 */

// TC: O(n*2^n) -- n * because of storing item in the list
// SC: O(n*2^n) -- O(2^n) subsets each of avg size n
// Aux SC: O(n)
private fun solve(
    nums: IntArray,
    idx: Int,
    result: MutableList<List<Int>>,
    curList: MutableList<Int>
) {
    result.add(curList.toList())
    if (idx == nums.size) {
        return
    }
    for (i in idx until nums.size) {
        if (i > idx && nums[i] == nums[i - 1]) continue
        curList.add(nums[i])
        solve(nums, i + 1, result, curList)
        curList.removeAt(curList.lastIndex)
    }
    return
}

fun subsetsWithDup(nums: IntArray): List<List<Int>> {
    val res = mutableListOf<List<Int>>()
    nums.sort()
    solve(nums, 0, res, mutableListOf<Int>())
    return res
}
