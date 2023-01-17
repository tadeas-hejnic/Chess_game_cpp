/**
 * @author Tadeáš Hejnic <hejnitad@fit.cvut.cz>
 * @date 01.06.2022
 */

#include "CRules.h"
#include "../Chessman/CChessman.h"

#include <memory>
#include <iostream>

using namespace std;

bool CRules::isEnd ( CBoard & board, STATE & winner ) {
    board . switchTurn ();

    if ( isCheck ( board ) && cantMove ( board ) ) {
        cout << " -------- CHECKMATE! --------" << endl;
        winner = board . getTurn ( true );      // winner is the opponent
        return true;
    } else if ( cantMove ( board ) ) {
        cout << " -------- STALEMATE! --------" << endl;
        winner = STATE::EMPTY;      // tie
        return true;
    }

    return false;
}

bool CRules::endOfTurn ( CBoard & board, const pair < int, int > position,
                         const pair < int, int > target_position ) {

    // the chessman was moved
    auto chessman = board . m_fields [ target_position . first ][ target_position . second ] . m_chessman;
    chessman -> m_played = true;

    // check of en passant
    if ( board . m_fields [ target_position . first ][ target_position . second ] . m_chessman -> enPassant()
      && isEnPassant ( position, target_position ) )
        board . m_fields [ target_position . first ][ target_position . second ] . en_passant = true;

    // check of castling
    pair < int, int > rook, target_rook;
    if ( chessman -> castling ()
      && isCastling ( position, target_position, rook, target_rook, board . getTurn () ) )
        board . make_move ( rook, target_rook );

    // check of promotion
    if ( chessman -> promotion () && isPromotion ( target_position ) )
        return true;

    return false;
}

void CRules::beginOfTurn ( CBoard & board ) {
    if ( isCheck ( board ) ) {
        cout << " ---------- CHECK! ----------" << endl;
        board . m_check = true;
    } else
        board . m_check = false;

    deleteEnPassant ( board );
}

bool CRules::isEnPassant ( const pair < int, int > position, const pair < int, int > target_position ) {
    if ( abs ( position . first - target_position . first ) == constants::EN_PASSANT )
        return true;
    else
        return false;
}

bool CRules::isCastling ( const std::pair < int, int > king_pos, const std::pair < int, int > king_target,
                           std::pair < int, int > & rook_pos, std::pair < int, int > & rook_target,
                           STATE player ) {

    // left
    if ( ( king_pos . second - king_target . second ) == constants::CASTLING_LEFT ) {
        rook_pos . first = constants::PLAYER_ONE_SECOND;
        rook_pos . second = constants::L_ROOK;
        if ( player == STATE::TWO )
            rook_pos . first = constants::PLAYER_TWO_SECOND;

        rook_target = { king_target . first, king_target . second + 1 };

        return true;

    // right
    } else if ( ( king_pos . second - king_target . second ) == constants::CASTLING_RIGHT ) {
        rook_pos . first = constants::PLAYER_ONE_SECOND;
        rook_pos . second = constants::R_ROOK;
        if ( player == STATE::TWO )
            rook_pos . first = constants::PLAYER_TWO_SECOND;

        rook_target = { king_target . first, king_target . second - 1 };

        return true;

        // castling hasn't been played
    } else
        return false;

}

bool CRules::isPromotion ( const std::pair<int, int> position ) {
    return position . first == constants::PROMOTION_LINE_1 || position . first == constants::PROMOTION_LINE_2;
}

void CRules::deleteEnPassant ( CBoard & board ) {
    STATE player = board . getTurn();

    for ( int i = constants::B_BEGIN; i < constants::B_END; i++ )
        for ( int j = constants::B_BEGIN; j < constants::B_END; j++ )
            if ( board . m_fields [ i ][ j ] . m_state == player
              && board . m_fields [ i ][ j ] . en_passant ) {

                board . m_fields [ i ][ j ] . en_passant = false;
                break;

            }
}

bool CRules::isCheck ( CBoard & board ) {
    pair < int, int > king = findKing ( board );

    for ( int i = constants::B_BEGIN; i < constants::B_END; i++ )
        for ( int j = constants::B_BEGIN; j < constants::B_END; j++ ) {
            auto field = board . m_fields [ i ][ j ];
            if ( field . m_state == board . getTurn ( true ) ) {
                // switches the turn because of the possibleMoves()
                board . switchTurn ();
                auto moves = field . m_chessman -> possibleMoves ( board, { i, j }, false );
                board . switchTurn ();
                if ( moves . find ( king ) != moves . end () )
                    return true;
            }
        }

    return false;
}

pair < int, int > CRules::findKing ( const CBoard & board ) {
    for ( int i = constants::B_BEGIN; i < constants::B_END; i++ )
        for ( int j = constants::B_BEGIN; j < constants::B_END; j++ )
            if ( board . m_fields [ i ][ j ] . m_state == board . getTurn ()
              && board . m_fields [ i ][ j ] . m_chessman -> inCheck () )    // only king can be in check
                return { i, j };
    return {};
}

bool CRules::possibleCheck ( const CBoard & board, std::pair< int, int > position, std::pair< int, int > target ) {
    CBoard tmp = board;
    tmp . make_move ( position, target );

    if ( isCheck ( tmp ) )
        return true;
    else
        return false;
}

void CRules::checkMoves ( const CBoard & board, std::pair< int, int > pos, std::set< std::pair< int, int> > & moves ) {
    auto it = moves . begin();
     while ( it != moves . end () ) {
        if ( possibleCheck ( board, pos, *it ) )
            it = moves . erase ( it );
        else
            it++;
    }
}

bool CRules::cantMove ( CBoard & board ) {
    for ( int i = constants::B_BEGIN; i < constants::B_END; i++ )
        for ( int j = constants::B_BEGIN; j < constants::B_END; j++ )
            if ( board . m_fields [ i ][ j ] . m_state == board . getTurn ()
            && ! ( board . m_fields [ i ][ j ] . m_chessman -> possibleMoves ( board, { i, j }, true ) . empty() ) )
                return false;

    return true;
}
