using laba3_func;

namespace laba3
{
    class Program
    {
        static void Main(string[] args)
        {
            func f = new func(); //створимо об'єкт класу func для виклику методів
            Train[] trains = f.CreateArr(); //створимо масив об'єктів класу Train
            f.OutputTrains(trains); //метод виводу потягів
            f.FindTrains(trains); //метод визначення потягів, які відправляються у заданий період часу
        }
    }
}