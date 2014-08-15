
object Main extends App {

  val source = scala.io.Source.fromFile(args(0))
  val lines = source.getLines.filter(_.length > 0)
  for (l <- lines) {
    println("RESULT:" + predictNum(l.toLong))
  }
 
  def predictNum(n: Long): Int = {
    def genNum(index: Long, count: Long, seq: String): Int = {
//      println("i:" + index)
//      println("c:" + count)
//      println("seq:" + seq)
//      println(count - index)
      if (seq.length > index) seq.substring ( index.toInt, index.toInt + 1 ).toInt
      else {
	val s: String = seq map (c => if (c == '0') '1' else if (c == '1') '2' else '0')
//	println("s:" + s)
	genNum(index, 0, seq + s)
      }
    }
    genNum(n, 0, "0")
  }
}
