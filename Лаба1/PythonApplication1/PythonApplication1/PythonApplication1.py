import os

def inputText(): #заповнення стартового файлу
    print("Input your text:")
    a = 'text.txt'
    f = open(a, 'w'); #відкриття файлу для запису
    text = " " #temp
    c = 0
    while(text): #isEmpty
        text=input()
        if c == 0: f.write(text) 
        else: f.write('\n'+text)
        c+=1
    f.close()
    return a

def changeFiles(a,b,c): #перепис рядків по файлах
    f1 = open(a, 'r') #стартовий файл, для зчитування
    f2 = open(b, 'w') #для парних
    f3 = open(c, 'w') #для непарних
    c = 1
    text = " "
    while(text):
        text = f1.readline() #зчитуємо порядково
        if text:
            if(c%2==0):f2.write(text)
            else: f3.write(text)
            c+=1
    f1.close()
    f2.close()
    f3.close()

def addText(): #дозаповнення файлу
    print("Input your text:")
    a = 'text.txt'
    f = open(a, 'a'); #відкриваємо файл для дозапису
    text = " "
    c = 0
    while(text):
        text=input()
        if c == 0: f.write(text) 
        else: f.write("\n"+text)
        c+=1
    f.close()

def outputFile(a): #виведення вмісту файлів
    f = open(a, 'r')
    text = f.read()
    print(text)
    f.close()

def changeWords(a): #сортування за алфавітом
    f = open(a, 'r') 
    text = f.read() #записуємо текст файлу 
    arr = text.split('\n') #розділяємо текст по рядках в список
    arr.pop(len(arr)-1) #видалення зайвого рядка (пустого)
    f.close()
    n = 0
    for i in arr:
        tArr = i.split(' ') #розділяємо рядок на слова
        for j in range(0, len(tArr)-1): #сортування
            for j1 in range(0, len(tArr)-1):
                if len(tArr[j1])>len(tArr[j1+1]): 
                    for k in range(0, len(tArr[j1+1])):
                        if tArr[j1][k] > tArr[j1+1][k]:
                            t = tArr[j1+1]
                            tArr[j1+1] = tArr[j1]
                            tArr[j1] = t
                            break
                        elif tArr[j1][k] < tArr[j1+1][k]:
                            break
                else:
                    for k in range(0, len(tArr[j1])):
                        if tArr[j1][k] > tArr[j1+1][k]:
                            t = tArr[j1+1]
                            tArr[j1+1] = tArr[j1]
                            tArr[j1] = t
                            break
                        elif tArr[j1][k] > tArr[j1+1][k]:
                            break
        arr[n] = tArr
        n+=1
    f = open(a, 'w') #запис зміненого тексту в файл
    for i in arr:
        f.write(' '.join(i)+'\n') 
    f.close()

if __name__=="__main__":
    startFile = inputText() #стартовий файл, ф-ція повертає назву файлу
    os.system('cls||clear') #очищення консолі
    print("Current text:")
    outputFile(startFile)
    n = int(input("Do you want to add some text?\n1 - Yes\n2 - No\nType here: "))
    if n == 1:
        addText()
    os.system('cls||clear')
    print("Start file:")
    outputFile(startFile)
    f1 = 't1.txt' #перший файл (для парних)
    f2 = 't2.txt' #другий файл (для непарних)
    changeFiles(startFile, f1, f2)
    print("Text of the first file (even, unsorted):")
    outputFile(f1)
    changeWords(f1)
    print("Text of the first file (even, sorted):")
    outputFile(f1)
    print("Text of the second file (odd):")
    outputFile(f2)

#hello world
#hi hello 123 1a a23
#t fgh 5 dfh4e
#bbb aa ccc 22d

#qwerty qwetufgh qrwrey s q ry dg g 
#abc abg 1qwer 1qwen bbc bbs
#yfh jfjfhwe ew fsd ffq
#nnng nnnng ssss aaaa bbbb 11a
#fhfghj6rj gsfa fafag a fa
