void main() {
  Car car = Car(weight: 1000);
  print(car.countryCode);
}

class Car {
  /*
  ! Question Mark ( ? )

  If we declare a variable without initializing it,
  Compiler tries to assign a default value to the variable,
  which is null by default.

  However, the type of the variable is not nullable,
  which means it cannot be assigned null value.
  Therefore, the compiler will throw an error.

  If we declare a variable with a question mark after the type,
  the type of the variable becomes nullable, (int? = nullable int)
  which means it can be assigned null value.
  Therefore, the compiler will not throw an error,
  and the variable will be assigned null value by default,
  when the variable is not initialized.

  ! Exclamation Mark ( ! )

  When we want to assign a non-nullable variable to a nullable variable,
  we can use the exclamation mark ( ! ) after the variable name.

  This mark converts the variable to a non-nullable variable.

  However, if the variable that we marked as non-nullable is null,
  the compiler will throw a runtime error.


  ! 'required' Keyword

  If we declare non-nullable variable without initializing it,
  however, we initialize it in the constructor,
  the compiler will not throw an error.

  However, dart has another way to initialize variables in the constructor than usual ones,
  which is called 'named parameters'.
  In this case, users do not have to send all the parameters,
  when they call the constructor, since it is named.

  This feature brings about a problem,
  which is that users can forget to send a non-nullable parameter,
  and the compiler will not throw an error.

  With the 'required' keyword, dart compiler will assure that,
  the variable is initialized with constructor.
  This way, compiler will not throw an error,
  when we declare a non-nullable variable without initializing it.


  ! 'late' Keyword

  The 'late' keyword tells the compiler,
  that we will initialize the variable later, before using it.

  If the variable is not initialized before using it,
  the compiler will throw a runtime error, when we use the variable.

  ! 'late' Keyword vs 'required' Keyword

  The 'late' keyword is used to initialize a variable,
  that is declared without initializing it,
  and we want to use the variable before the constructor.

  The 'required' keyword is used to initialize a variable,
  that is declared without initializing it,
  and we want to use the variable after the constructor.

  ! 'late final' Keywords Together

  The 'late final' keywords together,
  tells the compiler that,
  we will initialize the variable later, before using it,
  and we will not change the value of the variable.

  If we try to change the value of the variable,
  the compiler will throw a runtime error.

  */
  int weight;
  int? speed;
  // int speed; // Error: The non-nullable local variable 'speed' must be assigned before it can be used.
  late int countryCode;
  Car({
    required this.weight,
    this.speed,
  });
}
