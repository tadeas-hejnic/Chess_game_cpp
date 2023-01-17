/**
 * @author Tadeáš Hejnic <hejnitad@fit.cvut.cz>
 * @date 22.05.2022
 */

#include "CBoard.h"
#include "../Builders/CBoardLoader.h"
#include "../Builders/CBoardGenerator.h"
#include "../Chessman/CChessman.h"

#include <iostream>

#define WHITE_B "\033[40m"
#define BLACK_B "\033[0;100m"
#define RESET "\033[m"

using namespace std;

CBoard::CBoard ( ) {
    m_turn = STATE::ONE;

    for ( int i = constants::B_BEGIN; i < constants::B_END; i++ )
        for ( int j = constants::B_BEGIN; j < constants::B_END; j++ )
            m_fields [ i ][ j ] = CBoardGenerator::newField ( { i, j } );

    m_check = false;
}

CBoard::CBoard ( bool ) {
    string data;
    if ( ! CBoardLoader::loadFile ( data ) )
        throw runtime_error ( "Error. Issue with file data." );

    int pos = 0;
    for ( int i = constants::B_BEGIN; i < constants::B_END; i++ )
        for ( int j = constants::B_BEGIN; j < constants::B_END; j++ ) {
            m_fields [ i ][ j ] = CBoardLoader::loadField ( data, pos );
            pos++;
        }

    m_turn = CBoardLoader::loadTurn ( data [ pos ] );
    m_check = false;
}

// simplify?
void CBoard::printBoard ( ) const {
    cout << string ( 28, '-' ) << "\n" << endl;

    // A-F
    cout << "    ";
    for ( int i = 'A'; i <= 'H'; i++ )
        cout << char ( i ) << string ( 2, ' ' );

    cout << endl;

    for ( int i = constants::B_BEGIN; i < constants::B_END; i++ ) {
        cout << " " << i + 1 << " ";   // 1-8

        // deck
        for ( int j = constants::B_BEGIN; j < constants::B_END; j++ ) {
            if ( ( j + i ) % 2 == 1 ) {
                cout << BLACK_B << " ";
                if ( m_fields [ i ] [ j ] . m_state != STATE::EMPTY )
                    cout << *m_fields [ i ] [ j ] . m_chessman;
                else
                    cout << " ";

                cout << " " << RESET;
            } else {
                cout << WHITE_B << " ";
                if ( m_fields [ i ] [ j ] . m_state != STATE::EMPTY )
                    cout << *m_fields [ i ] [ j ] . m_chessman;
                else
                    cout << " ";
                cout << " " << RESET;
            }
        }
        cout << " " << i + 1;   // 1-8
        cout << endl;
    }
    // A-F
    cout << "    ";
    for ( int i = 'A'; i <= 'H'; i++ )
        cout << char ( i ) << string ( 2, ' ' );

    cout << endl;
}

// DONE
STATE CBoard::getTurn ( bool opposite ) const {
    if ( opposite ) {
        if ( m_turn == STATE::ONE ) return STATE::TWO;
        else return STATE::ONE;
    } else return m_turn;
}

// DONE
void CBoard::switchTurn() {
    if ( m_turn == STATE::ONE ) m_turn = STATE::TWO;
    else m_turn = STATE::ONE;
}

// DONE
void CBoard::make_move ( std::pair < int, int > start, std::pair < int, int > target ) {
    if ( m_fields [ target . first ][ target . second ] . m_state == STATE::EMPTY
      && m_fields [ start  . first ][ target . second ] . en_passant
      && m_fields [ start . first ][ start . second ] . m_chessman -> enPassant () ) {
        m_fields [ start . first ][ target . second ] = CField ();
    }
    m_fields [ target . first ][ target . second ] = m_fields [ start . first ][ start . second ];
    m_fields [ start  . first ][ start  . second ] = CField ();
}

// DONE
bool CBoard::validPosition ( const std::pair < int, int > pos ) const {
    if ( ! checkPosition ( pos )
        || m_fields [ pos . first ][ pos . second ] . m_state != m_turn )
        return false;

    return true;
}

bool CBoard::validTarget ( const std::pair < int, int > pos, bool pawn ) const {

    if ( ! checkPosition ( pos ) )
        return false;

    if ( pawn && m_fields [ pos.first ][ pos.second ] . m_state != STATE::EMPTY )
        return false;

    if ( ! pawn && m_fields [ pos . first ][ pos . second ] . m_state == m_turn )
        return false;

    return true;
}

bool CBoard::checkPosition ( std::pair < int, int > in ) {

    if ( in . first  < constants::B_BEGIN || in . first  >= constants::B_END
      || in . second < constants::B_BEGIN || in . second >= constants::B_END )
        return false;

    return true;
}
