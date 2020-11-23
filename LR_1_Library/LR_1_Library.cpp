// LR_1_Library.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <vector>
#include <conio.h>
#include <fstream>
using namespace std;


ofstream out;

//int get_Int()
//{
//    while (true) // цикл продолжается до тех пор, пока пользователь не введет корректное значение
//    {
//        cout << "Enter year of publishing: ";
//        int a, b;
//        cin >> a;
//
//        if (cin.fail()) // если предыдущее извлечение оказалось неудачным,
//        {
//            cin.clear(); // то возвращаем cin в 'обычный' режим работы
//            cin.ignore(32767, '\n'); // и удаляем значения предыдущего ввода из входного буфера
//
//
//        }
//        else // если всё хорошо, то возвращаем a
//            return a;
//    }
//}

int  check_number()
{
    char s;
    int j = 0, i = 0;
    cout << "Enter year of publishing";
    while ((s = _getch()) != '\r')
    {
        if (s == 8)
        {
            if (i)
            {
                i--;
                cout << (char)8 << " " << char(8);
                j /= 10;
            }
        }
        else if (i >= 4)
        {
            system("cls");
            cout << "Enter 4 digit\n" << endl;
            system("pause & cls");
            return -1;
        }
        else if (s >= '0' && s <= '9')
        {
            cout << s;
            j = j * 10 + (s - '0');
            i++;
        }
    }

    if (s == '\r' && i)
        return j;
    else
    {
        system("cls");
        cout << "Input error!\n" << endl;
        system("pause & cls");
        return -1;
    }
}

class Book {
public:
    string name, author;
    int year_of_publishing, temp_year;
    void edit()
    {
        cout << "Enter information about book\n";
        cout << "Name: "; getline(cin, name, '\n');
        cin.clear();
        cout << "Author: "; cin >> author;
        cin.clear();
        year_of_publishing = check_number();
        
    }
    int getYear() { return year_of_publishing; }

    Book(string name = "hdbc", string author = "Pushkin", int year_of_publishing = 1700) {
        this->name = name;
        this->author = author;
        this->year_of_publishing = year_of_publishing;
    }

    void print()
    {
        //cout << "Enter information about book" 
        cout << "Name: "; cout << name << "\n";
        cout << "Author: "; cout << author << "\n";
        cout << "Year of publishing: "; cout << year_of_publishing << "\n";
    }


};


vector <Book> add_book(vector<Book> arr)
{
    
    cout << "Input Hello and Enter\n";
    cin.ignore(100,'\n');
    system("cls");
    string name, author;
    int year_of_publishing;

    cout << "Enter information about book"<<endl;
    cout << "Name: "; getline(cin, name);
   
    cout << "Author: "; cin >> author;
    year_of_publishing = check_number();
    
    //    arr[1] = (Book)"Pushkin","kuku",123;
    arr.push_back(Book(name, author, year_of_publishing));
    return arr;

}

vector <Book> deleteBook(vector <Book> arr, int pos)
{
    arr.erase(arr.begin() + pos - 1);
    return arr;
}

vector<Book> sheker(vector<Book> arr, int size) {
    int left = 0, right = size - 1; // левая и правая границы сортируемой области массива
    int flag = 1;  // флаг наличия перемещений
    // Выполнение цикла пока левая граница не сомкнётся с правой
    // или пока в массиве имеются перемещения
    while ((left < right) && flag > 0)
    {
        flag = 0;
        for (int i = left; i < right; i++)  //двигаемся слева направо
        {
            if (arr[i].year_of_publishing > arr[i + 1].year_of_publishing) // если следующий элемент меньше текущего,
            {             // меняем их местами
                Book t = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = t;
                flag = 1;      // перемещения в этом цикле были
            }
        }
        right--; // сдвигаем правую границу на предыдущий элемент
        for (int i = right; i > left; i--)  //двигаемся справа налево
        {
            if (arr[i - 1].year_of_publishing > arr[i].year_of_publishing) // если предыдущий элемент больше текущего,
            {            // меняем их местами
                Book t = arr[i];
                arr[i] = arr[i - 1];
                arr[i - 1] = t;
                flag = 1;    // перемещения в этом цикле были
            }
        }
        left++; // сдвигаем левую границу на следующий элемент
    }
    return arr;
}



vector<Book> input() {
    vector<Book> arr;
    while (true) {
        arr = add_book(arr);

        cout << "\n\"1\" - continue, \"0\" - exit: ";
        int g; cin >> g;
        
        if (g == 0) break;
    }
    return arr;
}






void printByYear(vector<Book> arr, int year)
{
    for (int i = 0; i < (int)arr.size(); i++)
    {
        if (arr[i].getYear() == year) arr[i].print();
    }
}

void save(vector<Book> arr)
{
    out.open("C:\\Users\\DELL\\source\\repos\\OOP_LR\\LR_1_Library\\Save.txt");
    if (out.is_open())
    {
        for (int i = 0; i < arr.size(); i++)
        {
            out << arr[i].name << "\t" << arr[i].author << "\t" << arr[i].year_of_publishing << "\t" << endl;
        }
    }
    out.close();
    // out << "end";
}
vector<Book> read()
{
    string name, author;
    int year_of_publishing;
    vector <Book> arr;

    ifstream in("C:\\Users\\DELL\\source\\repos\\OOP_LR\\LR_1_Library\\Save.txt");
    if (in.is_open())
    {

        while (in >> name >> author >> year_of_publishing)
        {
            arr.push_back(Book(name, author, year_of_publishing));
        }
    }
    in.close();

    return arr;
}


int main()
{

    
    string name, author;
    int year_of_publishing;
    vector<Book> arr = input();
    //vector <Book> arr = menu();
    while (true) {
        for (int i = 0; i < (int)arr.size(); i++) arr[i].print();

        cout << "\n\"1\" - edit, \"2\" - search, \"3\" - remove, \"4\" - sort,\"5\" - add book \"6\" - save\"7\" - load from file \"0\" - exit: ";
        int g; cin >> g;
        cin.clear();
        int pos;
        if (g == 0) break;
        switch (g) {
        case 1:
            cout << "Enter the pos: "; cin >> pos;
            cin.clear();
            arr[pos - 1].edit();
            break;
        case 2:
            
            cout << "Enter the year of publishing: "; cin >> year_of_publishing;
            cin.clear();
            printByYear(arr, year_of_publishing);
            break;
        case 3:
            cout << "Enter the pos: "; cin >> pos;
            cin.clear();
            arr = deleteBook(arr, pos);
            break;
        case 4:
            arr = sheker(arr, (int)arr.size());
            break;
        case 5:
            arr = add_book(arr);
            break;
        case 6:
            save(arr);

            break;
        case 7:

            arr = read();
            break;
        }

    }









}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
