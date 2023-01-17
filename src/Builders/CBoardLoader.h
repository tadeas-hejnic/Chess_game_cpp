/**
 * @author Tadeáš Hejnic <hejnitad@fit.cvut.cz>
 * @date 01.06.2022
 */

#pragma once
#include "../Game/CField.h"
#include "../Application/EState.h"

/**
 * Class that loads a board from given file
 */

class CBoardLoader {
public:
    CBoardLoader () = delete;

    /**
     * Load file to data string
     *
     * @param[out] data
     *
     * @return true if file was opened and loaded correctly, otherwise false
     */
    static bool loadFile ( std::string & data );

    /**
     * Checks given data, number of chessmen on board
     * Check if number of kings is equal to one. Doesn't check amount of all chessman types
     *
     * @param[in] data form loaded file
     *
     * @return true if everything is correct, otherwise false
     */
    static bool checkFile ( const std::string & data );

    /**
     * Based on loaded data creates a new field
     *
     * @param[in] data form loaded file
     * @param[in,out] i data index
     *
     * @throw runtime_error if unknown sign is in input data
     * @return new CField
     */
    static CField loadField ( const std::string & data, int & i );

    /**
     * Based on given char decides the state of the field
     *
     * @param[in] turn
     *
     * @throw runtime_error if unknown sign is in input data
     * @return state
     */
    static STATE loadTurn ( char turn );

    /**
     * Based on given char decides true/false
     *
     * @param[in] load char from input
     *
     * @throw runtime_error if unknown sign is in input data
     * @return true if load is equal to 1, false if equal to 0
     */
    static bool loadBool ( char load );
};


