/**
 * Question:
 * https://leetcode.com/problems/combination-sum-ii/
 */

private fun solve(
    cads: IntArray,
    tar: Int,
    result: MutableSet<List<Int>>,
    idx: Int,
    curList: MutableList<Int>
) {
    if (tar == 0) {
        result.add(curList.toList())
        return
    }
    if (idx >= cads.size) return

    for (i in idx until cads.size) {
        if (i > idx && cads[i] == cads[i - 1]) continue
        if (cads[i] > tar) break
        curList.add(cads[i])
        solve(cads, tar - cads[i], result, i + 1, curList)
        curList.removeAt(curList.lastIndex)
    }
    return
}


fun combinationSum2(candidates: IntArray, target: Int): List<List<Int>> {
    val result = mutableSetOf<List<Int>>()
    candidates.sort()
    solve(candidates, target, result, 0, mutableListOf<Int>())
    return result.toList()
}
