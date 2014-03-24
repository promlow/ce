import scala.annotation.tailrec

object Main extends App {
  val source = scala.io.Source.fromFile(args(0))
  val lines = source.getLines.filter(_.length > 0)
  for (l <- lines) {
    val xs = for (x <- l.split(" ").toList) yield x.toInt    
    val ys = compressSequence(xs)
    println(ys map( y => y._1.toString + " " + y._2.toString) mkString(" "))
  }

  def compressSequence(xs: List[Int]): List[(Int, Int)] = {
    @tailrec
    def compressor(acc: Int, head: Int, xs: List[Int], zs: List[(Int, Int)]): List[(Int, Int)] = xs match {
	case Nil => (acc, head) :: zs
	case x :: Nil => if (head == x) zs :+ (acc + 1, head);
			 else zs :+ (1, x)
	case x :: xs  => if (head == x) compressor(acc + 1, x, xs, zs);
		         else compressor(1, x, xs, zs :+ (acc, head))
      }
    compressor(1, xs.head, xs.tail, List())
  }
}
// 5 81 7 94 9 65 9 20 8 41 9 0 8 25 10 82 8 57 10 10 6 58 7 66 1 47 9 72 7 90 10 79 5 97
