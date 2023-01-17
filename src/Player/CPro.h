/**
 * @author Tadeáš Hejnic <hejnitad@fit.cvut.cz>
 * @date 22.05.2022
 */

#pragma once
#include "CPlayer.h"

#include <deque>
#include <set>

/**
 * Child class that has better generator of moves, still not so smart, really offensive
 */
class CPro : public CPlayer {
public:
    explicit CPro ( STATE player_num );

    /**
     * Selects random move if attack move is not possible
     *
     * @param[in,out] board where the move is made
     *
     * @return true if everything ends correctly, false otherwise
     */
    bool makeMove ( CBoard & board ) override;

    /**
     * Chooses queen
     *
     * @param[in,out] choice
     *
     * @return always true
     */
    bool choosePromotion ( int & choice ) override;

private:
    /**
     * Chooses better moves of the chessman
     *
     * @param[in] board where the move is made
     * @param[out] moves of the chessman
     *
     * @return the target position
     */
    static std::pair < int, int > betterMoves ( const CBoard & board, std::set< std::pair < int, int > > & moves );

    /**
     * Erase non-atatck moves
     *
     * @param[in] board where the move is made
     * @param[in,out] moves of the chessman
     */
    static void justAttack ( const CBoard & board, std::set< std::pair < int, int > > & moves );
};
