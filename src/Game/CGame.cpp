/**
 * @author Tadeáš Hejnic <hejnitad@fit.cvut.cz>
 * @date 22.05.2022
 */

#include "CGame.h"
#include "../Player/CHuman.h"
#include "../Player/CBeginner.h"
#include "../Player/CPro.h"
#include "../Player/CLegend.h"
#include "../Game/CRules.h"

#include <iostream>
#include <memory>

using namespace std;

CGame::CGame ( char mode, char board ) {
    m_one = make_unique< CHuman >( STATE::ONE );

    if ( mode == constants::M_TWO_PLAYERS )
        m_two = make_unique< CHuman >( STATE::TWO );

    else if ( mode == constants::M_BEGINNER )
        m_two = make_unique< CBeginner >( STATE::TWO );

    else if ( mode == constants::M_PRO )
        m_two = make_unique< CPro >( STATE::TWO );

    else if ( mode == constants::M_LEGEND )
        m_two = make_unique< CLegend >( STATE::TWO );

    if ( board == constants::NEW_GAME )
        m_board = CBoard ();

    else
        try {
            m_board = CBoard ( true );
        } catch ( runtime_error & e ) {
            cout << "\n-----------------------" << endl;
            cout << e . what() << endl;
            cout << "\nNEW GAME:" << endl;
        }
}

bool CGame::play ( STATE & result ) {
    while ( true ) {
        m_board . printBoard ();

        if ( m_board . getTurn () == STATE::ONE ) {
            if ( ! m_one -> makeMove ( m_board ) )
                return false;
        } else
            if ( ! ( m_two -> makeMove ( m_board ) ) )
                return false;

        if ( CRules::isEnd ( m_board, result ) ) {
            m_board . printBoard ();
            return true;
        }
    }
}
