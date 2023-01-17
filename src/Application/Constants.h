/**
 * @author Tadeáš Hejnic <hejnitad@fit.cvut.cz>
 * @date 01.06.2022
 */

#pragma once
#include <string>

#define PATH_EXAMPLES "../hejnitad/examples/"

#define PLAYER_ONE "player ONE"
#define PLAYER_TWO "player TWO"
#define ON_TURN " is on turn..."


#define WHITE "\033[1;97m"
#define BLACK "\033[1;93m"

class constants {
public:
    /** CMenu **/
    static const char NEW_GAME  = 'N';
    static const char LOAD_GAME = 'L';
    static const char QUIT_GAME = 'Q';

    // game modes
    static const char M_TWO_PLAYERS = '2';
    static const char M_BEGINNER    = 'B';
    static const char M_PRO         = 'P';
    static const char M_LEGEND      = 'L';

    /** CRules **/
    static const int EN_PASSANT = 2;
    static const int PROMOTION_LINE_1 = 0;
    static const int PROMOTION_LINE_2 = 7;
    static const int CASTLING_LEFT = 2;
    static const int CASTLING_RIGHT = -2;

    static const int B_BEGIN = 0;
    static const int B_END = 8;

    static const int PLAYER_ONE_FIRST = 6;
    static const int PLAYER_ONE_SECOND = 7;
    static const int PLAYER_TWO_FIRST = 1;
    static const int PLAYER_TWO_SECOND = 0;

    static const int L_ROOK = 0;
    static const int L_KNIGHT = 1;
    static const int L_BISHOP = 2;
    static const int QUEEN = 3;
    static const int KING = 4;
    static const int R_BISHOP = 5;
    static const int R_KNIGHT = 6;
    static const int R_ROOK = 7;


    /** CBoard generators **/
    static const size_t SAVE_SIZE = ( ( B_END * B_END ) * 3 ) + 1;    // 3 -> 3 chars for each field, 1 -> m_turn
    static const char CHAR_ROOK = 'R';
    static const char CHAR_KNIGHT = 'N';
    static const char CHAR_BISHOP = 'B';
    static const char CHAR_QUEEN = 'Q';
    static const char CHAR_KING = 'K';
    static const char CHAR_PAWN = 'P';
    static const char CHAR_EMPTY = 'E';

    static const int MAX = 16;

    static const char TURN_ONE = '1';
    static const char TURN_TWO = '2';

    static const char CHAR_TRUE = '1';
    static const char CHAR_FALSE = '0';

    static const char YES = 'y';
    static const char NO = 'n';

    static const int NUM_OF_KING = 1;

    /** Promotion **/
    static const int QUEEN_CHOICE = 1;
    static const int ROOK_CHOICE = 2;
    static const int BISHOP_CHOICE = 3;
    static const int KNIGHT_CHOICE = 4;

    static const int NUM_OF_PROMOTION = 4;

    /** Pawn **/
    static const int OPPOSITE_1 = 2;
    static const int OPPOSITE_2 = 4;
};


