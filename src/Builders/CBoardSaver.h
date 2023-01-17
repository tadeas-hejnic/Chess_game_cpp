/**
 * @author Tadeáš Hejnic <hejnitad@fit.cvut.cz>
 * @date 01.06.2022
 */

#pragma once
#include "../Game/CBoard.h"
#include <iostream>
#include <string>
#include <fstream>

/**
* Class that saves a board to given file
*/

class CBoardSaver {
public:
    CBoardSaver () = delete;

    /**
     * Coordinates the whole saving process
     *
     * @param[in] board that should be saved
     *
     * @return true if the board was saved correctly, otherwise false
     */
    static bool save ( const CBoard & board );

    /**
     * Gets the name of the file where the board should be saved
     *
     * @param[out] file_name
     *
     * @return true if the name was given correctly, otherwise false
     */
    static bool fileName ( std::string & file_name );

    /**
     * Goes through the whole board and save the fields to given stream
     *
     * @param[in] board that should be saved
     * @param[out] os
     */
    static void saveBoard ( const CBoard & board, std::ofstream & os );

    /**
     * Saves the bool type to stream
     *
     * @param[in, out] os
     * @param[in] x bool that should be written to stream
     */
    static void boolSave ( std::ostream & os, bool x = false );

    /**
     * Checks duplicity of file and asks if the file should be overwritten
     *
     * @param[in] file_name
     *
     * @return true if this file can be used for saving, otherwise false
     */
    static bool overwriteFile ( std::string & file_name );

    /**
     * Adds the path to file_name
     *
     * @param[in,out] file_name
     *
     * @return true if this file already exists, otherwise false
     */
    static bool exist ( std::string & file_name );
};


