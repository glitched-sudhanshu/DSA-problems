/**
 * Question:
 * https://leetcode.com/problems/permutations/description/
 */

private fun swap(nums: IntArray, i: Int, j: Int) {
    val temp = nums[j]
    nums[j] = nums[i]
    nums[i] = temp
}

// TC: O(n!*n)
// SC: O(n!) no extra space apart from anser one
private fun solveViaSwap(
    nums: IntArray,
    idx: Int,
    result: MutableList<List<Int>>,
) {
    if (idx >= nums.size) {
        result.add(nums.toList())
        return
    }

    for (i in idx until nums.size) {
        swap(nums, idx, i)
        solve(nums, idx + 1, result)
        swap(nums, idx, i)
    }
}


// TC: O(n!*n)
// SC: O(n!) but extra space for curList
private fun solve(
    nums: IntArray,
    result: MutableList<List<Int>>,
    curList: MutableList<Int>,
    isPresent: BooleanArray
) {
    if (curList.size == nums.size) {
        result.add(curList.toList())
        return
    }

    for (i in 0 until nums.size) {
        if (isPresent[i]) continue
        isPresent[i] = true
        curList.add(nums[i])
        solve(nums, result, curList, isPresent)
        curList.removeAt(curList.lastIndex)
        isPresent[i] = false
    }
}

fun permute(nums: IntArray): List<List<Int>> {
    val result = mutableListOf<List<Int>>()
    solveViaSwap(nums, 0, result)

    val isPresent = BooleanArray(nums.size)
    solve(nums, result, mutableListOf(), isPresent)

    return result
}


