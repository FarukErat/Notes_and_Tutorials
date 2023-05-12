import 'package:json2yaml/json2yaml.dart';
import '../models/person_model.dart';

class PersonView {
  // Displays information about a single person
  static void displayPerson(Person? person, {int depth = 0}) {
    if (person == null) {
      return;
    }
    // print the attributes in yaml format
    print(json2yaml(person.toMap()));
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
