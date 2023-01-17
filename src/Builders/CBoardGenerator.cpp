/**
 * @author Tadeáš Hejnic <hejnitad@fit.cvut.cz>
 * @date 01.06.2022
 */

#include "CBoardGenerator.h"
#include "../Application/Constants.h"
#include "../Application/EState.h"
#include "../Chessman/CBishop.h"
#include "../Chessman/CKing.h"
#include "../Chessman/CKnight.h"
#include "../Chessman/CPawn.h"
#include "../Chessman/CQueen.h"
#include "../Chessman/CRook.h"

#include <memory>

using namespace std;

CField CBoardGenerator::newField ( std::pair< int, int > pos ) {
    if ( pos . first == constants::PLAYER_ONE_SECOND || pos . first == constants::PLAYER_TWO_SECOND ) {
        STATE player = STATE::ONE;
        if ( pos . first == constants::PLAYER_TWO_SECOND ) player = STATE::TWO;

        if ( pos . second == constants::L_ROOK || pos . second == constants::R_ROOK )
            return { player, make_shared< CRook >( CRook ( player ) ) };
        else if ( pos . second == constants::L_KNIGHT || pos . second == constants::R_KNIGHT )
            return { player, make_shared< CKnight >( CKnight ( player ) ) };
        else if ( pos . second == constants::L_BISHOP || pos . second == constants::R_BISHOP )
            return { player, make_shared< CBishop >( CBishop ( player ) ) };
        else if ( pos . second == constants::KING )
            return { player, make_shared< CKing >( CKing ( player ) ) };
        else if ( pos . second == constants::QUEEN )
            return { player, make_shared< CQueen >( CQueen ( player ) ) };

    } else if ( pos . first == constants::PLAYER_ONE_FIRST || pos . first == constants::PLAYER_TWO_FIRST ) {

        STATE player = STATE::ONE;
        if ( pos . first == constants::PLAYER_TWO_FIRST ) player = STATE::TWO;

        return { player, make_shared< CPawn >( CPawn ( player ) ) };
    }

    return {};
}
