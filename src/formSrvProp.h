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

#ifndef FORMSRVPROP_H
#define FORMSRVPROP_H


#include <KDialog>
#include "actions.h"

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class KTabWidget;
class QWidget;
class QLabel;
class KLineEdit;
class KTextEdit;
class KLed;
class QSplitter;
class QTreeWidget;
class QTreeWidgetItem;
class serviceFile;


class formSrvProp : public KDialog
{
    Q_OBJECT

public:
   formSrvProp( QTreeWidgetItem *lvi, QWidget* parent = 0, Qt::WindowFlags fl = 0 );
    ~formSrvProp();
    
    void setServiceProp(QTreeWidgetItem *lvi, actionStack acts);
    void initData();
    void initListView();
    
    KTabWidget* tabWidgetProp;
    QWidget* TabPage_1;
    QLabel* textLabel1_2;
    QLabel* textLabel1_2_2;
    KLineEdit* lineEditDocPath;
    KTextEdit* textEditShortDescript;
    QLabel* textLabel1;
    KLineEdit* lineEditName;
    KLineEdit* lineEditLinkPath;
    QLabel* textLabel1_2_2_2;
    QPushButton* pushButtonStart;
    QPushButton* pushButtonStop;
    QPushButton* pushButtonRestart;
    QWidget* TabPage_2;
    KLed* kLedR4;
    KLed* kLedR0;
    QLabel* textLabel1_3_3_2;
    QLabel* textLabel1_3_2_2;
    KLed* kLedR2;
    QLabel* textLabel1_3_2_3;
    QLabel* textLabel1_3_2_2_2;
    KLed* kLedR6;
    KLed* kLedR3;
    QLabel* textLabel1_3;
    QLabel* textLabel1_3_2;
    QLabel* textLabel1_3_4;
    KLed* kLedRS;
    KLed* kLedR1;
    QLabel* textLabel1_3_3;
    KLed* kLedR5;
    QWidget* TabPage_3;
    QLabel* textLabel1_5;
    KTextEdit* textEditDescript;
    QWidget* TabPage_4;
    QSplitter* splitter1;
    QTreeWidget* listViewOriginalSet;
    QWidget* TabPage_5;
    QTreeWidget* listViewChangedSet;

public slots:
    void pushButtonStart_clicked();
    void pushButtonStop_clicked();
    void pushButtonRestart_clicked();

protected:
    QVBoxLayout* formSrvPropLayout;
    QVBoxLayout* tabLayout_1;
    QSpacerItem* spacer18;
    QGridLayout* layout5;
    QHBoxLayout* layout24;
    QSpacerItem* spacer2;
    QVBoxLayout* tabPageLayout_2;
    QSpacerItem* spacer12;
    QGridLayout* layoutGridLeds;
    QVBoxLayout* tabLayout_3;
    QVBoxLayout* TabPageLayout_4;
    QVBoxLayout* TabPageLayout_5;
    QHBoxLayout* layout2;
    QSpacerItem* spacer1;

protected slots:
    virtual void languageChange();

private:
    QTreeWidgetItem *_lviData;
   actionStack _ActClass;
   serviceFile *_sf;


};

#endif // FORMSRVPROP_H
