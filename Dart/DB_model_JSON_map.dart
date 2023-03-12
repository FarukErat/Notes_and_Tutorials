class ChildModel {
  String? name;
  int? age;

  ChildModel({this.name, this.age});

  ChildModel.fromJson(Map<String, dynamic> json) {
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

class PersonModel {
  String? name;
  int? age;
  List<ChildModel>? children;

  PersonModel({this.name, this.age, this.children});

  PersonModel.fromJson(Map<String, dynamic> json) {
    name = json['name'];
    age = json['age'];
    if (json['children'] != null) {
      children = [];
      json['children'].forEach((v) {
        children!.add(new ChildModel.fromJson(v));
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
  var person = PersonModel(
    name: 'John',
    age: 30,
    children: [
      ChildModel(name: 'Tom', age: 5),
      ChildModel(name: 'Elsa', age: 6),
    ],
  );

  print(person.toJson());

  var person2 = PersonModel.fromJson(person.toJson());

  print(person2.toJson());
}
