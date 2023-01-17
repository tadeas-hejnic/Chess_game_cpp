/**
 * @author Tadeáš Hejnic <hejnitad@fit.cvut.cz>
 * @date 26.05.2022
 */

#pragma once
#include <initializer_list>

enum class DIR {
    UP,
    DOWN,
    LEFT,
    RIGHT,
    UPLEFT,
    UPRIGHT,
    DOWNLEFT,
    DOWNRIGHT
};

constexpr std::initializer_list<DIR> all_DIR = { DIR::UP, DIR::DOWN, DIR::LEFT, DIR::RIGHT,
                                                 DIR::UPLEFT, DIR::UPRIGHT, DIR::DOWNLEFT, DIR::DOWNRIGHT };
constexpr std::initializer_list<DIR> straight_DIR = { DIR::UP, DIR::DOWN, DIR::LEFT, DIR::RIGHT };
constexpr std::initializer_list<DIR> diag_DIR = { DIR::UPLEFT, DIR::UPRIGHT, DIR::DOWNLEFT, DIR::DOWNRIGHT };
