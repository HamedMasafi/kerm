/****************************************************************************
** Form implementation generated from reading ui file 'formRemoveService.ui'
**
** Created: Thu Sep 3 00:14:37 2009
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "formRemoveService.h"

#include <QComboBox>
#include <QLayout>
#include <QToolTip>
#include <QWhatsThis>
#include <QLabel>
#include <KLocalizedString>


formRemoveService::formRemoveService( QWidget* parent, Qt::WFlags fl )
        : KDialog( parent, fl )
{
   QFrame* mainWidget = new QFrame( this );
    formRemoveServiceLayout = new QVBoxLayout( mainWidget );
    setMainWidget( mainWidget );
    showButtonSeparator(true);
    
    textLabel1_2_2_2 = new QLabel;
    textLabel1_2_2_2->setWordWrap(true);
    formRemoveServiceLayout->addWidget( textLabel1_2_2_2 );

    layout5 = new QHBoxLayout;

    textLabel1_2_2 = new QLabel;
    textLabel1_2_2->setWordWrap( true );
    layout5->addWidget( textLabel1_2_2 );

    comboBoxRunlevel = new QComboBox;
    layout5->addWidget( comboBoxRunlevel );
    formRemoveServiceLayout->addLayout( layout5 );
    spacer2 = new QSpacerItem( 20, 20, QSizePolicy::Minimum, QSizePolicy::Expanding );
    formRemoveServiceLayout->addItem( spacer2 );

    layout6 = new QHBoxLayout;
    spacer1 = new QSpacerItem( 86, 20, QSizePolicy::Expanding, QSizePolicy::Minimum );

    languageChange();
    resize( QSize(230, 168).expandedTo(minimumSizeHint()) );

    comboBoxRunlevel->addItems( QStringList() << "0" << "1" << "2" << "3" << "4"
                                << "5" << "6" << "S" );

}

/*
 *  Destroys the object and frees any allocated resources
 */
formRemoveService::~formRemoveService()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void formRemoveService::languageChange()
{
   setCaption( i18n( "Remove service" ) );

    textLabel1_2_2_2->setText( i18n( "For removing the current service from a runlevel please select  your desired runlevel and click <b>OK</b> button." ) );
    textLabel1_2_2->setText( i18n( "Runlevel" ) );
    comboBoxRunlevel->setWhatsThis( i18n( "Select your runlevel.\n"
                                           "Note: only avaible runlevels are shown." ) );
}


QString formRemoveService::runlevel()
{
    return this->comboBoxRunlevel->currentText();
}

void formRemoveService::setRunlevels(QString rs)
{
    int i;
    this->comboBoxRunlevel->clear();
    for (i=1; i<=rs.length(); i++)
        this->comboBoxRunlevel->addItem (rs.section( "", i, i ));

    this->comboBoxRunlevel->setCurrentIndex (0);
}

