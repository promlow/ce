import scala.collection.immutable.HashMap

object Main extends App {
  val keymap = HashMap(0 -> List("0"), 
		       1 -> ("1"), 
		       2 -> List("a", "b", "c"),
		       3 -> List("d", "e", "f"),
		       4 -> List("g", "h", "i"),
		       5 -> List("j", "k", "l"),
		       6 -> List("m", "n", "o"),
		       7 -> List("p", "q", "r", "s"),
		       8 -> List("t", "u", "v"),
		       9 -> List("w", "x", "y", "z")
		       )
  val source = scala.io.Source.fromFile(args(0))
  val lines = source.getLines.filter(_.length > 0)
  for (l <- lines) {
    val xs = l.toList
    println(xs)
  }

  def telephoneWords(xs: List[String], map: HashMap[Int, List[String]]): List[String] = {
    return xs
  }

}
