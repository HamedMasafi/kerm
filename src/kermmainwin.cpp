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




//KDE headers
#include <KLocale>
#include <KMessageBox>
#include <KApplication>
#include <KAction>
#include <KMenuBar>
#include <KMenu>
#include <KFileDialog>
#include <QTreeWidget>
#include <KListWidget>
#include <KXmlGuiWindow>
#include <KStatusBar>
#include <KActionCollection>

// Qt headers
#include <QGroupBox>
#include <QLabel>
#include <QSpinBox>
#include <QCheckBox>
#include <QLayout>
#include <QToolTip>
#include <QWhatsThis>
#include <QDir>
#include <QFile>
#include <QSplitter>

//project headers
#include "common.h"
#include "actions.h"
#include "formAddService.h"
#include "formSrvProp.h"
#include "formRemoveService.h"
#include "formSwitchToRunlevel.h"



#include "kermmainwin.h"
#include <QHeaderView>
#include "formProcessRunner.h"






kermMainWin::kermMainWin()
        : KXmlGuiWindow( 0, 0 ),
        _isBusy( FALSE )
{
    InitWindow();
}
kermMainWin::kermMainWin( QWidget* parent, Qt::WFlags fl )
        : KXmlGuiWindow( parent, fl ),
        _isBusy( FALSE )
{
    InitWindow();
}

void kermMainWin::InitWindow()
{
    (void)statusBar();

    setCentralWidget( new QWidget( this ) );
    kermMainWinViewLayout = new QVBoxLayout( centralWidget() );//, 11, 6, "kermMainWinViewLayout");

    splitterMain = new QSplitter(centralWidget());
    splitterMain->setOrientation( Qt::Vertical );
    QWidget* privateLayoutWidget = new QWidget( splitterMain );

    layoutListGroup = new QHBoxLayout( privateLayoutWidget );//, 0, 6, "layout13");

    listViewRunlevels = new QTreeWidget( privateLayoutWidget );//, "listViewRunlevels" );


    listViewRunlevels->setObjectName( "listViewRunlevels" );
    listViewRunlevels->setMidLineWidth( 1 );
    listViewRunlevels->setRootIsDecorated( FALSE );
    listViewRunlevels->setContextMenuPolicy( Qt::CustomContextMenu );
    layoutListGroup->addWidget( listViewRunlevels );

    layoutGroupSpacer = new QVBoxLayout;//0, 0, 6, "layout16");

    groupBoxServiceDetails = new QGroupBox( privateLayoutWidget );
    groupBoxServiceDetails->setEnabled( FALSE );
//TODO   groupBoxServiceDetails->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, groupBoxServiceDetails->sizePolicy().hasHeightForWidth() ) );

    QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Preferred);
    sizePolicy.setHorizontalStretch(0);
    sizePolicy.setVerticalStretch(0);


    lblRunlevel0 = new QLabel( groupBoxServiceDetails );
    sizePolicy.setHeightForWidth( lblRunlevel0 );
    lblRunlevel0->setSizePolicy( sizePolicy );

    lblRunlevel1 = new QLabel( groupBoxServiceDetails );
    sizePolicy.setHeightForWidth( lblRunlevel1 );
    lblRunlevel1->setSizePolicy( sizePolicy );

    lblRunlevel2 = new QLabel( groupBoxServiceDetails );
    sizePolicy.setHeightForWidth( lblRunlevel2 );
    lblRunlevel2->setSizePolicy( sizePolicy );

    lblRunlevel3 = new QLabel( groupBoxServiceDetails );
    sizePolicy.setHeightForWidth( lblRunlevel3 );
    lblRunlevel3->setSizePolicy( sizePolicy );

    lblRunlevel4 = new QLabel( groupBoxServiceDetails );
    sizePolicy.setHeightForWidth( lblRunlevel4 );
    lblRunlevel4->setSizePolicy( sizePolicy );

    lblRunlevel5 = new QLabel( groupBoxServiceDetails );
    sizePolicy.setHeightForWidth( lblRunlevel5 );
    lblRunlevel5->setSizePolicy( sizePolicy );

    lblRunlevel6 = new QLabel( groupBoxServiceDetails );
    sizePolicy.setHeightForWidth( lblRunlevel6 );
    lblRunlevel6->setSizePolicy( sizePolicy );

    lblRunlevelS = new QLabel( groupBoxServiceDetails );
    sizePolicy.setHeightForWidth( lblRunlevelS );
    lblRunlevelS->setSizePolicy( sizePolicy );


    spbIndex0 = new QSpinBox( groupBoxServiceDetails );
    spbIndex1 = new QSpinBox( groupBoxServiceDetails);
    spbIndex2 = new QSpinBox( groupBoxServiceDetails);
    spbIndex3 = new QSpinBox( groupBoxServiceDetails);
    spbIndex4 = new QSpinBox( groupBoxServiceDetails);
    spbIndex5 = new QSpinBox( groupBoxServiceDetails);
    spbIndex6 = new QSpinBox( groupBoxServiceDetails);
    spbIndexS = new QSpinBox( groupBoxServiceDetails);

    chkStart0 = new QCheckBox( groupBoxServiceDetails);
    chkStart1 = new QCheckBox( groupBoxServiceDetails);
    chkStart2 = new QCheckBox( groupBoxServiceDetails);
    chkStart3 = new QCheckBox( groupBoxServiceDetails);
    chkStart4 = new QCheckBox( groupBoxServiceDetails);
    chkStart5 = new QCheckBox( groupBoxServiceDetails);
    chkStart6 = new QCheckBox( groupBoxServiceDetails);
    chkStartS = new QCheckBox( groupBoxServiceDetails);





    QGridLayout *detailsLayout = new QGridLayout( groupBoxServiceDetails );
    detailsLayout->addWidget( lblRunlevel0, 0, 0 );
    detailsLayout->addWidget( lblRunlevel1, 1, 0 );
    detailsLayout->addWidget( lblRunlevel2, 2, 0 );
    detailsLayout->addWidget( lblRunlevel3, 3, 0 );
    detailsLayout->addWidget( lblRunlevel4, 4, 0 );
    detailsLayout->addWidget( lblRunlevel5, 5, 0 );
    detailsLayout->addWidget( lblRunlevel6, 6, 0 );
    detailsLayout->addWidget( lblRunlevelS, 7, 0 );

    detailsLayout->addWidget( spbIndex0, 0, 1 );
    detailsLayout->addWidget( spbIndex1, 1, 1 );
    detailsLayout->addWidget( spbIndex2, 2, 1 );
    detailsLayout->addWidget( spbIndex3, 3, 1 );
    detailsLayout->addWidget( spbIndex4, 4, 1 );
    detailsLayout->addWidget( spbIndex5, 5, 1 );
    detailsLayout->addWidget( spbIndex6, 6, 1 );
    detailsLayout->addWidget( spbIndexS, 7, 1 );


    detailsLayout->addWidget( chkStart0, 0, 2 );
    detailsLayout->addWidget( chkStart1, 1, 2 );
    detailsLayout->addWidget( chkStart2, 2, 2 );
    detailsLayout->addWidget( chkStart3, 3, 2 );
    detailsLayout->addWidget( chkStart4, 4, 2 );
    detailsLayout->addWidget( chkStart5, 5, 2 );
    detailsLayout->addWidget( chkStart6, 6, 2 );
    detailsLayout->addWidget( chkStartS, 7, 2 );

    layoutGroupSpacer->addWidget( groupBoxServiceDetails );

    spacerGroupBox = new QSpacerItem( 41, 30, QSizePolicy::Minimum, QSizePolicy::Expanding );
    layoutGroupSpacer->addItem( spacerGroupBox );

    layoutListGroup->addLayout( layoutGroupSpacer );

    ActionsList = new KListWidget(splitterMain );


    kermMainWinViewLayout->addWidget( splitterMain );

//statusBar
    statusBar()->setSizeGripEnabled(TRUE);
    statusBar()->insertFixedItem("Ready.", 0);


// menubar
    KStandardAction::quit( kapp, SLOT(quit()), actionCollection());


    exportSelectedAction  = new KAction("exportSelectedAction", this);
    exportAction = new KAction( "exportAction", this );
    importAction = new KAction( "importAction", this );
    fileToRunlevelAction = new KAction( "fileToRunlevelAction", this );
    fileReloadAction = new KAction( "fileReloadAction", this );
    fileApplyAction = new KAction( "fileApplyAction", this );
    serviceStartAction = new KAction( "serviceStartAction", this );
    serviceRestartAction = new KAction( "serviceRestartAction", this );
    serviceStopAction = new KAction( "serviceStopAction", this );
    servicePropertiesAction = new KAction( "servicePropertiesAction", this );
    serviceAddToAction = new KAction( "serviceAddToAction", this );
    serviceRemoveFromAction = new KAction( "serviceRemoveFromAction", this );
    actionsShowHideAction = new KAction( "actionsShowHideAction", this );

    actionsShowHideAction->setCheckable( true );
    actionsShowHideAction->setChecked( true );

    actionCollection()->addAction( "exportSelectedAction", exportSelectedAction );
    actionCollection()->addAction( "exportAction", exportAction );
    actionCollection()->addAction( "importAction", importAction );
    actionCollection()->addAction( "fileToRunlevelAction", fileToRunlevelAction );
    actionCollection()->addAction( "fileReloadAction", fileReloadAction );
    actionCollection()->addAction( "fileApplyAction", fileApplyAction );
    actionCollection()->addAction( "serviceStartAction", serviceStartAction );
    actionCollection()->addAction( "serviceRestartAction", serviceRestartAction );
    actionCollection()->addAction( "serviceStopAction", serviceStopAction );
    actionCollection()->addAction( "servicePropertiesAction", servicePropertiesAction );
    actionCollection()->addAction( "serviceAddToAction", serviceAddToAction );
    actionCollection()->addAction( "serviceRemoveFromAction", serviceRemoveFromAction );
    actionCollection()->addAction( "actionsShowHideAction", actionsShowHideAction );


    setupGUI(Default, "kermui.rc" );

    languageChange();
    resize( QSize(462, 343).expandedTo(minimumSizeHint()) );


    connect( chkStart0,                SIGNAL( stateChanged(int) ),            this, SLOT( checkBox_stateChanged(int) ) );
    connect( chkStart1,                SIGNAL( stateChanged(int) ),            this, SLOT( checkBox_stateChanged(int) ) );
    connect( chkStart2,                SIGNAL( stateChanged(int) ),            this, SLOT( checkBox_stateChanged(int) ) );
    connect( chkStart3,                SIGNAL( stateChanged(int) ),            this, SLOT( checkBox_stateChanged(int) ) );
    connect( chkStart4,                SIGNAL( stateChanged(int) ),            this, SLOT( checkBox_stateChanged(int) ) );
    connect( chkStart5,                SIGNAL( stateChanged(int) ),            this, SLOT( checkBox_stateChanged(int) ) );
    connect( chkStart6,                SIGNAL( stateChanged(int) ),            this, SLOT( checkBox_stateChanged(int) ) );
    connect( chkStartS,                SIGNAL( stateChanged(int) ),            this, SLOT( checkBox_stateChanged(int) ) );
    connect( spbIndex0,                SIGNAL( valueChanged(const QString&) ), this, SLOT( spbIndex_valueChanged(const QString&) ) );
    connect( spbIndex1,                SIGNAL( valueChanged(const QString&) ), this, SLOT( spbIndex_valueChanged(const QString&) ) );
    connect( spbIndex2,                SIGNAL( valueChanged(const QString&) ), this, SLOT( spbIndex_valueChanged(const QString&) ) );
    connect( spbIndex3,                SIGNAL( valueChanged(const QString&) ), this, SLOT( spbIndex_valueChanged(const QString&) ) );
    connect( spbIndex4,                SIGNAL( valueChanged(const QString&) ), this, SLOT( spbIndex_valueChanged(const QString&) ) );
    connect( spbIndex5,                SIGNAL( valueChanged(const QString&) ), this, SLOT( spbIndex_valueChanged(const QString&) ) );
    connect( spbIndex6,                SIGNAL( valueChanged(const QString&) ), this, SLOT( spbIndex_valueChanged(const QString&) ) );
    connect( spbIndexS,                SIGNAL( valueChanged(const QString&) ), this, SLOT( spbIndex_valueChanged(const QString&) ) );
    /*connect( listViewRunlevels,     SIGNAL( doubleClicked(QTreeWidgetItem*,const QPoint&,int) ),           this, SLOT( listViewRunlevels_doubleClicked(QTreeWidgetItem*,const QPoint&,int) ) );
    connect( listViewRunlevels,     SIGNAL( rightButtonClicked(QTreeWidgetItem*,const QPoint&,int) ),      this, SLOT( listViewRunlevels_rightButtonClicked(QTreeWidgetItem*,const QPoint&,int) ) );
    connect( listViewRunlevels,     SIGNAL( mouseButtonClicked(int,QTreeWidgetItem*,const QPoint&,int) ), this, SLOT( listViewRunlevels_mouseButtonClicked(int,QTreeWidgetItem*,const QPoint&,int) ) );
    */
    QMetaObject::connectSlotsByName( this );

    CheckBoxs[0] = this->chkStart0;
    CheckBoxs[1] = this->chkStart1;
    CheckBoxs[2] = this->chkStart2;
    CheckBoxs[3] = this->chkStart3;
    CheckBoxs[4] = this->chkStart4;
    CheckBoxs[5] = this->chkStart5;
    CheckBoxs[6] = this->chkStart6;
    CheckBoxs[7] = this->chkStartS;

    SpinBoxs[0] = this->spbIndex0;
    SpinBoxs[1] = this->spbIndex1;
    SpinBoxs[2] = this->spbIndex2;
    SpinBoxs[3] = this->spbIndex3;
    SpinBoxs[4] = this->spbIndex4;
    SpinBoxs[5] = this->spbIndex5;
    SpinBoxs[6] = this->spbIndex6;
    SpinBoxs[7] = this->spbIndexS;

    Labels[0]   = this->lblRunlevel0;
    Labels[1]   = this->lblRunlevel1;
    Labels[2]   = this->lblRunlevel2;
    Labels[3]   = this->lblRunlevel3;
    Labels[4]   = this->lblRunlevel4;
    Labels[5]   = this->lblRunlevel5;
    Labels[6]   = this->lblRunlevel6;
    Labels[7]   = this->lblRunlevelS;

    languageChange();

    reloadAllData();
}


kermMainWin::~kermMainWin()
{}

void kermMainWin::actionCollection_actionTriggered(QAction*)
{
    KMessageBox::information(this,"A","X");
}

void kermMainWin::languageChange()
{
    lblRunlevel0->setText( i18n("r0") );
    lblRunlevel1->setText( i18n("r1") );
    lblRunlevel2->setText( i18n("r2") );
    lblRunlevel3->setText( i18n("r3") );
    lblRunlevel4->setText( i18n("r4") );
    lblRunlevel5->setText( i18n("r5") );
    lblRunlevel6->setText( i18n("r6") );
    lblRunlevelS->setText( i18n("rS") );

    chkStart0->setText( i18n("Start") );
    chkStart1->setText( i18n("Start") );
    chkStart2->setText( i18n("Start") );
    chkStart3->setText( i18n("Start") );
    chkStart4->setText( i18n("Start") );
    chkStart5->setText( i18n("Start") );
    chkStart6->setText( i18n("Start") );
    chkStartS->setText( i18n("Start") );

    QTreeWidgetItem *___qtreewidgetitem = listViewRunlevels->headerItem();
    ___qtreewidgetitem->setText( 0, i18n( "Service" ) );
    ___qtreewidgetitem->setText( 1, i18n( "r0" ) );
    ___qtreewidgetitem->setText( 2, i18n( "r1" ) );
    ___qtreewidgetitem->setText( 3, i18n( "r2" ) );
    ___qtreewidgetitem->setText( 4, i18n( "r3" ) );
    ___qtreewidgetitem->setText( 5, i18n( "r4" ) );
    ___qtreewidgetitem->setText( 6, i18n( "r5" ) );
    ___qtreewidgetitem->setText( 7, i18n( "r6" ) );
    ___qtreewidgetitem->setText( 8, i18n( "rS" ) );
    ___qtreewidgetitem->setText( 9, i18n( "Descript" ) );
}

/* routines */

void kermMainWin::sendNewTask(int rc)
{
    QString servicename;
    QString runlevelNo;
    QString oldIndex;
    QString oldState;
    QString newIndex;
    QString newState;
    QString newLviText;

    if (!currLvi) return;
    if (currLvi->text( rc + 1 ) == "-") return;

    servicename = currLvi->text(0);
    runlevelNo = common::getRunlevelText( rc );
    oldIndex = currLvi->text( rc + 1 ).section( "-", 1, 1);
    oldState = currLvi->text( rc + 1 ).section( "", 1, 1);
    newIndex = SpinBoxs[rc]->text();
    newState = CheckBoxs[rc]->isChecked()?"S":"K";

    if (newIndex.length() == 1) newIndex = "0" + newIndex;

    if (oldIndex!=newIndex || oldState!=newState) {
        _Actions.newTaskModify( servicename, runlevelNo, oldIndex, oldState, newIndex, newState );

        newLviText = newState == "S" ? "Start" : "Kill";
        newLviText.append( "-" );
        newLviText.append( newIndex );

        currLvi->setText( rc + 1, newLviText  );
    }//if

    _Actions.fillActionViewer(this->ActionsList);
}

void kermMainWin::getInitdFiles()
{
    QDir rlDir;
    QString sFileName;
    QString path;
    serviceFile *sf;

    sf = new serviceFile();
    path = "/etc/init.d/";

    rlDir = QDir::root();
    rlDir.cd(path);

    rlDir.setFilter( QDir::Files );
    rlDir.setSorting( QDir::Size | QDir::Reversed );

    QFileInfoList rlList = rlDir.entryInfoList();

    listViewRunlevels->clear();

    const bool __sortingEnabled = listViewRunlevels->isSortingEnabled();
    listViewRunlevels->setSortingEnabled(false);
    for ( int i = 0; i < rlList.size(); i++)
    {
        sFileName = rlList.at( i ).fileName();

        if (sFileName.toLower() != "readme") {

            QTreeWidgetItem *newItem = new QTreeWidgetItem(listViewRunlevels);

            newItem->setText( 0, sFileName );

            sf->srvPath =  rlList.at( i ).filePath();
            editListviewRow(sFileName, common::_col_comment, sf->getFileDesc(TRUE) );


            for (int i=common::_col_rl0; i<=common::_col_rlS; i++) {
                newItem->setText(i, "-");
//TODO            this->listViewRunlevels->setColumnWidth(i, 40);

            }//for
        }//if
    }//for
    listViewRunlevels->setSortingEnabled( __sortingEnabled );
}

void kermMainWin::getRunlevelServices(QString runlevelNo, int runlevelCol)
{
    QDir rlDir;
    QString sFileName;
    QString path;
    QString servname;
    QString status;

    path = "/etc/rc" + runlevelNo + ".d";

    rlDir = QDir::root();
    rlDir.cd(path);

    rlDir.setFilter( QDir::Files );
    rlDir.setSorting( QDir::Size | QDir::Reversed );

    QFileInfoList rlList = rlDir.entryInfoList();

    for ( int i = 0; i < rlList.size(); i++ )
    {
        sFileName = rlList.at( i ).fileName();

        if (sFileName.toLower() != "readme") {
            servname =  sFileName.section("", 4, sFileName.length());

            status = "-";
            if (sFileName.section("", 0, 1).toLower()=="k")  status = "Kill";
            if (sFileName.section("", 0, 1).toLower()=="s")  status = "Start";

            status += "-" + sFileName.section("", 2, 3);

            editListviewRow(servname, runlevelCol, status);
        }//if
    }//for
}

void kermMainWin::editListviewRow(QString servname, int col, QString text)
{
    this->editListviewRow(servname, col, text, FALSE);
}
void kermMainWin::editListviewRow(QString servname, int col, QString text, bool applyAction )
{
    QTreeWidgetItem *lvi;
    QString lviText;
    QString
    serviceName,
    runlevelNo,
    oldState,
    oldIndex,
    newState,
    newIndex;

    lvi = listViewRunlevels->findItems(servname, Qt::MatchExactly, 0)[0];

    if (!lvi) return;

    lviText = lvi->text( col );
    lvi->setText(col, text);

    if (lviText == lvi->text( col ) ) return;

    if (applyAction)
    {
        /*
          task t;
          t.serviceName = servname;
          t.runlevelNo = common::getRunlevelText(col - 1);
          t.oldState = lviText.section( "-", 0, 0);
          t.oldIndex = lviText.section( "-", 1, 1);
          t.newState = lvi->text( col ).section( "-", 0, 0);
          t.newIndex = lvi->text( col ).section( "-", 1, 1);


          if (lviText == "-" && lvi->text( col ) != "-" ) t.actionType = actions::ACTION_TYPE_ADD;
          if (lviText != "-" && lvi->text( col ) == "-" ) t.actionType = actions::ACTION_TYPE_REMOVE;
          if (lviText != "-" && lvi->text( col ) != "-" ) t.actionType = actions::ACTION_TYPE_MODIFY;
          */

        serviceName = servname;
        runlevelNo = common::getRunlevelText(col - 1);
        oldState = lviText.section( "-", 0, 0);
        oldIndex = lviText.section( "-", 1, 1);
        newState = lvi->text( col ).section( "-", 0, 0);
        newIndex = lvi->text( col ).section( "-", 1, 1);

        if (lviText == "-" && lvi->text( col ) != "-" )
            _Actions.newTaskCreate(serviceName, runlevelNo, newIndex, newState);

        if (lviText != "-" && lvi->text( col ) == "-" )
            _Actions.newTaskRemove(serviceName, runlevelNo, oldIndex, oldState);

        if (lviText != "-" && lvi->text( col ) != "-" )
            _Actions.newTaskModify(serviceName, runlevelNo, oldIndex, oldState, newIndex, newState);

        //_Actions.newTask( &t );
        //_Actions.newTaskModify(t.serviceName, t.runlevelNo, t.oldIndex, t.oldState, t.newIndex, t.newState);
    }//if

}

bool kermMainWin::setCheckIndexState(QString text, int index)
{
    QString startState;
    QString startIndex;

    if (text=="-") {
        SpinBoxs[index]->setEnabled(FALSE);
        CheckBoxs[index]->setEnabled(FALSE);
        Labels[index]->setEnabled(FALSE);
        return FALSE;
    }
    else {
        SpinBoxs[index]->setEnabled(TRUE);
        CheckBoxs[index]->setEnabled(TRUE);
        Labels[index]->setEnabled(TRUE);

        startState=text.section("-", 0, 0);
        startIndex=text.section("-", 1, 1);

        SpinBoxs[index]->setValue(startIndex.toInt());

        if (startState.toLower()=="start")
            CheckBoxs[index]->setChecked(TRUE);
        else
            CheckBoxs[index]->setChecked(FALSE);
        return TRUE;
    }//if
}

void kermMainWin::reloadAllData()
{
    _isBusy=TRUE;

    getInitdFiles();
    getRunlevelServices("0", common::_col_rl0);
    getRunlevelServices("1", common::_col_rl1);
    getRunlevelServices("2", common::_col_rl2);
    getRunlevelServices("3", common::_col_rl3);
    getRunlevelServices("4", common::_col_rl4);
    getRunlevelServices("5", common::_col_rl5);
    getRunlevelServices("6", common::_col_rl6);
    getRunlevelServices("S", common::_col_rlS);

    _isBusy=FALSE;
    _Actions.clear();

    this->fileApplyAction->setEnabled( FALSE );
}

bool kermMainWin::changeCurrentServiceStatus(QString status)
{
    return _serviceFile.changeSatus( status );
}

void kermMainWin::getCurrentLviInfo()
{
    _isBusy = TRUE;
    currLvi = listViewRunlevels->currentItem();
    int rcount = 0;

    if (currLvi) {
        this->serviceAddToAction->setEnabled(TRUE);
        this->serviceRemoveFromAction->setEnabled(TRUE);
        this->serviceStartAction->setEnabled(TRUE);
        this->serviceStopAction->setEnabled(TRUE);
        this->serviceRestartAction->setEnabled(TRUE);
        this->servicePropertiesAction->setEnabled(TRUE);
        this->exportSelectedAction->setEnabled(TRUE);

        _serviceFile.srvPath = "/etc/init.d/" + currLvi->text( common::_col_service );

        groupBoxServiceDetails->setEnabled(TRUE);
        for (int i=0; i<=7; i++)
            rcount += setCheckIndexState(currLvi->text(i + 1), i);

        this->serviceAddToAction->setEnabled( rcount != 8 );
        this->serviceRemoveFromAction->setEnabled ( rcount != 0 );
    }//if
    _isBusy=FALSE;
}

QString kermMainWin::readFile(QString path) {
    QFile file( path );
    
    if ( file.open( QIODevice::ReadOnly ) )
        return file.readAll();
    else
        return "";
}



/* Object event implaments */
void kermMainWin::spbIndex_valueChanged(const QString&)
{
    if (_isBusy)return;
    this->fileApplyAction->setEnabled(TRUE);

    int i;
    for (i=0; i<=7; i++)
        this->sendNewTask( i );

}

void kermMainWin::checkBox_stateChanged(int)
{
    if (_isBusy)return;
    this->fileApplyAction->setEnabled(TRUE);

    int i;
    for (i=0; i<=7; i++)
        this->sendNewTask( i );

}

void kermMainWin::on_serviceStartAction_triggered()
{
    this->changeCurrentServiceStatus ("start");
}

void kermMainWin::on_serviceRestartAction_triggered()
{
    this->changeCurrentServiceStatus ("restart");
}

void kermMainWin::on_serviceStopAction_triggered()
{
    this->changeCurrentServiceStatus ("stop");
}

void kermMainWin::on_serviceAddToAction_triggered()
{
    int rc;
    QString runlevelsList;

    //is on user click() mode?
    _isBusy=TRUE;

    //if nothins is selected then go away!
    if (!currLvi) return;

    //create new runlevel_edit form and show it as a modal form
    formAddService *frmset;
    frmset = new formAddService(0, 0);
    frmset->setModal(TRUE);

    //create a list of avaible runlevels for send to frmset.
    runlevelsList = "";
    for (int i=common::_col_rl0; i<=common::_col_rlS; i++)
        if (currLvi->text(i)=="-")
            runlevelsList.append( common::getRunlevelText( i - common::_col_rl0 ) );
    frmset->setRunlevels (runlevelsList);

    //if user click OK then apply changes
    if (frmset->exec() == QDialog::Accepted) {
        if (frmset->runlevel().toLower()=="s")
            rc = common::_col_rlS;
        else
            rc = frmset->runlevel().toInt() + 1;

        currLvi->setText( rc, frmset->status() + "-" + frmset->index() );
        _Actions.newTaskCreate( currLvi->text( common::_col_service ),frmset->runlevel(), frmset->index(), frmset->statusChar() );

        this->fileApplyAction->setEnabled(TRUE);
        this->getCurrentLviInfo();
    }  //if

    _Actions.fillActionViewer(this->ActionsList);
}

void kermMainWin::on_fileReloadAction_triggered()
{
    int ret;

    if (_Actions.haveChanges() )
        ret = KMessageBox::questionYesNo( this,
                                          i18n( "Some changes not saved yet.\n Continue...?" ),
                                          i18n( "Unsaved changes" ) );

    if (ret == KMessageBox::No) return;

    this->reloadAllData();
    this->getCurrentLviInfo();
    _Actions.clear();
}

void kermMainWin::on_listViewRunlevels_currentItemChanged ( QTreeWidgetItem * , QTreeWidgetItem *  )
//void kermMainWin::listViewRunlevels_mouseButtonClicked( int,QTreeWidgetItem*,const QPoint&,int)
{
    this->getCurrentLviInfo();
}

void kermMainWin::on_fileApplyAction_triggered()
{
    int ret;

    if ( _Actions.haveChanges() )
        ret = KMessageBox::questionYesNo( this,
                                          i18n( "There are usaved changes.\nWant processed?" ),
                                          i18n( "Unsaved changes" ) );

    if (ret == KMessageBox::No) return;

    _Actions.complateAllTasks();
    reloadAllData();
}

void kermMainWin::on_servicePropertiesAction_triggered()
{
    formSrvProp *ssp;

    ssp = new formSrvProp(currLvi);
    ssp->setServiceProp(this->currLvi, _Actions);

    ssp->exec();
}

void kermMainWin::on_listViewRunlevels_customContextMenuRequested ( const QPoint &  )
{
    this->getCurrentLviInfo();

}

void kermMainWin::on_serviceRemoveFromAction_triggered()
{
    int rc;
    QString runlevelsList;
    QString srvAttText;

    //is on user click() mode?
    _isBusy = TRUE;

    //if nothins is selected then go out!
    if (!currLvi) return;

    //create new runlevel_edit form and show it as a modal form

    formRemoveService *frmset;
    frmset = new formRemoveService(0, 0);
    frmset->setModal(TRUE);

    //create a list of avaible runlevels for send to frmset.
    runlevelsList = "";
    for (int i=common::_col_rl0; i<=common::_col_rlS; i++)
        if (currLvi->text(i)!="-")
            runlevelsList.append( common::getRunlevelText( i - common::_col_rl0 ) );
    frmset->setRunlevels (runlevelsList);

    //if user click OK then apply changes
    if (frmset->exec() == QDialog::Accepted) {
        if (frmset->runlevel().toLower() == "s")
            rc = common::_col_rlS;
        else
            rc = frmset->runlevel().toInt() + 1;

        srvAttText = currLvi->text( rc );
        currLvi->setText( rc, "-" );
        _Actions.newTaskRemove( currLvi->text( common::_col_service ),
                                frmset->runlevel(), srvAttText.section( "-", 1, 1) ,
                                srvAttText.section( "", 1, 1) );

        this->fileApplyAction->setEnabled(TRUE);
        this->getCurrentLviInfo();
    }  //if

    _Actions.fillActionViewer(this->ActionsList);
}

void kermMainWin::on_listViewRunlevels_itemDoubleClicked( QTreeWidgetItem * , int  )
{
    (new formSrvProp(currLvi))->exec();
}

void kermMainWin::on_fileToRunlevelAction_triggered()
{
    formSwitchToRunlevel *rlchanger;
    rlchanger = new formSwitchToRunlevel();
    rlchanger->setModal(TRUE);
    if ( rlchanger->exec() == QDialog::Accepted )
    {
        formProcessRunner *prn;
        prn = new formProcessRunner;
        prn->setModal(TRUE);
        prn->show();
        prn->setProcess ("/sbin/telinit",
                         QStringList() << rlchanger->runlevel(),
                         QString ( i18n( "Change to runlevel %1 ..." ) ).arg( rlchanger->runlevel() ) );
        prn->execProcess();
        this->close();
    }//if
}

void kermMainWin::on_exportAction_triggered()
{
    this->doExport( FALSE );
}

void kermMainWin::on_importAction_triggered()
{
    int ret;
    QString filePath = KFileDialog::getOpenFileName(
                           KUrl( QDir::homePath() ),
                           "*.kdt|kerm data (*.kdt)\n*.*|All files (*.*)",
                           this,
                           i18n("Import system config" ) );

    if (filePath == "")
        return;

    if (_Actions.haveChanges() )
        ret = KMessageBox::questionYesNo( this,
                                          i18n( "Some changes not saved yet.\n Continue...?" ),
                                          i18n( "Unsaved changes") );

    if (ret == KMessageBox::No) return;

    reloadAllData();
    _Actions.clear();

    QFile file( filePath );
    file.open( QIODevice::ReadOnly );
    QDataStream stream( &file );
    QString buffer;
    QString rinfo[8];

    while (!stream.atEnd() )
    {
        stream >> buffer
        >> rinfo[0]
        >> rinfo[1]
        >> rinfo[2]
        >> rinfo[3]
        >> rinfo[4]
        >> rinfo[5]
        >> rinfo[6]
        >> rinfo[7];

        for (int i = common::_col_rl0; i <= common::_col_rlS; i++)
            this->editListviewRow( buffer, i, rinfo[i - 1], TRUE);

        stream >> buffer;
    }//while

    _Actions.fillActionViewer(this->ActionsList);
}

void kermMainWin::redoActivated()
{

}

void kermMainWin::undoActivated()
{

}

void kermMainWin::on_exportSelectedAction_triggered()
{
    this->doExport( TRUE );
}

void kermMainWin::doExport(bool onlySelected)
{
    QString filePath = KFileDialog::getSaveFileName(
                           KUrl( QDir::homePath() ),
                           "*.kdt|kerm data (*.kdt)\n*.*|All files (*.*)",
                           this,
                           i18n("Export system config" ) );

    if (filePath == "")
        return;

    QFile file( filePath );
    file.open( QIODevice::WriteOnly );
    QDataStream stream( &file );

    for ( int i = 0; i < listViewRunlevels->topLevelItemCount(); i++)
    {
        if ( onlySelected && !listViewRunlevels->topLevelItem( i )->isSelected() )
            continue;

        for (int col = common::_col_service; col <= common::_col_rlS; col++)
            stream << listViewRunlevels->topLevelItem( i )->text( col );
        stream << "\n";
    }//for
}

void kermMainWin::on_actionsShowHideAction_triggered()
{
    actionsShowHideAction->setChecked( actionsShowHideAction->isChecked() );
    ActionsList->setVisible( actionsShowHideAction->isChecked() );
}
