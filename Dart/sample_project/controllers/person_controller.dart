import '../database/people_database.dart';
import '../models/person_model.dart';

class PersonController {
  // Fetch all people from the database
  static List<Person>? getPeople() {
    return peopleDB;
  }

  // Add a new person to the database with a random ID
  static void addPerson(Person person) {
    if (peopleDB == null) {
      peopleDB = [person];
    } else {
      peopleDB!.add(person);
    }
  }

  // Update an existing person in the database
  static void updatePerson(String id, Person updatedPerson) {
    if (peopleDB != null) {
      int index = peopleDB!.indexWhere((person) => person.id == id);
      if (index >= 0) {
        peopleDB![index] = updatedPerson;
      }
    }
  }

  // Delete an existing person from the database
  static void deletePerson(String id) {
    if (peopleDB != null) {
      peopleDB!.removeWhere((person) => person.id == id);
    }
  }

  // Find a person by ID
  static Person? getPersonById(String id) {
    if (peopleDB != null) {
      return peopleDB!.firstWhere((person) => person.id == id);
    }
    return null;
  }

  // Find people by name
  static List<Person>? getPeopleByName(String name) {
    if (peopleDB != null) {
      return peopleDB!
          .where((person) =>
              person.name!.toLowerCase().contains(name.toLowerCase()))
          .toList();
    }
    return null;
  }

  // Find people by hobby
  static List<Person>? getPeopleByHobby(String hobby) {
    if (peopleDB != null) {
      return peopleDB!
          .where((person) => person.hobbies!.contains(hobby))
          .toList();
    }
    return null;
  }

  // Find all children of a person by ID
  static List<Person>? getChildrenById(String id) {
    Person? person = getPersonById(id);
    if (person != null) {
      return person.children;
    }
    return null;
  }

  // Add a child to a person by ID
  static void addChildById(String id, Person child) {
    Person? person = getPersonById(id);
    if (person != null) {
      if (person.children == null) {
        person.children = [child];
      } else {
        person.children!.add(child);
      }
    }
  }

  // Remove a child from a person by ID and child ID
  static void removeChildById(String id, String childId) {
    Person? person = getPersonById(id);
    if (person != null) {
      person.children?.removeWhere((child) => child.id == childId);
    }
  }

  static void addHobbyToPersonById(String id, String hobby) {
    Person? person = getPersonById(id);
    if (person != null) {
      if (person.hobbies == null) {
        person.hobbies = [hobby];
      } else if (!person.hobbies!.contains(hobby)) {
        person.hobbies!.add(hobby);
      }
    }
  }

  static void removeHobbyFromPersonById(String id, String hobby) {
    Person? person = getPersonById(id);
    if (person != null) {
      person.hobbies?.remove(hobby);
    }
  }
}
