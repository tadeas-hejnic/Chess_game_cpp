/**
 * @author Tadeáš Hejnic <hejnitad@fit.cvut.cz>
 * @date 22.05.2022
 */

#pragma once
#include "CPlayer.h"

class CBeginner : public CPlayer {
public:
    explicit CBeginner ( STATE );

    /**
     * Selects random chessman, then select random move
     *
     * @param[in,out] board  where the move is done
     *
     * @return true if everything ends correctly, false otherwise
     */
    bool makeMove ( CBoard & board ) override;

    /**
     * Selects random promotion
     *
     * @param[out] choice
     *
     * @return always true
     */
    bool choosePromotion ( int & choice ) override;
};


