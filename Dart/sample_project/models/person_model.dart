import 'dart:convert';
import 'dart:math';

import '../database/people_database.dart';

class Person {
  String? id;
  String? name;
  String? surname;
  int? age;
  List<String>? hobbies; // contains primitive types
  List<Person>? children; // contains objects

  Person({
    this.id,
    this.name,
    this.surname,
    this.age,
    this.hobbies,
    this.children,
  }) {
    if (id == null) {
      int salt = Random().nextInt(4294967296);
      children?.forEach((c) {
        salt = '${c.id}$salt'.hashCode.abs();
      });
      String seed = "$name$surname$age$hobbies$salt";
      int hash = seed.hashCode.abs();
      this.id = hash.toString();
      if (peopleDB != null) {
        while (peopleDB!.any((p) => p.id == this.id)) {
          // Regenerate the hash if the id is not unique
          hash = (hash + 1).hashCode.abs();
          this.id = hash.toString();
        }
      }
    }
  }

  factory Person.fromMap(Map<String, dynamic> data) {
    return Person(
      id: data['id'],
      name: data['name'],
      surname: data['surname'],
      age: data['age'],
      hobbies: (data['hobbies'] as List).cast<String>(),
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
    data['id'] = this.id;
    data['name'] = this.name;
    data['surname'] = this.surname;
    data['age'] = this.age;
    data['hobbies'] = this.hobbies;
    if (this.children != null) {
      data['children'] = this.children!.map(
        (i) {
          return i.toMap();
        },
      ).toList();
    }
    data.removeWhere((key, value) => value == null);
    return data;
  }

  factory Person.fromJson(String jsonEncoded) {
    return Person.fromMap(jsonDecode(jsonEncoded));
  }

  String toJson() {
    return jsonEncode(this.toMap());
  }
}
