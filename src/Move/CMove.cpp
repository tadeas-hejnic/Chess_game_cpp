/**
 * @author Tadeáš Hejnic <hejnitad@fit.cvut.cz>
 * @date 26.05.2022
 */

#include "CMove.h"
#include "../Chessman/CChessman.h"
#include "../Game/CRules.h"
#include "../Chessman/CQueen.h"
#include "ranks.h"

using namespace std;

const std::map< std::pair< int, int >, int > CMove::POSITION_MAP = {
        // middle fields
        { { CENTER_1, CENTER_1 }, CENTER_RANK },
        { { CENTER_1, CENTER_2 }, CENTER_RANK },
        { { CENTER_2, CENTER_1 }, CENTER_RANK },
        { {CENTER_2, CENTER_2 }, CENTER_RANK },
        // fields middle -> sides
        { { CENTER_1, NEXT_1 }, CENTER_RANK_2 },
        { { CENTER_2, NEXT_1 }, CENTER_RANK_2 },
        { { CENTER_1, NEXT_2 }, CENTER_RANK_2 },
        { { CENTER_2, NEXT_2 }, CENTER_RANK_2 },
};

CMove::CMove ( std::pair< int, int > position, std::pair< int, int > target, int rank ) {
    m_position = position;
    m_target = target;
    overall_rank = rank;
}

int CMove::attackRank ( const CBoard & board, std::pair< int, int > target ) {
    if ( board . m_fields [ target . first ][ target . second ] . m_state == board . getTurn ( true ) )
        return board . m_fields [ target . first ][ target . second ] . m_chessman -> getRank ();

    return 0;
}

int CMove::positionRank ( const CBoard & board, std::pair< int, int > position, std::pair< int, int > target ) {
    int rank = 0, new_rank = 0;
    auto it1 = POSITION_MAP . find ( position );
    if ( it1 == POSITION_MAP . end ()
    && ! board . m_fields [ position . first ][ position . second ] . m_chessman -> promotion () )
        rank += POS_NOTHING;
    else
        rank += it1 -> second;

    auto it2 = POSITION_MAP . find ( target );
    if ( it2 == POSITION_MAP . end ()
         && ! board . m_fields [ position . first ][ position . second ] . m_chessman -> promotion () )
        new_rank += POS_NOTHING;
    else if ( it2 == POSITION_MAP . end ()
        && board . m_fields [ position . first ][ position . second ] . m_chessman -> promotion () ) {
        new_rank += POS_PROMOTION_2;
        if ( target . first == constants::PROMOTION_LINE_2 )
            new_rank += POS_PROMOTION_1;

    } else
        new_rank += it2 -> second;

    return ( new_rank * NEW_POS_RANK - rank / PREV_POS_RANK );
}

bool CMove::defendRank ( const CBoard & board, std::pair< int, int > position, std::pair< int, int > target ) {
    CBoard tmp = board;
    tmp . make_move ( position, target );
    tmp . switchTurn ();

    for ( int i = constants::B_BEGIN; i < constants::B_END; i++ )
        for ( int j = constants::B_BEGIN; j < constants::B_END; j++ ) {
            auto field = tmp . m_fields [ i ][ j ];
            if ( field . m_state == tmp . getTurn ( ) ) {
                auto moves = field . m_chessman -> possibleMoves ( tmp, { i, j }, true );
                if ( moves . find ( target ) != moves . end () )
                    return true;
            }
        }

    return false;
}

int CMove::checkRank ( const CBoard & board, std::pair< int, int > position, std::pair<int, int> target ) {
    CBoard tmp = board;
    tmp . switchTurn ();
    if ( CRules::possibleCheck ( tmp, position, target ) )
        return RANK_CHECK;

    return 0;
}

int CMove::getRank ( const CBoard & board, std::pair< int, int > position, std::pair< int, int > target,
                    std::pair< int, int > previous, int num_of_plays ) {
    int rank = 0;
    if ( position == previous ) {
        rank -= SAME;
    }

    if ( num_of_plays < NUM_OF_PLAYS
      && board . m_fields [ position . first ][ position . second ] . m_chessman -> dontMoveEarly () )
        rank -= EARLY_MOVE;


    int attack = ATTACK * attackRank ( board, target );
    rank += attack;
    if ( defendRank ( board, position, target ) ) {
        int defend = board . m_fields [ position . first ][ position . second ] . m_chessman -> getRank();
        if ( attack < defend )
            defend = defend * DEFEND;

        rank -= defend;
    }

    rank += positionRank ( board, position, target );
    rank += checkRank ( board, position, target );

    return rank;
}

bool operator < ( const CMove & x, const CMove & y ) {
    return x . overall_rank < y . overall_rank;
}
