/**
 * Question:
 * https://leetcode.com/problems/subsets/
 */

// TC: O(n*(2^n))
// SC: O(n)
private fun getAll(nums: IntArray): List<List<Int>> {
    val n = nums.size
    val num = 1 shl n
    var i = 0
    val res = mutableListOf<List<Int>>()
    while (i < num) {
        val temp = mutableListOf<Int>()
        for (j in 0 until n) {
            if (i and (1 shl j) != 0) {
                temp.add(nums[j])
            }
        }
        res.add(temp.toList())
        i++
    }
    return res
}

// TC: O(n*(2^n))
// SC: O(n)
private fun getAll(idx: Int, nums: IntArray, curr: MutableList<Int>, res: MutableList<List<Int>>) {
    if (idx == nums.size) {
        res.add(curr.toList())
        return
    }
    curr.add(nums[idx])
    getAll(idx + 1, nums, curr, res)
    curr.remove(nums[idx])
    getAll(idx + 1, nums, curr, res)
    return
}

fun subsets(nums: IntArray): List<List<Int>> {
    val res = mutableListOf<List<Int>>()
    getAll(0, nums, mutableListOf<Int>(), res)
    return getAll(nums)
}
