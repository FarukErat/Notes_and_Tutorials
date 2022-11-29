void main() {
  var c = Car();
  c.initiateEngine();
  c.initiateEngine();
}

abstract class Vehicle {
  int accelerationValue = 0;

  void accelerate();

  void decelerate();

  int getCapacity();
}

mixin EngineMixin {
  bool isEngineInitiated = false;

  void initiateEngine() {
    if (!isEngineInitiated) {
      isEngineInitiated = true;
      print('Engine is initiated');
    } else {
      print('Engine is already initiated');
    }
  }
}

class Car extends Vehicle with EngineMixin {
  @override
  void accelerate() {
    if (isEngineInitiated) {
      accelerationValue += 10;
    } else {
      initiateEngine();
    }
  }

  @override
  void decelerate() {
    if (isEngineInitiated && accelerationValue != 0) {
      accelerationValue -= 10;
    }
  }

  @override
  int getCapacity() => 5;
}
