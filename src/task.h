/*
    <one line to give the program's name and a brief idea of what it does.>
    Copyright (C) <year>  <name of author>

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along
    with this program; if not, write to the Free Software Foundation, Inc.,
    51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.

*/

#ifndef TASK_H
#define TASK_H
#include <QString>

class task
{

public:
   task();
   ~task();

   QString serviceName;
   QString runlevelNo;
   QString oldIndex;
   QString oldState;
   QString newIndex;
   QString newState;
   int     actionType;
   int     index;
   int     No;


   QString newString() const;
   QString oldString() const;

   void setServiceName (QString s);
   void setRunlevelNo (QString s);
   void setOldIndex (QString s);
   void setOldState (QString s);
   void setNewIndex (QString s);
   void setNewState (QString s);
};


#endif // TASK_H
