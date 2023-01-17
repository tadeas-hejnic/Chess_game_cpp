/**
 * @author Tadeáš Hejnic <hejnitad@fit.cvut.cz>
 * @date 22.05.2022
 */

#include "CHuman.h"
#include "../Chessman/CChessman.h"
#include "../Game/CRules.h"
#include "../Builders/CBoardSaver.h"
#include "../Application/CMenu.h"
#include "../Application/messages.h"

#include <set>
#include <iostream>

using namespace std;

CHuman::CHuman ( STATE player_num ) : CPlayer ( player_num ) {}

bool CHuman::makeMove ( CBoard & board ) {
    printTurn ( m_num );

    CRules::beginOfTurn ( board );

    pair < int, int > position, target_position;

    if ( ! choosePosition ( board, position ) )
        return false;

    if ( ! chooseTarget ( board, position, target_position ) )
        return false;

    board . make_move ( position, target_position );

    if ( CRules::endOfTurn ( board, position, target_position ) ) {
        board . printBoard ();
        CMenu::printPromotion ();
        int choice;
        if ( ! choosePromotion ( choice ) )
            return false;
        board . m_fields [ target_position . first ][ target_position . second ] . makePromotion ( choice );
    }

    return true;
}

bool CHuman::choosePosition ( const CBoard & board, std::pair< int, int > & position ) {

    while ( ! cin . eof () ) {
        cout << TYPE_POSITION;

        string input;
        if ( !( getline ( cin, input ) ) )
            cout << TRY_AGAIN << endl;

        else {
            if ( !( processInput ( input, position, board ) ) )
                return false;

            if ( CBoard::checkPosition ( position ) ) {

                auto typedPlace = board . m_fields [ position . first ][ position . second ];

                if ( typedPlace . m_state == STATE::EMPTY)
                    cout << WRONG_INPUT << " " << EMPTY_PLACE << endl;

                else if ( typedPlace . m_state != board.getTurn() )
                    cout << WRONG_INPUT << " " << NOT_YOUR_CHESSMAN << endl;

                else {
                    if ( typedPlace . m_chessman -> possibleMoves ( board, position, true ) . empty () )
                        cout << CANT_MOVE << endl;
                    else
                        return true;
                }

            } else
                cout << WRONG_INPUT << endl;
        }
    }
    return false;
}

bool CHuman::chooseTarget ( const CBoard & board, pair < int, int > position, pair < int, int > & target ) {
    auto typedPlace = board . m_fields [ position . first ][ position . second ];
    set < pair < int, int > > p_moves = typedPlace . m_chessman -> possibleMoves ( board, position, true );

    cout << CHOOSE_TARGET;
    for ( auto & i : p_moves )
        cout << " " << char ( i . second + 65 ) << i . first + 1;

    cout << endl;

    while ( ! cin . eof () ) {

        string input;
        if ( !( getline ( cin, input ) ) )
            cout << WRONG_INPUT << " " << TRY_AGAIN << endl;

        else {
            if ( !( processInput ( input, target, board ) ) )
                return false;

            auto it_target = p_moves . find ( target );

            if ( it_target == p_moves . end () )
                cout << WRONG_INPUT << " " << FROM_ABOVE << endl;
            else {
                return true;
            }
        }
    }

    return false;
}

bool CHuman::processInput ( const string & input, std::pair< int, int > & position, const CBoard & board ) {

    if ( input == SAVE ) {
        CBoardSaver::save ( board );
        return false;
    } else if ( input == QUIT ) {
        return false;
    } else if ( input . size () != 2 ) {
        position = {};
        return true;
    }

    position = { int ( input [ 1 ] ) - '1', int ( input [ 0 ] ) - 'A' };
    return true;
}

bool CHuman::choosePromotion ( int & choice ) {
    string input;
    while ( ! cin . eof () ) {
        if ( ! getline ( cin, input ) || input . size () != 1 )
            cout << WRONG_INPUT << " " << TRY_AGAIN << endl;

        else {
            choice = int ( input [ 0 ] ) - '0';
            if ( choice != constants::QUEEN_CHOICE && choice != constants::ROOK_CHOICE
                && choice != constants::BISHOP_CHOICE && choice != constants::KNIGHT_CHOICE)
                cout << WRONG_INPUT << " " << FROM_ABOVE << endl;

            else
                return true;
        }
    }

    return false;
}
