private fun getAll(
    d: IntArray,
    num: Int,
    idx: Int,
    vis: BooleanArray,
    res: MutableSet<Int>
) {
    if (num >= 100) {
        if (num % 2 == 0) {
            println(num)
            res.add(num)
        }
        return
    }

    for (i in 0 until d.size) {
        if (vis[i]) continue

        val nNum = num * 10 + d[i]

        vis[i] = true
        getAll(d, nNum, i, vis, res)
        vis[i] = false
    }
}

private fun getAll(digits: IntArray): Int {
    val freq = IntArray(10)
    digits.forEach {
        freq[it]++
    }
    val res = (100..999 step 2).count {
        var temp = it
        val freqNum = IntArray(10)
        while (temp > 0) {
            val d = temp % 10
            freqNum[d]++
            temp /= 10
        }
        val isValid = (0..9).all { freq[it] >= freqNum[it] }
        isValid
    }
    return res
}

fun totalNumbers(digits: IntArray): Int {
    if (digits.size < 3) return 0

    val res = mutableSetOf<Int>()

    getAll(
        digits,
        0,
        -1,
        BooleanArray(digits.size),
        res
    )

    return res.size
    return getAll(digits)
}
