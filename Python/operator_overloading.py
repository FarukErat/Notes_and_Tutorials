class Number:
    def __init__(self, whole=0, numerator=0, denominator=1):
        if denominator == 0:
            raise ValueError("Denominator cannot be zero")
        self.whole = whole
        self.numerator = numerator
        self.denominator = denominator
        self.simplify()

    def simplify(self):
        temp = self.numerator // 2 + 1
        for i in range(2, temp + 1):
            while self.numerator % i == 0 and self.denominator % i == 0:
                self.numerator //= i
                self.denominator //= i
        self.whole += self.numerator // self.denominator
        self.numerator %= self.denominator

    def format(self):
        self.numerator = self.whole * self.denominator + self.numerator
        self.whole = 0

    def __add__(self, other):
        sum = Number()
        self.format()
        other.format()
        sum.numerator = self.numerator * other.denominator + other.numerator * self.denominator
        sum.denominator = self.denominator * other.denominator
        sum.simplify()
        return sum

    def __sub__(self, other):
        diff = Number()
        self.format()
        other.format()
        diff.numerator = self.numerator * other.denominator - other.numerator * self.denominator
        diff.denominator = self.denominator * other.denominator
        diff.simplify()
        return diff

    def __mul__(self, other):
        product = Number()
        self.format()
        other.format()
        product.numerator = self.numerator * other.numerator
        product.denominator = self.denominator * other.denominator
        product.simplify()
        return product

    def __truediv__(self, other):
        quotient = Number()
        self.format()
        other.format()
        quotient.numerator = self.numerator * other.denominator
        quotient.denominator = self.denominator * other.numerator
        quotient.simplify()
        return quotient

    def __str__(self):
        return "Number({0} + {1}/{2})".format(self.whole, self.numerator, self.denominator)


num1 = Number(1, 2, 3) 
num2 = Number(3, 1, 2)

print(num1 + num2) # Number(5 + 1/6)
print(num1 - num2) # Number(-2 + 1/6)
print(num1 * num2) # Number(5 + 5/6)
print(num1 / num2) # Number(0 + 10/21)
