// Shapes.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <math.h>
#include <windows.h>

using namespace std;
const double PI = 3.141592;

class Figure {
public:
    virtual void print();

    virtual double getSquare();

    virtual double getPerimeter();

    virtual double getVolume();


};

class TwoDFigure : public Figure {

};


class ThreeDFigure : public Figure {


};

class Parallelepiped : public ThreeDFigure {
    double width, longg, height;
public:
    Parallelepiped(double h, double l, double w) : height(h), longg(l), width(w) {}

    Parallelepiped() {
        width = height = longg = 1.1;
    }

    double getSquare() override {
        return 2 * width * longg + 2 * height * longg + 2 * height * width;
    }

    double getVolume() override {
        return width * longg * height;
    }

    void print() {
        std::cout << "Parallelepiped" << std::endl;
    }
};

class Sphere : public ThreeDFigure {
    double radius;
public:
    Sphere(double r) : radius(r) {}

    Sphere() {
        radius = 1.1;
    }

    double getSquare() override {
        return 4 * radius * radius * PI;
    }

    double getVolume() override {
        return 4 / 3 * radius * radius * radius * PI;
    }

    void print() {
        std::cout << "Sphere" << std::endl;
    }

};


class Rectangle : public TwoDFigure {
    double height, width;
public:
    Rectangle(double w, double h) : width(w), height(h) {}

    Rectangle() {
        width = 1.1;
        height = 1.2;
    }

    double getSquare() override {
        return width * height;
    }

    double getPerimeter() override {
        return width * 2 + height * 2;
    }

    void print() {
        std::cout << "Rectangle" << std::endl;
    }

};

class Treeangle : public TwoDFigure {
    double side1, side2, side3;
public:
    Treeangle(double s1, double s2, double s3) : side1(s1), side2(s2), side3(s3) {}

    Treeangle() {
        side1 = 1.2;
        side2 = 1.3;
        side3 = 1.3;
    }

    double getSquare() override {
        return sqrt(getPerimeter() / 2 * (getPerimeter() / 2 - side1) * (getPerimeter() / 2 - side2) *
                    (getPerimeter() / 2 - side3));
    }

    double getSquare(double s1, double s2, double s3) {
        double perimetr = s1 + s2 + s3;
        return sqrt(perimetr / 2 * (perimetr / 2 - s1) * (perimetr / 2 - s2) * (perimetr / 2 - s3));
    }

    double getPerimeter() override {
        return side1 + side2 + side3;
    }

    void print() {
        std::cout << "Treeangle" << std::endl;
    }
};

class Circle : public TwoDFigure {
    double radius;
public:
    Circle(double r) : radius(r) {}

    Circle() {
        radius = 1.1;
    }

    double getSquare() override {

        return radius * radius * PI;
    }

    double getPerimeter() override {
        return 2 * PI * radius;
    }

    void print() {
        std::cout << "Circle" << std::endl;
    }
};

class Piramid : public ThreeDFigure, public Treeangle {
    double side1, side2, side3, side4, side5, side6;
public:
    Piramid(double s1, double s2, double s3, double s4, double s5, double s6)
            : Treeangle(s1, s2, s3), side4(s4), side5(s5), side6(s6) {}

    Piramid() {
        side1 = side2 = side3 = side4 = side5 = side6 = 1.8;
    }

    double getSquare() override {
        return Treeangle::getSquare(side4, side5, side1) + Treeangle::getSquare(side2, side3, side1) +
               Treeangle::getSquare(side2, side4, side6) + Treeangle::getSquare(side3, side5, side6);
    }

    double getVolume() override {
        return sqrt(side4 * side4 -
                    (side1 * side2 * side3 / (4 * Treeangle::getSquare(side2, side3, side1)) *
                     (side1 * side2 * side3 / (4 * Treeangle::getSquare(side2, side3, side1))))) / 3 *
               Treeangle::getSquare(side2, side3, side1);
    }

    void print() {
        std::cout << "Sphere" << std::endl;
    }
};

int main()
{
    int choice;
    double sides[6];
    std::cout << "Hello";

    Treeangle trea;
    Rectangle rec;
    Circle cir;

    Parallelepiped p;
    Sphere sph;
    Piramid pir;
    setlocale(LC_ALL, "Russian");

    std::cout << "С каким типом фигур вы хотите поработать? 2- двумерные, 3 - трёхмерные";
    std::cin >> choice;
    if (choice == 2)
    {
        std::cout << "Данная программа позволяет работать с такикми видами двумерных фигур:\n 1) Треугольник\n 2) Круг\n 3) Прямоугольник\n";
        std::cin >> choice;

        if (choice == 1)
        {
            std::cout << "Введите длинны сторон треугольника";
            for (int i = 0; i < 3; i++)
            {
                std::cin>>sides[i];
            }
             trea(sides[0], sides[1], sides[2]);
        }
        else if (choice == 2)
        {
                std::cout << "Введите радиус круга";            
                std::cin >> sides[0];
                 cir(sides[0]);            
        }
        else if (choice == 3)
        {
            std::cout << "Введите длинны сторон прямоугольника";
            for (int i = 0; i < 2; i++)
            {
                std::cin >> sides[i];
            }
             rec(sides[0], sides[1]);
        }
    }
    else if (choice == 3)
    {
        std::cout << "Данная программа позволяет работать с такикми видами трёхмерных фигур:\n 1) Параллелипипед \n 2) Сфера\n 3) Пирамида\n";
        std::cin >> choice;

        if (choice == 1)
        {
            std::cout << "Введите длинны сторон параллелипипеда";
            for (int i = 0; i < 3; i++)
            {
                std::cin >> sides[i];
            }
             p(sides[0], sides[1], sides[2]);
        }
        if (choice == 2)
        {
            std::cout << "Введите радиус круга";
            std::cin >> sides[0];
             sph(sides[0]);
        }
        if (choice == 3)
        {
            std::cout << "Введите длинны сторон пирамиды";
            for (int i = 0; i < 6; i++)
            {
                std::cin >> sides[i];
            }
             pir(sides[0], sides[1], sides[2],sides[3],sides[4],sides[5]);
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
