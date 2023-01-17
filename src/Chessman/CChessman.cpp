/**
 * @author Tadeáš Hejnic <hejnitad@fit.cvut.cz>
 * @date 23.05.2022
 */

#include "CChessman.h"
#include <iostream>

using namespace std;

CChessman::CChessman ( STATE player, bool played ) {
    m_player = player;
    m_played = played;
}

std::pair < int, int > CChessman::directionValues ( DIR dir ) {
    switch ( dir ) {
        case DIR::UP:
            return {-1, 0 };
        case DIR::DOWN:
            return { 1, 0 };
        case DIR::LEFT:
            return { 0, -1 };
        case DIR::RIGHT:
            return { 0, 1 };
        case DIR::UPLEFT:
            return { -1, -1 };
        case DIR::UPRIGHT:
            return { -1, 1 };
        case DIR::DOWNLEFT:
            return { 1, -1 };
        case DIR::DOWNRIGHT:
            return { 1, 1 };
        default:
            return {};
    }
}

void CChessman::discoverFields ( DIR dir, const CBoard & board, std::pair < int, int > position, set< std::pair < int, int > > & p_moves ) const {
    int i = position . first;
    int j = position . second;
    pair < int, int > direction = directionValues ( dir );

    while ( true ) {
        i += direction . first;
        j += direction . second;

        if  ( board . m_fields [ i ][ j ] . m_state == board . getTurn ()
              || !( board . validTarget ( { i, j } ) ) )
            break;

        else if ( board . m_fields [ i ][ j ] . m_state == STATE::EMPTY )
            p_moves.insert ( { i, j } );

        else {
            p_moves . insert ( { i,  j } );
            break;
        }
    }
}

// NO COMMENTS NEEDED
// ---------------------------------------
bool CChessman::castling () const {
    return false;
}

bool CChessman::promotion() const {
    return false;
}

std::ostream & operator << ( ostream & os, const CChessman & chessman ) {
    return chessman . print ( os );
}

bool CChessman::inCheck() const {
    return false;
}

std::ostream & CChessman::save ( ostream & os ) const {
    return os << m_save;
}

bool CChessman::enPassant() const {
    return false;
}

bool CChessman::dontMoveEarly() const {
    return false;
}

bool CChessman::isPartCastling() const {
    return false;
}

