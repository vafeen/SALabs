#include "AbonentList_Abonent_Adress.hpp"

int main()
{
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
    AbonentList *head = new AbonentList;
    ifstream filer("abonents.txt");
    string name1, name2, name3;
    string street;
    string number_of_phone;
    short number_of_home;
    short number_of_apart;
    Abonent object;

    float balance = 0;
    while (filer >> name1 >> name2 >> name3 >> street >> number_of_home >> number_of_apart >> number_of_phone >> balance)
    {
        string FIO = name1 + " " + name2 + " " + name3;
        object.set_info(FIO, street, number_of_home, number_of_apart, number_of_phone, balance);
        head->push_back(object);
    }
    head->print_until_this_balance(1500);
    // head->print();

    head->clear();
    system("pause");
    return 1;
}