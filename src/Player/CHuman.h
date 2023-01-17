/**
 * @author Tadeáš Hejnic <hejnitad@fit.cvut.cz>
 * @date 22.05.2022
 */

#pragma once
#include "CPlayer.h"
#include "../Game/CBoard.h"


/**
 * Child class that is controlled by human
 */
class CHuman : public CPlayer {
public:
    explicit CHuman ( STATE );

    /**
     * Runs the whole process of making a move
     *
     * @param[in,out] board the board where the move is made
     *
     * @return true if everything ends correctly, false otherwise
     */
    bool makeMove ( CBoard & board ) override;

    /**
     * Runs the process of promotion
     *
     * @param[out] choice
     *
     * @return true if everything ends correctly, false otherwise
     */
    bool choosePromotion ( int & choice ) override;

private:
    /**
     * Gets input from std::cin and checks if position is valid
     *
     * @param[in] board the board where the move is made
     * @param[out] position the chosen position
     *
     * @return true if everything ends correctly, false otherwise
     */
    static bool choosePosition ( const CBoard & board, std::pair < int, int > & position ) ;

    /**
     * Gets input from std::cin and checks if target position is valid
     *
     * @param[in] board the board where the move is made
     * @param[in] position the original position of chessman
     * @param[out] target the chosen target
     *
     * @return true if everything ends correctly, false otherwise
     */
    static bool chooseTarget ( const CBoard & board, std::pair < int, int > position, std::pair < int, int > & target );

    /**
     * @param[in] input
     * @param[out] position processed position from input
     * @param[in] board the board where the move is made
     *
     * @return true if input is correct, otherwise false
     */
    static bool processInput ( const std::string & input, std::pair< int, int > & position, const CBoard & board );
};


