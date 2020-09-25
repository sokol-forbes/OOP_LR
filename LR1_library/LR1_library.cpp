// LR1_library.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;


ofstream out;

int get_Int()
{
    while (true) // цикл продолжается до тех пор, пока пользователь не введет корректное значение
    {
        cout << "Enter year of publishing: ";
        int a,b;
        cin >> a;

        if (cin.fail()) // если предыдущее извлечение оказалось неудачным,
        {
            cin.clear(); // то возвращаем cin в 'обычный' режим работы
            cin.ignore(32767, '\n'); // и удаляем значения предыдущего ввода из входного буфера
            
            
        }
        else // если всё хорошо, то возвращаем a
            return a;
    }
}


class Book {
public:
    string name, author;
    int year_of_publishing, temp_year;
    void edit()
    {
        cout << "Enter information about book" << endl;
        cout << "Name: "; cin >> name; cout << endl;
        cout << "Author: "; cin>> author; cout << endl;
        year_of_publishing=get_Int();
        cout << endl;
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
        cout << "Name: ";cout << name<<endl; 
        cout << "Author: ";cout << author<<endl;
        cout << "Year of publishing: ";cout << year_of_publishing<<endl;
    }
    

};


vector <Book> add_book(vector<Book> arr)
{
    string name, author;
    int year_of_publishing;

    cout << "Enter information about book" <<endl;
    cout << "Name: "; cin>> name;
    cout << "Author: "; cin >> author;
    year_of_publishing=get_Int();
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
    out.open("C:\\Users\\DELL\\source\\repos\\OOP_LR\\LR1_library\\Save.txt");
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

    ifstream in("C:\\Users\\DELL\\source\\repos\\OOP_LR\\LR1_library\\Save.txt");
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
   
    setlocale(0);
        string name, author;
        int year_of_publishing, index;
        vector<Book> arr = input();
        //vector <Book> arr = menu();
        while (true) {
            for (int i = 0; i < (int)arr.size(); i++) arr[i].print();

            cout << "\n\"1\" - edit, \"2\" - search, \"3\" - remove, \"4\" - sort,\"5\" - add book \"6\" - save\"7\" - load from file \"0\" - exit: ";
            int g; cin >> g;
            int pos;
            if (g == 0) break;
            switch (g) {
            case 1:
                cout << "Enter the pos: "; cin >> pos;
                arr[pos - 1].edit();
                break;
            case 2:
                int year;
                cout << "Enter the year of publishing: "; cin >> year;
                printByYear(arr, year);
                break;
            case 3:
                cout << "Enter the pos: "; cin >> pos;
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
