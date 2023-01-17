#include "../Application/CApplication.h"

#include <iostream>

int main ( ) {
    if ( ! CApplication::run () ) {
        std::cout << "END..." << std::endl;
    }

    return 0;
}

