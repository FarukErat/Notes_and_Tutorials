import 'dart:async';
import 'package:flutter/foundation.dart';

void main() async {
  List<int> numbers = [1, 2, 3, 4, 5];
  int sum = await compute(_sum, numbers);
  print('Sum of $numbers is $sum');
}

int _sum(List<int> numbers) {
  return numbers.reduce((a, b) => a + b);
}
