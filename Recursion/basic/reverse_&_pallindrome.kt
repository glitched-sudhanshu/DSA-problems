fun <T> Array<T>.swap(l: Int, r: Int) {
    val val_l = this[l]
    this[l] = this[r]
    this[r] = val_l
}

fun reverseArray(l: Int, arr: Array<Int>): Array<Int> {
    if(l>=(arr.size/2)) return arr;
    arr.swap(l, arr.size - l - 1);
    return reverseArray(l+1, arr)
}

fun checkPallindrome(idx: Int, str: String): Boolean {
    if(idx >= (str.length/2)) return true
    if(str[idx] != str[str.length - idx - 1]) return false;

    return checkPallindrome(idx+1, str);
}

fun main() {
    val arr = arrayOf(1,2,4,3,7,5,6)
    println(reverseArray(0, arr).contentToString())
    println("-------------------")
    val strArr = listOf("Sush", "Ranjan", "noon", "racecar", "ff")
    strArr.forEach {
        println(checkPallindrome(0, it))
        println("--------------")
    }
}