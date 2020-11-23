// LR_2_Array.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <iomanip>
using namespace std;

ostream& setup1(ostream& stream) {
    stream.setf(ios::left);
    stream << setw(8) << setfill(' ')<<'|';
    return stream;
}
ostream& setup2(ostream& stream) {
    stream.setf(ios::left);
    stream << setw(7) << setfill(' ') << '|';
    return stream;
}
ostream& setup3(ostream& stream) {
    stream.setf(ios::left);
    stream << setw(9) << setfill(' ') << '|';
    return stream;
}
ostream& setup4(ostream& stream) {
    stream.setf(ios::left);
    stream << setw(200) << setfill('-');
    return stream;
}
ostream& setup5(ostream& stream) {
    stream.setf(ios::left);
    stream << setw(7) << setfill(' ') << '|';
    return stream;
}
ostream& setup6(ostream& stream) {
    stream.setf(ios::left);
    stream << setw(8) << setfill(' ') << '|';
    return stream;
}

bool cheker(int size, string type)
{
    if (type == "Float" && size > 0 && size < 20) return true;
    else if (type == "Integer" && size > 0 && size < 10)return true;
    else 
    { 
        cout << "Input error";
        return false; 
    }
}

class Array
{
private:
    int** Integer_array = new int*[2];//колличество строк
    float** Float_array = new float*[2];
    string Type="Integer";
    /*for(int i=0;i<2;i++)
    Float_array[i]=new float[20]*/
public:
    /*void setIntValue(int index_v_stroke, int index_v_stolbce, int value)
    {
        if ((index_v_stroke < 0 || index_v_stroke >= 10)&&(index_v_stolbce<0|| index_v_stolbce>=2))
            return;
        Integer_array[index_v_stolbce][index_v_stroke] = value;
    }
    int getIntValue(int index_v_stroke, int index_v_stolbce) { return Integer_array[index_v_stolbce][index_v_stroke]; }

    void setFloatValue(int index_v_stroke, int index_v_stolbce, float value)
    {
        if ((index_v_stroke < 0 || index_v_stroke >= 20) && (index_v_stolbce < 0 || index_v_stolbce >= 2))
            return;
        Float_array[index_v_stolbce][index_v_stroke] = value;
    }
    float getFloatValue(int index_v_stroke, int index_v_stolbce) { return  Float_array[index_v_stolbce][index_v_stroke]; }*/

    void print(int size, string type, int starter_number)
    {
        if (type == "Integer"||type=="integer")
        {
            for (int i = 0; i < 2; i++)
            {
                for (int j = 0; j < size; j++)
                {
                    if (i == 0)cout << setup1 << Integer_array[i][j];
                    else if (Integer_array[0][j] >= 10 && Integer_array[0][j] <= 20) cout << setup2 << Integer_array[i][j];
                    else if (Integer_array[0][j] < 10 || Integer_array[0][j] > 20) cout << setup5 << "--";
                    
                }
                cout << endl;
                cout << setup4 << "-";
                cout << endl;
            }
        }
        else if (type == "Float"||type=="float")
        {
            for (int i = 0; i < 2; i++)
            {
                for (int j = 0; j < size; j++)
                {
                    if (i == 0)
                    {
                        if (j % 2 == 1)
                        {
                            if (Float_array[0][j] > 10.0f && Float_array[0][j] < 20.0f)
                            {
                                cout << setup3 << Float_array[i][j];
                            }
                            else if (Float_array[0][j] < 10.0f || Float_array[0][j] > 20.0f)
                                cout << setup5 <<Float_array[i][j];

                        }
                        else cout << setup1 << Float_array[i][j];
                    }
                   else if (Float_array[i][j] >= 100)cout << setup2 << Float_array[i][j];
                    else if (Float_array[1][j] < 100.0f)cout << setup6 << " ";

                }
                cout << endl;
                cout <<setup4<<"-";
                cout << endl;
            }
        }
    }

    Array(int size, string type, int Int_Element=0, float Fl_Element =0.5f)
    {
        Type = type;
        if (type == "Integer")
        { 
            //int element = 10;
            for (int i = 0; i < 2; i++)
                Integer_array[i] = new int[size];
            for (int i = 0; i < 2; i++)
            {
                for (int j = 0; j < size; j++)
                {
                    if (i == 0)
                    {
                        Integer_array[i][j] = Int_Element;
                        Int_Element +=1;
                    }
                    if(i==1)
                    Integer_array[i][j] = Integer_array[0][j] * Integer_array[0][j];
                    
                    
                }
            }
        }
        else if (type == "Float")
        {
            //float element = 10.0;
            for (int i = 0; i < 2; i++)
                Float_array[i] = new float[size];
            for (int i = 0; i < 2; i++)
            {
                for (int j = 0; j < size; j++)
                {
                    if (i == 0)
                    {
                        Float_array[i][j] = Fl_Element;
                        Fl_Element += 0.5;
                    }
                    if (i == 1)
                    {
                        Float_array[i][j] = Float_array[0][j] * Float_array[0][j];
                    }
                }
            }
        }
        else cout << "Type error" << endl;
    }
    ~Array()
    {
        if (Type == "Integer")
        {
            for (int count = 0; count < 2; count++)
                delete[] Integer_array[count];
        }
        else
        {
            for (int count = 0; count < 2; count++)
                delete[] Float_array[count];
        }
    }
};
int main()
{
    int size, starter_number_int;
    float starter_number_fl;
    string type;
    bool check = false;
    while (!check)
    {

        cout << "Enter size of array and Type\n Int Max size = 10 Float max size 20\n And starter number\n";
        cin >> size;
        cin >> type;
        if (type == "Integer" || type == "integer")
        {
            cin >> starter_number_int;
        }
        else if (type == "Float" || type == "float")
        {
            cin >> starter_number_fl;
        }
        check=cheker(size, type);
    }
    if (type == "Integer" || type == "integer")
    {
        Array* first = new Array(size, type, starter_number_int,0);
        first->print(size, type, starter_number_int);
        delete first;
    }
    else if (type == "Float" || type == "float")
    {
        Array* first = new Array(size, type, 0,starter_number_fl);
        first->print(size, type, starter_number_fl);
        delete first;
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
