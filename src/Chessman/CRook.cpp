/**
 * @author Tadeáš Hejnic <hejnitad@fit.cvut.cz>
 * @date 23.05.2022
 */

#include "CRook.h"
#include "../Game/CRules.h"

#include <iostream>

using namespace std;

CRook::CRook ( STATE player, bool played ) : CChessman ( player, played ) {
    if ( player == STATE::ONE )
        m_save = constants::CHAR_ROOK;
    else
        m_save = tolower ( constants::CHAR_ROOK );
}

std::ostream & CRook::print ( std::ostream & os ) const {
    if ( m_player == STATE::ONE )
        return os << WHITE << std::string ( S_ROOK );
    else
        return os << BLACK << std::string ( S_ROOK );
}

std::set < std::pair < int, int > > CRook::possibleMoves ( const CBoard & board, std::pair < int, int > pos, bool check ) {
    set < pair < int, int > > p_moves;

    for ( auto dir : straight_DIR )
        discoverFields ( dir, board, pos, p_moves );

    if ( check )
        CRules::checkMoves( board, pos, p_moves );

    return p_moves;
}

bool CRook::isPartCastling () const {
    return true;
}

int CRook::getRank() const {
    return ROOK;
}
