/**
 * @author Tadeáš Hejnic <hejnitad@fit.cvut.cz>
 * @date 23.05.2022
 */

#include "CKnight.h"
#include "../Game/CRules.h"
#include <iostream>


const std::vector< std::pair< int, int > > CKnight::KNIGHT_MOVES = {
        { -2, -1 }, { -1, -2 }, { 1, -2 }, { 2, -1 },
        { 2, 1 }, { 1, 2 }, { -1, 2 }, { -2, 1 }
};

using namespace std;

CKnight::CKnight ( STATE player, bool played ) : CChessman ( player, played ) {
    if ( player == STATE::ONE )
        m_save = constants::CHAR_KNIGHT;
    else
        m_save = tolower ( constants::CHAR_KNIGHT );
}

std::ostream & CKnight::print ( std::ostream & os ) const {
    if ( m_player == STATE::ONE )
        return os << WHITE << string ( S_KNIGHT );
    else
        return os << BLACK << string ( S_KNIGHT );
}

std::set<std::pair<int, int> > CKnight::possibleMoves ( const CBoard & board, std::pair < int, int > pos, bool check ) {
    set < pair < int, int > > p_moves;

    for ( auto move : KNIGHT_MOVES ) {
        pair < int , int > tmp = { pos . first + move . first, pos . second + move . second };
        if ( board . validTarget ( tmp ) )
            p_moves . insert ( tmp );
    }

    if ( check )
        CRules::checkMoves( board, pos, p_moves );

    return p_moves;
}

int CKnight::getRank() const {
    return KNIGHT;
}
