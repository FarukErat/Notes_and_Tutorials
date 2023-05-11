import './controllers/person_controller.dart';
import './views/person_view.dart';
import './models/person_model.dart';

void main() {
  PersonController.addPerson(
    Person(
      name: "Faruk Erat",
      age: 21,
      hobbies: [
        "playing reversi",
        "coding",
      ],
      children: [
        Person(
          name: "Cengiz",
          hobbies: [
            "surfing but on the internet",
          ],
          children: [
            Person(
              name: "Metehan",
            )
          ],
        ),
      ],
    ),
  );
  PersonView.displayPeople(PersonController.getPeopleByName("Faruk Erat"));
}
