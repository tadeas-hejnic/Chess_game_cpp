/**
 * @author Tadeáš Hejnic <hejnitad@fit.cvut.cz>
 * @date 26.05.2022
 */

#include "CApplication.h"
#include "../Game/CGame.h"
#include "CMenu.h"
#include "EState.h"
#include "Constants.h"

using namespace std;

bool CApplication::run () {

    char choice, choice_new;
    if ( ! start ( choice, choice_new ) )
        return true;

    STATE winner;

    CGame game = CGame ( choice, choice_new );
    if ( ! game . play ( winner ) )
        return false;

    CMenu::printResult ( choice, winner );

    return true;
}

bool CApplication::start ( char & choice, char & choice_new ) {
    CMenu::printMenu ();

    if ( ! CMenu::choice ( choice, constants::M_TWO_PLAYERS, constants::M_BEGINNER, constants::M_PRO,
                             constants::M_LEGEND, constants::QUIT_GAME ) )
        return false;

    if ( choice == constants::QUIT_GAME )
        return false;

    CMenu::printNew();
    if ( ! CMenu::choice ( choice_new, constants::NEW_GAME, constants::LOAD_GAME, constants::QUIT_GAME ) )
        return false;

    if ( choice_new == constants::QUIT_GAME )
        return false;

    return true;
}
