#include <iostream>
#include <fstream>
#include <string>
using namespace std;
string input(); //заповнення стартового файлу
void addText(string); //дозаповнення файлу
void changeFiles(string, string, string); //перепис рядків по файлах
void outputFile(string); //виведення вмісту файлів
void changeWords(string); //сортування за алфавітом

int main() {
    string startFile = input(); //стартовий файл, ф-ція повертає назву файлу
    system("CLS"); //очищення консолі
    string f1 = "f1.txt"; //перший файл (для парних)
    string f2 = "f2.txt"; //другий файл (для непарних)
    cout << "Start file:\n";
    outputFile(startFile);
    cout << "Do you want to add some text?\n1 - Yes\n2 - No\nType here: ";
    int n;
    cin >> n;
    if (n == 1) addText(startFile);
    system("CLS");
    changeFiles(startFile, f1, f2);
    cout << "Start file:\n";
    outputFile(startFile);
    cout << "Text of the first file (even, unsorted):\n";
    outputFile(f1);
    changeWords(f1);
    cout << "Text of the first file (even, sorted):\n";
    outputFile(f1);
    cout << "Text of the second file (odd):\n";
    outputFile(f2);
    
}

string input() {
    string a = "text.txt";
    cout << "Input your text (press Ctrl + R to stop):\n";
    ofstream fout(a); //об'єкт класу для запису даних у файл
    string s; //temp
    int count = 0;
    while(s.find(18) == string::npos) { //перевірка на наявність комбінації в потоці (Ctrl+R)
        getline(cin, s);
        if (count == 0 && s.find(18) == string::npos)
            fout << s;
        else if (s.find(18) == string::npos)
            fout << endl << s;
        count++;
    }
    fout.close();
    return a;
}

void changeFiles(string a, string b, string c) {
    ifstream fin(a); //об'єкт класу для читання даних з файлу (зі стартового)
    ofstream fout1(b); //..для запису в перший файл (для парних)
    ofstream fout2(c); //..(для непарних)
    string s;
    int count = 1;
    while (!fin.eof()) { //перевірка на кінець файлу
        getline(fin, s);
        if (count % 2 == 0) {
            if(count == 2) fout1 << s;
            else fout1 << endl << s ;
        }
        else {
            if (count == 1) fout2 << s;
            else fout2 << endl << s;
        }
        count++;
    }
    fin.close();
    fout1.close();
    fout2.close();
}

void addText(string a) {
    ofstream fout(a, ios::app); //app (append) використовується для дозапису даних
    cout << "You can add some text:\n";
    string s;
    int count = 0;
    while (s.find(18) == string::npos) {
        getline(cin, s);
        if (count == 0 && s.find(18) == string::npos)
            fout << s;
        else if (s.find(18) == string::npos)
            fout << endl << s;
        count++;
    }
    fout.close();
}

void outputFile(string a) {
    ifstream fin(a);
    string s;
    while (!fin.eof()) {
        getline(fin, s);
        cout << s << endl;
    }
    cout << endl;
}

void changeWords(string a) {
    fstream fin(a); //об'єкт універсального класу (i/o)
    int count = 0;
    string s;
    while (!fin.eof()) { //для обрахування рядків
        getline(fin, s);
        count++;
    }
    fin.close();
    fin.open(a, ios::in); //відкриваємо файл для зчитування
    string* text = new string[count]; //масив рядків тексту
    for (int i = 0; i < count; i++) {
        getline(fin, text[i]);
    }
    fin.close();
    for (int i = 0; i < count; i++) {
        int cn = 0;
        string nStr = "", dStr;
        for (int j = 0; j < text[i].length(); j++) { //цикл для редагування пробілів
            if (text[i][j] == ' ') {
                cn++;
            }
            else {
                if (cn != 0) {
                    cn = 0;
                    nStr += ' ';
                }
                nStr += text[i][j];
            }
        }
        if (nStr[0] == ' ') nStr.erase(0, 1);
        if (nStr[nStr.length() - 1] != ' ') nStr.push_back(' ');
        int c = 0;
        text[i] = nStr;
        while (nStr.length() > 0) { //обрахування к-сті слів рядка
            c++;
            nStr.erase(0, nStr.find(' ') + 1);
        }
        string* temp = new string[c]; //перезапис рядка в масив слів
        nStr = text[i];
        for (int j = 0; j < c; j++) {
            temp[j] = nStr.substr(0, nStr.find(' '));
            nStr.erase(0, nStr.find(' ') + 1);
        }
        for (int j = 0; j < c - 1; j++) { //сортування слів за алфавітом
            for (int j1 = 1; j1 < c; j1++) {
                if (temp[j1 - 1].length() > temp[j1].length()) { 
                    for (int k = 0; k < temp[j1].length(); k++) {
                        if (temp[j1 - 1][k] > temp[j1][k]) { //перевірка букв сусідніх слів з однаковими індексами
                            string t = temp[j1];
                            temp[j1] = temp[j1 - 1];
                            temp[j1 - 1] = t;
                            break;
                        }
                        else if (temp[j1 - 1][k] < temp[j1][k]) break;
                    }
                }
                else {
                    for (int k = 0; k < temp[j1 - 1].length(); k++) {
                        if (temp[j1 - 1][k] > temp[j1][k]) {
                            string t = temp[j1];
                            temp[j1] = temp[j1 - 1];
                            temp[j1 - 1] = t;
                            break;
                        }
                        else if (temp[j1 - 1][k] < temp[j1][k]) break;
                    }
                }
            }
        }
        text[i] = "";
        for (int j = 0; j < c; j++) { //запис відсортованих рядків в масив
            text[i] += temp[j] + ' ';
        }
    }
    fin.open(a, fstream::in | fstream::out | fstream::trunc); //запис масиву в файл (trunc - для очистки файлу)
    for (int i = 0; i < count; i++) {
        fin << text[i] << endl;
    }
    fin.close();
}

//hello world
//hi hello 123 1a a23
//t fgh 5 dfh4e
//bbb aa ccc 22d
//
//qwerty qwetufgh qrwrey s q ry dg g
//abc abg 1qwer 1qwen bbc bbs
//yfh jfjfhwe ew fsd ffq
//nnng nnnng ssss aaaa bbbb 11a
//fhfghj6rj gsfa fafag a fa