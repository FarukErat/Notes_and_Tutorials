void foo1(int num) {
  print("foo1 $num");
}

// below is wrong because default value is not allowed as named parameter
// void foo1(int num = 0) { print("foo1 $num");}

void foo2({int? num}) {
  print("foo2 $num");
}

void foo3({int num = 0}) {
  print("foo3 $num");
}

void main() {
  // foo1(); // error
  foo1(1); // foo1 1
  // foo1(num: 1); // error

  foo2(); // foo2 null
  // foo2(1); // error
  foo2(num: 1); // foo2 1

  foo3(); // foo3 0
  // foo3(1); // error
  foo3(num: 1); // foo3 1
}
