/**
 * Question:
 * https://leetcode.com/problems/count-collisions-of-monkeys-on-a-polygon/description/?envType=problem-list-v2&envId=recursion
 */

private val mod = (10.0.pow(9) + 7).toLong()

//TC: O(logN)
//SC: O(1)
private fun pow(num: Int, times: Int): Long {
    var ans = 1L
    var n = times.toLong()
    var x = num.toLong()
    while(n != 0L) {
        if(n%2 == 1L) {
            ans = (ans*x)% mod
        }
        x = (x*x)%mod
        n/=2
    }
    return ans
}

//TC: O(logN)
//SC: O(logN)
private fun powRec(num: Int, times: Int): Long {
    if(times == 0) return 1L
    val res = powRec(num, times/2)
    if(times%2 == 1) return (num * res * res)%mod
    return (res * res)%mod
}

fun monkeyMove(n: Int): Int {
    val res = (powRec(2, n) - 2 + mod)%mod
    return res.toInt()
}
