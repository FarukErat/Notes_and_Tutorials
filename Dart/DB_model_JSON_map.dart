class Person {
  String? name;
  int? age;
  List<String>? hobbies; // contains primitive types
  List<Person>? children; // contains objects

  Person({
    this.name,
    this.age,
    this.hobbies,
    this.children,
  });

  factory Person.fromJson(Map<String, dynamic> json) {
    return Person(
      name: json['name'],
      age: json['age'],
      hobbies: json['hobbies'],
      children: json['children'] != null
          ? (json['children'] as List).map(
              (i) {
                return Person.fromJson(i);
              },
            ).toList()
          : null,
    );
  }

  Map<String, dynamic> toJson() {
    final Map<String, dynamic> json = new Map<String, dynamic>();
    json['name'] = this.name;
    json['age'] = this.age;
    json['hobbies'] = this.hobbies;
    if (this.children != null) {
      json['children'] = this.children!.map(
        (i) {
          return i.toJson();
        },
      ).toList();
    }
    return json;
  }
}

void main() {
  Person p1 = Person(
    name: 'John',
    age: 30,
    hobbies: ['swimming', 'reading'],
    children: [
      Person(
        name: 'Mary',
        age: 5,
        hobbies: ['dancing', 'singing'],
      ),
      Person(
        name: 'Peter',
        age: 3,
        hobbies: ['playing'],
      ),
    ],
  );

  print(p1.toJson());
  Person p2 = Person.fromJson(p1.toJson());
  print(p2.toJson());
}

// Output:
// {name: John, age: 30, hobbies: [swimming, reading], children: [{name: Mary, age: 5, hobbies: [dancing, singing]}, {name: Peter, age: 3, hobbies: [playing]}]}
// {name: John, age: 30, hobbies: [swimming, reading], children: [{name: Mary, age: 5, hobbies: [dancing, singing]}, {name: Peter, age: 3, hobbies: [playing]}]}
