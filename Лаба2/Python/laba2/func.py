import os
def WorkWithFile(path, call): # функція для запису даних у файл
    if os.path.exists(path): # перевірка існування файлу
        temp = int(input("\nIf you want to add this call to the Phonecall book, input 1\nif you want to create new Phonecall book, input 2\nYour answer: "))
        # вибір користувача
        if temp == 1: # відкривається файл для дозапису
            f = open(path, 'ab')
            for i in call:
                bt = (i + '\n').encode() # перетворення рядка на байти
                f.write(bt) # запис байтів у файл
            f.close()
        else: # створюється новий файл
            f = open(path, 'wb')
            for i in call:
                bt = (i + '\n').encode()
                f.write(bt)
            f.close()
    else: # якщо файлу не існує - він створюється
        f = open(path, 'wb')
        for i in call:
            bt = (i + '\n').encode()
            f.write(bt)
        f.close()

def outputFile(path):
    call = ["","","",""]
    print("----------------------\nCurrent Phonecall book:\n")
    if os.path.exists(path): # перевірка існування файлу
        i = 1
        f = open(path, 'rb') # відриття файлу для читання
        count = 0
        for line in f:
            s = line.decode() # перекодування рядку байтів в звичайний рядок
            s = s[:-1] # видаляємо символ \n
            call[count]= s
            count+=1
            if count == 4:
                print("Call №"+str(i)+"\nDate of the call: "+call[0]+"\nstartTime of the call: "+call[1]+"\nendTime of the call: "+call[2]+"\nSum to pay for the call: "+call[3]+"\n\n")
                i+=1
                count = 0
        f.close()
    else:
        print("PhoneBook is empty!\n")
    print("----------------------\n")


def countSum(path):
    call = ["", "", "", ""]
    call[0] = input("Input the date of the call:\n")
    call[1] = input("Input startTime of the call:\n")
    call[2] = input("Input endTime of the call:\n")
    tsH, tsM = call[1].split(':') # розділимо рядки з часом за двокрапкою
    teH, teM = call[2].split(':')

    stH = int(tsH) # запишемо час з рядків в числа
    stM = int(tsM)
    endH = int(teH)
    endM = int(teM)

    sumM = 0
    ind1 = 0
    ind2 = 0

    # введення індексів для розділення часу на сектори:
    #         1 - від 00:00 до 06:59
    #         2 - від 07:00 до 08:59
    #         3 - від 09:00 до 17:59
    #         4 - від 18:00 до 21:69
    #         5 - від 22:00 до 23:59
    #         ind1 - початковий час, ind2 - кінцевий час

    if 0 <= stH <= 6: ind1 = 1
    elif 7 <= stH <= 8: ind1 = 2
    elif 9 <= stH <= 17: ind1 = 3
    elif 18 <= stH <= 21: ind1 = 4
    elif 22 <= stH <= 23: ind1 = 5

    if 0 <= endH <= 6: ind2 = 1
    elif 7 <= endH <= 8: ind2 = 2
    elif 9 <= endH <= 17: ind2 = 3
    elif 18 <= endH <= 21: ind2 = 4
    elif 22 <= endH <= 23: ind2 = 5

    if ind1 < ind2: # умова, за якої початковий час менший за кінцевий
        sumM += ForMethod(ind1, ind2)
        sumM += SwitchInd1(ind1, stH, stM)
        sumM += SwitchInd2(ind2, endH, endM)

    elif ind1 > ind2: # умова, за якої кінцевий час більший за початковий (перехід в наступний день)
        if ind1 == 5:
            ind1 = 1
            sumM += ForMethod(ind1, ind2)
            sumM += SwitchInd2(ind2, endH, endM)

        else:
            sumM += ForMethod(ind1, 5)
            sumM += SwitchInd1(ind1, stH, stM)
            sumM += ForMethod(1, ind2)
            sumM += SwitchInd2(ind2, endH, endM)

    else: # умова, за якої години рівні
        if(stH * 60 + stM) < (endH * 60 + endM):
            if ind1 == 2:
                sumM = 1.2 * ((endH * 60 + endM) - (stH * 60 + stM))
            elif ind1 == 3:
                sumM += 1.7 * ((endH * 60 + endM) - (stH * 60 + stM))
            elif ind1 == 4:
                sumM += 1.2 * ((endH * 60 + endM) - (stH * 60 + stM))
        else:
            if ind1 == 5:
                ind1 = 1
                sumM += ForMethod(ind1, ind2)
                sumM += SwitchInd2(ind2, endH, endM)
            else:
                sumM += ForMethod(ind1, 5)
                sumM += SwitchInd1(ind1, stH, stM)
                sumM += ForMethod(1, ind2)
                sumM += SwitchInd2(ind2, endH, endM)
    call[3] = str(sumM)
    WorkWithFile(path, call) # запис структури в файл

def ForMethod (a, b): # викликається за умови повної години (15:30 - 17:30, повна година - 16)
    sumM = 0
    for i in range(a+1, b):
        if i == 2:
            sumM += 1.2 * 120
        elif i == 3:
            sumM += 1.7 * 9 * 60
        elif i == 4:
            sumM += 1.2 * 4 * 60
    return sumM

def SwitchInd1(ind, H, M): # добір тарифу справа (15:30 - 17:30, добір: 17:00 - 17:30)
    sumM = 0
    if ind == 2:
        sumM += 1.2 * (9 * 60 - H * 60 - M)
    elif ind == 3:
        sumM += 1.7 * (18 * 60 - H * 60 - M)
    elif ind == 4:
        sumM += 1.2 * (22 * 60 - H * 60 - M)
    return sumM

def SwitchInd2(ind, H, M): # добір тарифу зліва (15:30 - 17:30, добір: 15:30 - 16:00)
    sumM = 0
    if ind == 2:
        sumM += 1.2 * ((H * 60 + M) - 7 * 60)
    elif ind == 3:
        sumM += 1.7 * ((H * 60 + M) - 9 * 60)
    elif ind == 4:
        sumM += 1.2 * ((H * 60 + M) - 18 * 60)
    return sumM
