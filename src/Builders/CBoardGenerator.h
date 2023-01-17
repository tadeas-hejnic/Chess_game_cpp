/**
 * @author Tadeáš Hejnic <hejnitad@fit.cvut.cz>
 * @date 01.06.2022
 */


#pragma once
#include "../Game/CField.h"

/**
 * Class that generates completely new board based on classic chess rules
 */

class CBoardGenerator {
public:
    CBoardGenerator () = delete;

    /**
     * Depends on position choose the right field type ( chessman, state, ... )
     *
     * @param[in] position on board
     *
     * @return new CField
     */
    static CField newField ( std::pair < int, int > position );
};


