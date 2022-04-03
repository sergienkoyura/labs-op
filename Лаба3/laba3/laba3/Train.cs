using System;
using static System.Console;

namespace laba3_func
{
    public class Train
    {
        private int numOfTrain; 
        private string destination;
        private string departureTime;

        public Train() //конструктор за замовчуванням
        {
            Write("\nInput the number of the train: ");
            NumOfTrain = Convert.ToInt32(ReadLine());
            Write("Input the destination: ");
            Destination = ReadLine();
            while (true) //перевірка вводу часу в форматі ГГ-ХХ
            {
                Write("Input the departure time: ");
                DepartureTime = ReadLine();
                if (DepartureTime.IndexOf('-') == -1)
                    Write("Wrong input!");
                else
                {
                    string[] nums = DepartureTime.Split("-");
                    int h = Convert.ToInt32(nums[0]);
                    int m = Convert.ToInt32(nums[1]);
                    if(h<0 || h>24 || m < 0 || m >= 60)
                        Write("Wrong input!");
                    else break;
                }
            }

            
        }

        public Train(int numOfTrain, string destination, string departureTime)
        //конструктор з параметрами
        {
            NumOfTrain = numOfTrain;
            Destination = destination;
            DepartureTime = departureTime;
        }

        public int NumOfTrain
        {
            get => numOfTrain;
            set => numOfTrain = value;
        }

        public string Destination
        {
            get => destination;
            set => destination = value;
        }

        public string DepartureTime
        {
            get => departureTime;
            set => departureTime = value;
        }

        public override string ToString() //перевантаження методу для виведення даних
        {
            return $"\nTrain number: {NumOfTrain}\nThe destination: {Destination}\nDeparture time: {DepartureTime}";
        }
    }
}