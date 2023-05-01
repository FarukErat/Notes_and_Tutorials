class MyClass {
  int? a;
  int? b;

  MyClass({
    this.a,
    this.b,
  });

  void display() => _$display(this);
}

void _$display(MyClass instance) {
  print(instance.a);
  print(instance.b);
}

void main() {
  MyClass mc = MyClass(a: 1, b: 2);
  mc.display();
  _$display(mc);
}
