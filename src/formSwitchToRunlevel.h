/****************************************************************************
** Form interface generated from reading ui file 'formSwitchToRunlevel.ui'
**
** Created: Thu Sep 3 00:14:52 2009
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef FORMSWITCHTORUNLEVEL_H
#define FORMSWITCHTORUNLEVEL_H

#include <KDialog>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class KComboBox;

class formSwitchToRunlevel : public KDialog
{
    Q_OBJECT

public:
    formSwitchToRunlevel( QWidget* parent = 0, Qt::WFlags fl = 0 );
    ~formSwitchToRunlevel();

    QLabel* textLabel1_2_2_2;
    QLabel* textLabel1_2_2;
    KComboBox* comboBoxRunlevel;
    QPushButton* pushButtonCancel;
    QPushButton* pushButtonOK;
   
    QString runlevel() const;
    
protected:
    QVBoxLayout* formSwitchToRunlevelLayout;
    QSpacerItem* spacer2;
    QHBoxLayout* layout9;
    QHBoxLayout* layout10;
    QSpacerItem* spacer1;

protected slots:
    virtual void languageChange();

};

#endif // FORMSWITCHTORUNLEVEL_H
