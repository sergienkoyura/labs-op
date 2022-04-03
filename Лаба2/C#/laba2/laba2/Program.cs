using laba2_func;   

namespace laba2_main
{
    class Program
    {
        static void Main(string[] args)
        {
            string path = "Phonebook.dat"; 
            func f = new func(); //створюємо об'єкт класа функцій для виклику методів
            
            f.outputFile(path); //виведення вмісту файлу
            f.countSum(path); //обрахування тарифу
            f.outputFile(path);
        }
    }
}