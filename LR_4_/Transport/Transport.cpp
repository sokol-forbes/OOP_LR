// Transport.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

const double M_PI = 3.14;
class City
{
    string name;
    float latitude, longitude; //ширина, долгота
    bool plane_access;
    bool train_access;
    bool auto_access;
public:
    City(string name1, float latitude1,float longitude1, bool plane_access1, bool train_access1, bool auto_access1)
    {
        name = name1;
        latitude = latitude1 * M_PI / 180;
        longitude = longitude1 * M_PI / 180;
        plane_access = plane_access1;
        train_access = train_access1;
        auto_access = auto_access1;
    }
    void show()
    {
        cout << "Город: " << name << " Широта\t" <<latitude<< "° Долгота\t"<<longitude<<"° ";
        if (plane_access == 1) { cout << " Аэропорт работает "; }
        else { cout << "Аэропорт не работает"; }
        if (train_access == 1) { cout << " Вокзал работает "; }
        else { cout << "Вокзал не работает"; }
        if (auto_access == 1) { cout << " Дорога открыта\n "; }
        else { cout << "Дорога закрыта\n"; }
    }
    friend float Distance(City first, City second);
    bool getPlaneAccess() { return plane_access; }
    bool getTrainAccess() { return train_access; }
    bool getAutoAccess() { return auto_access; }
};

float Distance(City f, City s)
{
    
    float dist =6371* 2 * asin(sqrt((sin((f.latitude - s.latitude) / 2) * sin((f.latitude - s.latitude) / 2)) + cos(f.latitude) * cos(s.latitude) * sin((f.longitude - s.longitude) / 2)*sin((f.longitude - s.longitude) / 2)));
    return dist;

}
class Vehicle
{
    int average_speed;
    float cost_of_km;
public:
    void getData()
    {
        cout << "Введите среднюю скорость " << endl;
        cin >> average_speed;
    }
    void putData()const{
        cout << "Средняя скорость: "<<average_speed<<" км/ч"<<endl;
        cout << "Один километр на данном транспорте стоит " << cost_of_km << endl;
    }
    Vehicle(int av,float c)
    {
        average_speed = av;
        cost_of_km = c;
    }
    int getSpeed() { return average_speed; }
    float getCost() { return cost_of_km; }
};

class Plane:public Vehicle
{
    string airline;
    //const float cost_of_km=0.053F;
public:
    void getData()
    {
        cout << "Введите немного информации о данном самолёте" << endl;
        Vehicle::getData();
        cout << "Введите имя компании " << endl;
        cin >> airline;
        
    }
    void putData() const
    {
        Vehicle::putData();
        cout << "Данный самолёт принадлежит авиакомпании: " << airline<<endl;
        
    }
    Plane(string airline) : Vehicle(800, 0.053)
    {
        this->airline = airline;
    }

};

class Train : public Vehicle
{
    const float cost_of_km = 0.066F;
    int type=-1;
    int speed=100;

public: 
    void getData()
    {
        cout << "Введите немного информации о данном паровозе" << endl;
        Vehicle::getData();
        cout << "Введите тип (1.Региональный, 2.Городской, 3.Межгородской)" << endl;
        cin >> type;
       
        if (type == 1)
            speed = 100;
        if (type == 2)
            speed = 80;
        if (type == 3)
            speed = 150;
    }
    void putData() const
    {
        Vehicle::putData();
        cout << "Данный поезд принадлежит к ";

        if (type == 1)
            cout << "Региональным";
        if (type == 2)
                cout << "Городским";
        if (type == 3)
            cout << "Межгородским";
        cout <<" линиям" << endl;
        cout << "скорость" << speed << endl;
    }
    Train(int type,int speed): Vehicle(speed, 0.066)
    {
        this->type = type;
        this->speed = speed;
    }
};

class Auto : public Vehicle
{
    const float cost_of_km = 0.059F;
public:
    void getData()
    {
        Vehicle::getData();
    }
    void putData() const
    {
        Vehicle::putData();
    }
    Auto() : Vehicle(130, 0.059)
    {   }
};

void Calc(City f,City s,Plane pl,Train tr,Auto au)
{
    
    if (f.getPlaneAccess() && s.getPlaneAccess())
    {
        cout << "\t\t\tPlane\n";
        pl.putData();
        cout << Distance(f, s) / pl.getSpeed() << " часа" << endl;
        cout << "Стоимость " << pl.getCost() * Distance(f, s) << "$\n";
    }
    else cout << "К сожалению, самолет на данном маршруте не доступен\n";

    if (f.getTrainAccess() && s.getTrainAccess())
    {
        cout << "\t\t\tTrain\n";
        tr.putData();
        cout << Distance(f, s)*2 / tr.getSpeed() << " часа" << endl;
        cout << "Стоимость " << tr.getCost() *2* Distance(f, s) << "$\n";
    }
    else cout << "К сожалению, поезд на данном маршруте не доступен\n";

    if (f.getAutoAccess() && s.getAutoAccess())
    {
        cout << "\t\t\tAuto\n";
        au.putData();
        cout << Distance(f, s) *1.5/ au.getSpeed() << " часа" << endl;
        cout << "Стоимость " << au.getCost() * 1.5*Distance(f, s) << "$\n";
    }
    else cout << "К сожалению, автомобиль на данном маршруте не доступен\n";
}



int main()
{
    setlocale(LC_ALL, "rus");
    
    int choice,index_d,index_a;
    string name;
    float latitude, longitude; //ширина, долгота
    bool plane_access;
    bool train_access;
    bool auto_access;
    vector <City> city;
    Plane pl("Белавиа");
    Train tr(2, 100);
    Auto au;
    city.push_back(City("Москва", 55.753960, 37.620393, 1, 1, 1));
    //City first("Moscow", 55.753960, 37.620393,1,1,1);
    city.push_back(City("Минск", 53.9, 27.57, 1, 1, 1));
    city.push_back(City("Нью-Йорк", 43.10535, -75.29128, 1, 0, 1));
    city.push_back(City("Лида", 53.88333, 25.29972, 0, 1, 1));
   // cout << Distance(first, second)<<"км"<<endl;
    while (1)
    {
        cout << "\n1.Add city\n2.Edit plane\n3.Edit train\n4.Edit auto\n5.Calculation\n0.To Exit\n";
        cin >> choice;
        if (choice == 1)
        {
            cout << "Введите данные о новом городе\nНазвание\nШироту\nДолготу\nНаличие Аэропорта, ЖД Вокзала, Автомобильных дорог\n";
                cin >> name >> latitude>>longitude>>plane_access>>train_access>>auto_access;
                city.push_back(City(name, latitude, longitude, plane_access, train_access, auto_access));
        }
        if (choice == 2)
        {
            pl.getData();
        }
        if (choice == 3)
        {
            tr.getData();
        }
        if (choice == 4)
        {
            au.getData();
        }
        if (choice == 5)
        {
            for (int i = 0; i < city.size(); i++)
            {
                cout << i+1 << ")\n";
                city.at(i).show();
            }
            cout << "Введите номера городов для расчётов\n";
            cin >> index_a >> index_d;
            Calc(city.at(index_a-1), city.at(index_d-1), pl, tr, au);
        }
        if (choice == 0)
        {
            exit(0);
        }
    }
    
    
    //Calc(city.at(index_a),city.at(index_d),pl,tr,au);
    
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
