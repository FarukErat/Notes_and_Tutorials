import 'package:flutter/foundation.dart';
import 'package:flutter/material.dart';
import 'package:flutter/services.dart';
import 'dart:math';

Future<void> main() async {
  runApp(const MyApp());
}

class MyApp extends StatelessWidget {
  const MyApp({super.key});

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      title: 'Factorization',
      home: const MyHomePage(title: 'Factorization'),
      theme: ThemeData.dark(),
    );
  }
}

class MyHomePage extends StatefulWidget {
  const MyHomePage({super.key, required this.title});

  final String title;

  @override
  State<MyHomePage> createState() => _MyHomePageState();
}

class _MyHomePageState extends State<MyHomePage> {
  int? _inputNumber;
  final _inputText = TextEditingController();

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: Text(widget.title),
      ),
      body: Center(
        child: Column(
          mainAxisAlignment: MainAxisAlignment.center,
          children: <Widget>[
            TextField(
              controller: _inputText,
              decoration: const InputDecoration(
                border: OutlineInputBorder(),
                hintText: 'Please enter a number',
              ),
              keyboardType: TextInputType.number,
              maxLength: 18,
              style: const TextStyle(fontSize: 20),
              inputFormatters: <TextInputFormatter>[
                FilteringTextInputFormatter.digitsOnly
              ],
              onSubmitted: (value) {
                setState(
                  () {
                    if (value.isEmpty) {
                      _inputNumber = null;
                    } else {
                      _inputNumber = int.parse(value);
                    }
                  },
                );
              },
            ),
            const SizedBox(height: 20),
            if (_inputNumber != null)
              FutureBuilder<Expanded>(
                future: factorsExpanded(_inputNumber!),
                builder: (context, snapshot) {
                  if (snapshot.hasData) {
                    return snapshot.data!;
                  } else if (snapshot.hasError) {
                    return Text('${snapshot.error}');
                  }
                  return const CircularProgressIndicator();
                },
              ),
          ],
        ),
      ),
    );
  }
}

List<String> factorize(int number) {
  List<int> factors = [];
  List<int> powers = [];
  List<String> result = [];
  int divider = 3;
  int lastDivider = 1;
  int stop = sqrt(number).toInt();
  if (number >= 0 && number <= 3) {
    factors.add(number);
    powers.add(1);
  } else {
    if (number % 2 == 0) {
      factors.add(2);
      powers.add(0);
      do {
        number = number ~/ 2;
        stop = sqrt(number).toInt();
        powers[0]++;
      } while (number % 2 == 0);
    }
    while (number > 1) {
      if (number % divider == 0) {
        number = number ~/ divider;
        stop = sqrt(number).toInt();
        if (divider == lastDivider) {
          powers[powers.length - 1]++;
        } else {
          factors.add(divider);
          powers.add(1);
          lastDivider = divider;
        }
      } else {
        divider += 2;
        if (divider > stop) {
          divider = number;
        }
      }
    }
  }
  for (int i = 0; i < factors.length; i++) {
    if (powers[i] == 1) {
      result.add(factors[i].toString());
    } else {
      result.add('${factors[i]} ^ ${powers[i]}');
    }
  }
  return result;
}

Future<Expanded> factorsExpanded(int number) async {
  List<String> factors = await compute(factorize, number);
  return Expanded(
    child: ListView.builder(
      itemCount: factors.length,
      itemBuilder: (context, index) {
        return Column(
          children: [
            ListTile(
              title: Text(factors[index]),
            ),
            const Divider(
              height: 2,
              thickness: 1,
            ),
          ],
        );
      },
    ),
  );
}
