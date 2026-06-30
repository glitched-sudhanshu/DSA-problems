/**
 * Question:
 * https://leetcode.com/problems/combination-sum-iii/description/
 */

// TC: O((9/k)*k)
// (9/k) -> 9Ck (choosing max k elements combination among 9 options)
// *k is for copying the list
private fun solve(
    idx: Int,
    k: Int,
    tar: Int,
    res: MutableList<List<Int>>,
    curList: MutableList<Int>
) {
    if (k == 0 && tar == 0) {
        res.add(curList.toList())
        return
    }
    if (k < 0 || tar < 0 || idx > 9) return

    for (i in idx..9) {
        if (k < 0 || tar < 0 || i > tar) break
        if (i <= tar && k >= 0) {
            curList.add(i)
            solve(i + 1, k - 1, tar - i, res, curList)
            curList.removeAt(curList.lastIndex)
        }
    }
}

fun combinationSum3(k: Int, n: Int): List<List<Int>> {
    val result = mutableListOf<List<Int>>()
    solve(1, k, n, result, mutableListOf<Int>())
    return result.toList()
}