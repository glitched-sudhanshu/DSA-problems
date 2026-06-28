/**
 * Question:
 * https://leetcode.com/problems/combination-sum/description/
 */

// TC: O(2^(T/M))
// T: target
// M: smallest set that can acheieve target
private fun solve(
    cads: IntArray,
    tar: Int,
    result: MutableList<List<Int>>,
    idx: Int,
    curList: MutableList<Int>
) {
    if (idx >= cads.size) return
    if (tar < 0) return
    if (tar == 0) {
        result.add(curList.toList())
        return
    }

    if (tar - cads[idx] >= 0) {
        curList.add(cads[idx])
        solve(cads, tar - cads[idx], result, idx, curList)
        curList.removeAt(curList.lastIndex)
    }
    solve(cads, tar, result, idx + 1, curList)
    return
}

fun combinationSum(candidates: IntArray, target: Int): List<List<Int>> {
    val result = mutableListOf<List<Int>>()
    solve(candidates, target, result, 0, mutableListOf<Int>())
    return result.toList()
}