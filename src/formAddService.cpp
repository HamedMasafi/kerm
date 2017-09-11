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

#include "formAddService.h"


#include <KLocalizedString>

#include <QSpinBox>
#include <KComboBox>
#include <QCheckBox>
#include <KPushButton>
#include <QLayout>
#include <QLabel>
#include <QToolTip>
#include <QWhatsThis>



formAddService::formAddService( QWidget* parent, Qt::WFlags fl )
        : KDialog( parent, fl )
{
    QFrame* mainWidget = new QFrame( this );
    formAddServiceLayout = new QVBoxLayout( mainWidget );
    setMainWidget( mainWidget );
    showButtonSeparator(true);

    textLabel1_2_2_2 = new QLabel( this );
    textLabel1_2_2_2->setWordWrap(true);
    formAddServiceLayout->addWidget( textLabel1_2_2_2 );

    layoutElementGrid = new QGridLayout;

    spinBoxIndex = new QSpinBox( this );
    layoutElementGrid->addWidget( spinBoxIndex, 1, 1 );

    textLabel1_2 = new QLabel( this );
//TODO    textLabel1_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)4, (QSizePolicy::SizeType)5, 0, 0, textLabel1_2->sizePolicy().hasHeightForWidth() ) );
    layoutElementGrid->addWidget( textLabel1_2, 1, 0 );

    textLabel1_2_2 = new QLabel( this );
//TODO   textLabel1_2_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)4, (QSizePolicy::SizeType)5, 0, 0, textLabel1_2_2->sizePolicy().hasHeightForWidth() ) );
    layoutElementGrid->addWidget( textLabel1_2_2, 0, 0 );

    comboBoxRunlevel = new KComboBox( this );
    layoutElementGrid->addWidget( comboBoxRunlevel, 0, 1 );

    formAddServiceLayout->addLayout( layoutElementGrid );

    //checkbox line
    checkBoxStartService = new QCheckBox( this );
    checkBoxStartService->setChecked( TRUE );
    formAddServiceLayout->addWidget( checkBoxStartService );

    //spacer line
    spacerForm = new QSpacerItem( 20, 80, QSizePolicy::Minimum, QSizePolicy::Expanding );
    formAddServiceLayout->addItem( spacerForm );


    languageChange();
    resize( QSize(261, 193).expandedTo(minimumSizeHint()) );

    comboBoxRunlevel->addItems( QStringList() << "0" << "1" << "2" << "3" << "4"
                                << "5" << "6" << "S" );

}

/*
 *  Destroys the object and frees any allocated resources
 */
formAddService::~formAddService()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void formAddService::languageChange()
{
    setCaption( i18n( "Add service" ) );
    textLabel1_2_2_2->setText( i18n( "For adding the current service to a runlevel please select  your desired runlevel and click <b>OK</b> button." ) );
    textLabel1_2->setText( i18n( "Index:" ) );
    textLabel1_2->setWhatsThis( i18n( "Select order of service. When you switch to a runlevel all process by sorting index (From down to up)." ) );
    textLabel1_2_2->setText( i18n( "Runlevel" ) );
    comboBoxRunlevel->setWhatsThis( i18n( "Select your runlevel.\n"
                                          "Note: only avaible runlevels are shown." ) );
    checkBoxStartService->setText( i18n( "&Start service" ) );
    checkBoxStartService->setWhatsThis( i18n( "If you want to start this service check here else leave it unchecked." ) );
}


QString formAddService::runlevel()
{
    return this->comboBoxRunlevel->currentText();
}

QString formAddService::index()
{
    QString sret;
    sret = this->spinBoxIndex->text();
    if (sret.length() == 1)
        sret = "0" + sret;
    return sret;
}

QString formAddService::status()
{
    return this->checkBoxStartService->isChecked()?"Start":"Kill";
}

QString formAddService::statusChar()
{
    return this->checkBoxStartService->isChecked()?"S":"K";
}

void formAddService::setRunlevels(QString rs)
{
    int i;
    this->comboBoxRunlevel->clear();
    for (i=1; i<=rs.length(); i++)
        this->comboBoxRunlevel->addItem (rs.section( "", i, i ));

    this->comboBoxRunlevel->setCurrentIndex (0);
}
