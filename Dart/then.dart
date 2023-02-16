import 'dart:io';

void main() async {
  print('main: begin');
  CreatedData data1 = await _createData1();
  print('data1: ${data1.data}');
  CreatedData data2 = await _createData2();
  print('data2: ${data2.data}');
  CreatedData data3 = await _createData3();
  print('data3: ${data3.data}');
  print('main: end');
}

Future<int> _loadFromDisk() async {
  return Future.delayed(Duration(seconds: 2), () => 42);
}

Future<String> _fetchNetworkData(int id) async {
  return Future.delayed(
      Duration(seconds: 2), () => 'network data with id: $id');
}

class CreatedData {
  final String data;

  CreatedData(this.data);

  CreatedData.empty() : data = 'empty';
}

Future<CreatedData> _createData1() async {
  return _loadFromDisk().then((id) {
    return _fetchNetworkData(id);
  }).then((data) {
    return CreatedData(data);
  });
}

Future<CreatedData> _createData2() async {
  int id = await _loadFromDisk();
  String data = await _fetchNetworkData(id);
  return CreatedData(data);
}

Future<CreatedData> _createData3() async {
  try {
    int id = await _loadFromDisk();
    String data = await _fetchNetworkData(id);
    return CreatedData(data);
  } on HttpException catch (e) {
    print('HttpException: $e');
    return CreatedData.empty();
  } finally {
    print('All done!');
  }
}
