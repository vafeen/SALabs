#include <iostream>

#include <fstream>
#include <string>
#include <windows.h>
using namespace std;
#define ct const
const string my_undefined = "undefined";
class Adress
{
    string street;
    short number_of_home;
    short number_of_apart;

public:
    Adress(ct string &_street = my_undefined, ct short &_number_of_home = 0, ct short &_number_of_apart = 0);
    void set_info(ct string &_street, ct short &_number_of_home, ct short &_number_of_apart);
    void set_street(ct string &_street);
    void set_number_of_home(ct short &_number_of_home);
    void set_number_of_apart(ct short &_number_of_apart);
    string get_street() const;
    short get_number_of_home() const;
    short get_number_of_apart() const;
    friend ostream &operator<<(ostream &stream, const Adress &object);
    Adress &operator=(const Adress &object);
    ~Adress();
};

class Abonent
{
    string FIO;
    string number_of_phone;
    float balance;

public:
    Adress adress_of_abonent;

    Abonent(ct string &_FIO = my_undefined, ct string &_number_of_phone = my_undefined, ct float &_balance = 0, ct string &_street = my_undefined, ct short &_number_of_home = 0, ct short &_number_of_apart = 0);
    Abonent(ct Abonent &object);
    void set_info(ct string &_FIO, ct string &_street, ct short &_number_of_home, ct short &_number_of_apart, ct string &_number_of_phone, ct float &_balance);
    void set_info(const Abonent &object);
    friend ostream &operator<<(ostream &stream, const Abonent &object);
    Abonent operator=(const Abonent &object);

    void set_FIO(ct string &_FIO);
    void set_number_of_phone(ct string &_number_of_phone);
    void set_balance(ct float &_balance);

    string get_FIO() const;
    string get_number_of_phone() const;
    float get_balance() const;

    ~Abonent();
};

class AbonentList
{
    Abonent *abonent;
    AbonentList *next;

public:
    AbonentList *get_next() const;
    Abonent *get_abonent() const;
    AbonentList(ct string &_FIO = my_undefined, ct string &_number_of_phone = my_undefined, ct float &_balance = 0, ct string &_street = my_undefined, ct short &_number_of_home = 0, ct short &_number_of_apart = 0);
    AbonentList(const Abonent &object);
    friend ostream &operator<<(ostream &stream, const AbonentList &object);
    void push_back(const Abonent &object);
    void delAfterThis();
    void clear();
    ~AbonentList();
    void print() const;
    void print_until_this_balance(const float &_balance) const;
};
