/**
 * Question:
 * https://leetcode.com/problems/find-the-k-th-character-in-string-game-i/description/
 */

//TC: O(K)
// additional k for copying the string
private fun generate(k: Int, word: String): Char {
    if (word.length > k) return word[k - 1]

    var nword = word
    word.forEach {
        nword += it + 1
    }
    return generate(k, nword)
}

//TC: O(log(n))
private fun gen(k: Int): Char {
    if (k == 1) return 'a'

    var len = 1
    while (len < k) {
        len *= 2
    }
    return if (k <= len / 2) {
        gen(k)
    } else {
        val ch = gen(k - (len / 2))
        if (ch == 'z') 'a' else ch + 1
    }
}

fun kthCharacter(k: Int): Char {
    return generate(k, "a")

    return gen(k)

    //TC: O(log(n))
    return ('a' + Integer.bitCount(k - 1)).toChar()
}
