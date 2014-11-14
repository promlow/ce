import scala.annotation.tailrec

object Main extends App {
  val source = scala.io.Source.fromFile(args(0))
  val lines = source.getLines.filter(_.length > 0)
  for (l <- lines) {
    val splitLine = l.toString.split(";")
    val words = splitLine(0).split(" ").zipWithIndex.toList
    val given_indices = splitLine(1).split(" ").filter(_.length > 0).map(x => x.toInt - 1)
    val all_indices = for(i <- 0 to words.size - 1) yield(i)
    val indices = given_indices ++ all_indices.diff(given_indices)
    val most = for(i <- 0 to indices.size - 1) yield (words(i)._1, indices(i))
    val sentence = most.sortBy(_._2).map(x => x._1)
    println(sentence.mkString(" "))
  }
}
