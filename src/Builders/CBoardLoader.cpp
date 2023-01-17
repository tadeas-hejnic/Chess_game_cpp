/**
 * @author Tadeáš Hejnic <hejnitad@fit.cvut.cz>
 * @date 01.06.2022
 */

#include "CBoardLoader.h"
#include "../Application/Constants.h"
#include "../Application/CMenu.h"
#include "../Chessman/CPawn.h"
#include "../Chessman/CRook.h"
#include "../Chessman/CKnight.h"
#include "../Chessman/CBishop.h"
#include "../Chessman/CQueen.h"
#include "../Chessman/CKing.h"
#include <fstream>

using namespace std;

CField CBoardLoader::loadField ( const std::string & data, int & i ) {

    bool en_passant = loadBool ( data [ i++ ] );
    bool played = loadBool (  data [ i++ ]  );

    STATE player = STATE::ONE;

    if ( islower ( data [ i ] ) )
        player = STATE::TWO;

    switch ( toupper ( data [ i ] ) ) {
        case constants::CHAR_PAWN:
            return { player, make_shared< CPawn >( CPawn ( player, played ) ), en_passant };

        case constants::CHAR_ROOK:
            return { player, make_shared< CRook >( CRook ( player, played ) ), en_passant };

        case constants::CHAR_KNIGHT:
            return { player, make_shared< CKnight >( CKnight ( player, played ) ), en_passant };

        case constants::CHAR_BISHOP:
            return { player, make_shared< CBishop >( CBishop ( player, played ) ), en_passant };

        case constants::CHAR_QUEEN:
            return { player, make_shared< CQueen >( CQueen ( player, played ) ), en_passant };

        case constants::CHAR_KING:
            return { player, make_shared< CKing >( CKing ( player, played ) ), en_passant };

        case constants::CHAR_EMPTY:
            return {};

        default:
            throw runtime_error ( "Unknown sign." );
    }
}

bool CBoardLoader::loadFile ( string & data ) {
    string file_name;
    if ( ! CMenu::printLoad ( file_name ) )
        return false;
    ifstream f ( file_name );

// doesn't exist, ...
    if ( f . fail () )
        return false;

// while not error / EOF
    char c;
    while ( f . get ( c ) ) {
        data += c;
        if ( data . size () > constants::SAVE_SIZE )
            return false;
    }

// check of eof at the end of the file
    if ( ! f . eof () ) {
        f . close ();
        return false;
    }

    f . close ();

    if ( checkFile ( data ) )
        return true;
    else
        return false;
}

STATE CBoardLoader::loadTurn ( char turn ) {
    if ( turn == constants::TURN_ONE ) return STATE::ONE;
    else if ( turn == constants::TURN_TWO ) return STATE::TWO;
    else throw runtime_error ( "Wrong input." );
}

bool CBoardLoader::loadBool ( char load ) {
    if ( load == constants::CHAR_TRUE ) return true;
    else if ( load == constants::CHAR_FALSE ) return false;
    else throw runtime_error ( "Unknown sign." );
}

bool CBoardLoader::checkFile ( const string & data ) {
    if ( data . size () != constants::SAVE_SIZE )
        return false;

    int one = 0, two = 0, empty = 0, king1 = 0, king2 = 0;
    for ( char i : data ) {
        if ( islower ( i ) && i != constants::CHAR_EMPTY ) {
            two++;
            if (toupper ( i ) == constants::CHAR_KING )
                king2++;
        }
        else if ( isupper ( i ) && i != constants::CHAR_EMPTY ) {
            if ( toupper ( i ) == constants::CHAR_KING )
                king1++;
            one++;
        } else if ( i == constants::CHAR_EMPTY ) empty++;
    }

    if ( one > constants::MAX || two > constants::MAX
    || ( one + two + empty ) != ( constants::B_END * constants::B_END )
    || king1 != constants::NUM_OF_KING || king2 != constants::NUM_OF_KING )
        return false;

    return true;
}


