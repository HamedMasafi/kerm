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
#ifndef KERMMAINWIN_H
#define KERMMAINWIN_H

#include "servicefile.h"
#include "actions.h"

//class actionStack;
class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QAction;
class QActionGroup;
class QToolBar;
class QPopupMenu;
class QTreeWidget;
class QTreeWidgetItem;
class QGroupBox;
class QLabel;
class QSpinBox;
class QCheckBox;
class QPushButton;
class QSplitter;
class KAction;
   
/**
   @author Hamed Masafi <Hamed.Masafi@GMail.com>
*/
#include <KXmlGuiWindow>
class kermMainWin : public KXmlGuiWindow
{
   Q_OBJECT
   
public:
   kermMainWin();
   kermMainWin(QWidget* parent, Qt::WFlags fl);
   virtual ~kermMainWin();

   QTreeWidget* listViewRunlevels;
   QGroupBox* groupBoxServiceDetails;
   QLabel* lblRunlevel1;
   QLabel* lblRunlevel5;
   QLabel* lblRunlevel2;
   QLabel* lblRunlevel3;
   QLabel* lblRunlevelS;
   QLabel* lblRunlevel0;
   QLabel* lblRunlevel6;
   QLabel* lblRunlevel4;
   QSpinBox* spbIndex6;
   QSpinBox* spbIndex5;
   QSpinBox* spbIndex4;
   QSpinBox* spbIndex3;
   QSpinBox* spbIndex2;
   QSpinBox* spbIndex1;
   QCheckBox* chkStart1;
   QCheckBox* chkStart2;
   QCheckBox* chkStart3;
   QCheckBox* chkStart4;
   QCheckBox* chkStart5;
   QCheckBox* chkStart6;
   QCheckBox* chkStartS;
   QSpinBox* spbIndexS;
   QCheckBox* chkStart0;
   QSpinBox* spbIndex0;
   KMenu *ServicePopup;
   KListWidget *ActionsList;
   QSplitter *splitterMain;

   //KAction s
   KAction* fileToRunlevelAction;
   KAction* fileReloadAction;
   KAction* fileApplyAction;
   KAction* serviceStartAction;
   KAction* serviceRestartAction;
   KAction* serviceStopAction;
   KAction* servicePropertiesAction;
   KAction* serviceRemoveFromAction;
   KAction* serviceAddToAction;
   KAction* importAction;
   KAction* exportAction;
   KAction* exportSelectedAction;
   KAction* actionsShowHideAction;
   QVBoxLayout* kermMainWinViewLayout;
   QHBoxLayout* layoutListGroup;
   QVBoxLayout* layoutGroupSpacer;
   QSpacerItem* spacerGroupBox;
   
public slots:
   void on_exportAction_triggered();
   void on_importAction_triggered();
   void on_serviceStartAction_triggered();
   void on_serviceRestartAction_triggered();
   void on_serviceStopAction_triggered();
   void on_serviceAddToAction_triggered();
   void on_fileReloadAction_triggered();
  // void listViewRunlevels_mouseButtonClicked(int, QTreeWidgetItem*, const QPoint&, int);
   void checkBox_stateChanged(int);
   void spbIndex_valueChanged(const QString&);
   void on_fileApplyAction_triggered();
   void on_servicePropertiesAction_triggered();
   void on_serviceRemoveFromAction_triggered();
   void on_listViewRunlevels_itemDoubleClicked( QTreeWidgetItem * item, int column );
   void on_fileToRunlevelAction_triggered();
   void redoActivated();
   void undoActivated();
   void on_exportSelectedAction_triggered();
   void on_actionsShowHideAction_triggered();
   void on_listViewRunlevels_currentItemChanged ( QTreeWidgetItem * current, QTreeWidgetItem * previous );
   void actionCollection_actionTriggered(QAction*);
   void on_listViewRunlevels_customContextMenuRequested ( const QPoint & pos );
   
protected slots:
   virtual void languageChange();
   
   
private:
   QPixmap image0;
   void InitWindow();
   bool changeCurrentServiceStatus(QString status);
   void getInitdFiles();
   void getRunlevelServices(QString runlevelNo, int runlevelCol);
   void editListviewRow(QString servname, int runlevelNo, QString text);
   void editListviewRow(QString servname, int runlevelNo, QString text, bool);
   bool setCheckIndexState(QString text, int index);
   void reloadAllData();
   void sendNewTask(int runlevelNo);
   QString readFile(QString path);
   void getCurrentLviInfo();
   void doExport(bool);
   void initGui();
   
   actionStack          _Actions;
   QCheckBox        *CheckBoxs[8];
   QSpinBox         *SpinBoxs[8];
   QLabel           *Labels[8];
   QTreeWidgetItem    *currLvi;
   bool             _isBusy;
   serviceFile      _serviceFile;

};

#endif
