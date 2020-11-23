//// String.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
////
//#include<iostream>
//using namespace std;
//
//class String {
//	char str[127];
//public :
//	String(char* ss) { strcpy_s(str, ss); }
//	String(){ strcpy_s(str, "NULL"); }
//	char* operator=(String);
//	char* operator+=(String);
//	char* operator==(String);
//	char* operator<(String);
//	char* operator>(String);
//	char* operator!=(String);
//	char* operator>=(String);
//	char* operator<=(String);
//};
//
//
//char* String::operator=(String a)
//{
//
//}
//
//class Set { // класс «множество»
//	char str[80]; // строка
//public:
//	Set(char* ss) { strcpy_s(str, ss); }
//	char* operator&(Set); // объявление функции operator
//	char* operator|(Set);
//};
//char* Set::operator&(Set S) { // описание функции operator
//	int t = 0, l = 0;
//	while (str[t++] != '\0'); // вычисление длины строки
//	char* s1 = new char[t]; // выделение памяти под строку
//	for (int j = 0; str[j] != '\0'; j++)
//		for (int k = 0; S.str[k] != '\0'; k++)
//			if (str[j] == S.str[k]) {
//				s1[l] = str[j];
//				l++;
//				break;
//			}
//	s1[l] = '\0';
//	return s1;
//}
//char* Set::operator|(Set S) {
//	int t = 0, l = 0,j=0;
//	while (str[t++] != '\0'); // вычисление длины строки
//	while (S.str[t++] != '\0');
//	char* s1 = new char[t]; // выделение памяти под строку
//	for (; str[l] != '\0'; j++,l++)
//		s1[l] = str[l];
//	for (int k=0; S.str[k] != '\0';k++)
//	{
//		
//				s1[l] = S.str[k];
//		
//		l++;
//		
//	}
//	for (int i = 0; i < l; i++)
//	{
//		for(int q=0;q<i;q++)
//			if (s1[i] == s1[q])
//			{
//				s1[i] = s1[i + 1];
//				s1[l] = s1[q];
//				l--;
//			}
//	}
//	
//	s1[l] = '\0';
//	return s1;
//}
//int main() {
//	Set S1((char*)"1f2bg5e6");
//	Set S2((char*)"abcdef"); // задаются два множества
//	cout << (S1 & S2) << endl; // результат «fbe»
//	cout << (Set((char*)"123") & Set((char*)"426")) << endl; // результат«2»
//	cout<<(S1|S2);
//}
//
//// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
//// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"
//
//// Советы по началу работы
////   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
////   2. В окне Team Explorer можно подключиться к системе управления версиями.
////   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
////   4. В окне "Список ошибок" можно просматривать ошибки.
////   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
////   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.

#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>
#include <cstdlib>
#include <fstream>
using namespace std;

class String
{
    int size = 10;
public:
    char* str;
    String();
    String(char* src);
    int getSize() { return size; }
    void setSize(int size1){}

    String& operator=(const String& right)
    {
        strcpy_s(str,sizeof(right.str), right.str);
        return *this;
    }
    
    friend const String operator+( String& left,  String& right);
    void operator<= (String& obj2);
    void operator>= (String& obj2);
    void operator== (String& obj2);
    void operator!= (String& obj2);

    //Консольный Ввод и Вывод
    friend ostream& operator<<(ostream& stream, String &obj);
    friend istream& operator>>(istream& stream, String &obj);

};
//Конструктор
String::String()
{
    str = new char[255];
}
String::String(char* src)
{
   str = src;
}




const String operator+(String& left, String& right) {

    strcat_s(left.str,sizeof(right.str)+sizeof(left.str), right.str);

    return String(left.str);
}

void String::operator<=(String& obj2) {
    int t = atoi(str);
    int k = atoi(obj2.str);
    if (t <= k) {
        cout << "Да 1 <= 2" << endl;
    }
    else
        cout << "Лож" << endl;
}

void String::operator>=(String& obj2) {
    int t = atoi(str);
    int k = atoi(obj2.str);
    if (t >= k) {
        cout << "Да 1 >= 2" << endl;
    }
    else
        cout << "Лож" << endl;
}

void String::operator==(String& obj2) {
    if (strcmp(str, obj2.str)) {
        cout << "Не равны!" << endl;
        cout << str;
        cout << obj2.str;
    }
    else
        cout << "Равны!" << endl;
}

void String::operator!=(String& obj2) {
    strcmp(str, obj2.str);
    if (!strcmp(str, obj2.str)) {
        cout << "Равны!" << endl;
    }
    else
        cout << "Не равны!" << endl;
}

//Описание консольного вывода
ostream& operator<<(ostream& stream, String &obj)
{
    stream << obj.str;
    return stream;
}

//Описание консольного ввода
istream& operator>>(istream& stream, String &obj)
{
    stream >> obj.str;
    return stream;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    String obj1, obj2;
    int deistv;
    cout << "Введите строку" << "\n" << "-> ";
    cin >> obj1;
    cout << "\nВаша строка" << "\n->";
    cout << obj1;
    cout << "Введите вторую строку" << "\n" << "-> ";
    cin >> obj2;
    cout << "\nВаша строка" << "\n->";
    cout << obj2;
    
    while (1) {
        cout << "\n" << "Выберите действие (перегрузку):\n";
        cout << "1. Демонстрация присвоения" << endl;
        cout << "2. Сложить (+)" << endl;
        cout << "3. Сравнить (==)" << endl;
        cout << "4. Сравнить (!=)" << endl;
        cout << "5. <=" << endl;
        cout << "6. >=" << endl;
        cout << "7. Выход из программы" << endl;
      
        cout << "->";
        cin >> deistv;
        if (deistv == 1) {
            obj2 = obj1;
            cout << "Второй объект содержит строку: ";
            cout << obj2;
        }

        if (deistv == 2) {
           obj2 + obj1;
            cout << "Второй объект содержит строку: ";
            cout << obj2;
        }

        if (deistv == 3) {
            obj2 == obj1;
        }

        if (deistv == 4) {
            obj2 != obj1;

        }

        if (deistv == 5) {
            obj1 <= obj2;

        }

        if (deistv == 6) {
            obj1 >= obj2;

        }

        if (deistv == 7) {
            system("PAUSE");
            return 0;
        }
    }
}