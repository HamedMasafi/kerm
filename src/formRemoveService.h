/****************************************************************************
** Form interface generated from reading ui file 'formRemoveService.ui'
**
** Created: Thu Sep 3 00:14:37 2009
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef FORMREMOVESERVICE_H
#define FORMREMOVESERVICE_H

#include <KDialog>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QComboBox;

class formRemoveService : public KDialog
{
    Q_OBJECT

public:
    formRemoveService( QWidget* parent = 0, Qt::WFlags fl = 0 );
    ~formRemoveService();

    QString runlevel();
    void setRunlevels(QString rs);
    
    QLabel* textLabel1_2_2_2;
    QLabel* textLabel1_2_2;
    QComboBox* comboBoxRunlevel;


protected:
    QVBoxLayout* formRemoveServiceLayout;
    QSpacerItem* spacer2;
    QHBoxLayout* layout5;
    QHBoxLayout* layout6;
    QSpacerItem* spacer1;

protected slots:
    virtual void languageChange();

};

#endif // FORMREMOVESERVICE_H
