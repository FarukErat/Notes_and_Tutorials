import 'dart:convert';
import 'package:flutter/material.dart';
import 'package:flutter/services.dart';
import 'package:http/http.dart' as http;

Future<void> main() async {
  runApp(const MyApp());
}

class MyApp extends StatelessWidget {
  const MyApp({Key? key}) : super(key: key);

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      title: 'Bcrypt Hash',
      home: const MyHomePage(title: 'Hash with Bcrypt'),
      theme: ThemeData.dark(),
      debugShowCheckedModeBanner: false,
    );
  }
}

class MyHomePage extends StatefulWidget {
  const MyHomePage({Key? key, required this.title}) : super(key: key);

  final String title;

  @override
  State<MyHomePage> createState() => _MyHomePageState();
}

class _MyHomePageState extends State<MyHomePage> {
  String? _password;
  final _inputText = TextEditingController();

  @override
  void dispose() {
    _inputText.dispose();
    super.dispose();
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
                hintText: 'Password',
              ),
              maxLength: 40,
              style: const TextStyle(fontSize: 20),
              onSubmitted: (value) {
                setState(
                  () {
                    if (value.isEmpty) {
                      _password = null;
                    } else {
                      _password = value;
                    }
                  },
                );
              },
            ),
            const SizedBox(height: 20),
            if (_password != null)
              FutureBuilder<String>(
                future: bcryptHash(_password!),
                builder: (context, snapshot) {
                  if (snapshot.hasData) {
                    return Column(
                      children: [
                        const Text(
                          "BCRYPT   HASH",
                          style: TextStyle(
                            color: Colors.lightBlue,
                          ),
                        ),
                        Text(snapshot.data!),
                        const SizedBox(
                          height: 10,
                        ),
                        ElevatedButton(
                          onPressed: () {
                            _copyToClipboard(snapshot.data!);
                          },
                          style: ElevatedButton.styleFrom(
                              backgroundColor: Colors.grey),
                          child: const Text('Copy Hash'),
                        ),
                      ],
                    );
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

  Future<void> _copyToClipboard(String text) async {
    await Clipboard.setData(ClipboardData(text: text));
    if (context.mounted) {
      ScaffoldMessenger.of(context).showSnackBar(
        const SnackBar(content: Text('Hash copied to clipboard')),
      );
    }
  }
}

Future<String> bcryptHash(String password) async {
  String? hash;

  // serverIp may change
  // use the one that the server outputs
  // do not use localhost nor 127.0.0.1
  const serverIp = "192.168.1.103";
  const url = "http://$serverIp:3013";

  var data = {'password': password};
  var response = await http.post(
    Uri.parse('$url/hash'),
    headers: {
      'Content-Type': 'application/json; charset=UTF-8',
    },
    body: json.encode(data),
  );
  if (response.statusCode == 200) {
    hash = jsonDecode(response.body)["hash"];
  }
  return hash ?? "Error";
}
