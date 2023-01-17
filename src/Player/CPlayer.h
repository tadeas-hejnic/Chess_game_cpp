/**
 * @author Tadeáš Hejnic <hejnitad@fit.cvut.cz>
 * @date 22.05.2022
 */

#pragma once
#include "../Game/CBoard.h"

#include <string>
#include <set>

/**
 * Base class for players
 * Holds just the number of player
 */
class CPlayer {
public:
    CPlayer ( STATE );
    virtual ~CPlayer() = default;

    /**
     * Makes a move of chessman on given board.
     * Depends on type of player, this method generates move or gets instruction from stdin
     *
     * @param[in,out] board where the move is done
     *
     * @return true if all ends correctly, otherwise false
     */
    virtual bool makeMove ( CBoard & board ) = 0;

    /**
     * Chooses a promotion of pawn. Depends on type of player
     *
     * @param[out] choice
     *
     * @return true if all ends correctly, otherwise false
     */
    virtual bool choosePromotion ( int & choice ) = 0;

    /**
     * Prints which player is on turn
     *
     * @param[in] player that is o turn
     */
    static void printTurn ( STATE player ) ;
protected:

    /**
     * Generates moves of random chessman
     *
     * @param[in] board where the move should be played
     * @param[in,out] p_moves possible moves of the chosen chessman
     *
     * @return the position of the chessman
     */
    static std::pair< int, int > randomMoves ( const CBoard & board, std::set< std::pair< int, int > > & p_moves );

    /**
     * Generates random move from given set
     *
     * @param[in] p_moves possible moves of the chessman
     *
     * @return the target position of the chessman
     */
    static std::pair< int, int > randomTarget ( std::set< std::pair< int, int > > & p_moves );

    STATE m_num;
};


