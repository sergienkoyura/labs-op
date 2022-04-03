using System;
using static System.Console;

namespace laba3_func
{
    public class func
    {
        public Train[] CreateArr() //створення масиву об'єктів класу Train
        {
            Write("Input the number of trains: ");
            Train[] arr = new Train[Convert.ToInt32(ReadLine())]; //створення масиву розміром, введеного користувачем
            for (int i = 0; i < arr.Length-1; i++)
            {
                arr[i] = new Train(); //виклик конструктора за замовчуванням
            }
            arr[arr.Length - 1] = new Train(420, "Lviv", "16-30");
            return arr;
        }

        public void FindTrains(Train[] arr) //знаходження потягів, які відправляються в певний період часу
        {
            Write("\nInput the start time of the range: ");
            int startTime = Convert.ToInt32(ReadLine());
            Write("Input the end time: ");
            int endTime = Convert.ToInt32(ReadLine());
            WriteLine();
            foreach (Train t in arr)
            {
                string[] temp = t.DepartureTime.Split("-");
                int h = Convert.ToInt32(temp[0]); //виділяємо із рядка години
                if (startTime > endTime) //якщо період часу вказаний з поточного дня на наступний (наприклад 23 - 8)
                {
                    if ((h >= startTime && h < 24) || (h >= 0 && h < endTime))
                        WriteLine($"The train №{t.NumOfTrain} departs in this time range");

                }
                else if (endTime > startTime)
                {
                    if (h >= startTime && h < endTime)
                        WriteLine($"The train №{t.NumOfTrain} departs in this time range");
                }
                else if(h==startTime)
                    WriteLine($"The train №{t.NumOfTrain} departs in this time range");
            }
        }

        public void OutputTrains(Train[] arr)
        {
            Write("--------------------------");
            foreach (Train t in arr) //виведення масиву об'єктів
            {
                WriteLine(t.ToString());
            }
            Write("--------------------------");
        }
    }
}