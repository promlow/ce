import scala.annotation.tailrec

object Main extends App {
  val source = scala.io.Source.fromFile(args(0))
  val lines = source.getLines.filter(_.length > 0)
  for (l <- lines) {
    val lr = l.split('|') map (s => s.trim.split(' ').toList)
    val xs = for (x <- lr(0)) yield x.toInt
    val ys = for (y <- lr(1)) yield y.toInt
    println ( (xs, ys).zipped.map( _ * _ ) mkString(" ") )
  }
}
