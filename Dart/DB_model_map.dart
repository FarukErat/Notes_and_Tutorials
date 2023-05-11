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

  factory Person.fromMap(Map<String, dynamic> data) {
    return Person(
      name: data['name'],
      age: data['age'],
      hobbies: data['hobbies'],
      children: data['children'] != null
          ? (data['children'] as List).map(
              (i) {
                return Person.fromMap(i);
              },
            ).toList()
          : null,
    );
  }

  Map<String, dynamic> toMap() {
    final Map<String, dynamic> data = new Map<String, dynamic>();
    data['name'] = this.name;
    data['age'] = this.age;
    data['hobbies'] = this.hobbies;
    if (this.children != null) {
      data['children'] = this.children!.map(
        (i) {
          return i.toMap();
        },
      ).toList();
    }
    return data;
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

  print(p1.toMap());
  Person p2 = Person.fromMap(p1.toMap());
  print(p2.toMap());
}

// Output:
// {name: John, age: 30, hobbies: [swimming, reading], children: [{name: Mary, age: 5, hobbies: [dancing, singing]}, {name: Peter, age: 3, hobbies: [playing]}]}
// {name: John, age: 30, hobbies: [swimming, reading], children: [{name: Mary, age: 5, hobbies: [dancing, singing]}, {name: Peter, age: 3, hobbies: [playing]}]}
