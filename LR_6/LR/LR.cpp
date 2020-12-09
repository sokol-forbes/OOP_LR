// LR.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "Header.h"
int main() {
	system("chcp 1251");
	while (true)
	{
		int choose1;
		system("cls");
		cout << "1 Выполнить" << endl << "0 Выход" << endl << "Ваш выбор: ";
		while (true) {
			cin >> choose1;
			cin.ignore(32767, '\n');

			if (cin.fail() || choose1 < 0 || choose1>1) {
				cout << "Некорректный ввод.";
				cin.clear();
				cin.ignore(32767, '\n');
			}
			else {
				break;
			}
		}
		if (choose1 == 1)
		{
			system("cls");
			cout << "Введите тип батареи смартфона: ";
			string type_battery;
			while (true)
			{
				getline(cin, type_battery);
				if (type_battery == "" || type_battery == " ")
				{
					cout << "Некорректный ввод.";
				}
				else break;
			}
			cout << "Введите ёмкость батареи смартфона (мАч): ";
			double battery_capacity;
			while (true) {
				cin >> battery_capacity;
				cin.ignore(32767, '\n');

				if (cin.fail() || battery_capacity <= 0) {
					cout << "Некорректный ввод.";
					cin.clear();
					cin.ignore(32767, '\n');
				}
				else {
					break;
				}
			}
			cout << "Введите потребляемую мощность смартфона (Вт): ";
			double consume_power;
			while (true) {
				cin >> consume_power;
				cin.ignore(32767, '\n');

				if (cin.fail() || consume_power <= 0) {
					cout << "Некорректный ввод.";
					cin.clear();
					cin.ignore(32767, '\n');
				}
				else {
					break;
				}
			}
			system("pause");

			system("cls");
			cout << "Введите название процессора смартфона: ";
			string cpu;
			while (true)
			{
				getline(cin, cpu);
				if (cpu == "" || cpu == " ")
				{
					cout << "Некорректный ввод.";
				}
				else break;
			}
			cout << "Введите количество ядер (2,4,8,16) " << cpu << " : ";
			int core_count;
			while (true) {
				cin >> core_count;
				cin.ignore(32767, '\n');

				if (cin.fail() || (core_count != 2 && core_count != 4 && core_count != 8 && core_count != 16)) {
					cout << "Некорректный ввод.";
					cin.clear();
					cin.ignore(32767, '\n');
				}
				else {
					break;
				}
			}
			cout << "Введите  частоту ядер (не меньше 1000 МГц) " << cpu << " : ";
			double cpu_frequency;
			while (true) {
				cin >> cpu_frequency;
				cin.ignore(32767, '\n');

				if (cin.fail() || cpu_frequency < 1000) {
					cout << "Некорректный ввод.";
					cin.clear();
					cin.ignore(32767, '\n');
				}
				else {
					break;
				}
			}
			system("pause");

			system("cls");
			cout << "Введите цвет смартфона: ";
			string color;
			while (true)
			{
				getline(cin, color);
				if (color == "" || color == " " || color.find_first_not_of("абвгдеёжзийклмнопрстуфхцчшщъыьэюяАБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯabcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ") != string::npos)
				{
					cout << "Некорректный ввод.";
				}
				else break;
			}
			cout << "Введите разрешение камеры(не меньше 8 Мп): ";
			double camera_resolution;
			while (true) {
				cin >> camera_resolution;
				cin.ignore(32767, '\n');

				if (cin.fail() || camera_resolution < 8) {
					cout << "Некорректный ввод.";
					cin.clear();
					cin.ignore(32767, '\n');
				}
				else {
					break;
				}
			}
			system("pause");

			system("cls");
			cout << "Введите стоимость смартфона (не меньше 100$): ";
			double cost;
			while (true) {
				cin >> cost;
				cin.ignore(32767, '\n');

				if (cin.fail() || cost < 100) {
					cout << "Некорректный ввод.";
					cin.clear();
					cin.ignore(32767, '\n');
				}
				else {
					break;
				}
			}
			system("pause");

			system("cls");
			cout << "Введите название смартфона: ";
			string name;
			while (true)
			{
				getline(cin, name);
				if (name == "" || name == " ")
				{
					cout << "Некорректный ввод.";
				}
				else break;
			}
			smartphone smrt(type_battery, battery_capacity, consume_power, cpu, core_count, cpu_frequency, color, camera_resolution, cost, name);


			system("pause");
			bool flag = true;
			while (flag) {
				system("cls");
				smartphone* ptr_smrt = &smrt;
				cout << setiosflags(ios::left) << setw(20) << "Название "
					<< setiosflags(ios::left) << setw(20) << "Стоимость ($)"
					<< setiosflags(ios::left) << setw(20) << "Тип батареи" << setiosflags(ios::left) << setw(25) << "Ёмкость батареи (мАч)" << setiosflags(ios::left) << setw(35) << "Потребляемая мощность (Вт)"
					<< setiosflags(ios::left) << setw(25) << "Название процессора" << endl << setiosflags(ios::left) << setw(20) << ptr_smrt->get_name() << setiosflags(ios::left) << setw(20) << ptr_smrt->get_cost()
					<< setiosflags(ios::left) << setw(20) << ptr_smrt->get_type_battery() << setiosflags(ios::left) << setw(25) << ptr_smrt->get_battery_capacity() << setiosflags(ios::left) << setw(35) << ptr_smrt->get_consume_power()
					<< setiosflags(ios::left) << setw(25) << ptr_smrt->get_cpu() << endl << endl <<
					setiosflags(ios::left) << setw(20) << "Количество ядер" << setiosflags(ios::left) << setw(25) << "Частота ядер (МГц)"
					<< setiosflags(ios::left) << setw(20) << "Цвет" << setiosflags(ios::left) << setw(30) << "Разрешение камеры (Мп)" << endl;
				cout << setiosflags(ios::left) << setw(20) << ptr_smrt->get_core_count() << setiosflags(ios::left) << setw(25) << ptr_smrt->get_cpu_frequency()
					<< setiosflags(ios::left) << setw(20) << ptr_smrt->get_color() << setiosflags(ios::left) << setw(30) << ptr_smrt->get_camera_resolution() << endl << endl;

				cout << "1 Редактировать название смартфона" << endl
					<< "2 Редактировать стоимость" << endl
					<< "3 Редактировать тип батареи" << endl << "4 Редактировать ёмкость батареи" << endl << "5 Редактировать потребляемую мощность" << endl
					<< "6 Редактировать название процессора" << endl << "7 Редактировать количество ядер " << endl << "8 Редактировать частоту процессора" << endl
					<< "9 Редактировать цвет смартфона" << endl << "10 Редактировать разрешение камеры" << endl
					<< "0 Выход" << endl << "Ваш выбор: ";
				int choose2;
				while (true) {
					cin >> choose2;
					cin.ignore(32767, '\n');
					if (cin.fail() || choose2 < 0 || choose2>10) {
						cout << "Некорректный ввод.";
						cin.clear();
						cin.ignore(32767, '\n');
					}
					else {
						break;
					}
				}
				if (choose2 == 1)
				{
					cout << "Введите название смартфона: ";
					string new_name;
					while (true)
					{
						getline(cin, new_name);
						if (new_name == "" || new_name == " ")
						{
							cout << "Некорректный ввод.";
						}
						else break;
					}
					ptr_smrt->set_name(new_name);
				}
				else if (choose2 == 2)
				{
					cout << "Введите стоимость смартфона (не меньше 100$): ";
					double new_cost;
					while (true) {
						cin >> new_cost;
						cin.ignore(32767, '\n');

						if (cin.fail() || new_cost < 100) {
							cout << "Некорректный ввод.";
							cin.clear();
							cin.ignore(32767, '\n');
						}
						else {
							break;
						}
					}
					unknown_device* ptr_unk_dev = &smrt;
					ptr_unk_dev->set_cost(new_cost);
				}
				else if (choose2 == 3)
				{
					cout << "Введите тип батареи смартфона: ";
					string new_type_battery;
					while (true)
					{
						getline(cin, new_type_battery);
						if (new_type_battery == "" || new_type_battery == " ")
						{
							cout << "Некорректный ввод.";
						}
						else break;
					}
					electronic_device* ptr_elec_dev = &smrt;
					ptr_elec_dev->set_type_battery(new_type_battery);
				}
				else if (choose2 == 4)
				{
					cout << "Введите ёмкость батареи смартфона (мАч): ";
					double new_battery_capacity;
					while (true) {
						cin >> new_battery_capacity;
						cin.ignore(32767, '\n');

						if (cin.fail() || new_battery_capacity <= 0) {
							cout << "Некорректный ввод.";
							cin.clear();
							cin.ignore(32767, '\n');
						}
						else {
							break;
						}
					}
					electronic_device* ptr_elec_dev = &smrt;
					ptr_elec_dev->set_battery_capacity(new_battery_capacity);
				}
				else if (choose2 == 5)
				{
					cout << "Введите потребляемую мощность смартфона (Вт): ";
					double new_consume_power;
					while (true) {
						cin >> new_consume_power;
						cin.ignore(32767, '\n');

						if (cin.fail() || new_consume_power <= 0) {
							cout << "Некорректный ввод.";
							cin.clear();
							cin.ignore(32767, '\n');
						}
						else {
							break;
						}
					}
					electronic_device* ptr_elec_dev = &smrt;
					ptr_elec_dev->set_consume_power(new_consume_power);
				}
				else if (choose2 == 6)
				{
					cout << "Введите название процессора смартфона: ";
					string new_cpu;
					while (true)
					{
						getline(cin, new_cpu);
						if (new_cpu == "" || new_cpu == " ")
						{
							cout << "Некорректный ввод.";
						}
						else break;
					}
					computing_device* ptr_comp_dev = &smrt;
					ptr_comp_dev->set_cpu(new_cpu);
				}
				else if (choose2 == 7)
				{
					cout << "Введите количество ядер (2,4,8,16) " << cpu << " : ";
					int new_core_count;
					while (true) {
						cin >> new_core_count;
						cin.ignore(32767, '\n');

						if (cin.fail() || (new_core_count != 2 && new_core_count != 4 && new_core_count != 8 && new_core_count != 16)) {
							cout << "Некорректный ввод.";
							cin.clear();
							cin.ignore(32767, '\n');
						}
						else {
							break;
						}
					}
					computing_device* ptr_comp_dev = &smrt;
					ptr_comp_dev->set_core_count(new_core_count);
				}
				else if (choose2 == 8)
				{
					cout << "Введите  частоту ядер (не меньше 1000 МГц) " << cpu << " : ";
					double new_cpu_frequency;
					while (true) {
						cin >> new_cpu_frequency;
						cin.ignore(32767, '\n');

						if (cin.fail() || new_cpu_frequency < 1000) {
							cout << "Некорректный ввод.";
							cin.clear();
							cin.ignore(32767, '\n');
						}
						else {
							break;
						}
					}
					computing_device* ptr_comp = &smrt;
					ptr_comp->set_cpu_frequency(new_cpu_frequency);
				}
				else if (choose2 == 9)
				{
					cout << "Введите цвет смартфона: ";
					string new_color;
					while (true)
					{
						getline(cin, new_color);
						if (new_color == "" || new_color == " " || new_color.find_first_not_of("абвгдеёжзийклмнопрстуфхцчшщъыьэюяАБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯabcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ") != string::npos)
						{
							cout << "Некорректный ввод.";
						}
						else break;
					}
					user_device us_dev;
					user_device* ptr_us = &us_dev;
					ptr_us->set_color(new_color);
					unknown_device* ptr_unk = &smrt;
					ptr_unk->set_color(new_color);
				}
				else if (choose2 == 10)
				{
					cout << "Введите разрешение камеры(не меньше 8 Мп): ";
					double new_camera_resolution;
					while (true) {
						cin >> new_camera_resolution;
						cin.ignore(32767, '\n');

						if (cin.fail() || new_camera_resolution < 8) {
							cout << "Некорректный ввод.";
							cin.clear();
							cin.ignore(32767, '\n');
						}
						else {
							break;
						}
					}
					user_device us_dev;
					user_device* ptr_us = &us_dev;
					ptr_us->set_camera_resolution(new_camera_resolution);
					unknown_device* ptr_unk = &smrt;
					ptr_unk->set_camera_resolution(new_camera_resolution);
				}
				else if (choose2 == 0)
				{
					flag = false;
				}
			}
		}
		else if (choose1 == 0) return 0;
		system("pause");
	}
	return 0;
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
