/**
 * @author Tadeáš Hejnic <hejnitad@fit.cvut.cz>
 * @date 04.06.2022
 */

#include "CPro.h"
#include "../Game/CRules.h"
#include "../Chessman/CChessman.h"

using namespace std;

CPro::CPro ( STATE player_num ) : CPlayer ( player_num ) {}

bool CPro::makeMove ( CBoard & board ) {
    CRules::beginOfTurn ( board );

    set < pair < int, int > > p_moves;
    pair < int, int > position = betterMoves ( board, p_moves );


    if ( p_moves . empty() )
        position = randomMoves ( board, p_moves );

    pair < int, int > target_position = randomTarget ( p_moves );

    board . make_move ( position, target_position );

    if ( CRules::endOfTurn ( board, position, target_position ) ) {
        int choice;
        choosePromotion ( choice );
        board . m_fields [ target_position . first ][ target_position . second ] . makePromotion ( choice );
    }

    return true;
}

pair < int, int > CPro::betterMoves ( const CBoard & board, set< pair < int, int > > & moves) {
    for ( int i = constants::B_BEGIN; i < constants::B_END; i++ )
        for ( int j = constants::B_BEGIN; j < constants::B_END; j++ )
            if ( board . m_fields [ i ][ j ] . m_state == board . getTurn () )  {

                moves = board . m_fields [ i ][ j ] . m_chessman -> possibleMoves ( board, { i, j }, true );

                justAttack ( board, moves );

                if ( !( moves . empty () ) )
                    return { i , j };
            }

    return {};
}

void CPro::justAttack ( const CBoard & board, set< std::pair < int, int > > & moves ) {
    auto it = moves . begin();
    while ( it != moves . end () ) {
        if ( board . m_fields [ it -> first ][ it -> second ] . m_state != board . getTurn ( true ) )
            it = moves . erase ( it );
        else
            it++;
    }
}

bool CPro::choosePromotion ( int & choice ) {
    choice = constants::QUEEN_CHOICE;
    return true;
}