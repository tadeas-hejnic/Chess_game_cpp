/**
 * @author Tadeáš Hejnic <hejnitad@fit.cvut.cz>
 * @date 22.05.2022
 */

#pragma once
#include "CPlayer.h"
#include "../Move/CMove.h"


/**
 * Child class that has the "best" moves based on ranks that can be easily modified
 */
class CLegend : public CPlayer {
public:
    /**
     * Construct legend player and set num_of_plays to zero
     * @param[in] player_num
     */
    explicit CLegend ( STATE player_num );

    /**
     * Selects sophisticated move, depends on constants of CMove
     *
     * @param[in,out] board - the game board where the move is done
     *
     * @return true if everything ends correctly, false otherwise
     */
    bool makeMove ( CBoard & board ) override;

    /**
     * Selects always queen as a promotion
     *
      * @param[out] choice
     *
     * @return always true
     */
    bool choosePromotion ( int & choice ) override;

    /**
     * Goes trough all possible moves of the player
     * Put the best move of each chessman and sort them by ranks.
     *
     * @param[in] board where the move should be done
     *
     * @return the last move of sorted vector of moves
     */
    CMove chooseMove ( const CBoard & board );

    /**
     * Goes trough all possible moves of the chessman and chooses the best one
     *
     * @param[in] board where the move should be done
     * @param[in] position of the chessman
     * @param[in] moves of the chessman
     *
     * @return the best move of the chessman
     */
    CMove chooseBest ( const CBoard & board, std::pair< int, int > position, const std::set< std::pair< int, int > > & moves );
private:
    std::pair< int, int > last_move;
    int num_of_plays;
};


