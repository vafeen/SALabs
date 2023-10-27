#include <iostream>
#include <conio.h>
#include <vector>
#include <Windows.h>
#include <string>

#define MYCOLOR_BLACK 0
#define MYCOLOR_BLUE 1
#define MYCOLOR_GREEN 2
#define MYCOLOR_RED 4
#define MYCOLOR_BROWN 6
#define MYCOLOR_GRAY 8
#define MYCOLOR_LIGHT_BLUE 9
#define MYCOLOR_LIGHT_GREEN 10
#define MYCOLOR_LIGHT_RED 12
#define MYCOLOR_YELLOW 6
#define MYCOLOR_WHITE 15

using namespace std;

// технические параметры
const short COLOR_PUNCH = MYCOLOR_GREEN, COLOR_BLOCK = MYCOLOR_BLACK;
const char CHAR_OF_CHIP = 'S', CHAR_OF_BOMB = 'X', CHAR_OF_POLE = '~', CHAR_OF_FREE_FIRE = 'o';
const size_t SIZE_OF_POLE = 10,
             KOORDS_TAG = 30,
             POLE_TAG = KOORDS_TAG + 1,
             NAME_TAG = POLE_TAG + 3,
             TAGS_FOR_MEDIUM_NAME = 8;

// изменяемые параметры пользователя
const string str_player1 = "PLAYER1", str_player2 = "PLAYER2";

struct Koords
{
    size_t x;
    size_t y;
};

enum type_of_punch
{
    OneToTo,
    ToToOne
};

class Pole
{
    char symbol;
    Pole *next;
    ~Pole();

public:
    size_t size();
    bool isEmpty(Pole *head);
    void deleteFromHead(Pole *&head);
    void clear();
    void deleteAfterNode();
    Pole *get_next();
    char get_symbol();
    void createPole(size_t size);
    char get_ij(size_t i, size_t j);
    void set_ij(size_t i, size_t j, char symbol);
    Pole();
};

class SeaWarPlayer
{

    string name;
    short color;
    Pole *plans, *ships;
    // сколько раз осталось попасть
    size_t ostatok_size_ships;

public:
    void set_name(string _name);
    string get_name();
    void print_ships();
    Pole *get_plans();
    void set_plans_ij(size_t i, size_t j, char symbol);
    char get_plans_ij(size_t i, size_t j);

    Pole *get_ships();
    void set_ships_ij(size_t i, size_t j, char symbol);
    char get_ships_ij(size_t i, size_t j);
    void reduce_the_balance_of_ships();
    size_t get_balance_of_ships();
    void take_ships_to_sea();
    void CleverGetChar(size_t &koord_x, size_t &koord_y);

    SeaWarPlayer();
    ~SeaWarPlayer();
    bool take_koords_of_one_ship_to_pole(const vector<Koords> &koords);
    bool true_koords(const vector<Koords> &Koords);
};

class SeaWar
{
    SeaWarPlayer player1, player2;
    type_of_punch punch;

public:
    void print2pole(Pole *pole1, Pole *pole2);
    void print4pole();
    void play_game();
    void print_probels(size_t number);
    bool fight(SeaWarPlayer &fighter, SeaWarPlayer &blocker);
    void swapTypeOfPunch();
    SeaWar();
};