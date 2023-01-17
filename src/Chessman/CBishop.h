/**
 * @author Tadeáš Hejnic <hejnitad@fit.cvut.cz>
 * @date 23.05.2022
 */

#pragma once
#include "CChessman.h"

class CBishop : public CChessman {
public:
    /**
     * Constructs bishop chessman
     *
     * @param[in] player to whom belongs
     * @param[in] played
     */
    explicit CBishop ( STATE player, bool played = false );

    /**
     * Finds the valid targets of possible moves typical for bishop ( diagonal moves )
     * ( Defined in base class )
     *
     * @param[in] board where the move should be done
     * @param[in] pos position of the chessman
     * @param[in] check when true, the method calls the function for further check of moves
     *
     * @return the set of position of possible move
     */
    std::set < std::pair < int, int > > possibleMoves ( const CBoard & board, std::pair < int, int > pos, bool check ) override;

    /**
     * Simple print method defined in base class
     */
    std::ostream & print ( std::ostream & os ) const override;

    /**
     * Defined in base class
     */
    int getRank () const override;
};