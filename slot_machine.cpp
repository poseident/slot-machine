#include <ctime>
#include <cstdlib>
#include <iostream>
#include <string>

#ifndef COLOR
# define COLOR

# define CLEAR		"\x1B[2J\x1B[H"
# define F_NONE		"\033[0;37m"
# define RED		"\033[1;31m"
# define GREEN		"\033[1;32m"
# define CYANE		"\033[1;36m"
# define F_BOLD		"\033[1m"
# define PURPLE      "\033[1;35m" 	
# define F_YELLOW	"\033[1;33m"
# define F_BLUE		"\033[34m" 

#endif

int main(void)
{
    int win = 0;
    srand( time( NULL ) );
    int spin = 100000;
    int result = 0;
    int count = 0;
    std::string input;
    std::cout << "Welcome in the slot machine" << std::endl;
    std::cout << "if you get 3 same numbers you win" << std::endl;
    std::cout << "enter 1 to spin and anything else to quit" << std::endl;
    std::cin >> input;
    while (input == "1")
    {
        spin = 100000;
        while (spin > 0)
        {
            count = 0;
            while (count < 3)
            {
                result = rand() % ( 3 - 0 ) + 0;
                int color = rand() % ( 5 - 0 ) + 0;
                switch(color)
                {
                    case 0: std::cout << PURPLE; break;
                    case 1: std::cout << F_BLUE; break;
                    case 2: std::cout << GREEN; break;
                    case 3: std::cout << F_YELLOW; break;
                    case 4: std::cout << RED; break;
                }
                std::cout << "  " << result;
                count++;
            }
            spin--;
            std::cout << F_NONE << std::endl;
        }
        std::cout << "___________" << std::endl;
        result = rand() % ( 3 - 0 ) + 0;
        int a = rand() % ( 3 - 0 ) + 0;
        int b = rand() % ( 3 - 0 ) + 0;
        if (result == a && result == b)
        {
            std::cout << GREEN;
            win = 1;
        }
        else
            std::cout << RED;
        std::cout << "  " << result;
        std::cout << "  " << a;
        std::cout << "  " << b << F_NONE << std::endl;
        if (win == 1)
            std::cout << "You win !" << std::endl;
        else
            std::cout << "You lost.." << std::endl;
        std::cout << "enter 1 to spin or anything else to quit" << std::endl;
        std::cin >> input;
    }
    return (0);
}