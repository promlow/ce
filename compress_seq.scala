import scala.annotation.tailrec

object Main extends App {
  val source = scala.io.Source.fromFile(args(0))
  val lines = source.getLines.filter(_.length > 0)
  for (l <- lines) {
    val xs = for (x <- l.split(" ").toList) yield x.toInt    
    val ys = compressSequence(xs)
    val zs = for (y <- ys) yield y._1.toString.trim + " " + y._2.toString.trim
    println (zs.mkString(" ").trim)
  }

  def compressSequence(xs: List[Int]): List[(Int, Int)] = {
    @tailrec
    def compressor(acc: Int, head: Int, xs: List[Int], zs: List[(Int, Int)]): List[(Int, Int)] = xs match {
	case Nil => zs :+ (acc, head)
	case x :: Nil => if (head == x) List((acc + 1, head))
			 else zs :+ (acc, head) :+ (1, x)
	case x :: xs  => if (head == x) compressor(acc + 1, x, xs, zs);
		         else compressor(1, x, xs, zs :+ (acc, head))
      }
    compressor(1, xs.head, xs.tail, List())
  }
}
