/**
 * @author Tadeáš Hejnic <hejnitad@fit.cvut.cz>
 * @date 01.06.2022
 */

#include <filesystem>
#include "CBoardSaver.h"

using namespace std;

void CBoardSaver::saveBoard ( const CBoard & board, ofstream & os ) {

    for ( int i = 0; i < constants::B_END; i++ )
        for ( int j = 0; j < constants::B_END; j++ )
            os << board . m_fields [ i ][ j ];

    if ( board . getTurn () == STATE::ONE )
        os << char ( constants::TURN_ONE );
    else
        os << char ( constants::TURN_TWO );

}

void CBoardSaver::boolSave ( ostream & os, bool x ) {
    if ( x ) os << char ( constants::CHAR_TRUE );
    else os << char ( constants::CHAR_FALSE );
}

bool CBoardSaver::fileName ( string & file_name ) {
    while ( ! cin . eof () ){
        cout << "Type a file name:  ";
        if ( ! ( getline (cin, file_name ) ) )
            cout << "Wrong input! Try again." << endl;

        if ( overwriteFile ( file_name ) )
            return true;
    }

    return false;
}

bool CBoardSaver::overwriteFile ( string & file_name ) {
    if ( exist ( file_name ) )
        while ( true ) {
            cout << "Game with this name already exists. Do you want to overwrite? (y/n)" << endl;

            char choice;
            if ( !( cin >> choice ) || ( choice != constants::YES && choice != constants::NO ) )
                cout << "Wrong input! Try again." << endl;
            else if ( choice == constants::YES )
                return true;
            else
                return false;
        }

    return true;
}

bool CBoardSaver::exist ( string & file_name ) {
    file_name = PATH_EXAMPLES + file_name;
    for ( const auto & entry : std::filesystem::directory_iterator ( PATH_EXAMPLES ) )
        if ( entry . path() == file_name )
            return true;

    return false;
}

bool CBoardSaver::save ( const CBoard & board ) {
    ofstream f;
    string file_name;
    if ( ! fileName ( file_name ) ) return false;

    f . open ( file_name,  ios::out | ios::trunc );

    if ( ! ( f . good () ) ) return false;

    saveBoard ( board, f );

    f . close ();
    if ( ! ( f . good () ) ) return false;

    return true;
}


