fun printName(current: Int, times: Int) {
    if(current == times) return

    println("Sush Ranjan")
    printName(current+1, times)
}

fun printTillN(curr: Int, n: Int) {
    if(curr>n) return

    println(curr)
    printTillN(curr+1, n);
}

// backtrack
fun printTillNViaBt(curr: Int) {
    if(curr<0) return

    printTillNViaBt(curr-1);
    println(curr)
}

fun printFromN(curr: Int) {
    if (curr<0) return
    println(curr)
    printFromN(curr-1)
}

//backtrack
fun printFromNViaBt(curr: Int, n: Int) {
    if (curr>n) return
    printFromNViaBt(curr+1, n)
    println(curr)
}

fun main() {
    val times: Int = readln().toInt()
    printName(0, times)
    println("--------------")
    printTillN(0, times)
    println("--------------")
    printFromN(times)
    println("--------------")
    printTillNViaBt(times)
    println("--------------")
    printFromNViaBt(0, times)
    println("--------------")
}