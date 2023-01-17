/**
 * @author Tadeáš Hejnic <hejnitad@fit.cvut.cz>
 * @date 23.05.2022
 */

#include "CKing.h"
#include "../Game/CRules.h"

#include <iostream>

using namespace std;

CKing::CKing ( STATE player, bool played ) : CChessman ( player, played ) {
    if ( player == STATE::ONE )
        m_save = constants::CHAR_KING;
    else
        m_save = tolower ( constants::CHAR_KING );
}

std::ostream & CKing::print ( std::ostream & os ) const {
    if ( m_player == STATE::ONE )
        return os << WHITE << std::string ( S_KING );
    else
        return os << BLACK << std::string ( S_KING );
}

std::set < std::pair < int, int > > CKing::possibleMoves ( const CBoard & board, pair < int, int > pos, bool check ) {
    set < pair < int, int > > p_moves;
    pair < int , int > tmp;
    int l = pos . first;
    int n = pos . second;

    // check all 8 positions next to current
   for ( auto dir : all_DIR ) {
       tmp = { pos . first + directionValues ( dir ) . first, pos . second + directionValues ( dir ) . second };
       if ( board . validTarget ( tmp ) )
           p_moves . insert ( tmp );
   }

    // castling
    bool left = true, right = true;
    if ( ! board . m_check && ! board . m_fields [ pos . first ][ pos . second ] . m_chessman -> m_played) {
        castlingPossible ( board, pos, left, right );
        tmp = { l, n - 2 };
        if ( left )
            p_moves . insert ( tmp );

        tmp = { l, n + 2 };
        if ( right )
            p_moves . insert ( tmp );
    }

    if ( check )
        CRules::checkMoves ( board, pos, p_moves );

    return p_moves;
}

void CKing::castlingPossible ( const CBoard & board, pair < int, int > pos, bool & left, bool & right ) {

// check if fields are empty
    for ( int i = pos . second + 1; i < constants::R_ROOK; i++ )
        if ( board . m_fields [ pos . first ][ i ] . m_state != STATE::EMPTY ) {
            right = false;
        }

    for ( int i = pos . second - 1; i > constants::L_ROOK; i-- )
        if ( board . m_fields [ pos . first ][ i ] . m_state != STATE::EMPTY )
            left = false;

    pair < int, int > rook;
    rook . first = playerRook ( board );
    rook . second = constants::L_ROOK;

    rookCheck ( board, rook, left );

    rook . second = constants::R_ROOK;
    rookCheck ( board, rook, right );

    if ( left )
        if ( CRules::possibleCheck ( board, pos, { pos . first, pos . second - 1 } ) )
            left = false;

    if ( right )
        if ( CRules::possibleCheck ( board, pos, { pos . first, pos . second + 1 } ) )
            right = false;

}

void CKing::rookCheck ( const CBoard & board, const pair< int, int > position, bool & side ) {
    if ( board . m_fields [ position . first ][ position . second ] . m_state != board . getTurn()
     || ! board . m_fields [ position . first ][ position . second ] . m_chessman -> isPartCastling ()
     || board . m_fields [ position . first ][ position . second ] . m_chessman -> m_played )
        side = false;
}

bool CKing::castling () const {
    return true;
}

bool CKing::inCheck() const {
    return true;
}

int CKing::getRank () const {
    return KING;
}

int CKing::playerRook ( const CBoard & board ) {
    if ( board . getTurn () == STATE::ONE )
        return constants::PLAYER_ONE_SECOND;
    else
        return constants::PLAYER_TWO_SECOND;
}
