/**
 * @author Tadeáš Hejnic <hejnitad@fit.cvut.cz>
 * @date 26.05.2022
 */

#pragma once
#include "../Application/EState.h"
#include <memory>

/**
 * Field is a part of board, can be empty occupied by a chessman of one of the players
 * Holds important information for chess rules - en passant
 */

// only in pointer needed
class CChessman;

class CField {
public:
    /**
     * Constructs empty field
     */
    CField ();
    /**
     * Constructs occupied field
     *
     * @param[in] player number
     * @param[in] chessman
     * @param[in] e_p true if the chessman can be attacked in en passant way
     */
    CField ( STATE player, std::shared_ptr < CChessman > chessman, bool e_p = false );

    CField & operator = ( CField );

    ~CField() = default;

    /**
     * Makes the promotion of pawn
     *
     * @param[in] choice
     *
     * @return false if choice isn't correct, otherwise true
     */
    bool makePromotion ( int choice );

    /**
     * Saves the field to given stream
     *
     * @param os
     *
     * @return the stream with saved field
     */
    std::ostream & save ( std::ostream & os ) const;

    friend std::ostream & operator << ( std::ostream &, const CField & );

    STATE m_state;
    std::shared_ptr < CChessman > m_chessman;

    bool en_passant;    /** true if PAWN can be attacked in en passant way */
};


