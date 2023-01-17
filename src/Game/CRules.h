/**
 * @author Tadeáš Hejnic <hejnitad@fit.cvut.cz>
 * @date 01.06.2022
 */

#pragma once
#include "CBoard.h"

#include <set>

/**
 * Static class for checking all rules
 */

class CRules {
public:
    CRules() = delete;

    /**
     * Finds if is check and if the opponent has any possible move, also switches the turn
     *
     * @param[in] board where the game is played
     * @param[out] winner EMPTY if tie, else the number of the winning player
     *
     * @return true if the game has ended, false when the game continues
     */
    static bool isEnd ( CBoard & board, STATE & winner );

    /**
     * Checks all rules at the end of turn
     * Set m_played of the chessman to true. Checks if the chessman can be drawn in en passant way.
     * Makes move of the rook when castling is played. Decides of pawns promotion.
     *
     * @param[in] board where the game is played
     * @param[in] position original position of the chessman
     * @param[in] target_position new position of the chessman
     *
     * @return true if promotion will be made, otherwise false
     */
    static bool endOfTurn ( CBoard & board, std::pair < int, int > position, std::pair < int, int > target_position );

    /**
     * Checks all rules at the beginning of turn
     * Checks the check, when is check set m_check to true, otherwise to false-
     * Calls the method for setting en_passant bool from previous turn to false.
     *
     * @param[in] board where the game is played
     */
    static void beginOfTurn ( CBoard & board );

    /**
     * Checks all possible moves of the opponent
     *
     * @param[in] board where the game is played
     *
     * @return true when opponent hasn't any possible move otherwise false
     */
    static bool cantMove ( CBoard & board );

    /**
     * Checks if the player will be in check after given move
     *
     * @param[in] board where the game is played
     * @param[in] position original position of the chessman
     * @param[in] target_position new position of the chessman
     *
     * @return true when the moves leads to check, when the move is valid returns false
     */
    static bool possibleCheck ( const CBoard & board, std::pair< int, int > position, std::pair< int, int > target_position );

    /**
     * Goes through all possible moves and deletes moves that will lead to check ( invalid moves )
     *
     * @param[in] board where the game is played
     * @param[in] position original position of the chessman
     * @param[in] p_moves all possible moves of the chessman
     */
    static void checkMoves ( const CBoard & board, std::pair< int, int > position, std::set< std::pair< int, int > > & p_moves );

    /**
     * Finds if is check or not
     * Calls findKing() to get the position of the king
     *
     * @param[in] board where the game is played
     *
     * @return true if is check, otherwise returns false
     */
    static bool isCheck ( CBoard & board );
private:
    /**
     * Decides if the move can lead to en passant capture of the pawn
     *
     * @param[in] position original position of the chessman
     * @param[in] target_position new position of the chessman
     *
     * @return true if the move can lead to en passant capture, otherwise returns false
     */
    static bool isEnPassant ( std::pair< int, int > position, std::pair< int, int > target_position );

    /**
     * Decides if the move was castling
     *
     * @param[in] king_pos original position of the chessman
     * @param[in] king_target new position of the chessman
     * @param[out] rook_pos original position the rook
     * @param[out] rook_target new position of the rook
     * @param[in] player
     *
     * @return true if the move was castling, otherwise returns false
     */
    static bool isCastling ( std::pair < int, int > king_pos, std::pair < int, int > king_target,
                              std::pair < int, int > & rook_pos, std::pair < int, int > & rook_target,
                              STATE player );
    /**
     * Decides if the chessman should be promoted
     *
     * @param[in] position new position of the chessman
     *
     * @return true if should be promoted, otherwise returns false
     */
    static bool isPromotion ( std::pair< int, int > position );

    /**
     * Set the en passant bool of the pawn from previous turn to false
     *
     * @param[in] board where the game is played
     */
    static void deleteEnPassant ( CBoard & board );

    /**
     * @param[in] board where the game is played
     *
     * @return position of king
     */
    static std::pair< int, int > findKing ( const CBoard & board );
};