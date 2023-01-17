/**
 * @author Tadeáš Hejnic <hejnitad@fit.cvut.cz>
 * @date 23.05.2022
 */

#pragma once
#include "CChessman.h"

class CKing : public CChessman {
public:
    /**
     * Constructs king chessman
     *
     * @param[in] player to whom belongs
     * @param[in] played
     */
    CKing ( STATE player, bool played = false );

    /**
     * Finds the valid targets of possible moves typical for king
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
     * Castling is typical move of king
     *
     * @return always true
     */
    bool castling () const override;

    /**
     * King can be in check
     *
     * @return always true
     */
    bool inCheck () const override;

    /**
     * Defined in base class
     */
    int getRank () const override;

private:
    /**
     * Checks both possible castlings
     *
     * @param[in] board where the move should be done
     * @param[in] position of the chessman
     * @param[in,out] left true if queens side is possible
     * @param[in,out] right true if kings side is possible
     */
    static void castlingPossible ( const CBoard & board, std::pair < int, int > position, bool & left, bool & right );

    /**
     * Checks if castling can be made with rook
     *
     * @param board where the castling should be done
     * @param position where the rook should be
     *
     * @param[in,out] side set to false if some condition is false
     */
    static void rookCheck ( const CBoard & board, const std::pair< int, int > position, bool & side );

    /**
     * @param board where the move should be done
     *
     * @return constant depending on player number ( the first number from rook's position )
     */
    static int playerRook ( const CBoard & board );
};


