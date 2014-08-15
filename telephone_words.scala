import scala.collection.immutable.HashMap

object Main extends App {
  val keymap = HashMap(0 -> List("0"), 
		       1 -> List("1"), 
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
    val xs = for(x <- l.split("").filter(_.length > 0)) yield x.toInt
    println(telephoneWords(xs.toList, keymap))
  }

  def telephoneWords(xs: List[Int], map: HashMap[Int, List[String]]): List[String] = {
    def genString(s: String, ys: List[String]): String = ys match {
      case Nil => s
      case y :: Nil => s + genString(y, Nil)
      case y :: ys => s + genString(y, ys.tail)
    }

    val keys = for (x <- xs) yield map(x)
    println(keys)

    //for (k <- keys) if (keys.head != k) println(genString(keys.head.head, k))
    for (k <- keys) println(k)

    Nil
  }

}
