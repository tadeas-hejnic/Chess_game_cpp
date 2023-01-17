project(semestral)

set(CMAKE_CXX_STANDARD 17)

add_executable( hejnitad
        hejnitad/src/Main/main.cpp

        hejnitad/src/Application/CApplication.cpp
        hejnitad/src/Application/CApplication.h
        hejnitad/src/Application/CMenu.cpp
        hejnitad/src/Application/CMenu.h
        hejnitad/src/Application/EState.h

        hejnitad/src/Chessman/CChessman.cpp
        hejnitad/src/Chessman/CChessman.h
        hejnitad/src/Chessman/CKing.h
        hejnitad/src/Chessman/CKing.cpp
        hejnitad/src/Chessman/CQueen.h
        hejnitad/src/Chessman/CQueen.cpp
        hejnitad/src/Chessman/CRook.h
        hejnitad/src/Chessman/CRook.cpp
        hejnitad/src/Chessman/CBishop.h
        hejnitad/src/Chessman/CBishop.cpp
        hejnitad/src/Chessman/CKnight.h
        hejnitad/src/Chessman/CKnight.cpp
        hejnitad/src/Chessman/CPawn.h
        hejnitad/src/Chessman/CPawn.cpp

        hejnitad/src/Game/CBoard.h
        hejnitad/src/Game/CBoard.cpp
        hejnitad/src/Game/CGame.h
        hejnitad/src/Game/CGame.cpp
        hejnitad/src/Game/CField.h
        hejnitad/src/Game/CField.cpp

        hejnitad/src/Player/CPlayer.h
        hejnitad/src/Player/CPlayer.cpp
        hejnitad/src/Player/CHuman.h
        hejnitad/src/Player/CHuman.cpp
        hejnitad/src/Player/CBeginner.h
        hejnitad/src/Player/CBeginner.cpp
        hejnitad/src/Player/CPro.h
        hejnitad/src/Player/CLegend.h
        hejnitad/src/Game/CRules.cpp hejnitad/src/Game/CRules.h hejnitad/src/Application/Constants.h hejnitad/src/Builders/CBoardGenerator.cpp hejnitad/src/Builders/CBoardGenerator.h hejnitad/src/Builders/CBoardLoader.cpp hejnitad/src/Builders/CBoardLoader.h hejnitad/src/Builders/CBoardSaver.cpp hejnitad/src/Builders/CBoardSaver.h hejnitad/src/Application/EDir.h hejnitad/src/Player/CPro.cpp hejnitad/src/Player/CLegend.cpp hejnitad/src/Move/CMove.h hejnitad/src/Move/CMove.cpp hejnitad/src/Move/ranks.h hejnitad/src/Application/messages.h)