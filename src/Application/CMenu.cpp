/**
 * @author Tadeáš Hejnic <hejnitad@fit.cvut.cz>
 * @date 29.05.2022
 */

#include "CMenu.h"
#include "../Application/Constants.h"

#include <iostream>
#include <iomanip>
#include <filesystem>

using namespace std;

void CMenu::printMenu () {
    cout    << "\n"
            <<  "  ____    _   _    ____    ____    ____  \n"
            <<  "/  ___|  | | | |  |  __|  /  __|  /  __| \n"
            <<  "| |      | |_| |  | |_    | |__   | |__  \n"
            <<  "| |      |  _  |  |  _|   \\___ \\  \\__  \\ \n"
            <<  "| |___   | | | |  | |__    __| |   __| | \n"
            <<  "\\_____|  |_| |_|  |____|  |____/  |____/ \n"
            << setw ( LINE_LENGTH - 1 ) << "by hejnitad"
            << "\n"
            << setw ( LINE_LENGTH ) << setfill ( '-' ) << "\n"
            << "\n";

    printMode ();

    cout    << "\n"
            << setw ( LINE_LENGTH ) << setfill ( '-' ) << "\n"
            << setfill( ' ' );

    cout << "Type your choice:  ";
}

void CMenu::printTie () {
    cout << "\n"
         << setfill ( ' ' ) << setw ( TIE_MIDDLE )      << " _____    _    ____   \n"
         << setfill ( ' ' ) << setw ( TIE_MIDDLE )      << "|_   _|  | |  | ___|  \n"
         << setfill ( ' ' ) << setw ( TIE_MIDDLE )      << "  | |    | |  | |_    \n"
         << setfill ( ' ' ) << setw ( TIE_MIDDLE )      << "  | |    | |  |  _|   \n"
         << setfill ( ' ' ) << setw ( TIE_MIDDLE - 1 )  << "  | |    | |  | |__  \n"
         << setfill ( ' ' ) << setw ( TIE_MIDDLE - 1 )  << "  |_|    |_|  |____| \n"
         << endl;
}

void CMenu::printLose () {
    cout    << "\n"
            << " _         ___     ____    ____    ____   \n"
            << "| |       / _ \\   /  __|  |  __|  |  _  \\  \n"
            << "| |      | | | |  | |__   | |_    | |_| |  \n"
            << "| |      | | | |  \\__  \\  |  _|   |    /   \n"
            << "| |___   | |_| |   __| |  | |__   | |\\ \\  \n"
            << "|_____|   \\___/   |____/  |____|  |_| \\_\\ \n"
            << endl;
}

void CMenu::printWin ( ) {
    cout << "\n"
         << "  _      _    _    __     _    __     _    ____    ____   \n"
         << " | |    | |  | |  |   \\  | |  |   \\  | |  |  __|  |  _  \\ \n"
         << " | | __ | |  | |  | |\\ \\ | |  | |\\ \\ | |  | |_    | |_| | \n"
         << " | |/  \\| |  | |  | | \\ \\| |  | | \\ \\| |  |  _|   |    /  \n"
         << " |   /\\   |  | |  | |  \\ \\ |  | |  \\ \\ |  | |__   | |\\ \\  \n"
         << " |__/  \\__|  |_|  |_|   \\__|  |_|   \\__|  |____|  |_| \\_\\ \n";
}

bool CMenu::choice ( char & choice, char a, char b, char c, char d, char e ) {
    while ( ! cin . eof () ) {
        string input;
        if ( !( getline ( cin, input ) ) || input . size() != 1 )
            cout << "Wrong input! Try again." << endl;
        else {
            choice = input [ 0 ];
            if ( choice == a || choice == b || choice == c || choice == d || choice == e )
                return true;

            cout << "Wrong input! Choose from above." << endl;
        }
    }

    return false;
}

void CMenu::printMode () {
    cout << "\n"
         << string ( SET_MIDDLE, ' ' ) << "(" << constants::M_TWO_PLAYERS << ")" << " PLAYERS\n"
         << string ( SET_MIDDLE, ' ' ) <<   "(B)EGINNER\n"
         << string ( SET_MIDDLE, ' ' ) <<   "(P)RO\n"
         << string ( SET_MIDDLE, ' ' ) <<   "(L)EGEND\n"
         << endl;

    cout << string ( 34, ' ' ) << "(Q)UIT";
}

void CMenu::printNew () {
    cout << setw ( LINE_LENGTH ) << setfill ( '-' ) << "\n"
         << "\n"
         << string ( SET_MIDDLE, ' ' ) << "(N)EW GAME\n"
         << string ( SET_MIDDLE, ' ' ) << "(L)OAD GAME\n"
         << string ( SET_MIDDLE, ' ' ) << "(Q)UIT GAME\n"
         << "\n"
         << setw ( LINE_LENGTH ) << setfill ( '-' ) << "\n"
         << "Type your choice:  ";
}

bool CMenu::printLoad ( string & file_name ) {

    // print names of saved games
    for ( const auto & entry : std::filesystem::directory_iterator ( PATH_EXAMPLES ) )
        cout << entry . path() << endl;

    cout << "Type a name of your saved game: ";

    string name;
    while ( ! cin . eof () ) {
        if ( !( getline ( cin, name ) ) )
            cout << "Wrong input! Try again." << endl;
        else {
            file_name = PATH_EXAMPLES + name;
            if ( validFileName ( file_name ) )
                return true;
            else
                cout << "Invalid name of file! Try again." << endl;
        }
    }

    return false;
}

void CMenu::printPromotion () {
    cout << "PROMOTION! Type a number of chessman:\n"
            "   (1) QUEEN\n"
            "   (2) ROOK\n"
            "   (3) BISHOP\n"
            "   (4) KNIGHT\n"
         << endl;
}

bool CMenu::validFileName ( const string & file_name ) {

    for ( const auto & entry : std::filesystem::directory_iterator ( PATH_EXAMPLES ) )
        if ( entry . path() == file_name )
            return true;

    return false;

}

void CMenu::printResult ( char mode, STATE winner ) {
    if ( mode == constants::M_TWO_PLAYERS && winner != STATE::EMPTY) {
        printWin();
        string player;
        playerOut ( winner, player );
        cout << "\n" << setfill ( ' ' ) << setw ( 48 )
             << "is player " << player << "\n"
             << endl;

    } else if ( mode != constants::M_TWO_PLAYERS && winner == STATE::ONE )
        printWin();

    else if ( mode != constants::M_TWO_PLAYERS && winner == STATE::TWO )
        printLose ();

    else
        printTie ();
}

void CMenu::playerOut ( STATE winner, string & player ) {
    player = PLAYER_ONE;
    if ( winner == STATE::TWO ) player = PLAYER_TWO;
}
