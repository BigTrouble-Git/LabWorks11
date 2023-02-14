#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <math.h>
using namespace std;
void CreateBIN(char* fname) // створення файлу символів з введених рядків
{
    ofstream fout(fname, ios::binary); // відкрили файл для запису
    char ch; // відповідь користувача – чи продовжувати введення
    int n;
    cout << "Enter number of elements: "; cin >> n;
    double* s = new double[n]; // введений користувачем рядок
    do
    {
        cin.get(); // очищуємо буфер клавіатури – щоб не було символу
        cin.sync(); // "кінець рядка", який залишився після вводу числа
        cout << "enter line: ";
        for (unsigned i = 0; i < n; i++) {
            cin >> s[i];// ввели рядок
            fout.write((char*)&s[i], sizeof(s[i]));
        }// записали символ у файл
        cout << "continue? (y/n): "; cin >> ch;
    } while (ch == 'y' || ch == 'Y');
    cout << endl;
}
void PrintBIN(char* fname) // виведення файлу на екран
{
    ifstream fin(fname, ios::binary); // відкрили файл для зчитування
    double c; // прочитаний символ
    while (fin.read((char*)&c, sizeof(c))) // поки можна прочитати символ
    {
        cout << c << endl; // виводимо його на екран
    }
    cout << endl;
}
double ProcessBIN(char* fname, char* gname) // переписати із файлу f
{ // у файл g символи-цифри
    ifstream f(fname, ios::binary); // відкрили файл для зчитування
    ofstream g(gname, ios::binary); // відкрили файл для запису
    double c; // прочитаний символ
    double s = 0; // сума додатних
    double sk = 0; // кількість додатних 
    double p = 0; // сума від'ємних
    double pk = 0;// кількість від'ємних 

    while (f.read((char*)&c, sizeof(c))) // поки можна прочитати символ
    {
        if (c > 0) {
            s += c;
            sk++;
        }
        if (c < 0) {
            p = p + c;
            pk++;
        }
    }
    double avgs = s / sk; // середнє значення додатних
    double avgp = p / pk;// середнє значення від'ємних
    g.write((char*)&avgs, sizeof(avgs));
    g.write((char*)&avgp, sizeof(avgp));

    return 0;

}

int main()
{
    // binary files
    char fname[100]; // ім'я першого файлу
    cout << "enter file name 1: "; cin >> fname;
    CreateBIN(fname); // ввели рядки файлу з клавіатури
    PrintBIN(fname); // вивели вміст першого файлу на екран
    char gname[100]; // ім'я другого файлу
    cout << "enter file name 2: "; cin >> gname;
    ProcessBIN(fname, gname);
    PrintBIN(gname); // вивели вміст другого файлу на екран

    return 0;
}