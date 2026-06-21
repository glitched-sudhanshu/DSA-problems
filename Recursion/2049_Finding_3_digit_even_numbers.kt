/**
 * Question:
 * https://leetcode.com/problems/finding-3-digit-even-numbers/description/?envType=problem-list-v2&envId=recursion
 */

private fun findPermute(
    digits: IntArray,
    used: MutableList<Int>,
    curr: Int
): Set<Int> {
    if(used.size == 3) {
        return if(curr%2==0) {
            setOf(curr)
        } else {
            emptySet()
        }
    }
    val result = mutableSetOf<Int>()
    for(i in digits.indices) {
        if(i in used) continue;
        if(used.isEmpty() && digits[i] == 0) continue;

        used.add(i)
        result.addAll(
            findPermute(
                digits,
                used,
                curr*10+digits[i]
            )
        )
        used.removeAt(used.lastIndex)
    }
    return result
}

private fun mapMethod(digits: IntArray): IntArray {
    val freq = IntArray(10)
    digits.forEach {
        freq[it]++;
    }

    return (100..999 step 2)
        .filter { num ->
            val needed = IntArray(10)
            var temp = num
            repeat(3) {
                needed[temp%10]++;
                temp/=10
            }
            (0..9).all { needed[it] <= freq[it] }
        }.toIntArray()
}

fun findEvenNumbers(digits: IntArray): IntArray {
    val result = findPermute(
        digits,
        mutableListOf(),
        0
    )
    // recursion -
    // TC: O(n^k) (n - length of digits, k - number of digits in the target)
    // SC: O(k)
    return result.toIntArray().sortedArray()
    // optimization - 10
    // TC: k*(10^k)
    // SC: O(1)
    return mapMethod(digits)
}