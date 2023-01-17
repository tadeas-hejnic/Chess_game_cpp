/**
 * @author Tadeáš Hejnic <hejnitad@fit.cvut.cz>
 * @date 22.05.2022
 */

#include "CPlayer.h"
#include "../Chessman/CChessman.h"
#include "../Application/Constants.h"

#include <iostream>

using namespace std;

CPlayer::CPlayer ( STATE state ) {
    m_num = state;
    // m_name = std::move (name );
}
/*
std::string & CPlayer::getName () {
    return m_name;
}
*/
std::pair< int, int > CPlayer::randomMoves ( const CBoard & board, set< std::pair < int, int > > & p_moves ) {
    while ( true ) {
        int i = random () % constants::B_END;
        int j = random () % constants::B_END;

        if ( board . validPosition ( { i, j } ) ) {
            p_moves = board . m_fields [ i ][ j ] . m_chessman -> possibleMoves ( board, { i, j }, true );

            if ( !( p_moves . empty() ) )
                return { i, j };
        }
    }
}

std::pair<int, int> CPlayer::randomTarget( set< std::pair< int, int > > & p_moves ) {

    auto it = p_moves . begin();
    advance (it, random () % p_moves . size() );

    return *it;
}

void CPlayer::printTurn ( STATE player ) {
    if ( player == STATE::ONE )
        cout << PLAYER_ONE;
    else
        cout << PLAYER_TWO;

    cout << ON_TURN << endl;
}
