/**
 * @author Tadeáš Hejnic <hejnitad@fit.cvut.cz>
 * @date 22.05.2022
 */

#pragma once
#include "../Game/CField.h"
#include "../Application/Constants.h"

/**
 * The board where the game is played
 * Board is composed of 64 fields, holds information about turn and check
 */
class CBoard {
    STATE m_turn;
public:
    /**
     * Constructs new board
     */
    CBoard ( );

    /**
     * Construct a loaded board
     *
     * @throw runtime_error if some issue with loading
     */
    explicit CBoard ( bool );

    /**
     * Goes through fields, switches between light and dark background.
     * When the field is occupied - prints the CHESSMAN
     */
    void printBoard () const;

    /**
     * @param[in] opposite
     *
     * @return the number of the player who is on turn, if opposite is true return the other player
     */
    STATE getTurn ( bool opposite = false ) const;

    /**
     * Makes move on board
     * Original position of chessman is turned to empty field
     * The target position is changed
     *
     * @param[in] start
     * @param[in] target
     */
    void make_move ( std::pair < int, int > start, std::pair < int, int > target );

    /**
     * @param position
     * @return false if position is out of board
     * or if this position is not occupied by players chessman,
     * otherwise true
     */
    bool validPosition ( const std::pair< int, int > position ) const;

    /**
     * @param[in] position
     * @param[in] pawn
     *
     * @return false if position is out of board
     * or if this position is empty or the position is occupied by players chessman
     * otherwise true
     */
    bool validTarget ( const std::pair < int, int > position, bool pawn = false ) const;

    /**
     * @param[in] in
     *
     * @return false if the position is out of board, otherwise true
     */
    static bool checkPosition ( std::pair < int, int > in ) ;

    /**
     * Switches the turn
     */
    void switchTurn ();

    CField m_fields [ constants::B_END ][ constants::B_END ];
    bool m_check;
};


