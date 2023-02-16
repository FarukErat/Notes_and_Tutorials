// if there is no await before async functions
// then the async functions are started but not waited for

// if there is await before async functions
// then the async functions are started and waited for

// calc
Future<void> calc1(String funcName) async {
  String calcName = 'calc1';
  print('$funcName: $calcName: starting');
  await Future.delayed(Duration(seconds: 2));
  print('$funcName: calc: done');
}

Future<void> calc2(String funcName) async {
  String calcName = 'calc2';
  print('$funcName: $calcName: starting');
  Future.delayed(Duration(seconds: 2));
  print('$funcName: calc: done');
}

Future<void> calc3(String funcName) async {
  String calcName = 'calc3';
  print('$funcName: $calcName: starting');
  for (int i = 0; i < 100000; i++) {
    for (int j = 0; j < 100000; j++) {
      i = i;
    }
  }
  print('$funcName: calc: done');
}

// foo
void foo1(Future<void> calc(String funcName)) {
  String funcName = 'foo1';
  print('$funcName: starting');
  calc(funcName);
  print('$funcName: done');
}

Future<void> foo2(Future<void> calc(String funcName)) async {
  String funcName = 'foo2';
  print('$funcName: starting');
  await calc(funcName);
  print('$funcName: done');
}

Future<void> foo3(Future<void> calc(String funcName)) async {
  String funcName = 'foo3';
  print('$funcName: starting');
  calc(funcName);
  print('$funcName: done');
}

// funcGroup
void funcGroup1() {
  foo1(calc1);
  foo2(calc1);
  foo3(calc1);
}

void funcGroup2() {
  foo1(calc2);
  foo2(calc2);
  foo3(calc2);
}

void funcGroup3() {
  foo1(calc3);
  foo2(calc3);
  foo3(calc3);
}

void main() {
  print('main: starting');

  funcGroup1();
  // funcGroup2();
  // funcGroup3();

  print('main: done');
}

/*
funcGroup1             funcGroup2             funcGroup3
---------------------  ---------------------  ---------------------
main: starting         main: starting          main: starting
foo1: starting         foo1: starting          foo1: starting
foo1: calc1: starting  foo1: calc2: starting   foo1: calc3: starting
foo1: done             foo1: calc: done        foo1: calc: done
foo2: starting         foo1: done              foo1: done
foo2: calc1: starting  foo2: starting          foo2: starting
foo3: starting         foo2: calc2: starting   foo2: calc3: starting
foo3: calc1: starting  foo2: calc: done        foo2: calc: done
foo3: done             foo3: starting          foo3: starting
main: done             foo3: calc2: starting   foo3: calc3: starting
foo1: calc: done       foo3: calc: done        foo3: calc: done
foo2: calc: done       foo3: done              foo3: done
foo2: done             main: done              main: done
foo3: calc: done       foo2: done              foo2: done
*/
