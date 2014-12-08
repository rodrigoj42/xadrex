#ifndef SETTINGS_H_INCLUDED
#define SETTINGS_H_INCLUDED

class Settings {
private:
    bool m_timeLimitPlayerEnabled;
    bool m_timeLimitTurnEnabled;
    unsigned int m_timeLimitPlayer;
    unsigned int m_timeLimitTurn;

public:
    static const int SCREEN_WIDTH;
    static const int SCREEN_HEIGHT;

    bool timeLimitPlayerEnabled();
    unsigned int timeLimitPlayer();
    bool timeLimitTurnEnabled();
    unsigned int timeLimitTurn();

    Settings();
};

#endif // SETTINGS_H_INCLUDED
