#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#define GAMESETTINGS_FILENAME "GameSettings.lua"
#define GAMESETTINGS_timeLimit_Player "timeLimit_Player"
#define GAMESETTINGS_timeLimit_Turn "timeLimit_Turn"

class GameSettings {
private:
    bool m_timeLimitPlayerEnabled;
    bool m_timeLimitTurnEnabled;
    unsigned int m_timeLimitPlayer;
    unsigned int m_timeLimitTurn;

public:
    bool timeLimitPlayerEnabled();
    unsigned int timeLimitPlayer();
    bool timeLimitTurnEnabled();
    unsigned int timeLimitTurn();

    GameSettings();
};

class Game
{

public:
    GameSettings Settings;
};

#endif // GAME_H_INCLUDED
