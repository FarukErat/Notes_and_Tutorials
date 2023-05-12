import '../models/person_model.dart';

class PersonView {
  // Displays information about a single person
  static void displayPerson(Person? person, {int depth = 0}) {
    if (person == null) {
      return;
    }
    final indent = ' ' * depth * 2;
    print(indent + '-' * 18);
    if (person.id != null) {
      print('${indent}id: ${person.id}');
    }
    if (person.name != null) {
      print('${indent}Name: ${person.name}');
    }
    if (person.age != null) {
      print('${indent}Age: ${person.age}');
    }
    if (person.hobbies != null && person.hobbies!.isNotEmpty) {
      print('${indent}Hobbies:');
      for (String hobby in person.hobbies!) {
        print('${indent}- $hobby');
      }
    }
    if (person.children != null && person.children!.isNotEmpty) {
      print('${indent}Children:');
      for (Person child in person.children!) {
        displayPerson(child, depth: depth + 1);
      }
    }
  }

  // Displays information about a list of people
  static void displayPeople(List<Person>? people) {
    if (people == null) {
      return;
    }
    if (people.isEmpty) {
      print('No people to display.');
    } else {
      for (Person person in people) {
        displayPerson(person);
        print('-' * 18);
      }
    }
  }
}
