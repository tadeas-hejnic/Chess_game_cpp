/**
 * @author Tadeáš Hejnic <hejnitad@fit.cvut.cz>
 * @date 23.05.2022
 */

#include "CQueen.h"
#include "../Game/CRules.h"
#include <iostream>

using namespace std;

CQueen::CQueen ( STATE player, bool played ) : CChessman ( player, played ) {
    if ( player == STATE::ONE )
        m_save = constants::CHAR_QUEEN;
    else
        m_save = tolower ( constants::CHAR_QUEEN );
}

std::ostream & CQueen::print ( std::ostream & os ) const {
    if ( m_player == STATE::ONE )
        return os << WHITE << std::string ( S_QUEEN );
    else
        return os << BLACK << std::string ( S_QUEEN );
}

std::set<std::pair<int, int> > CQueen::possibleMoves ( const CBoard & board, std::pair < int, int > pos, bool check ) {
    set < pair < int, int > > p_moves;

    for ( auto dir : all_DIR )
        discoverFields ( dir, board, pos, p_moves );

    if ( check )
        CRules::checkMoves ( board, pos, p_moves );

    return p_moves;
}

int CQueen::getRank() const {
    return QUEEN;
}

bool CQueen::dontMoveEarly () const {
    return true;
}
