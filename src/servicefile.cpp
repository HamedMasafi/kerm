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

#include <QDir>
#include <QProcess>
#include <QWidget>
#include <KMessageBox>

#include "servicefile.h"
#include "formProcessRunner.h"
#include <qtextstream.h>

QString _serviceName;
QProcess *proc;

const char* commentShortDescript = "# Short-Description:";
const char* commentLongDescript  = "# Description:";
const char* commentDefaultStart  = "# Default-Start:";
const char* commentDefaultStop   = "# Default-Stop:";


serviceFile::serviceFile()
{
}
serviceFile::serviceFile(QString serviceName)
{
	srvName = serviceName;
	srvPath = "/etc/init.d/" + serviceName;
}


serviceFile::~serviceFile()
{
}




		
//service control routines
bool serviceFile::changeSatus(QString status)
{
	QStringList sparams;
	QString sprm;
	QString caption;
	QStringList::Iterator sl;
	QString runnerPath = getRunnerPath();
	
	caption = status;
	caption.append( "ing service ");
	caption.append( srvName );
	
	sparams = runnerPath.split( " " );	


	sparams << srvPath;
	sparams << status;
	
	formProcessRunner *prn;
	prn = new formProcessRunner ();
	prn->setModal(TRUE);
	prn->show();
	prn->setProcess (runnerPath, sparams, caption);
	prn->execProcess();
	
	return TRUE;
}

bool serviceFile::start()
{
	return changeSatus( "start" );
}

bool serviceFile::stop()
{
	return changeSatus( "stop" );
}

bool serviceFile::restart()
{
	return changeSatus( "restart" );
}



//description read routines
QString serviceFile::getFileDesc(bool lenghtLimit)
{
	QString sret;
	QString desc, shortdesc;
   desc = getCommentInText( QString::QString( commentLongDescript ) );
   shortdesc = getCommentInText( QString::QString( commentShortDescript ) );
	
	if (desc!="")
		sret = desc;
	else if (shortdesc!="")
		sret = shortdesc;
	else
		sret = "-";
	
   if ( lenghtLimit )
		sret = getShortWord( sret, 30);
	
	return sret;
}
QString serviceFile::getShortWord(QString s, int wordLimit)
{
	int spacePos;
	QString sret;
	
	if (s.length() > wordLimit ){
		spacePos = s.indexOf( ' ', wordLimit);
		return s.section( "", 0, spacePos-1) + "..."; 
	}//if
	else
		return s;
	
}

QString serviceFile::getCommentInText( QString data )
{
	QStringList lines;
	QStringList::Iterator sl;
	QString sline;
	QString desc, shortdesc, buff;
	bool foundAtPreline;
	QString foundText, content;
	
	content = readFile();
	lines = content.split( "\n" );
	foundAtPreline = FALSE;
	
	for ( sl = lines.begin(); sl != lines.end(); ++sl ) {
		sline = *sl;
	
		if (foundAtPreline ){
			if( sline.section( "", 1, 3)=="#  ")
				foundText.append( " " + trim( sline ) );
			else
				return foundText;
		}
		
		QString sret;
		if (sline.toLower().startsWith(data.toLower())){
			sret = sline.section( "", data.length()+1, sline.length() );
			foundText = trim( sret.replace( "\n", " ") );
			foundAtPreline = TRUE;
		}//if
	}//for
	
	return foundText;
	
}


//etc routines
QString serviceFile::readFile()
{
	QFile file( srvPath );
	if ( file.open( QIODevice::ReadOnly ) ) {
		QTextStream stream( &file );
		QString fc;
      
		fc = stream.readAll();

		return fc;
		
	} // if (file.open)
	else{
		return "";
	}//if
}

QString serviceFile::trim(QString s)
{
	int i=1;
	if (s.section( "", 1, 1)=="#") i++;
	while(s.section( "", i, i)==" " || s.section( "", i, i)=="\t")
		i++;
	return s.section( "", i , s.length() );
}

QString serviceFile::getRunnerPath()
{
	QStringList lines;
 	QString content;
	QString sline;
	QStringList::Iterator sl;
	
	content = readFile();
	
	lines = content.split( "\n" );	
	for ( sl = lines.begin(); sl != lines.end(); ++sl ) {
		sline = *sl;
	
		if (sline.startsWith ("#!") ){
			return sline.section ("", 3, sline.length() );

		}

	}//for
	
	return "";
	
}

QString serviceFile::getDocPath()
{
	QDir tmpQDir;
	QString docPath;
	docPath = "/usr/share/doc/" + srvName;
	if (tmpQDir.exists( docPath ) )
		return docPath;
	else
		return "";

}

QString serviceFile::getShortDescript()
{
   return getCommentInText( QString::QString( commentShortDescript ) );
}

QString serviceFile::getLongDescript()
{
   return getCommentInText( QString::QString( commentLongDescript ) );
}

QString serviceFile::getDefaultStop()
{
   return getCommentInText( QString::QString( commentDefaultStop ) );
}

QString serviceFile::getDefaultStart()
{
   return getCommentInText( QString::QString( commentDefaultStart ) );
}
