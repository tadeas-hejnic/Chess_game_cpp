/**
 * @author Tadeáš Hejnic <hejnitad@fit.cvut.cz>
 * @date 23.05.2022
 */

#pragma once
#include "CChessman.h"

class CPawn : public CChessman {
public:
    /**
     * Constructs pawn chessman
     *
     * @param[in] player to whom belongs
     * @param[in] played
     */
    explicit CPawn ( STATE player, bool played = false );

    /**
     * Finds the valid targets of possible moves typical for pawn
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
     * Pawn can be promoted
     *
     * @return always true
     */
    bool promotion () const override;

    /**
     * Pawn can attack in en passant way
     *
     * @return always true
     */
    bool enPassant () const override;

    /**
     * Defined in base class
     */
    int getRank () const override;
};
