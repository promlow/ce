import scala.annotation.tailrec

object Main extends App {
  @tailrec
  def bubblesort(xs: List[Int], iter: Int) : List[Int] = xs match {
    case Nil => Nil
    case (x :: Nil) => Nil
    case (x :: xs) => bubblesort(xs, iter - 1)
  }

  val source = scala.io.Source.fromFile(args(0))
  val lines = source.getLines.filter(_.length > 0)
  for (l <- lines) {
    println(l)
    val splitLine = l.split("""\|""")
    val nums = splitLine(0).split(" ").map(x => x.toInt)
    println(nums.toList)
    val n = splitLine(1).toString.trim.toInt
    println(bubblesort(nums.toList, n))
  }
}
