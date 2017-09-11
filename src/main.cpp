/***************************************************************************
 *   Copyright (C) 2008 by Hamed Masafi   *
 *   Hamed.Masafi@GMail.com   *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/
#include "kermmainwin.h"
#include <kapplication.h>
#include <kaboutdata.h>
#include <kcmdlineargs.h>
#include <KDE/KLocale>

static const char description[] =
    I18N_NOOP("K Easy Runlevel Management");

static const char version[] = "0.5";

int main(int argc, char **argv)
{
    KAboutData about("kerm",
                     0,
                     ki18n("kerm"),
                     version,
                     ki18n(description),
                     KAboutData::License_GPL,
                     ki18n("(C) 2005 Hamed Masafi"),
                     KLocalizedString(),
                     0,
                     "Hamed.Masafi@GMail.com");
    about.addAuthor( ki18n("Hamed Masafi"), KLocalizedString(), "Hamed.Masafi@GMail.com" );
    KCmdLineArgs::init(argc, argv, &about);

    KCmdLineOptions options;
    options.add("+[URL]", ki18n( "Document to open" ));
    KCmdLineArgs::addCmdLineOptions(options);
    KApplication app;

    kermMainWin *widget = new kermMainWin;

    if (app.isSessionRestored())
    {
        RESTORE(kermMainWin);
    }
    else
    {
//TODO        KCmdLineArgs *args = KCmdLineArgs::parsedArgs();
        widget->show();
//        args->clear();
    }

    return app.exec();
}
