class Person {
  int? age;
  String? name;
  Person({this.age, this.name});
}

class Student extends Person {
  int? grade;
  String? school;
  Student({super.age, super.name, this.grade, this.school});
}

class Class {
  String? name;
  List<Student>? students;
  Class({this.name, this.students});
}

class Teacher extends Person with AbleToReadPdf {
  List<Class>? ownedClasses;
  Teacher({super.age, super.name, this.ownedClasses});
}

mixin AbleToReadPdf {
  void readPdf() {
    print("Reading pdf");
  }
}

void main() {
  Student ali = Student(name: "ali", age: 20);
  Student mehmet = Student(name: "mehmet", age: 19);
  Class first = Class(name: "first", students: [ali, mehmet]);
  Teacher yusuf = Teacher(age: 35, name: "yusuf", ownedClasses: [first]);
  print(
      '${yusuf.ownedClasses![0].students![0].name}, ${yusuf.ownedClasses![0].students![0].age}');
  print(
      '${yusuf.ownedClasses![0].students![1].name}, ${yusuf.ownedClasses![0].students![1].age}');
  yusuf.readPdf();
}
