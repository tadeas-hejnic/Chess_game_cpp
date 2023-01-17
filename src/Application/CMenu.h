/**
 * @author Tadeáš Hejnic <hejnitad@fit.cvut.cz>
 * @date 29.05.2022
 */

#pragma once
#include "EState.h"

#include <string>
/**
 * Static class for printing interface, mainly game menu
 */

class CMenu {
public:
    CMenu () = delete;

    /**
     * Simply prints "main page" with menu
     */
    static void printMenu ();

    /**
     * Simply prints options of opponents
     */
    static void printMode ();

    /**
     * Simply prints options of types of board
     */
    static void printNew ();

    /**
     * Prints all files from exaples/ and gets a file_name from std::cin
     *
     * @param[out] file_name
     *
     * @return true if the file_name was load correctly, otherwise false
     */
    static bool printLoad ( std::string & file_name );

    /**
     * @param[out] file_name
     *
     * @return true if the file is in examples/ directory, otherwise false
     */
    static bool validFileName ( const std::string & file_name );

    /**
     * Gets a char from std::cin and decides if is valid.
     * It means if is equal to one of the given chars
     *
     * @param[out] choice
     * @param[in] a
     * @param[in] b
     * @param[in] c
     * @param[in] d
     * @param[in] e
     *
     * @return true if the choice was load correctly, otherwise false
     */
    static bool choice ( char & choice, char a, char b, char c = 0, char d = 0, char e = 0 );

    /**
     * Decides who is the winner and calls the right print method
     *
     * @param[in] mode of the game
     * @param[in] winner of the game, EMPTY if the game ended as tie
     */
    static void printResult ( char mode, STATE winner );

    /**
     * Simply prints 'WINNER' in "ASCII ART"
     */
    static void printWin ();

    /**
     * Simply prints 'LOSER' in "ASCII ART"
     */
    static void printLose ();

    /**
     * Simply prints 'TIE' in "ASCII ART"
     */
    static void printTie ();

    /**
     * Prints the menu for promotion of pawn
     */
    static void printPromotion();

private:
    /**
     * Chooses the right "name"
     *
     * @param[in] winner
     * @param[out] player
     *
     * @return "player name" depends on the winner
     */
    static void playerOut ( STATE winner, std::string & player );

    static const int SET_MIDDLE = 15;
    static const int LINE_LENGTH = 41;
    static const int TIE_MIDDLE = 28;
};
