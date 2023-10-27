#include "AbonentList_Abonent_Adress.hpp"

Adress::Adress(ct string &_street, ct short &_number_of_home, ct short &_number_of_apart)
{
    set_info(_street, _number_of_home, _number_of_apart);
}
void Adress::set_info(ct string &_street, ct short &_number_of_home, ct short &_number_of_apart)
{
    street = _street;
    number_of_home = _number_of_home;
    number_of_apart = _number_of_apart;
}
void Adress::set_street(ct string &_street)
{
    street = _street;
}
void Adress::set_number_of_home(ct short &_number_of_home)
{
    number_of_home = _number_of_home;
}
void Adress::set_number_of_apart(ct short &_number_of_apart)
{
    number_of_apart = _number_of_apart;
}
string Adress::get_street() const
{
    return street;
}
short Adress::get_number_of_home() const
{
    return number_of_home;
}
short Adress::get_number_of_apart() const
{
    return number_of_apart;
}
ostream &operator<<(ostream &stream, const Adress &object)
{
    stream << "street= " << object.street << " " << object.number_of_home << ",       " << object.number_of_apart << " ";
    return stream;
}
Adress &Adress::operator=(const Adress &object)
{
    street = object.street;
    number_of_home = object.number_of_home;
    number_of_apart = object.number_of_apart;
    return *this;
}
Adress::~Adress()
{
    street = my_undefined;
    number_of_home = 0;
    number_of_apart = 0;
}

Abonent::Abonent(ct string &_FIO, ct string &_number_of_phone, ct float &_balance, ct string &_street, ct short &_number_of_home, ct short &_number_of_apart)
{
    set_info(_FIO, _street, _number_of_home, _number_of_apart, _number_of_phone, _balance);
}
Abonent::Abonent(ct Abonent &object)
{
    set_info(object.FIO, object.adress_of_abonent.get_street(), object.adress_of_abonent.get_number_of_home(), object.adress_of_abonent.get_number_of_apart(), object.number_of_phone, object.balance);
}
void Abonent::set_info(ct string &_FIO, ct string &_street, ct short &_number_of_home, ct short &_number_of_apart, ct string &_number_of_phone, ct float &_balance)
{
    FIO = _FIO;
    number_of_phone = _number_of_phone;
    balance = _balance;
    adress_of_abonent.set_info(_street, _number_of_home, _number_of_apart);
}
void Abonent::set_info(const Abonent &object)
{
    FIO = object.get_FIO();
    number_of_phone = object.get_number_of_phone();
    balance = object.get_balance();
    adress_of_abonent.set_info(object.adress_of_abonent.get_street(), object.adress_of_abonent.get_number_of_home(), object.adress_of_abonent.get_number_of_apart());
}
ostream &operator<<(ostream &stream, const Abonent &object)
{
    stream << "FIO= " << object.FIO << ",       phone= " << object.number_of_phone << ",       balance= " << object.balance << ",       adress: " << object.adress_of_abonent;
    return stream;
}
Abonent Abonent::operator=(const Abonent &object)
{
    this->FIO = object.get_FIO();
    number_of_phone = object.get_number_of_phone();
    balance = object.get_balance();
    adress_of_abonent = object.adress_of_abonent;
    return *this;
}

void Abonent::set_FIO(ct string &_FIO)
{
    FIO = _FIO;
}
void Abonent::set_number_of_phone(ct string &_number_of_phone)
{
    number_of_phone = _number_of_phone;
}
void Abonent::set_balance(ct float &_balance)
{
    balance = _balance;
}

string Abonent::get_FIO() const
{
    return FIO;
}
string Abonent::get_number_of_phone() const
{
    return number_of_phone;
}
float Abonent::get_balance() const
{
    return balance;
}

Abonent::~Abonent()
{
    FIO = my_undefined;
    number_of_phone = my_undefined;
    balance = 0.0F;
}

AbonentList *AbonentList::get_next() const
{
    return next;
}
Abonent *AbonentList::get_abonent() const
{
    return abonent;
}
AbonentList::AbonentList(ct string &_FIO, ct string &_number_of_phone, ct float &_balance, ct string &_street, ct short &_number_of_home, ct short &_number_of_apart)
{
    abonent = new Abonent(_FIO, _number_of_phone, _balance, _street, _number_of_home, _number_of_apart);
    next = nullptr;
}
AbonentList::AbonentList(const Abonent &object)
{
    abonent = new Abonent;
    *abonent = object;
    next = nullptr;
}
ostream &operator<<(ostream &stream, const AbonentList &object)
{
    stream << *object.abonent;
    return stream;
}
void AbonentList::push_back(const Abonent &object)
{
    if (abonent->get_FIO() == my_undefined)
    {
        abonent->set_info(object);
    }
    else
    {
        AbonentList *last = this;
        while (last->next != nullptr)
            last = last->next;

        AbonentList *p = new AbonentList(object);
        last->next = p;
    }
}
void AbonentList::delAfterThis()
{
    AbonentList *p = next;
    next = p->next;
    delete p;
}
void AbonentList::clear()
{
    while (next != nullptr)
        delAfterThis();
}
AbonentList::~AbonentList()
{
    delete abonent;
    abonent = nullptr;
    // delete next;
    next = nullptr;
}
void AbonentList::print() const
{
    const AbonentList *p = this;
    while (p != nullptr)
    {
        cout << *p << '\n';
        p = p->get_next();
    }
}
void AbonentList::print_until_this_balance(const float &_balance) const
{
    const AbonentList *p = this;
    while (p != nullptr && p->abonent->get_balance() <= _balance)
    {
        cout << *p << '\n';
        p = p->get_next();
    }
}
