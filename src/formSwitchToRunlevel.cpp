/****************************************************************************
** Form implementation generated from reading ui file 'formSwitchToRunlevel.ui'
**
** Created: Thu Sep 3 00:14:52 2009
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "formSwitchToRunlevel.h"

#include <QLabel>
#include <KComboBox>
#include <QLayout>
#include <QToolTip>
#include <QWhatsThis>
#include <QProcess>
#include <KLocalizedString>

/*
 *  Constructs a formSwitchToRunlevel as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
formSwitchToRunlevel::formSwitchToRunlevel( QWidget* parent, Qt::WFlags fl )
        : KDialog( parent, fl )
{
    setObjectName( "formSwitchToRunlevel" );

    QWidget *mainWidget = new QWidget( this );
    formSwitchToRunlevelLayout = new QVBoxLayout( mainWidget  );//, 11, 6, "formSwitchToRunlevelLayout");
    setMainWidget( mainWidget );
    showButtonSeparator( true );

    textLabel1_2_2_2 = new QLabel;
    textLabel1_2_2_2->setWordWrap(true);
    formSwitchToRunlevelLayout->addWidget( textLabel1_2_2_2 );

    layout9 = new QHBoxLayout;// 0, 0, 6, "layout9");

    textLabel1_2_2 = new QLabel;
//TODO    textLabel1_2_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)4, (QSizePolicy::SizeType)5, 0, 0, textLabel1_2_2->sizePolicy().hasHeightForWidth() ) );
    layout9->addWidget( textLabel1_2_2 );

    comboBoxRunlevel = new KComboBox;
    layout9->addWidget( comboBoxRunlevel );
    formSwitchToRunlevelLayout->addLayout( layout9 );
    spacer2 = new QSpacerItem( 20, 180, QSizePolicy::Minimum, QSizePolicy::Expanding );
    formSwitchToRunlevelLayout->addItem( spacer2 );

    languageChange();
    resize( QSize(239, 174).expandedTo(minimumSizeHint()) );


}

/*
 *  Destroys the object and frees any allocated resources
 */
formSwitchToRunlevel::~formSwitchToRunlevel()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void formSwitchToRunlevel::languageChange()
{
    setWindowTitle( i18n( "Switch to runlevel-kerm" ) );
    textLabel1_2_2_2->setText( i18n( "You can quikly switch to a runlevel. To do this make sure you are running <b>kerm</b> as root and then choose your desired runlevel and click 'OK' button." ) );
    textLabel1_2_2->setText( i18n( "Runlevel :" ) );
    comboBoxRunlevel->clear();
    comboBoxRunlevel->addItem( i18n( "0" ) );
    comboBoxRunlevel->addItem( i18n( "1" ) );
    comboBoxRunlevel->addItem( i18n( "2" ) );
    comboBoxRunlevel->addItem( i18n( "3" ) );
    comboBoxRunlevel->addItem( i18n( "4" ) );
    comboBoxRunlevel->addItem( i18n( "5" ) );
    comboBoxRunlevel->addItem( i18n( "6" ) );
    comboBoxRunlevel->addItem( i18n( "S" ) );
    comboBoxRunlevel->setWhatsThis( i18n( "Select your runlevel.\n"
                                           "Note: only avaible runlevels are shown." ) );

}

QString formSwitchToRunlevel::runlevel() const
{
   return comboBoxRunlevel->currentText();
}
