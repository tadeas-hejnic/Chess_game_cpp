/**
 * @author Tadeáš Hejnic <hejnitad@fit.cvut.cz>
 * @date 26.05.2022
 */

#pragma once

/**
 * Class for coordinating the app, runs the menu and the game
 */

class CApplication {
public:
    CApplication () = delete;
    /**
     * Finds if is check and if the opponent has any possible move, also switches the turn
     *
     * @param[in] board where the game is played
     * @param[out] winner EMPTY if tie, else the number of the winning player
     *
     * @return true if the game has ended, false when the game continues
     */
    static bool run ();

private:
    /**
     * Starts the game with MENU and coordinates the inputs
     *
     * @param[out] choice of the opponent
     * @param[out] choice_new type of board ( new / load )
     *
     * @return true if the game has started correctly, false otherwise ( quit, EOF, ... )
     */
    static bool start ( char & choice, char & choice_new );
};
