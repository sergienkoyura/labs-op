using System;
using System.IO;
using System.Text;
using static System.Console;

namespace laba2_func
{
    public class func
    {
        public struct PhoneCall //структура даних про дзвінок
        {
            public string date,
                startCall,
                endCall,
                sum;
        };

        public void WorkWithFile(string fileName, PhoneCall call) //функція для запису даних у файл
        {
            Write("\nIf you want to add this call to the Phonecall book, input 1\nif you want to create new Phonecall book, input 2\nYour answer: ");
            int c = Convert.ToInt32(ReadLine()); //вибір користувача

            using (FileStream fs = new FileStream(fileName, (c == 1) ? FileMode.Append : FileMode.Create, FileAccess.Write, FileShare.None)) 
                /* створюємо об'єкт класу FileStream для запису, використаємо тернарний оператор для визначення режиму відкриття файлу
                 (для дозапису в існуючий файл чи його створення) */
            {
                string text = "\nDate of the call: " + call.date + "\nstartTime of the call: " + call.startCall +
                              "\nendTime of the call: " + call.endCall + "\nSum to pay for the call: " + call.sum +
                              "\n";
                byte[] wb = Encoding.Default.GetBytes(text); // перетворимо рядок тексту на масив байтів
                fs.Write(wb, 0, wb.Length); //запис масиву байтів в файл
            }
        }

        public void outputFile(string fileName) //виведення вмісту файлу
        {
            WriteLine("------------------------\nCurrent Phonebook:");
            using (FileStream fs = new FileStream(fileName, FileMode.OpenOrCreate, FileAccess.Read, FileShare.None))
                // створюємо об'єкт класу FileStream для читання, застосовуючи режим відкриття чи створення файлу, якщо його не існує
            {
                if (fs.Length == 0) //якщо файл пустий
                {
                    WriteLine("Phonebook is empty!");
                }
                else
                {
                    byte[] rb = new byte[fs.Length]; //створюємо масив байтів розміром файлу
                    fs.Read(rb, 0, rb.Length); //зчитаємо вміст файлу
                    WriteLine(Encoding.Default.GetString(rb)); //виведемо перекодований вміст файлу
                }
            }
            WriteLine("------------------------");
        }

        public void countSum(string fileName) //обрахування тарифу
        {
            PhoneCall call = new PhoneCall(); //створення об'єкту структури
            WriteLine("Input the date of the call:");
            call.date = ReadLine();
            WriteLine("Input startTime of the call:");
            call.startCall = ReadLine();
            WriteLine("Input endTime of the call:");
            call.endCall = ReadLine();
            string[] st = call.startCall.Split(':'); //розділимо рядки з часом за двокрапкою
            string[] end = call.endCall.Split(':');
            int stH = Convert.ToInt32(st[0]); //запишемо час з рядків в числа
            int stM = Convert.ToInt32(st[1]);
            int endH = Convert.ToInt32(end[0]);
            int endM = Convert.ToInt32(end[1]);
            double sumM = 0;
            int ind1 = 0, ind2 = 0; 
            /*введення індексів для розділення часу на сектори:
             1 - від 00:00 до 06:59
             2 - від 07:00 до 08:59
             3 - від 09:00 до 17:59
             4 - від 18:00 до 21:69
             5 - від 22:00 до 23:59
             ind1 - початковий час, ind2 - кінцевий час
             */
            if (stH >= 0 && stH <= 6) ind1 = 1;
            else if (stH >= 7 && stH <= 8) ind1 = 2;
            else if (stH >= 9 && stH <= 17) ind1 = 3;
            else if (stH >= 18 && stH <= 21) ind1 = 4;
            else if (stH >= 22 && stH <= 23) ind1 = 5;

            if (endH >= 0 && endH <= 6) ind2 = 1;
            else if (endH >= 7 && endH <= 8) ind2 = 2;
            else if (endH >= 9 && endH <= 17) ind2 = 3;
            else if (endH >= 18 && endH <= 21) ind2 = 4;
            else if (endH >= 22 && endH <= 23) ind2 = 5;
            if (ind1 < ind2) //умова, за якої початковий час менший за кінцевий
            {
                sumM += ForMethod(ind1, ind2);
                sumM += SwitchInd1(ind1, stH, stM);
                sumM += SwitchInd2(ind2, endH, endM);
            }
            else if (ind2 < ind1) //умова, за якої кінцевий час більший за початковий (перехід в наступний день)
            {
                if (ind1 == 5)
                {
                    ind1 = 1;
                    sumM += ForMethod(ind1, ind2);
                    sumM += SwitchInd2(ind2, endH, endM);
                }
                else
                {
                    sumM += ForMethod(ind1, 5);
                    sumM += SwitchInd1(ind1, stH, stM);
                    sumM += ForMethod(1, ind2);
                    sumM += SwitchInd2(ind2, endH, endM);
                }
            }
            else //умова, за якої години рівні
            {
                if ((stH * 60 + stM) < (endH * 60 + endM))
                    switch (ind1)
                    {
                        case 2: sumM = 1.2 * ((endH * 60 + endM) - (stH * 60 + stM)); break;
                        case 3: sumM += 1.7 * ((endH * 60 + endM) - (stH * 60 + stM)); break;
                        case 4: sumM += 1.2 * ((endH * 60 + endM) - (stH * 60 + stM)); break;
                    }
                else
                {
                    if (ind1 == 5)
                    {
                        ind1 = 1;
                        sumM += ForMethod(ind1, ind2);
                        sumM += SwitchInd2(ind2, endH, endM);
                    }
                    else
                    {
                        sumM += ForMethod(ind1, 5);
                        sumM += SwitchInd1(ind1, stH, stM);
                        sumM += ForMethod(1, ind2);
                        sumM += SwitchInd2(ind2, endH, endM);
                    }
                }
            }
            call.sum = Convert.ToString(sumM);
            WorkWithFile(fileName, call); //запис структури в файл
        }
        public double ForMethod(int a, int b) //викликається за умови повної години (15:30 - 17:30, повна година - 16)
        {
            double sum = 0;
            for (int i = a + 1; i < b; i++)
            {
                switch (i)
                {
                    case 2: sum+= 1.2 * 120; break;
                    case 3: sum+= 1.7 * 9 * 60; break;
                    case 4: sum+= 1.2 * 4 * 60; break;
                }
            }
            return sum;
        }

        public double SwitchInd2(int ind, int H, int M) //добір тарифу справа (15:30 - 17:30, добір: 17:00 - 17:30)
        {
            double sum = 0;
            switch (ind)
            {
                case 2: sum += 1.2 * ((H * 60 + M) - 7 * 60); break;
                case 3: sum += 1.7 * ((H * 60 + M) - 9 * 60); break;
                case 4: sum += 1.2 * ((H * 60 + M) - 18 * 60); break;
            }
            return sum;
        }

        public double SwitchInd1(int ind, int H, int M) //добір тарифу зліва (15:30 - 17:30, добір: 15:30 - 16:00)
        {
            double sum = 0;
            switch (ind)
            {
                case 2: sum += 1.2 * (9 * 60 - H * 60 - M); break;
                case 3: sum += 1.7 * (18 * 60 - H * 60 - M); break;
                case 4: sum += 1.2 * (22 * 60 - H * 60 - M); break;
            }
            return sum;
        }
    }
}