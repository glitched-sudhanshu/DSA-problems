// funcational way - function itself returns the answer
fun sumOfN(n: Int): Int {
    if(n == 0) return 0;
    return sumOfN(n-1) + n;
}

//parameterized way
fun sumOfNViaP(curr: Int, n: Int){
    if(n == 0) {
        println(curr)
        return;
    }
    sumOfNViaP(curr+n, n-1);
}

// factorial of a number
fun factorial(n: Int): Int {
    if(n == 0) return 1;

    return n * factorial(n-1);
}

fun main() {
    val n: Int = readln().toInt()
    println(sumOfN(n))
    println("--------------------")
    println(sumOfNViaP(0,n))
    println("--------------------")
    println(factorial(n))
}