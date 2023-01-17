/**
 * @author Tadeáš Hejnic <hejnitad@fit.cvut.cz>
 * @date 03.06.2022
 */

#include "CLegend.h"
#include "../Chessman/CChessman.h"
#include "../Game/CRules.h"

#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

CLegend::CLegend ( STATE player_num ) : CPlayer( player_num ) {
    num_of_plays = 0;
}

bool CLegend::makeMove ( CBoard & board ) {
    CRules::beginOfTurn ( board );

    CMove move = chooseMove ( board );

    pair < int, int > position = move . m_position;
    pair < int, int > target_position = move . m_target;

    board . make_move ( position, target_position );
    last_move = target_position;

    if ( CRules::endOfTurn ( board, position, target_position ) ) {
        int choice;
        choosePromotion ( choice );
        board . m_fields [ target_position . first ][ target_position . second ] . makePromotion ( choice );
    }

    num_of_plays++;

    return true;
}

bool CLegend::choosePromotion ( int & choice ) {
    choice = constants::QUEEN_CHOICE;
    return true;
}

CMove CLegend::chooseMove ( const CBoard & board ) {
    vector< CMove > best_moves;
    for ( int i = constants::B_BEGIN; i < constants::B_END; i++ )
        for ( int j = constants::B_BEGIN; j < constants::B_END; j++ )
            if ( board . m_fields [ i ][ j ] . m_state == board . getTurn () ) {
                auto p_moves = board . m_fields [ i ][ j ] . m_chessman -> possibleMoves ( board, { i, j }, true );
                if ( ! p_moves . empty() ) {
                    CMove tmp = chooseBest ( board, { i, j }, p_moves );
                    best_moves . push_back ( tmp );
                }
            }

    sort ( best_moves . begin(), best_moves . end(), []( CMove & x, CMove & y ) {
                                                                    return x . overall_rank < y . overall_rank; } );

    return best_moves . back ();
}

CMove CLegend::chooseBest ( const CBoard & board, pair< int, int > position, const set< pair< int, int > > & moves ) {
    CMove best = CMove ( position, { moves . begin () -> first, moves . begin () -> second },
                         CMove::getRank ( board, position, { moves . begin () -> first, moves . begin () -> second },
                                          last_move, num_of_plays ) );

    for ( const auto & target : moves ) {
        int rank = CMove::getRank ( board, position, target, last_move, num_of_plays );
        CMove next = CMove ( position, target, rank );
        if ( best . overall_rank < next . overall_rank )
            best = next;
    }

    return best;
}
