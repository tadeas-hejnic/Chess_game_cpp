/**
 * @author Tadeáš Hejnic <hejnitad@fit.cvut.cz>
 * @date 23.05.2022
 */

#pragma once
#include "../Game/CBoard.h"
#include "../Application/EState.h"
#include "../Application/Constants.h"
#include "../Application/EDir.h"
#include <set>

#define S_KING "♔"
#define S_QUEEN "♕"
#define S_BISHOP "♗"
#define S_KNIGHT "♘"
#define S_ROOK "♖"
#define S_PAWN "♙"
/*
#define S_KING "K"
#define S_QUEEN "Q"
#define S_BISHOP "B"
#define S_KNIGHT "N"
#define S_ROOK "R"
#define S_PAWN "P"
*/
/**
 * Base class for all chessmen
 * This class does everything belongs to chessman and its moves
 */

class CChessman {
public:
    /**
     * Constructs chessman
     *
     * @param[in] player to whom belongs
     * @param[in] played
     */
    explicit CChessman ( STATE player, bool played = false );
    virtual  ~CChessman () = default;

    /**
     * Abstract method for generating possible moves of the chessman
     *
     * @param[in] board where the move should be done
     * @param[in] position of the chessman
     * @param[in] check when true, the method calls the function for further check of moves
     *
     * @return the set of position of possible move
     */
    virtual std::set < std::pair < int, int > > possibleMoves ( const CBoard & board, std::pair < int, int > position, bool check ) = 0;

    /**
     * Abstract method for printing the chessman on board
     *
     * @return stream with the chessman
     */
    virtual std::ostream & print ( std::ostream & ) const = 0;

    /**
     * "Saves" the chessman to stream ( m_save is used for this )
     *
     * @return stream with the saved chessman
     */
    std::ostream & save ( std::ostream & ) const;

    /**
     * Goes through fields in given direction and adds valid positions to possible moves.
     *
     * @param[in] dir direction of discovering
     * @param[in] board where the move should be made
     * @param[in] position of the chessman
     * @param[in,out] p_moves possible moves of chessman
     */
    void discoverFields ( DIR dir, const CBoard & board, std::pair < int, int > position, std::set < std::pair < int, int > > & p_moves ) const;

    /**
     * @return true if castling is possible with this chessman, otherwise false
     */
    virtual bool castling () const;

    /**
     * @return true if chessman can be a part of castling, otherwise false
     */
    virtual bool isPartCastling () const;
    /**
     * @return true if promotion is possible with this chessman, otherwise false
     */
    virtual bool promotion () const;
    /**
     * @return true if this chessman can be in check, otherwise false
     */
    virtual bool inCheck () const;

    /**
     * @return true if en passant move is possible with this chessman, otherwise false
     */
    virtual bool enPassant () const;

    /**
     * @return true if move with this chessman shouldn't be done early, otherwise false
     */
    virtual bool dontMoveEarly () const;

    /**
     * Abstract method for getting rank of the chessman
     *
     * @return rank of the chessman
     */
    virtual int getRank () const = 0;

    friend std::ostream & operator << ( std::ostream &, const CChessman & );

    STATE m_player;
    bool m_played;      // true if chessman has been moved
protected:
    /**
     * @param dir direction of the move
     *
     * @return the correct position based on given direction
     */
    static std::pair < int, int > directionValues ( DIR dir );

    char m_save;

    static const int PAWN = 1;
    static const int KNIGHT = 3;
    static const int BISHOP = 3;
    static const int ROOK = 5;
    static const int QUEEN = 9;
    static const int KING = 20;
};


