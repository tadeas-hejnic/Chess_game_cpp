/**
 * @author Tadeáš Hejnic <hejnitad@fit.cvut.cz>
 * @date 23.05.2022
 */

#pragma once
#include "CChessman.h"

class CQueen : public CChessman {
public:
    /**
     * Constructs queen chessman
     *
     * @param[in] player to whom belongs
     * @param[in] played
     */
    explicit CQueen ( STATE player, bool played = false );

    /**
     * Finds the valid targets of possible moves typical for queen ( all direction )
     * ( Defined in base class )
     *
     * @param[in] board where the move should be done
     * @param[in] position of the chessman
     * @param[in] check when true, the method calls the function for further check of moves
     *
     * @return the set of position of possible move
     */
    std::set < std::pair < int, int > > possibleMoves ( const CBoard & board, std::pair < int, int > position, bool check ) override;
    std::ostream & print ( std::ostream & os ) const override;

    /**
     * Usually it's not worth it to move with queen early
     *
     * @return always true
     */
    bool dontMoveEarly () const override;

    /**
     * Defined in base class
     */
    int getRank () const override;
};