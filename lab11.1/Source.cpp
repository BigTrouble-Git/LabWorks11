#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <math.h>
using namespace std;
void CreateBIN(char* fname) // ��������� ����� ������� � �������� �����
{
    ofstream fout(fname, ios::binary); // ������� ���� ��� ������
    char ch; // ������� ����������� � �� ������������ ��������
    int n;
    cout << "Enter number of elements: "; cin >> n;
    double* s = new double[n]; // �������� ������������ �����
    do
    {
        cin.get(); // ������� ����� ��������� � ��� �� ���� �������
        cin.sync(); // "����� �����", ���� ��������� ���� ����� �����
        cout << "enter line: ";
        for (unsigned i = 0; i < n; i++) {
            cin >> s[i];// ����� �����
            fout.write((char*)&s[i], sizeof(s[i]));
        }// �������� ������ � ����
        cout << "continue? (y/n): "; cin >> ch;
    } while (ch == 'y' || ch == 'Y');
    cout << endl;
}
void PrintBIN(char* fname) // ��������� ����� �� �����
{
    ifstream fin(fname, ios::binary); // ������� ���� ��� ����������
    double c; // ���������� ������
    while (fin.read((char*)&c, sizeof(c))) // ���� ����� ��������� ������
    {
        cout << c << endl; // �������� ���� �� �����
    }
    cout << endl;
}
double ProcessBIN(char* fname, char* gname) // ���������� �� ����� f
{ // � ���� g �������-�����
    ifstream f(fname, ios::binary); // ������� ���� ��� ����������
    ofstream g(gname, ios::binary); // ������� ���� ��� ������
    double c; // ���������� ������
    double s = 0; // ���� ��������
    double sk = 0; // ������� �������� 
    double p = 0; // ���� ��'�����
    double pk = 0;// ������� ��'����� 

    while (f.read((char*)&c, sizeof(c))) // ���� ����� ��������� ������
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
    double avgs = s / sk; // ������ �������� ��������
    double avgp = p / pk;// ������ �������� ��'�����
    g.write((char*)&avgs, sizeof(avgs));
    g.write((char*)&avgp, sizeof(avgp));

    return 0;

}

int main()
{
    // binary files
    char fname[100]; // ��'� ������� �����
    cout << "enter file name 1: "; cin >> fname;
    CreateBIN(fname); // ����� ����� ����� � ���������
    PrintBIN(fname); // ������ ���� ������� ����� �� �����
    char gname[100]; // ��'� ������� �����
    cout << "enter file name 2: "; cin >> gname;
    ProcessBIN(fname, gname);
    PrintBIN(gname); // ������ ���� ������� ����� �� �����

    return 0;
}