class Car():
    def __init__(self) -> None:
        self.__color = 'black'
        self.__speed = 0

    def get_color(self) -> str:
        return self.__color

    def get_speed(self) -> int:
        return self.__speed

    def set_color(self, color: str) -> None:
        self.__color = color

    def set_speed(self, speed: int) -> None:
        self.__speed = speed


class Truck(Car):
    def __init__(self) -> None:
        super().__init__()
        self.__load = 0

    def get_load(self) -> int:
        return self.__load

    def set_load(self, load: int) -> None:
        self.__load = load


classes = [Car, Truck]

myTruck = classes[1]()

myTruck.set_color('red')
myTruck.set_speed(100)
myTruck.set_load(1000)

print(myTruck.get_color())
print(myTruck.get_speed())
print(myTruck.get_load())
