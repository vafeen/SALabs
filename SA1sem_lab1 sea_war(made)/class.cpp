#include "class.hpp"
// инициализатор ячейки поля
Pole::Pole()
{
    symbol = CHAR_OF_POLE;

    next = nullptr;
}

// деструктор для очистки поля
Pole::~Pole()
{
    
}

// создание поля
void Pole::createPole(size_t size)
{
    Pole *p = this;

    for (size_t i = 0; i < size - 1; i++)
    {
        Pole *new_pole = new Pole;

        p->next = new_pole;

        p = p->next;
    }
}

// вычисление размера поля
size_t Pole::size()
{
    Pole *p = this;

    size_t size = 0;

    while (p != nullptr)
    {
        size += 1;

        p = p->next;
    }
    return size;
}

// геттер для [i][j] элемента поля
char Pole::get_ij(size_t i, size_t j)
{
    size_t number = i * SIZE_OF_POLE + j;
    Pole *p = this;
    for (size_t i = 0; i < number; i++)
        p = p->next;
    return p->symbol;
}

// сеттер для [i][j] элемента поля
void Pole::set_ij(size_t i, size_t j, char symbol)
{
    size_t number = i * SIZE_OF_POLE + j;
    Pole *p = this;
    for (size_t i = 0; i < number; i++)
        p = p->next;
    p->symbol = symbol;
}

// геттер символа ячейки поля
char Pole::get_symbol()
{
    return symbol;
}

// геттер поля next
Pole *Pole::get_next()
{
    return next;
}

// //проверка головы на пустоту
// bool Pole::isEmpty(Pole *head)
// {
//     return head == nullptr;
// }

// //удалить голову
// void Pole::deleteFromHead(Pole *&head)
// {
//     Pole *p = head;
//     head = head->next;
//     p->next = nullptr;
//     delete p;
//     p = nullptr;
// };

// //очистка списка с головы
// void Pole::clear(Pole *&head)
// {
//     while (!isEmpty(head))
//     {
//         deleteFromHead(head);
//     }
// };

void Pole::clear()
{
    while (next != nullptr)
        deleteAfterNode();
}
void Pole::deleteAfterNode()
{
    Pole *p = next;
    next = p->next;
    p->next = nullptr;
    delete p;
    p = 0;
};

// вывод двух параллельных полей
void SeaWar::print2pole(Pole *pole1, Pole *pole2)
{
    string koords = "X\\Y 0-1-2-3-4-5-6-7-8-9->";

    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);

    Pole *p1 = pole1;

    Pole *p2 = pole2;

    short color1, color2;

    if (punch == OneToTo)
    {
        color1 = COLOR_PUNCH;
        color2 = COLOR_BLOCK;
    }
    else
    {
        color1 = COLOR_BLOCK;
        color2 = COLOR_PUNCH;
    }

    SetConsoleTextAttribute(handle, color1);

    cout << koords;

    print_probels(KOORDS_TAG);

    SetConsoleTextAttribute(handle, color2);

    cout << koords + '\n';

    for (size_t i = 0; i < SIZE_OF_POLE; i++)
    {
        SetConsoleTextAttribute(handle, color1);

        cout << " " << i << "  ";

        for (size_t j = 0; j < SIZE_OF_POLE; j++)
        {
            cout << p1->get_symbol() << ' ';

            p1 = p1->get_next();
        }
        SetConsoleTextAttribute(handle, color2);

        print_probels(POLE_TAG);

        cout << " " << i << "  ";

        for (size_t j = 0; j < SIZE_OF_POLE; j++)
        {
            cout << p2->get_symbol() << ' ';

            p2 = p2->get_next();
        }
        cout << '\n';
    }
    cout << "\n";
    SetConsoleTextAttribute(handle, MYCOLOR_WHITE);
}

// вывод 4х полей(попарно 2 раза)
void SeaWar::print4pole()
{
    HANDLE hwnd = GetStdHandle(STD_OUTPUT_HANDLE);

    short color1, color2;

    if (punch == OneToTo)
    {
        color1 = COLOR_PUNCH;

        color2 = COLOR_BLOCK;
    }
    else
    {
        color1 = COLOR_BLOCK;

        color2 = COLOR_PUNCH;
    }

    system("cls");

    SetConsoleTextAttribute(hwnd, color1);

    print_probels(TAGS_FOR_MEDIUM_NAME);

    cout << str_player1;

    print_probels(NAME_TAG);

    SetConsoleTextAttribute(hwnd, color2);

    print_probels(TAGS_FOR_MEDIUM_NAME);

    cout << str_player2 << '\n';

    print2pole(player1.get_plans(), player2.get_plans());

    print2pole(player1.get_ships(), player2.get_ships());
}

// имена героев и тип удара
SeaWar::SeaWar()
{
    punch = OneToTo;
    player1.set_name(str_player1);
    player2.set_name(str_player2);
}

// вспомагательная функция вывода
void SeaWar::print_probels(size_t number)
{
    for (size_t i = 0; i < number; i++)
        cout << ' ';
}

// основная функция игры
void SeaWar::play_game()
{
    bool success = false;
    player1.take_ships_to_sea();

    player2.take_ships_to_sea();
    cout << "\nНачинает первый игрок!";

    while (player1.get_balance_of_ships() > 0 && player2.get_balance_of_ships() > 0)
    {
        print4pole();
        if (punch == OneToTo)
            success = fight(player1, player2);
        else
            success = fight(player2, player1);
        if (!success)
            swapTypeOfPunch();
    }
    system("cls");
    cout << "\n\nВЫИГРЫВАЕТ ";
    if (player1.get_balance_of_ships() != 0)
        cout << player1.get_name();
    else
        cout << player2.get_name();
    cout << "\n\nИГРАОКОНЧЕНА!\n\n\n";
}

// ввод координат удара, проверка возможности и ?проведение удара
bool SeaWar::fight(SeaWarPlayer &fighter, SeaWarPlayer &blocker)
{
    cout << "Введите координаты удара!\n->";
    size_t x, y;
    bool true_operation = false;
    do
    {
        blocker.CleverGetChar(x, y);
        if (blocker.get_ships_ij(x, y) == CHAR_OF_BOMB || blocker.get_ships_ij(x, y) == CHAR_OF_FREE_FIRE)
        {
            cout << "\nЯдерный удар в эту точку невозможен, там нет живого места!\nВыберите другую точку ->";
        }
    } while (blocker.get_ships_ij(x, y) == CHAR_OF_BOMB || blocker.get_ships_ij(x, y) == CHAR_OF_FREE_FIRE);
    if (blocker.get_ships_ij(x, y) == CHAR_OF_CHIP)
    {
        blocker.set_ships_ij(x, y, CHAR_OF_BOMB);
        fighter.set_plans_ij(x, y, CHAR_OF_BOMB);
        blocker.reduce_the_balance_of_ships();
        true_operation = true;
    }
    else if (blocker.get_ships_ij(x, y) == CHAR_OF_POLE)
    {
        blocker.set_ships_ij(x, y, CHAR_OF_FREE_FIRE);
        fighter.set_plans_ij(x, y, CHAR_OF_FREE_FIRE);
        true_operation = false;
    }
    return true_operation;
}

// изменение типа удара(по сути, смена ролей)
void SeaWar::swapTypeOfPunch()
{
    if (punch == OneToTo)
        punch = ToToOne;
    else
        punch = OneToTo;
}

// геттер имени игрока
string SeaWarPlayer::get_name()
{
    return name;
}

// уменьшение счетчика "живых" клеток с кораблями
void SeaWarPlayer::reduce_the_balance_of_ships()
{
    ostatok_size_ships -= 1;
}

// геттер для счетчика "живых" клеток с кораблями
size_t SeaWarPlayer::get_balance_of_ships()
{
    return ostatok_size_ships;
}

// геттер поля планов
Pole *SeaWarPlayer::get_plans()
{
    return plans;
}

// геттер поля кораблей
Pole *SeaWarPlayer::get_ships()
{
    return ships;
}

// деструктор для очистки полей игрока
SeaWarPlayer::~SeaWarPlayer()
{
    plans->clear();
    ships->clear();
}
// сеттер имени игрока
void SeaWarPlayer::set_name(string _name)
{
    name = _name;
}

// создание поля
SeaWarPlayer::SeaWarPlayer()
{
    plans = new Pole;

    ships = new Pole;

    plans->createPole(SIZE_OF_POLE * SIZE_OF_POLE);

    ships->createPole(SIZE_OF_POLE * SIZE_OF_POLE);

    ostatok_size_ships = 20;
}

// вывод доски планов для задания кораблей
void SeaWarPlayer::print_ships()
{
    Pole *p = ships;

    if (p->size() != 0)
    {
        system("cls");

        cout << "X\\Y 0-1-2-3-4-5-6-7-8-9->\n";

        for (size_t i = 0; i < SIZE_OF_POLE; i++)
        {
            cout << " " << i << "  ";

            for (size_t j = 0; j < SIZE_OF_POLE; j++)
            {
                cout << p->get_symbol() << ' ';

                p = p->get_next();
            }
            cout << '\n';
        }
        cout << " V\n";
    }
}

// задание кораблей
void SeaWarPlayer::take_ships_to_sea()
{
    short number_of_ships = 1;
    for (size_t number_of_type_ship = 4; number_of_type_ship > 0; number_of_type_ship--)
    {

        for (short j = 0; j < number_of_ships; j++)
        {
            print_ships();
            vector<Koords> one_ship_koords;
            Koords koords;
            cout << "\n"
                 << number_of_type_ship << "-МЕСТНЫЕ КОРАБЛИ( " << number_of_ships << " ):\n";
            cout << "КОРАБЛЬ № " << j + 1 << '\n';

            cout << "Нажмите " << number_of_type_ship << " пары координат по либо (сверху вниз/слева направо) по точкам корабля\n--->";
            do
            {
                one_ship_koords.clear();
                for (size_t i_koords = 0; i_koords < number_of_type_ship; i_koords++)
                {
                    CleverGetChar(koords.x, koords.y);

                    one_ship_koords.push_back(koords);
                }
                // добавляем координаты введенного корабля на доску
            } while (!take_koords_of_one_ship_to_pole(one_ship_koords));
        }
        number_of_ships += 1;
    }
}

// проверка корректности координат и добавление на поле планов и кораблей
bool SeaWarPlayer::take_koords_of_one_ship_to_pole(const vector<Koords> &koords)
{
    bool f = true;
    if (!true_koords(koords))
        return false;
    for (size_t i = 0; i < koords.size(); i++)
    {
        // смотрим, не поставили ли мы корабль на корабль
        if (ships->get_ij(koords[i].x, koords[i].y) == CHAR_OF_CHIP)
        {
            f = false;
            cout << "\nНа координатах: |" << koords[i].x << " , " << koords[i].y << "| уже стоит корабль!\nПовторите ввод координат корабля!\n-->";
            break;
        }
    }
    if (f)
    {
        // если нет бутерброда "два корабля друг на друге", то выставляем корабль
        for (size_t i = 0; i < koords.size(); i++)
            ships->set_ij(koords[i].x, koords[i].y, CHAR_OF_CHIP);
    }
    return f;
}

// умный ввод координат
void SeaWarPlayer::CleverGetChar(size_t &koord_x, size_t &koord_y)
{
    char key;
    do
    {
        key = _getch();
    } while (!('0' <= key && key <= '9'));
    koord_x = key - '0';
    cout << "( " << key << ", ";
    do
    {
        key = getch();
    } while (!('0' <= key && key <= '9'));
    koord_y = key - '0';
    cout << key << " ); ";
}

// проверка координат на соответствие координатамкорабля: ((0,0),(0,1),(0,2)) а не ((1,0),(5,0),(2,0))
bool SeaWarPlayer::true_koords(const vector<Koords> &Koords)
{
    size_t x_koord = Koords[0].x, y_koord = Koords[0].y;
    string error_message = "\nОшибка ввода координат! Повторите ввод\n-->";
    bool x_true = 1, y_true = 1;
    if (Koords.size() > 1)
    {
        for (size_t i = 1; i < Koords.size(); i++)
        {
            if (x_koord != Koords[i].x)
                x_true = 0;
            if (y_koord != Koords[i].y)
                y_true = 0;
        }
        // проверка горизонтальных кораблей на существование
        // чтобы координаты составляли корабль, типо (1 3) (1 4) (1 5), а не 1 3 1 4 1 9
        if (y_true && (Koords.size() > 1))
        {
            for (size_t i = 0; i < Koords.size() - 1; i++)
            {
                if (Koords[i].x + 1 != Koords[i + 1].x)
                {
                    cout << error_message;
                    return 0;
                }
            }
        }
        // проверка вертикальных кораблей
        else if (x_true && (Koords.size() > 1))
        {
            for (size_t i = 0; i < Koords.size() - 1; i++)
            {
                if (Koords[i].y + 1 != Koords[i + 1].y)
                {
                    cout << error_message;
                    return 0;
                }
            }
        }
        if ((x_true && y_true) == 0 && (x_true || y_true) == 1)
            return 1;
        cout << error_message;
        return 0;
    }
    // cout << error_message;
    return 1;
}

// геттер ячейки поля планов
void SeaWarPlayer ::set_plans_ij(size_t i, size_t j, char symbol)
{
    plans->set_ij(i, j, symbol);
}

// сеттер ячейки поля кораблей
void SeaWarPlayer ::set_ships_ij(size_t i, size_t j, char symbol)
{
    ships->set_ij(i, j, symbol);
}

// геттер ячейки поля планов
char SeaWarPlayer::get_plans_ij(size_t i, size_t j)
{
    return plans->get_ij(i, j);
}

// геттер ячейки поля кораблей
char SeaWarPlayer::get_ships_ij(size_t i, size_t j)
{
    return ships->get_ij(i, j);
}
