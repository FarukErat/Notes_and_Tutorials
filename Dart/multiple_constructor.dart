class Point {
  final double x;
  final double y;

  Point(this.x, this.y);

  // Named constructor
  Point.origin()
      : x = 0,
        y = 0;
}

void main() {
  var p = Point(1, 2);
  print("p.x:${p.x}, p.y:${p.y}");
  var o = Point.origin();
  print("o.x:${o.x}, o.y:${o.y}");
}
