/**
 * @author Tadeáš Hejnic <hejnitad@fit.cvut.cz>
 * @date 23.05.2022
 */

#pragma once
#include "CChessman.h"

#include <vector>

class CKnight : public CChessman {
public:
    /**
     * Constructs knight chessman
     *
     * @param[in] player to whom belongs
     * @param[in] played
     */
    explicit CKnight ( STATE player, bool = false );

    /**
     * Finds the valid targets of possible moves typical for knight
     * ( Defined in base class )
     *
     * @param[in] board where the move should be done
     * @param[in] position of the chessman
     * @param[in] check when true, the method calls the function for further check of moves
     *
     * @return the set of position of possible move
     */
    std::set < std::pair < int, int > > possibleMoves ( const CBoard & board, std::pair < int, int > position, bool check ) override;

    /**
     * Simple print method defined in base class
     */
    std::ostream & print ( std::ostream & os ) const override;

    /**
     * Defined in base class
     */
    int getRank () const override;

private:
    static const std::vector< std::pair< int, int > > KNIGHT_MOVES;
};