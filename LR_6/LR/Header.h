
#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <string.h>
#include <Windows.h>
using namespace std;

class electronic_device {
public:
	string type_battery;
	double battery_capacity;
	double consume_power;
	electronic_device();
	electronic_device(string _type_battery, double _battery_capacity, double _consume_power);
	~electronic_device();
	void set_type_battery(string _type_battery);
	void set_battery_capacity(double _battery_capacity);
	void set_consume_power(double _consume_power);
	string get_type_battery()const;
	double get_battery_capacity()const;
	double get_consume_power()const;
};
electronic_device::electronic_device() { cout << endl << "Работает конструктор без параметров electronic_device" << endl; }
electronic_device::electronic_device(string _type_battery, double _battery_capacity, double _consume_power) {
	cout << endl << "Работает конструктор c параметрами electronic_device" << endl;
	type_battery = _type_battery;
	battery_capacity = _battery_capacity;
	consume_power = _consume_power;
}
electronic_device::~electronic_device() { cout << endl << "Работает деструктор electronic_device" << endl; };
void electronic_device::set_type_battery(string _type_battery) { type_battery = _type_battery; }
void electronic_device::set_battery_capacity(double _battery_capacity) { battery_capacity = _battery_capacity; }
void electronic_device::set_consume_power(double _consume_power) { consume_power = _consume_power; }
string electronic_device::get_type_battery()const { return type_battery; }
double electronic_device::get_battery_capacity()const { return battery_capacity; }
double electronic_device::get_consume_power()const { return consume_power; }


class computing_device {
public:
	string cpu;
	int core_count;
	double cpu_frequency;
	computing_device();
	computing_device(string _cpu, int _core_count, double _cpu_frequency);
	~computing_device();
	void set_cpu(string _cpu);
	void set_core_count(int _core_count);
	void set_cpu_frequency(double _cpu_frequency);
	string get_cpu()const;
	int get_core_count()const;
	double get_cpu_frequency()const;
};
computing_device::computing_device() { cout << endl << "Работает конструктор без параметров computing_device" << endl; };
computing_device::computing_device(string _cpu, int _core_count, double _cpu_frequency) {
	cout << endl << "Работает конструктор c параметрами computing_device" << endl;
	cpu = _cpu;
	core_count = _core_count;
	cpu_frequency = _cpu_frequency;
}
computing_device::~computing_device() { cout << endl << "Работает деструктор computing_device" << endl; };
void computing_device::set_cpu(string _cpu) { cpu = _cpu; }
void computing_device::set_core_count(int _core_count) { core_count = _core_count; }
void computing_device::set_cpu_frequency(double _cpu_frequency) { cpu_frequency = _cpu_frequency; }
string computing_device::get_cpu()const { return cpu; }
int computing_device::get_core_count()const { return core_count; }
double computing_device::get_cpu_frequency()const { return cpu_frequency; }


class user_device {
public:
	string color;
	double camera_resolution;
	user_device();
	user_device(string _color, double _camera_resolution);
	virtual ~user_device();
	void set_color(string _color);
	void set_camera_resolution(double _camera_resolution);
	string get_color()const;
	double get_camera_resolution()const;
};
user_device::user_device() { cout << endl << "Работает конструктор без параметров user_device" << endl; }
user_device::user_device(string _color, double _camera_resolution) {
	cout << endl << "Работает конструктор c параметрами user_device" << endl;
	color = _color;
	camera_resolution = _camera_resolution;
}
user_device::~user_device() { cout << endl << "Работает деструктор user_device" << endl; };
void user_device::set_color(string _color) { color = _color; }
void user_device::set_camera_resolution(double _camera_resolution) { camera_resolution = _camera_resolution; }
string user_device::get_color()const { return color; }
double user_device::get_camera_resolution()const { return camera_resolution; }


class unknown_device : public electronic_device, public computing_device, private user_device {
public:
	double cost;
	unknown_device();
	unknown_device(string _type_battery, double _battery_capacity, double _consume_power, string _cpu, int _core_count, double _cpu_frequency, string _color, double _camera_resolution, double _cost);
	~unknown_device();
	void set_color(string _color);
	void set_camera_resolution(double _camera_resolution);
	void set_cost(double _cost);
	string get_color()const;
	double get_camera_resolution()const;
	double get_cost()const;
};
unknown_device::unknown_device() { cout << endl << "Работает конструктор без параметров unknown_device" << endl; };
unknown_device::unknown_device(string _type_battery, double _battery_capacity, double _consume_power, string _cpu, int _core_count, double _cpu_frequency, string _color, double _camera_resolution, double _cost)
	:
	electronic_device(_type_battery, _battery_capacity, _consume_power),
	computing_device(_cpu, _core_count, _cpu_frequency),
	user_device(_color, _camera_resolution) {
	cout << endl << "Работает конструктор c параметрами unknown_device" << endl;
	cost = _cost;
}
unknown_device::~unknown_device() { cout << endl << "Работает деструктор unknown_device" << endl; };
void unknown_device::set_color(string _color) { user_device::set_color(_color); }
void unknown_device::set_camera_resolution(double _camera_resolution) { user_device::set_camera_resolution(_camera_resolution); }
void unknown_device::set_cost(double _cost) { cost = _cost; }
string unknown_device::get_color()const { return user_device::get_color(); }
double unknown_device::get_camera_resolution()const { return user_device::get_camera_resolution(); }
double unknown_device::get_cost()const { return cost; }


class smartphone :public unknown_device {
public:
	string name;
	smartphone(string _type_battery, double _battery_capacity, double _consume_power, string _cpu, int _core_count, double _cpu_frequency, string _color, double _camera_resolution, double _cost, string _name);
	~smartphone();
	void set_name(string _name);
	string get_name()const;
};
smartphone::smartphone(string _type_battery, double _battery_capacity, double _consume_power, string _cpu, int _core_count, double _cpu_frequency, string _color, double _camera_resolution, double _cost, string _name)
	:
	unknown_device(_type_battery, _battery_capacity, _consume_power, _cpu, _core_count, _cpu_frequency, _color, _camera_resolution, _cost)
{
	cout << endl << "Работает конструктор c параметрами smartphone" << endl;
	name = _name;
}
smartphone::~smartphone() { cout << endl << "Работает деструктор smartphone" << endl; };
void smartphone::set_name(string _name) { name = _name; }
string smartphone::get_name()const { return name; }