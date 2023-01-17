/**
 * @author Tadeáš Hejnic <hejnitad@fit.cvut.cz>
 * @date 22.05.2022
 */

#pragma once
#include "../Player/CPlayer.h"

/**
 * In this class run the whole game
 * It holds the most important values, such as board and both players
 */

class CGame {
public:
    /**
     * Construct new game
     *
     * @param mode of opponent
     * @param board type
     */
    CGame ( char mode, char board );

    ~CGame () = default;

    CGame ( const CGame & ) = delete;

    /**
     * The main method when the game is played.
     * Runs the whole game.
     *
     * @param[out] result
     *
     * @return true when the game was finished, otherwise returns false
     */
    bool play ( STATE & result );
private:
    std::unique_ptr < CPlayer > m_one;   /**< Player n. one */
    std::unique_ptr < CPlayer > m_two;   /**< Player n. two */
    CBoard m_board;                      /**< Board where the game is played */
};



