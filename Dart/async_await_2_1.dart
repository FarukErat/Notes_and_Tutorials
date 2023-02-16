import 'dart:async';

void main() {
  print('main: begin');
  showFileContent();
  print('main: end');
}

void showFileContent() {
  print('showFileContent: begin');
  Future<String> fileContent = downloadFileContent();
  print('showFileContent: done: $fileContent');
}

Future<String> downloadFileContent() {
  print('downloadFileContent: begin');
  Future<String> fileContent = Future.delayed(Duration(seconds: 5), () {
    print('downloadFileContent: done');
    return 'file content';
  });
  print('downloadFileContent: end');
  return fileContent;
}

/*
main: begin
showFileContent: begin
downloadFileContent: begin
downloadFileContent: end
showFileContent: done: Instance of 'Future<String>'
main: end
downloadFileContent: done
*/
