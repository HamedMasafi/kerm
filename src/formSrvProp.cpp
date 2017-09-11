/****************************************************************************
** Form implementation generated from reading ui file 'formSrvProp.ui'
**
** Created: Thu Sep 3 00:14:43 2009
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "formSrvProp.h"

#include <KLocalizedString>
#include <KMessageBox>
#include <KImageFilePreview>
#include <KLed>
#include <KPushButton>
#include <KTabWidget>
#include <QLabel>
#include <KLineEdit>
#include <KTextEdit>
#include <kled.h>
#include <QSplitter>
#include <QLayout>
#include <QToolTip>
#include <QWhatsThis>
#include <QTreeWidget>


#include "common.h"
#include "servicefile.h"
#include "actions.h"
#include "task.h"



formSrvProp::formSrvProp( QTreeWidgetItem *lvi, QWidget* parent, Qt::WFlags fl )
    : KDialog( parent, fl )
{
   QWidget *mainWidget = new QWidget( this );
    formSrvPropLayout = new QVBoxLayout( mainWidget );
    setMainWidget( mainWidget );
    setButtons( Close );

    tabWidgetProp = new KTabWidget( mainWidget );;

    TabPage_1 = new QWidget( tabWidgetProp );
    tabLayout_1 = new QVBoxLayout( TabPage_1 );//( tab, 11, 6, "tabLayout"); 

    layout5 = new QGridLayout;//( 0, 1, 1, 0, 6, "layout5"); 

    textLabel1_2 = new QLabel( TabPage_1 );

    layout5->addWidget( textLabel1_2, 1, 0 );

    textLabel1_2_2 = new QLabel( TabPage_1 );

    layout5->addWidget( textLabel1_2_2, 2, 0 );

    lineEditDocPath = new KLineEdit( TabPage_1 );
    lineEditDocPath->setReadOnly( TRUE );

    layout5->addWidget( lineEditDocPath, 2, 1 );

    textEditShortDescript = new KTextEdit( TabPage_1 );
    textEditShortDescript->setReadOnly( TRUE );

    layout5->addWidget( textEditShortDescript, 3, 1 );

    textLabel1 = new QLabel( TabPage_1 );


    layout5->addWidget( textLabel1, 0, 0 );

    lineEditName = new KLineEdit( TabPage_1 );
    lineEditName->setReadOnly( TRUE );

    layout5->addWidget( lineEditName, 0, 1 );

    lineEditLinkPath = new KLineEdit( TabPage_1 );
    lineEditLinkPath->setReadOnly( TRUE );

    layout5->addWidget( lineEditLinkPath, 1, 1 );

    textLabel1_2_2_2 = new QLabel( TabPage_1 );
   textLabel1_2_2_2->setAlignment( Qt::AlignTop );

    layout5->addWidget( textLabel1_2_2_2, 3, 0 );
    tabLayout_1->addLayout( layout5 );
    spacer18 = new QSpacerItem( 20, 80, QSizePolicy::Minimum, QSizePolicy::Expanding );
    tabLayout_1->addItem( spacer18 );

    layout24 = new QHBoxLayout( TabPage_1 );
    spacer2 = new QSpacerItem( 54, 21, QSizePolicy::Expanding, QSizePolicy::Minimum );
    layout24->addItem( spacer2 );

    pushButtonStart = new QPushButton( TabPage_1 );
    layout24->addWidget( pushButtonStart );

    pushButtonStop = new QPushButton( TabPage_1 );
    layout24->addWidget( pushButtonStop );

    pushButtonRestart = new QPushButton( TabPage_1 );
    layout24->addWidget( pushButtonRestart );
    tabLayout_1->addLayout( layout24 );
    tabWidgetProp->addTab( TabPage_1 , QString::fromLatin1("") );

    // Tab page 2
    TabPage_2 = new QWidget( tabWidgetProp );
    tabPageLayout_2 = new QVBoxLayout( TabPage_2 );//( TabPage, 11, 6, "TabPageLayout"); 

    layoutGridLeds = new QGridLayout;//( 0, 1, 1, 10, 12, "layout22"); 

    kLedR4 = new KLed( TabPage_2 );
    layoutGridLeds->addWidget( kLedR4, 4, 1 );

    kLedR0 = new KLed( TabPage_2 );
    kLedR0->setState( KLed::Off );

    layoutGridLeds->addWidget( kLedR0, 0, 1 );

    textLabel1_3_3_2 = new QLabel( TabPage_2 );
    

    layoutGridLeds->addWidget( textLabel1_3_3_2, 6, 0 );

    textLabel1_3_2_2 = new QLabel( TabPage_2 );


    layoutGridLeds->addWidget( textLabel1_3_2_2, 3, 0 );

    kLedR2 = new KLed( TabPage_2 );
    kLedR2->setState( KLed::Off );

    layoutGridLeds->addWidget( kLedR2, 2, 1 );

    textLabel1_3_2_3 = new QLabel( TabPage_2 );


    layoutGridLeds->addWidget( textLabel1_3_2_3, 5, 0 );

    textLabel1_3_2_2_2 = new QLabel( TabPage_2 );


    layoutGridLeds->addWidget( textLabel1_3_2_2_2, 7, 0 );

    kLedR6 = new KLed( TabPage_2 );
    kLedR6->setState( KLed::Off );

    layoutGridLeds->addWidget( kLedR6, 6, 1 );

    kLedR3 = new KLed( TabPage_2 );
    kLedR3->setState( KLed::Off );

    layoutGridLeds->addWidget( kLedR3, 3, 1 );

    textLabel1_3 = new QLabel( TabPage_2 );


    layoutGridLeds->addWidget( textLabel1_3, 0, 0 );

    textLabel1_3_2 = new QLabel( TabPage_2 );


    layoutGridLeds->addWidget( textLabel1_3_2, 1, 0 );

    textLabel1_3_4 = new QLabel( TabPage_2 );


    layoutGridLeds->addWidget( textLabel1_3_4, 4, 0 );

    kLedRS = new KLed( TabPage_2 );
    kLedRS->setState( KLed::Off );

    layoutGridLeds->addWidget( kLedRS, 7, 1 );

    kLedR1 = new KLed( TabPage_2 );
    kLedR1->setState( KLed::Off );

    layoutGridLeds->addWidget( kLedR1, 1, 1 );

    textLabel1_3_3 = new QLabel( TabPage_2 );


    layoutGridLeds->addWidget( textLabel1_3_3, 2, 0 );

    kLedR5 = new KLed( TabPage_2 );
    kLedR5->setState( KLed::Off );

    layoutGridLeds->addWidget( kLedR5, 5, 1 );
    tabPageLayout_2->addLayout( layoutGridLeds );
    spacer12 = new QSpacerItem( 31, 30, QSizePolicy::Minimum, QSizePolicy::Expanding );
    tabPageLayout_2->addItem( spacer12 );
    tabWidgetProp->addTab( TabPage_2, QString::fromLatin1("") );

    // Tab page 3
    TabPage_3 = new QWidget( tabWidgetProp );
    tabLayout_3 = new QVBoxLayout( TabPage_3 );//( tab_2, 11, 6, "tabLayout_2"); 
    textLabel1_5 = new QLabel( TabPage_3 );
    tabLayout_3->addWidget( textLabel1_5 );
    textEditDescript = new KTextEdit( TabPage_3 );
    textEditDescript->setReadOnly( TRUE );
    tabLayout_3->addWidget( textEditDescript );
    tabWidgetProp->addTab( TabPage_3, QString::fromLatin1("") );

    // Tab page 4
    TabPage_4 = new QWidget( tabWidgetProp );
    TabPageLayout_4 = new QVBoxLayout( TabPage_4 );//( TabPage_2, 11, 6, "TabPageLayout_2"); 
    splitter1 = new QSplitter( TabPage_4 );
    splitter1->setOrientation( Qt::Vertical );
    listViewOriginalSet = new QTreeWidget( splitter1 );

    listViewOriginalSet->setSelectionMode( QTreeWidget::NoSelection );
    TabPageLayout_4->addWidget( splitter1 );
    tabWidgetProp->addTab( TabPage_4, QString::fromLatin1("") );


    // Tab page 5
    TabPage_5 = new QWidget( tabWidgetProp );
    TabPageLayout_5 = new QVBoxLayout( TabPage_5 );
    listViewChangedSet = new QTreeWidget( TabPage_5 );//, "listViewChangedSet" );

    listViewChangedSet->setSelectionMode( QTreeWidget::NoSelection );
    TabPageLayout_5->addWidget( listViewChangedSet );
    tabWidgetProp->addTab( TabPage_5, QString::fromLatin1("") );
    formSrvPropLayout->addWidget( tabWidgetProp );

    
    languageChange();
    resize( QSize(505, 391).expandedTo(minimumSizeHint()) );

    // signals and slots connections
    connect( pushButtonRestart, SIGNAL( clicked() ), this, SLOT( pushButtonRestart_clicked() ) );
    connect( pushButtonStop, SIGNAL( clicked() ), this, SLOT( pushButtonStop_clicked() ) );
    connect( pushButtonStart, SIGNAL( clicked() ), this, SLOT( pushButtonStart_clicked() ) );
    
    _lviData = lvi;
    initData();
}

/*
 *  Destroys the object and frees any allocated resources
 */
formSrvProp::~formSrvProp()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void formSrvProp::languageChange()
{
    setWindowTitle( i18n( "Service properties-kerm" ) );
    
    QTreeWidgetItem *___qtreewidgetitem = listViewOriginalSet->headerItem();
    ___qtreewidgetitem->setText( 0, i18n( "Runlevel" ) );
    ___qtreewidgetitem->setText( 1, i18n( "Enable" ) );
    ___qtreewidgetitem->setText( 2, i18n( "Status" ) );
    ___qtreewidgetitem->setText( 3, i18n( "Order" ) );
    
    ___qtreewidgetitem = listViewChangedSet->headerItem();
    ___qtreewidgetitem->setText( 0, i18n( "Runlevel" ) );
    ___qtreewidgetitem->setText( 1, i18n( "Enable" ) );
    ___qtreewidgetitem->setText( 2, i18n( "Status" ) );
    ___qtreewidgetitem->setText( 3, i18n( "Order" ) );

    
    textLabel1_2->setText( i18n( "Service Path:" ) );
    textLabel1_2_2->setText( i18n( "Doc Path:" ) );
    lineEditDocPath->setWhatsThis( i18n( "This field show service doc path. You can go to this location in your local fine browser (or shell) and see doc files." ) );
    textLabel1->setText( i18n( "Service name:" ) );
    lineEditName->setWhatsThis( i18n( "This field show the name of service that stored in <b>init.d</b> folder." ) );
    lineEditLinkPath->setWhatsThis( i18n( "This field show target of the service link in <b>init.d</b> folder." ) );
    textLabel1_2_2_2->setText( i18n( "Short Descript:" ) );
    pushButtonStart->setText( i18n( "St&art" ) );
    pushButtonStart->setWhatsThis( i18n( "This button <b>start </b>the service on local computer" ) );
    pushButtonStop->setText( i18n( "S&top" ) );
    pushButtonStop->setWhatsThis( i18n( "This button <b>stop </b>the service on local computer" ) );
    pushButtonRestart->setText( i18n( "&Restart" ) );
    pushButtonRestart->setWhatsThis( i18n( "This button <b>restart </b>the service on local computer" ) );

    textLabel1_3_3_2->setText( i18n( "Runlevel 6:" ) );
    textLabel1_3_2_2->setText( i18n( "Runlevel 3:" ) );
    textLabel1_3_2_3->setText( i18n( "Runlevel 5:" ) );
    textLabel1_3_2_2_2->setText( i18n( "Runlevel S:" ) );
    textLabel1_3->setText( i18n( "Runlevel 0:" ) );
    textLabel1_3_2->setText( i18n( "Runlevel 1:" ) );
    textLabel1_3_4->setText( i18n( "Runlevel 4:" ) );
    textLabel1_3_3->setText( i18n( "Runlevel 2:" ) );
    textLabel1_5->setText( i18n( "Descript:" ) );
    textEditDescript->setWhatsThis( i18n( "This text field show the description of the service. Descript of each service saved with \"Descript\" or \"Descript-short\" in script file of service in init.d directory." ) );
    listViewOriginalSet->setWhatsThis( i18n( "This table show runlevels and status of this services on these in one look." ) );
    listViewChangedSet->setWhatsThis( i18n( "This table show runlevels and status of this services on these in one look." ) );

    tabWidgetProp->setTabText( 0, "General" );
    tabWidgetProp->setTabText( 1, "Default Start" );
    tabWidgetProp->setTabText( 2, "Descript" );
    tabWidgetProp->setTabText( 3, "Default set." );
    tabWidgetProp->setTabText( 4, "Changed set" );
}



void formSrvProp::setServiceProp(QTreeWidgetItem *lvi, actionStack acts)
{
   _lviData = lvi;
   _ActClass = acts;
   initData();
}

void formSrvProp::initData()
{
   QString serviceName;
   QString docPath;
   QString defaultStart, defaultStop;
   
   serviceName = _lviData->text( common::_col_service );
   _sf = new serviceFile( serviceName );
	
   this->textEditDescript->setText 	   ( _sf->getLongDescript() );
   this->textEditShortDescript->setText( _sf->getShortDescript() );
   this->lineEditName->setText 		( serviceName );
   this->lineEditLinkPath->setText 	( "/etc/init.d/" + serviceName );
	
   docPath = _sf->getDocPath();
   if (docPath=="") docPath= i18n("<Not avaible>");
   this->lineEditDocPath->setText ( docPath );
						
   defaultStart = _sf->getDefaultStart();
   defaultStop = _sf->getDefaultStop();
   
   
   kLedR0->setState ( defaultStart.contains("0") ? KLed::On : KLed::Off );
   kLedR1->setState ( defaultStart.contains("1") ? KLed::On : KLed::Off );
   kLedR2->setState ( defaultStart.contains("2") ? KLed::On : KLed::Off );
   kLedR3->setState ( defaultStart.contains("3") ? KLed::On : KLed::Off );
   kLedR4->setState ( defaultStart.contains("4") ? KLed::On : KLed::Off );
   kLedR5->setState ( defaultStart.contains("5") ? KLed::On : KLed::Off );
   kLedR6->setState ( defaultStart.contains("6") ? KLed::On : KLed::Off );
   kLedRS->setState ( defaultStart.contains("S") ? KLed::On : KLed::Off );
   
   initListView();
}

void formSrvProp::pushButtonStart_clicked()
{
   _sf->start();
}

void formSrvProp::pushButtonStop_clicked()
{
   _sf->stop();
}

void formSrvProp::pushButtonRestart_clicked()
{
   _sf->restart();
}



/*!
    \fn formSrvProp::initListView()
 */
void formSrvProp::initListView()
{
   QString tmpData;
   QString tmpOrgData;
   QString sEnable, sStatus, sOrder;
   QTreeWidgetItem *lviChanged;
   QTreeWidgetItem *lviOriginal;
   int i;
	
   listViewChangedSet->clear();
   listViewOriginalSet->clear();
   
   for (i=0; i<=7; i++){
      tmpData = _lviData->text( i + common::_col_rl0 );				
		
      if ( tmpData == "-" ){
         sEnable = "No";
         sStatus = "-";
         sOrder = "-";
      }//if
      else{
         sEnable = "Yes";
         sStatus = tmpData.section( "-", 0, 0 );
         sOrder = tmpData.section( "-", 1, 1 );
      }//else
      
		//Add changed listViewItem
      lviChanged = new QTreeWidgetItem(listViewChangedSet, 
                                      QStringList() << "Runlevel " + common::getRunlevelText( i ) <<
                                           sEnable <<
                                           sStatus  <<
                                           sOrder );
             
		
      tmpOrgData = _ActClass.getServiceOriginalInfo( 
            _lviData->text( common::_col_service ), 
                            common::getRunlevelText( i ));
		
      if (tmpOrgData != "-") 
         tmpData = tmpOrgData;
      if ( tmpData == "-" || tmpData == "<n>" ){
         sEnable = "No";
         sStatus = "-";
         sOrder = "-";
      }//if
      else{
         sEnable = "Yes";
         sStatus = tmpData.section( "-", 0, 0 );
         sOrder = tmpData.section( "-", 1, 1 );
      }//else		
      
		//Add original listViewItem
      lviOriginal = new QTreeWidgetItem(listViewOriginalSet, 
                                       QStringList() << "Runlevel " + common::getRunlevelText( i ) <<
                                       sEnable <<
                                       sStatus <<
                                       sOrder );
   }//for
}


