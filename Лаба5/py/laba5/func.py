import math


class Point:
    def __init__(self, x, y):
        self.x = x
        self.y = y

    def getX(self):
        return self.x

    def getY(self):
        return self.y

    def setX(self, x):
        self.x = x

    def setY(self, y):
        self.y = y

    def toStr(self): # перетворюємо інформацію про точку в рядок
        return "X: " + str(self.x) + "; Y: " + str(self.y) + ";\n"


class TTriangle:
    def __init__(self, P1, P2, P3): # використовуємо об'єкти класу точки як атрибути класу трикутника (вершини)
        self.P1 = P1
        self.P2 = P2
        self.P3 = P3

    def getA(self): # знаходимо сторони трикутника
        return math.sqrt(pow(self.P2.getX() - self.P1.getX(), 2) + pow(self.P2.getY() - self.P1.getY(), 2))

    def getB(self):
        return math.sqrt(pow(self.P3.getX() - self.P1.getX(), 2) + pow(self.P3.getY() - self.P1.getY(), 2))

    def getC(self):
        return math.sqrt(pow(self.P3.getX() - self.P2.getX(), 2) + pow(self.P3.getY() - self.P2.getY(), 2))


class PTriangle(TTriangle): # прямокутний трикутник
    def __init__(self, P1, P2, P3): # наслідуємо від класу TTriangle атрибути (об'єкти класу точки)
        super().__init__(P1, P2, P3)

    def print(self):
        print("PTriangle:\n" + self.P1.toStr() + self.P2.toStr() + self.P3.toStr())

    def getSquare(self): # знаходимо площу трикутника
        if self.getA() > self.getB():
            if self.getA() > self.getC():
                return 0.5 * self.getB() * self.getC()
            elif self.getB() > self.getC():
                return 0.5 * self.getC() * self.getA()
            else:
                return 0.5 * self.getA() * self.getB()


class RSTriangle(TTriangle): # рівносторонній трикутник
    def __init__(self, P1, P2, P3): # наслідуємо від класу TTriangle атрибути (об'єкти класу точки)
        super().__init__(P1, P2, P3)

    def print(self):
        print("RSTriangle:\n" + self.P1.toStr() + self.P2.toStr() + self.P3.toStr())

    def getSquare(self): # знаходимо площу трикутника
        return self.getA()*self.getA()*math.sqrt(3)/4


class RBTriangle(TTriangle): # рівнобедренний трикутник
    def __init__(self, P1, P2, P3): # наслідуємо від класу TTriangle атрибути (об'єкти класу точки)
        super().__init__(P1, P2, P3)

    def print(self):
        print("RBTriangle:\n" + self.P1.toStr() + self.P2.toStr() + self.P3.toStr())

    def getPerimeter(self): # знаходимо периметр трикутника
        return self.getA()+self.getB()+self.getC()
