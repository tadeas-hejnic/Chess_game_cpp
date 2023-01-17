/**
 * @author Tadeáš Hejnic <hejnitad@fit.cvut.cz>
 * @date 23.05.2022
 */

#include "CBishop.h"
#include "../Game/CRules.h"

#include <iostream>

using namespace std;

CBishop::CBishop( STATE player, bool played ) : CChessman ( player, played ) {
    if ( player == STATE::ONE )
        m_save = constants::CHAR_BISHOP;
    else
        m_save = tolower ( constants::CHAR_BISHOP );
}

std::ostream & CBishop::print ( std::ostream & os ) const {
    if ( m_player == STATE::ONE )
        return os << WHITE << std::string ( S_BISHOP );
    else
        return os << BLACK << std::string ( S_BISHOP );
}

std::set< std::pair< int, int > > CBishop::possibleMoves ( const CBoard & board, std::pair < int, int > pos, bool check ) {
    set < pair < int, int > > p_moves;

    for ( auto dir : diag_DIR )
        discoverFields ( dir, board, pos, p_moves );

    if ( check )
        CRules::checkMoves ( board, pos, p_moves );

    return p_moves;
}

int CBishop::getRank () const {
    return BISHOP;
}
