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

#include "task.h"
#include <QString>

task::task() : serviceName("")
{ }

task::~task()
{}

QString task::newString() const
{
   return (newState == "S" ? "Start-" : "Kill-") + newIndex;
}

QString task::oldString() const
{
   return (oldState == "S" ? "Start-" : "Kill-") + oldIndex;
}

void task::setServiceName (QString s) { serviceName = s; }
void task::setRunlevelNo (QString s) { runlevelNo = s; }
void task::setOldIndex (QString s) { oldIndex = s; }
void task::setOldState (QString s) { oldState = s; }
void task::setNewIndex (QString s) { newIndex = s; }
void task::setNewState (QString s) { newState = s; }


