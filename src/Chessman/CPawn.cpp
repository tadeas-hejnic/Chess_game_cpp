/**
 * @author Tadeáš Hejnic <hejnitad@fit.cvut.cz>
 * @date 23.05.2022
 */

#include "CPawn.h"
#include "../Game/CRules.h"

#include <iostream>

using namespace std;

CPawn::CPawn ( STATE player, bool played ) : CChessman ( player, played ) {
    if ( player == STATE::ONE )
        m_save = constants::CHAR_PAWN;
    else
        m_save = tolower ( constants::CHAR_PAWN );
}

std::ostream & CPawn::print( std::ostream & os ) const {
    if ( m_player == STATE::ONE )
        return os << WHITE << std::string ( S_PAWN );
    else
        return os << BLACK << std::string ( S_PAWN );
}

std::set < std::pair < int, int> > CPawn::possibleMoves ( const CBoard & board, std::pair < int, int > pos, bool check ) {
    set < pair < int, int > > p_moves;
    pair < int , int > tmp;
    int n = pos . first;    // letter
    int l = pos . second;   // number

    tmp = {n - 1, l };
    if ( board . getTurn() == STATE::TWO )
        tmp . first += constants::OPPOSITE_1;

    if ( board . validTarget ( tmp, true )/* && board . checkMove ( pos, tmp ) */) {

        p_moves . insert ( tmp );

        tmp = {n - 2, l };
        if ( board . getTurn() == STATE::TWO )
            tmp . first += constants::OPPOSITE_2;

        if ( board . validTarget ( tmp, true ) && !m_played     // must be first move
            /* && board . checkMove ( pos, tmp  ) */ )
            p_moves . insert ( tmp );
    }

       // attack || attack en passant
       tmp = { n - 1, l + 1 };
       if ( board . getTurn() == STATE::TWO )
           tmp . first += constants::OPPOSITE_1;
       if ( board . validTarget ( tmp )
       && ( ( board . m_fields [ tmp .first ][ tmp . second ] . m_state != STATE::EMPTY )
           || ( board . m_fields [ tmp . first ][ tmp . second ] . m_state == STATE::EMPTY
             && board . m_fields [ n ][ tmp . second ] . en_passant ) )
       /*  && board . checkMove ( pos, tmp  ) */)
        p_moves . insert ( tmp );

    // attack || attack en passant
    tmp = { n - 1, l - 1 };
    if ( board . getTurn() == STATE::TWO )
        tmp . first += constants::OPPOSITE_1;
    if ( board . validTarget ( tmp )
    && ( ( board . m_fields [ tmp .first ][ tmp . second ] . m_state != STATE::EMPTY )
        || ( board . m_fields [ tmp . first ][ tmp . second ] . m_state == STATE::EMPTY
            && board . m_fields [ n ][ tmp . second  ] . en_passant ) )
    /*&& board . checkMove ( pos, tmp  ) */)
        p_moves . insert ( tmp );

    if ( check )
        CRules::checkMoves( board, pos, p_moves );

    return p_moves;
}

bool CPawn::promotion() const {
    return true;
}

bool CPawn::enPassant() const {
    return true;
}

int CPawn::getRank() const {
    return PAWN;
}
