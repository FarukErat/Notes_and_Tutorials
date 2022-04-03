#importing "random" library to get random data
import random

#defining the number of the people by a constant, which is generated with all capital letters
PEOPLE_NUMBER = 6

#creating lists whose elements will be chosen randomly
NAMES = ["Faruk", "Taha", "James", "Mary", "Robert", "Patricia", "John", "Jennifer"]
CITIES = ["Antalya", "Tokyo", "Shangai", "Ankara", "Mexico City", "Cairo", "New York", "Paris"]
DEATHS = ["COVID-19", "Hunger", "Car crash", "Heart attack", "Cancer", "WW3", "AIDS"]

#creating an empty list to store the person objects
people = []

#defining the class
class Person():
    #defining the inital function which is called when an object is created
    def __init__(self):
        #generating the attributes and setting them in advance 
        self.name = "unknown"
        self.city = "unknown"
        self.death = "unknown"
        self.age = 0
        self.height = 0
        self.weight = 0

    #defining a function, which is called method, since it is a member of an object, to print the attributes of the class
    def print_obj(self):
        print("name:\t", self.name)
        print("city:\t", self.city)
        print("death:\t", self.death)
        print("age:\t", self.age)
        print("height:\t", self.height)
        print("weight:\t", self.weight)
    
    #defining a function to set the attributes randomly
    def init_rand(self):
        #len() func returns the size of the list
        #randrange() func takes integer. if n is entered, it will generate a random number between [0,n)
        #if n,m is entered as two integer, it will generate a random number between [n,m)
        #the random number are used to get a random member from the lists
        self.name = NAMES[random.randrange(len(NAMES))]
        self.city = CITIES[random.randrange(len(CITIES))]
        self.death = DEATHS[random.randrange(len(DEATHS))]
        #randint is almost the same as randrange, the difference is it returns between [n,m]
        self.age = random.randint(15, 55)
        self.height = random.randint(150, 190)
        self.weight = random.randint(55, 105)

#creating objects and adding them into the end of people list
for p in range(PEOPLE_NUMBER):
    #creating object
    obj = Person()
    #setting the attributes of it
    obj.init_rand()
    #appending them into the list
    people.append(obj)

#a for list to print all the attributes of each object
for obj in people:
    #using a "method" to print
    obj.print_obj()
    #to sperate the object outputs from eachother, a print func is used
    print()
