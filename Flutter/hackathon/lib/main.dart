import 'package:flutter/material.dart';

void main() {
  runApp(const MyApp());
}

class MyApp extends StatelessWidget {
  const MyApp({super.key});
  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      debugShowCheckedModeBanner: false,
      home: Scaffold(
        appBar: AppBar(
          title: const Text('My First App'),
          backgroundColor: Colors.black,
          centerTitle: true,
        ),
        body: Column(
          children: [
            Image.asset('assets/party.jpg'),
            Container(
              padding: const EdgeInsets.all(10),
              child: Column(
                children: [
                  Row(
                    children: [
                      Icon(Icons.person),
                      Text('  Faruk Erat'),
                    ],
                  ),
                  Text(
                    'This is my first app. ' * 10,
                    style: TextStyle(fontSize: 16),
                  ),
                ],
              ),
              margin: const EdgeInsets.all(10),
              decoration: BoxDecoration(
                borderRadius: BorderRadius.circular(10),
                color: Colors.grey[400],
              ),
            ),
            Container(
              padding: const EdgeInsets.all(10),
              child: Text('Go to the next page', style: TextStyle(fontSize: 20)),
              decoration: BoxDecoration(
                borderRadius: BorderRadius.circular(10),
                color: Colors.green[400],
              ),
            ),
          ],
        ),
      ),
    );
  }
}
