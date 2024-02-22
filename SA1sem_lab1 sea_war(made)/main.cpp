#include "class.hpp"

int main()
{
    system("mode con cols=80 lines=45");
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(65001);
    SeaWar game;
    game.play_game();
    _getch();
}