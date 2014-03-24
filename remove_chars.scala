import scala.annotation.tailrec

object Main extends App {
  val source = scala.io.Source.fromFile(args(0))
  val lines = source.getLines.filter(_.length > 0)
  for (l <- lines) {
    val lr = l.split(',') map (s => s.trim.toList)
    val xs = lr(0).toList
    val ys = lr(1).toSet
    val zs = xs filterNot ys
    println ( (zs mkString("")).trim )
  }
}
