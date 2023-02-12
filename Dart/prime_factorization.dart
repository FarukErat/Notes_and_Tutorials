import 'package:flutter/material.dart';
import 'package:flutter/services.dart';
import 'dart:math';

void main() {
  runApp(const MyApp());
}

class MyApp extends StatelessWidget {
  const MyApp({super.key});

  @override
  Widget build(BuildContext context) {
    return const MaterialApp(
      title: 'Factorization',
      home: MyHomePage(title: 'Factorization'),
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
  Expanded _factors(int number) {
    List<int> factors = [];
    List<int> powers = [];
    List<String> result = [];
    int divider = 2;
    int lastDivider = 1;
    int stop = sqrt(number).toInt();
    if (number == 0 || number == 1) {
      factors.add(number);
      powers.add(1);
    } else {
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
          divider++;
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
    return Expanded(
      child: ListView.builder(
        itemCount: result.length,
        itemBuilder: (context, index) {
          return Column(
            crossAxisAlignment: CrossAxisAlignment.start,
            children: <Widget>[
              Text(
                result[index],
                style: const TextStyle(fontSize: 20),
              ),
              const Divider(
                color: Colors.black,
                height: 20,
                thickness: 1,
                indent: 0,
                endIndent: 0,
              ),
            ],
          );
        },
      ),
    );
  }

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
              maxLength: 15,
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
            if (_inputNumber != null) _factors(_inputNumber!)
          ],
        ),
      ),
    );
  }
}
