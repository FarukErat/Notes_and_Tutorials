class Person {
  int age = 0;
  Person(this.age);
  int get daysLived => age * 365;
  set daysLived(int value) => age = value ~/ 365;
}

void main() {
  var p = Person(1);
  print(p.age);
  print(p.daysLived);
  p.daysLived = 365 * 15;
  print(p.age);
  print(p.daysLived);
}
