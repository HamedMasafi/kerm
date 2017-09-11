/***************************************************************************
 *   Copyright (C) 2008 by Hamed Masafi   											*
 *   Hamed.Masafi@GMail.com   															*
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


// Qt headers
#include <QString>
#include <QFile>
#include <QDir>
#include <QProcess> 
#include <QList>

#include <KListWidget>

#include "actions.h"	
#include "task.h"
#include <KLocalizedString>


actionStack::actionStack()
{}



actionStack::~actionStack()
{
}


/*!
    \fn actions::newTask()
 */
void actionStack::newTask(task *t)
{
	bool found = FALSE;

   /* check for existig task and update it */
   for(int i = 0; i < tasks.size(); i++)
	{
      if (tasks.at( i ).serviceName == t->serviceName && 
          tasks.at( i ).runlevelNo == t->runlevelNo)
      {
         if (tasks.at( i ).actionType == ACTION_TYPE_MODIFY &&
             t->actionType == ACTION_TYPE_MODIFY )
         {
            tasks[ i ].setNewIndex( t->newIndex );
            tasks[ i ].setNewState( t->newState );

            found = TRUE;
            return;
         }//if

         if (tasks.at( i ).actionType == ACTION_TYPE_ADD &&
             t->actionType == ACTION_TYPE_MODIFY )
         {
            tasks[ i ].setNewIndex( t->newIndex );
            tasks[ i ].setNewState( t->newState );

            found = TRUE;
            return;
         }//if

         if (tasks.at( i ).actionType == ACTION_TYPE_ADD &&
             t->actionType == ACTION_TYPE_REMOVE )
         {
            //tasks.removeRef(taskItem);
            tasks.removeAt( i );
            return;
         }//if

         if (tasks.at( i ).actionType == ACTION_TYPE_ADD &&
             t->actionType == ACTION_TYPE_REMOVE )
         {
            return;
         }//if

         if (tasks.at( i ).actionType == ACTION_TYPE_MODIFY &&
             t->actionType == ACTION_TYPE_REMOVE )
         {
            //tasks.removeRef(taskItem);
            tasks.removeAt( i );
            //return;
         }//if
         
         if (tasks.at( i ).actionType == ACTION_TYPE_REMOVE &&
             t->actionType == ACTION_TYPE_ADD )
         {
            //tasks.removeRef(taskItem);
            tasks.removeAt( i );
            return;
         }//if
         
      }//if
	}//for
	      
	/* if the task not found then we wil create a one */
	if (found == FALSE)
	{
		t->index = currentIndex++;
		tasks.append( *t );
	}//if
   
}
  
void actionStack::newTaskModify(QString serviceName, QString runllevelNo, QString oldIndex, QString oldState, QString newIndex, QString newState)
{
	task *t;
		
	t = new task();
	t->serviceName = serviceName;
	t->runlevelNo = runllevelNo;
	t->oldIndex = oldIndex;
	t->oldState = oldState;
	t->newIndex = newIndex;
	t->newState = newState;
	t->actionType = ACTION_TYPE_MODIFY;
	
	newTask( t );
}
void actionStack::newTaskCreate(QString serviceName, QString runllevelNo, QString index, QString state)
{
	task *t;
		
	t = new task();
	t->serviceName = serviceName;
	t->runlevelNo = runllevelNo;
	t->oldIndex = QString::null;
	t->oldState = QString::null;
	t->newIndex = index;
	t->newState = state;
	t->actionType = ACTION_TYPE_ADD;
		
	newTask( t );	
}
void actionStack::newTaskRemove(QString serviceName, QString runlevelNo, QString index, QString state)
{
	task *t;
		
	t = new task();
	t->serviceName = serviceName;
	t->runlevelNo = runlevelNo;
	t->oldIndex = index;
	t->oldState = state;
	t->newIndex = QString::null;
	t->newState = QString::null;
	t->actionType = ACTION_TYPE_REMOVE;
	
	newTask( t );	
}
 
void actionStack::clear()
{
	tasks.clear();
	currentIndex = 0;
}

bool actionStack::haveChanges()
{
	return !tasks.isEmpty();
}

void actionStack::complateAllTasks()
{
	
//	for ( taskItem = tasks.first(); taskItem; taskItem = tasks.next())
   for(int i = 0; i < tasks.size(); i++)
	{
		switch (tasks.at( i ).actionType)
		{
			case ACTION_TYPE_ADD:
				doTask_Add( &tasks.at( i ) );
				break;
				
			case ACTION_TYPE_MODIFY:
				doTask_Modify( &tasks.at( i ) );
				break;
				
			case ACTION_TYPE_REMOVE:
				doTask_Remove( &tasks.at( i ) );
				break;
				
		}//switch     
	}//for
	clear();
}

bool actionStack::doTask_Modify( const task *t )
{
	QDir renamer;
	QString oldFile;
	QString newFile;
	
	oldFile = "/etc/rc" + t->runlevelNo + ".d/" + t->oldState.toUpper() + t->oldIndex +  t->serviceName;
	newFile = "/etc/rc" + t->runlevelNo + ".d/" + t->newState.toUpper() + t->newIndex +  t->serviceName;

	return renamer.rename( oldFile, newFile );
}

bool actionStack::doTask_Add( const task *t )
{
	QString linkBin;
	QString fileService, fileLink;
	QProcess *proc;	
	
	linkBin = "/usr/bin/link";
	fileService = "/etc/init.d/" + t->serviceName;
	fileLink = "/etc/rc" + t->runlevelNo + ".d/" + t->newState;
	fileLink.append( t->newIndex.length() == 1 ? "0" + t->newIndex : t->newIndex );
	fileLink.append( t->serviceName );
	
	proc = new QProcess( 0 );
		
   QStringList arguments;
   arguments << fileService << fileLink;
	
   proc->start( linkBin, arguments ) ;
   
	return  proc->exitCode();
}

bool actionStack::doTask_Remove( const task *t )
{
	QString fileSrv;
	QDir tmpRemover;
	
	fileSrv = "/etc/rc" + t->runlevelNo + ".d/" + t->oldState;
	fileSrv.append( t->oldIndex.length() == 1 ? "0" + t->oldIndex : t->oldIndex );
	fileSrv.append( t->serviceName );
	
	return tmpRemover.remove( fileSrv );
}


QString actionStack::getServiceOriginalInfo(QString srvName, QString rNo)
{
	QString sRet;
	sRet = "-";

   for(int i = 0; i < tasks.size(); i++)
		if (tasks.at( i ).serviceName == srvName && 
              tasks.at( i ).runlevelNo == rNo)
			switch (tasks.at( i ).actionType)
				{
					case ACTION_TYPE_ADD:
						sRet = "<n>";
						break;

					case ACTION_TYPE_MODIFY:
					case ACTION_TYPE_REMOVE:
						sRet = (tasks.at( i ).oldState.toUpper()  == "S" ? (QString)"Start" : (QString)"Kill") +
								 "-" + 
                         tasks.at( i ).oldIndex;
						break;
				}//switch

	return sRet;
}


void actionStack::fillActionViewer(KListWidget* listBox)
{
   QString sNewLine = "";
   listBox->clear();

   for(int i = 0; i < tasks.size(); i++)
   {
      task taskItem = tasks.at( i );
      taskItem.No = 0;//nCount;
      tasks.replace( i, taskItem );

      switch (tasks.at( i ).actionType)
      {
         case ACTION_TYPE_ADD:
            sNewLine =  QString( i18n( "%1. Add : %2 on runlevel %3 - with %4 state") )
                  .arg(i)
                  .arg(tasks.at( i ).serviceName)
                  .arg(tasks.at( i ).runlevelNo)
                  .arg(tasks.at( i ).newString());
            break;
            
         case ACTION_TYPE_MODIFY:
            sNewLine = QString( i18n( "%1. Change : %2 on runlevel %3 - from %4  to %5") )
                  .arg(i)
                  .arg(tasks.at( i ).serviceName)
                  .arg(tasks.at( i ).runlevelNo)
                  .arg(tasks.at( i ).oldString())
                  .arg(tasks.at( i ).newString());
            break;
         
         case ACTION_TYPE_REMOVE:
            sNewLine =  QString( i18n( "%1. Remove : %2 on runlevel %3") )
                  .arg(i)
                  .arg(tasks.at( i ).serviceName) 
                  .arg(tasks.at( i ).runlevelNo);
            break;
      }//switch
      
      listBox->addItem(sNewLine);
      
   }//for
  
}
