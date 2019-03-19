#ifndef CMDPARSER_H
#define CMDPARSER_H

#include <QString>

class CmdParser {
public:
    static CmdParser *Instance()
    {
        static CmdParser parser;
        return &parser;
    }

    bool    fullScreen     = false;
    bool    topWindow      = false;
    bool    prohibitNotify = false;
    bool    dbus           = false;
    uint    delay          = 0;
    QString savePath;

private:
    CmdParser() {}
    CmdParser(const CmdParser &) = delete;
    CmdParser operator=(CmdParser &) = delete;
    ~CmdParser() {}
};

#endif  //CMDPARSER_H
