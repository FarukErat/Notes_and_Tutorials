import 'dart:convert';

import 'package:flutter/material.dart';
import 'package:http/http.dart' as http;

void main() {
  runApp(const MyApp());
}

class MyApp extends StatelessWidget {
  const MyApp({super.key});
  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      home: DataFromAPI(),
    );
  }
}

class DataFromAPI extends StatefulWidget {
  @override
  _DataFromAPIState createState() => _DataFromAPIState();
}

class _DataFromAPIState extends State<DataFromAPI> {
  Future getUserData() async {
    var response =
        await http.get(Uri.https('jsonplaceholder.typicode.com', 'users'));
    var jsonData = jsonDecode(response.body);
    List<User> users = [];
    for (var u in jsonData) {
      User user =
          User(name: u['name'], email: u['email'], userName: u['username']);
      users.add(user);
    }
    print(users.length);
    return users;
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: const Text('User Data'),
      ),
      body: Container(
        child: Card(
          child: FutureBuilder(
            future: getUserData(),
            builder: (context, snaphot) {
              if (snaphot.data == null) {
                return const Center(
                  child: Text('Loading...',
                      style: TextStyle(
                        fontSize: 20,
                        fontWeight: FontWeight.bold,
                        backgroundColor: Colors.orange,
                      )),
                );
              } else {
                return ListView.builder(
                  itemCount: snaphot.data.length,
                  itemBuilder: (context, i) {
                    return ListTile(
                      title: Text(snaphot.data[i].name),
                      subtitle: Text(snaphot.data[i].email),
                      tileColor: Colors.orange,
                      shape: ShapeBorder.lerp(
                        RoundedRectangleBorder(
                          borderRadius: BorderRadius.circular(10),
                        ),
                        RoundedRectangleBorder(
                          borderRadius: BorderRadius.circular(10),
                        ),
                        10,
                      ),
                    );
                  },
                );
              }
            },
          ),
        ),
      ),
    );
  }
}

class User {
  final String? name;
  final String? email;
  final String? userName;

  User({this.name, this.email, this.userName});

  factory User.fromJson(Map<String, dynamic> json) {
    return User(
      name: json['name'],
      email: json['email'],
      userName: json['username'],
    );
  }
}
