/****************************************************************************
** Form implementation generated from reading ui file 'formProcessRunner.ui'
**
** Created: Thu Sep 3 00:14:20 2009
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "formProcessRunner.h"

#include <QLabel>
#include <KLineEdit>
#include <KTextEdit>
#include <QPushButton>
#include <QLayout>
#include <QToolTip>
#include <QWhatsThis>
#include <QProcess>
#include <KLocalizedString>

QProcess *_process;
bool 		_isProcessRunning;


/*
 *  Constructs a formProcessRunner as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
formProcessRunner::formProcessRunner( QWidget* parent, Qt::WFlags fl )
    : KDialog( parent, fl )
{
    QWidget *mainWidget = new QWidget( this );
    formProcessRunnerLayout = new QVBoxLayout( mainWidget );
    setMainWidget( mainWidget );
    setButtons( Cancel );

    textLabelPrcCaption = new QLabel( this );
    textLabelPrcCaption->setMinimumSize( QSize( 0, 26 ) );
    QFont textLabelPrcCaption_font(  textLabelPrcCaption->font() );
    textLabelPrcCaption_font.setBold( TRUE );
    textLabelPrcCaption->setFont( textLabelPrcCaption_font ); 
    formProcessRunnerLayout->addWidget( textLabelPrcCaption );

    textLabel1 = new QLabel( this );
    formProcessRunnerLayout->addWidget( textLabel1 );

    lineEditProcess = new KLineEdit( this );
    lineEditProcess->setReadOnly( TRUE );
    formProcessRunnerLayout->addWidget( lineEditProcess );

    textLabel1_2 = new QLabel( this );
    formProcessRunnerLayout->addWidget( textLabel1_2 );

    textEditOutput = new KTextEdit( this );
    textEditOutput->setStyleSheet( "background-color: black; color: white;" );
    QFont textEditOutput_font(  textEditOutput->font() );
    textEditOutput_font.setFamily( "Courier" );
    textEditOutput_font.setPointSize( 11 );
    textEditOutput->setFont( textEditOutput_font ); 
    textEditOutput->setWordWrapMode( QTextOption::WordWrap );
    textEditOutput->setReadOnly( TRUE );
    formProcessRunnerLayout->addWidget( textEditOutput );

    languageChange();
    resize( QSize(472, 325).expandedTo(minimumSizeHint()) );
}

/*
 *  Destroys the object and frees any allocated resources
 */
formProcessRunner::~formProcessRunner()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void formProcessRunner::languageChange()
{
    setWindowTitle( i18n( "Process runner-kerm" ) );
    textLabelPrcCaption->setText( i18n( "Process  caption." ) );
    textLabel1->setText( i18n( "Process:" ) );
    lineEditProcess->setWhatsThis( i18n( "Process comannd path." ) );
    textLabel1_2->setText( i18n( "Output:" ) );
    textEditOutput->setText( QString::null );
    textEditOutput->setWhatsThis( "This widget simulate consol. It can run process and show output." );
}


void formProcessRunner::execProcess()
{

   connect( _process, SIGNAL(readyReadStdout()), 	this, SLOT(readFromStdout()) );
   connect( _process, SIGNAL(processExited()), 		this, SLOT(processExited() ) );

   _isProcessRunning = TRUE;
   _process->start( _procName, _procArgs );
   
   if ( !_process->exitCode() ) {
      _isProcessRunning = FALSE;
		// error handling
   }//if
}

void formProcessRunner::readFromStdout()
{
   textEditOutput->append( "# " + _process->readAllStandardOutput() );
}


void formProcessRunner::initProcessName()
{
   QStringList::Iterator sl;
   QString sprm;
   QString processCommand;
   int i;
	
   for ( sl = _procArgs.begin(); sl != _procArgs.end(); ++sl ){
      sprm = *sl;
      processCommand.append( sprm );
      processCommand.append( " " );
   }//for
	
   this->textEditOutput->setText ("# " + processCommand);
   this->lineEditProcess->setText (processCommand);
}


void formProcessRunner::setProcess(QString procName, QStringList procArgs, QString caption)
{
   textLabelPrcCaption->setText(caption);
   _process = new QProcess;
   initProcessName();
}

void formProcessRunner::processExited()
{
   _isProcessRunning=FALSE;
   setButtons( Close );
   textEditOutput->append( "*** process end ***" );
}

