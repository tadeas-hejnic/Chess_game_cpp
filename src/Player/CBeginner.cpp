/**
 * @author Tadeáš Hejnic <hejnitad@fit.cvut.cz>
 * @date 22.05.2022
 */

#include "CBeginner.h"
#include "../Chessman/CChessman.h"
#include "../Game/CRules.h"
#include <set>
#include <iostream>
#include <utility>

using namespace std;

CBeginner::CBeginner ( STATE player_num ) : CPlayer ( player_num ) {}

bool CBeginner::makeMove ( CBoard & board ) {
    CRules::beginOfTurn ( board );

    set < pair < int, int > > p_moves;
    pair < int, int > position = randomMoves ( board, p_moves );

    pair < int, int > target_position = randomTarget ( p_moves );

    board . make_move ( position, target_position );

    if ( CRules::endOfTurn ( board, position, target_position ) ) {
        int choice;
        choosePromotion ( choice );
        board . m_fields [ target_position . first ][ target_position . second ] . makePromotion ( choice );
    }

    return true;
}

bool CBeginner::choosePromotion ( int & choice ) {
    choice = random() % constants::NUM_OF_PROMOTION;
    return true;
}


