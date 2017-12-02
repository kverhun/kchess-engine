#include <iostream>
#include <string>

namespace 
{
    void _PrintBoard()
    {
        const std::string g_pawn_str = "pppppppp";
        const std::string g_piece_str = "RNBKQNPR";
        const std::string g_blank_str = "--------";
        std::cout << g_piece_str << '\n'
                  << g_pawn_str  << '\n'
                  << g_blank_str << '\n'
                  << g_blank_str << '\n'
                  << g_blank_str << '\n'
                  << g_blank_str << '\n'
                  << g_pawn_str  << '\n'
                  << g_piece_str << '\n';
    }
}

int main(int i_argc, char** ip_argv)
{
    _PrintBoard();
    return 0;
}