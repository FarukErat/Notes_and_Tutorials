import 'dart:isolate';

void main() async {
  ReceivePort receivePort = ReceivePort();
  Isolate isolate = await Isolate.spawn(_isolateFunction, receivePort.sendPort);
  receivePort.listen((message) {
    print('Received message: $message');
    receivePort.close();
  });
  isolate.kill(priority: Isolate.immediate);
}

void _isolateFunction(SendPort sendPort) {
  sendPort.send('Hello from isolate!');
}
