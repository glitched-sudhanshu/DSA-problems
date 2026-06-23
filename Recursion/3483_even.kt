fun getAll(d: IntArray, num: Int, idx: Int, id: List<Int>): Set<Int> {
    if (num >= 100) {
        return if (num % 2 == 0) {
            println(num)
            setOf(num)
        } else {
            emptySet()
        }
    }

    val res = mutableSetOf<Int>()

    for (i in 0 until d.size) {
        if (idx == i || i in id) continue

        var nNum = num * 10 + d[i]
        val nL = id + listOf(i)
        res += getAll(d, nNum, i, nL)
        nNum = 0
    }

    return res
}

fun totalNumbers(digits: IntArray): Int {
    if (digits.size < 3) return 0

    val res = getAll(digits, 0, -1, emptyList<Int>())

    return res.size
}
