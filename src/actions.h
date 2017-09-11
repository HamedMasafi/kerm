/***************************************************************************
 *   Copyright (C) 2008 by Hamed Masafi                                    *
 *   Hamed.Masafi@GMail.com                                                *
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
#ifndef ACTIONS_H
#define ACTIONS_H
#include <QString>


class KListWidget;
#include "task.h"
#include <QList>

/**
   @author Hamed Masafi <Hamed.Masafi@GMail.com>
 */



class actionStack {
public:

    actionStack();
    ~actionStack();

    void newTask(task *t);
    void newTaskModify(QString servicename, QString runlevelNo, QString oldIndex, QString oldState, QString newIndex, QString newState);
    void newTaskCreate(QString servicename, QString runlevelNo, QString index, QString state);
    void newTaskRemove(QString serviceName, QString runlevelNo, QString index, QString state);
    void complateAllTasks();
    void clear();
    bool haveChanges();
    QString getServiceOriginalInfo(QString srvName, QString rNo);
    void fillActionViewer(KListWidget* listBox);

    // action types
    static const int ACTION_TYPE_MODIFY   = 1;
    static const int ACTION_TYPE_ADD      = 2;
    static const int ACTION_TYPE_REMOVE   = 3;

private:
    QList<task> tasks;
    int currentIndex;

    bool doTask_Add( const task *t );
    bool doTask_Modify( const task *t );
    bool doTask_Remove( const task *t );
};



#endif

