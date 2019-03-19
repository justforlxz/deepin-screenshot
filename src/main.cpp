/*
 * Copyright (C) 2017 ~ 2018 Deepin Technology Co., Ltd.
 *
 * Maintainer: Peng Hui<penghui@deepin.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <DApplication>
#include <DLog>
#include <DWidgetUtil>

#include <QObject>
#include <QTranslator>
#include <DDBusSender>

#include "screenshot.h"
#include "dbusservice/dbusscreenshotservice.h"
#include "utils/cmd_parser.h"

DWIDGET_USE_NAMESPACE

int main(int argc, char *argv[])
{
#if defined(STATIC_LIB)
    DWIDGET_INIT_RESOURCE();
#endif

     DApplication::loadDXcbPlugin();

     DApplication a(argc, argv);
     a.loadTranslator(QList<QLocale>() << QLocale::system());
     a.setOrganizationName("deepin");
     a.setApplicationName("deepin-screenshot");
     a.setApplicationVersion("4.0");
     a.setTheme("light");
     a.setQuitOnLastWindowClosed(false);
     a.setAttribute(Qt::AA_UseHighDpiPixmaps);

     CmdParser* cmd_parser = CmdParser::Instance();

     using namespace Dtk::Core;
     Dtk::Core::DLogManager::registerConsoleAppender();
     Dtk::Core::DLogManager::registerFileAppender();

     QCommandLineOption  delayOption(QStringList() << "d" << "delay",
                                                                             "Take a screenshot after NUM seconds.", "NUM");
     QCommandLineOption fullscreenOption(QStringList() << "f" << "fullscreen",
                                                                                "Take a screenshot the whole screen.");
     QCommandLineOption topWindowOption(QStringList() << "w" << "top-window",
                                                                             "Take a screenshot of the most top window.");
     QCommandLineOption savePathOption(QStringList() << "s" << "save-path",
                                                                             "Specify a path to save the screenshot.", "PATH");
     QCommandLineOption prohibitNotifyOption(QStringList() << "n" << "no-notification",
                                                                              "Don't send notifications.");
     QCommandLineOption iconOption(QStringList() << "i" << "icon",
                                                                           "Indicate that this program's started by clicking.");
    QCommandLineOption dbusOption(QStringList() << "u" << "dbus",
                                                                            "Start  from dbus.");
     QCommandLineParser cmdParser;
     cmdParser.setApplicationDescription("deepin-screenshot");
     cmdParser.addHelpOption();
     cmdParser.addVersionOption();
     cmdParser.addOption(delayOption);
     cmdParser.addOption(fullscreenOption);
     cmdParser.addOption(topWindowOption);
     cmdParser.addOption(savePathOption);
     cmdParser.addOption(prohibitNotifyOption);
     cmdParser.addOption(iconOption);
     cmdParser.addOption(dbusOption);
     cmdParser.process(a);

     if (cmdParser.isSet(delayOption)) {
         cmd_parser->delay = cmdParser.value(delayOption).toUInt();
     }

     if (cmdParser.isSet(fullscreenOption)) {
         cmd_parser->fullScreen = true;
     }

     if (cmdParser.isSet(topWindowOption)) {
         cmd_parser->topWindow = true;
     }

     if (cmdParser.isSet(savePathOption)) {
         cmd_parser->savePath = cmdParser.value(savePathOption);
     }

     if (cmdParser.isSet(prohibitNotifyOption)) {
         cmd_parser->prohibitNotify = true;
     }

     Screenshot w;
     w.hide();

     DBusScreenshotService dbusService (&w);
     Q_UNUSED(dbusService);
     //Register Screenshot's dbus service.
     QDBusConnection conn = QDBusConnection::sessionBus();
     if (!conn.registerService("com.deepin.Screenshot") ||
             !conn.registerObject("/com/deepin/Screenshot", &w)) {

         qApp->quit();
         return 0;
     }

     if (cmdParser.isSet(dbusOption)) {
         qDebug() << "dbus register wating!";
         return a.exec();
     }
     else {
        if (cmd_parser->delay != 0 && !cmd_parser->prohibitNotify) {
            // send delay screenshot notify
            w.delayScreenshot(cmd_parser->delay);
        }

         QTimer::singleShot(cmd_parser->delay * 1000, &w, &Screenshot::startScreenshot);
     }

     return a.exec();
}
