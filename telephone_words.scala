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

    def perms(s: String, ys: List[List[String]]): String = ys match {
      case Nil => s
      case y :: Nil => perms(y.head, List(y.tail))
      case y :: ys => s + perms(y.head, ys)
    }


    def permutations(s: List[String], ys: List[List[String]]): List[String] = ys match {
      case Nil => s match {
	case Nil => Nil
	case s :: Nil => s :: Nil
	case s :: ss => s :: permutations(ss, Nil)
      }
      case y :: Nil => s match {
	case Nil => permutations(y, Nil)
	case s :: Nil => s :: permutations(y, Nil)
	case s :: ss => s :: permutations(ss, y :: Nil)
      }
      case y :: ys => s match {
	case Nil => permutations(y, ys)
	case s :: Nil => s :: permutations(y, ys)
	case s :: ss => s :: permutations(ss, y :: ys)
      }
    }
    
    val keys = for (x <- xs) yield map(x)
    println(keys)
    println(perms(keys.head.head, keys.tail))
    permutations(keys.head, keys.tail)
  }

}
