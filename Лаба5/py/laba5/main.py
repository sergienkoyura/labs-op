import math
import random

import func

if __name__ == '__main__':
    n = int(input("How many triangles you want to create?\n"))
    pArr = [] # список об'єктів класу PTriangle
    rsArr = [] # ...RSTriangle
    rbArr = [] # ...RBTriangle
    sumP = 0 # сума площ прямокутних трикутників
    sumRS = 0 # сума площ рівносторонніх трикутників
    sumRB = 0 # сума площ рівнобедренних трикутників
    for i in range(0, n):
        # генеруємо вершини прямокутного трикутника
        p1 = func.Point(round(random.uniform(-10, 10), 1), round(random.uniform(-10, 10), 1))
        p2 = func.Point(round(random.uniform(-10, 10), 1), round(random.uniform(-10, 10), 1))
        p3 = func.Point(p1.getX(), p2.getY())
        temp = func.PTriangle(p1, p2, p3)
        pArr.append(temp)

        #генеруємо вершини рівнобедренного трикутника
        p1 = func.Point(round(random.uniform(-10, 10), 1), round(random.uniform(-10, 10), 1))
        p2 = func.Point(round(random.uniform(-10, 10), 1), round(random.uniform(-10, 10), 1))
        p3 = func.Point(0, 0)
        if p1.getX() > p2.getX():
            p3.setX(round(p2.getX() - abs(p1.getX() - p2.getX()), 1))
        else:
            p3.setX(round(abs(p1.getX() - p2.getX()) + p2.getX(), 1))
        p3.setY(p1.getY())
        temp = func.RBTriangle(p1, p2, p3)
        rbArr.append(temp)

        # генеруємо вершини рівностороннього трикутника
        p1 = func.Point(round(random.uniform(-10, 10), 1), round(random.uniform(-10, 10), 1))
        p2 = func.Point(round(random.uniform(-10, 10), 1), round(random.uniform(-10, 10), 1))
        p3 = func.Point(0, 0)
        p3.setX(round((p2.getX() - p1.getX()) * 0.5 - (p2.getY() - p1.getY()) * math.sqrt(3) / 2 + p1.getX(), 1))
        p3.setY(round((p2.getX() - p1.getX()) * math.sqrt(3) / 2 + (p2.getY() - p1.getY()) * 0.5 + p1.getY(), 1))
        temp = func.RSTriangle(p1, p2, p3)
        rsArr.append(temp)

    for i in range(0, n):
        pArr[i].print()
    print("-------------------")
    for i in range(0, n):
        rsArr[i].print()
    print("-------------------")
    for i in range(0, n):
        rbArr[i].print()
        sumP = sumP + pArr[i].getSquare()
        sumRS = sumRS + rsArr[i].getSquare()
        sumRB = sumRB + rbArr[i].getPerimeter()
    print("-------------------")

    print("Sum of squares of right triangles: " + str(round(sumP, 2)) + ";\nSum of squares of equilateral triangles: " + str(round(sumRS, 2)) + ";\nSum of perimeters of isosceles triangles: " + str(round(sumRB, 2)) + ".")