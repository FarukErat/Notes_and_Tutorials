class Child {
  String? name;
  int? age;

  Child({this.name, this.age});

  Child.fromJson(Map<String, dynamic> json) {
    name = json['name'];
    age = json['age'];
  }

  Map<String, dynamic> toJson() {
    final Map<String, dynamic> data = new Map<String, dynamic>();
    data['name'] = this.name;
    data['age'] = this.age;
    return data;
  }
}

class Person {
  String? name;
  int? age;
  List? children = [];

  Person({this.name, this.age, this.children});

  Person.fromJson(Map<String, dynamic> json) {
    name = json['name'];
    age = json['age'];
    if (json['children'] != null) {
      children = [];
      json['children'].forEach((v) {
        children!.add(new Person.fromJson(v));
      });
    }
  }

  Map<String, dynamic> toJson() {
    final Map<String, dynamic> data = new Map<String, dynamic>();
    data['name'] = this.name;
    data['age'] = this.age;
    if (this.children != null) {
      data['children'] = this.children!.map((v) => v.toJson()).toList();
    }
    return data;
  }
}

void main() {
  var person = Person(
    name: 'John',
    age: 30,
    children: [
      Person(name: 'Mary', age: 5, children: []),
      Person(name: 'Peter', age: 3, children: []),
    ],
  );
  print(person.toJson());

  Map<String, dynamic> json = person.toJson();
  Person person2 = Person.fromJson(json);
  print(person2.toJson());
}
