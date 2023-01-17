/**
 * @author Tadeáš Hejnic <hejnitad@fit.cvut.cz>
 * @date 26.05.2022
 */

#include "CField.h"
#include "../Builders/CBoardSaver.h"
#include "../Chessman/CQueen.h"
#include "../Chessman/CRook.h"
#include "../Chessman/CBishop.h"
#include "../Chessman/CKnight.h"

#include <iostream>

using namespace std;

CField::CField () {
    m_state = STATE::EMPTY;
    m_chessman = nullptr;
    en_passant = false;
}

CField::CField ( STATE player, std::shared_ptr < CChessman > chessman, bool e_p ) {
    m_state = player;
    m_chessman = std::move ( chessman );
    en_passant = e_p;
}

bool CField::makePromotion ( int choice ) {
    switch ( choice ) {
        case constants::QUEEN_CHOICE:
            m_chessman = make_shared < CQueen > ( CQueen ( m_state, true ) );
            break;
        case constants::ROOK_CHOICE:
            m_chessman = make_shared < CRook > ( CRook ( m_state, true ) );
            break;
        case constants::BISHOP_CHOICE:
            m_chessman = make_shared < CBishop > ( CBishop ( m_state, true ) );
            break;
        case constants::KNIGHT_CHOICE:
            m_chessman = make_shared < CKnight > ( CKnight ( m_state, true ) );
        default:
            return false;
    }

    return true;
}

std::ostream & CField::save ( ostream & os ) const {
    CBoardSaver::boolSave ( os, en_passant );

    if ( m_state == STATE::EMPTY ) {
        CBoardSaver::boolSave ( os );
        return os << constants::CHAR_EMPTY;
    }

    CBoardSaver::boolSave ( os, m_chessman -> m_played );
    m_chessman -> save ( os );

    return os;
}

std::ostream & operator << ( ostream & os, const CField & field ) {
    return field . save ( os );
}

CField & CField::operator = ( CField x ) {
    m_state = x . m_state;
    en_passant = x . en_passant;
    swap ( m_chessman, x . m_chessman );
    return *this;
}

