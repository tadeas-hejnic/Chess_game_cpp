/**
 * @author Tadeáš Hejnic <hejnitad@fit.cvut.cz>
 * @date 05.06.2022
 */

#pragma once
#include "../Game/CBoard.h"

#include <iostream>
#include <map>

/**
 * Really important class for comparing possible moves
 * Holds all information about the move, such as position, target and overall rank of this move
 */
class CMove {
public:
    CMove ( std::pair< int, int >, std::pair< int, int >, int );

    std::pair< int, int > m_position;
    std::pair< int, int > m_target;

    int overall_rank;

    /**
     * Generates the rank based on all parameters
     *
     * @param[in] board where the move should be done
     * @param[in] position original
     * @param[in] target
     * @param[in] previous
     * @param[in] num_of_plays of player
     *
     * @return the rank of this move
     */
    static int getRank ( const CBoard &, std::pair< int, int >, std::pair< int, int >, std::pair< int, int >, int );

private:
    /**
     * Finds the position in map and calculates the rank of the position
     *
     * @param[in] board where the move should be done
     * @param[in] position original
     * @param[in] target
     *
     * @return the rank of this target position
     */
    static int positionRank ( const CBoard &, std::pair< int, int >, std::pair< int, int > );

    /**
     * Calculates the rank in attack category
     *
     * @param[in] board where the move should be done
     * @param[in] target
     *
     * @return the rank of this target position
     */
    static int attackRank ( const CBoard &, std::pair< int, int > );

    /**
     * Calculates the rank in defend category
     *
     * @param[in] board where the move should be done
     * @param[in] position original
     * @param[in] target
     *
     * @return the rank of this target position
     */
    static bool defendRank ( const CBoard &, std::pair< int, int >, std::pair< int, int > );

    /**
     * Calculates the rank in check category
     *
     * @param[in] board where the move should be done
     * @param[in] position original
     * @param[in] target
     *
     * @return the rank of this target position
     */
    static int checkRank ( const CBoard &, std::pair< int, int >, std::pair<int, int> );

    /**
     * Calculates the rank in "is covered by another chessman" category
     *
     * @param[in] board where the move should be done
     * @param[in] position original
     * @param[in] target
     *
     * @return the rank of this target position
     */
    //static bool isCovered ( const CBoard &, std::pair<int, int>, std::pair< int, int > );

    /**
     * Calculates the rank in covering category
     *
     * @param[in] board where the move should be done
     * @param[in] position original
     * @param[in] target
     * @param[in,out] cover
     *
     * @return the rank of this target position
     */
    //static bool makesCover ( const CBoard & board, std::pair< int, int > position, std::pair< int, int > target, std::pair<int, int> & cover );

    /** map of fields with some rank*/
    static const std::map< std::pair< int, int >, int > POSITION_MAP;
};
