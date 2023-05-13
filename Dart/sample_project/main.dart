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
  var p = PersonController.getPeopleByName("Faruk");
  PersonView.displayPeople(p);
  print(p![0].toMap());
  print(p[0].toJson());
}
