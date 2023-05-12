import './controllers/person_controller.dart';
import './views/person_view.dart';
import './models/person_model.dart';

void main() {
  PersonController.addPerson(
    Person(
      name: "Faruk",
      surname: "Erat",
      age: 55,
      hobbies: [
        "playing reversi",
        "coding",
      ],
      children: [
        Person(
          name: "Cengiz",
          age: 30,
          hobbies: [
            "surfing but on the internet",
          ],
          children: [
            Person(
              name: "Metehan",
              age: 5,
            )
          ],
        ),
        Person(
          name: "Timur",
          age: 30,
          hobbies: [
            "hunting",
            "riding horse",
          ],
        )
      ],
    ),
  );
  PersonView.displayPeople(PersonController.getPeopleByName("Faruk"));
}
