/****************************************************************************
** Form interface generated from reading ui file 'formAddService.ui'
**
** Created: Thu Sep 3 00:14:11 2009
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef FORMADDSERVICE_H
#define FORMADDSERVICE_H

#include <qvariant.h>
#include <qpixmap.h>
#include <qdialog.h>

#include <kdialog.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QSpinBox;
class KComboBox;
class QCheckBox;

class formAddService : public KDialog
{
    Q_OBJECT

public:
    formAddService( QWidget* parent = 0, Qt::WFlags fl = 0 );
    ~formAddService();

    QLabel* textLabel1_2_2_2;
    QSpinBox* spinBoxIndex;
    QLabel* textLabel1_2;
    QLabel* textLabel1_2_2;
    KComboBox* comboBoxRunlevel;
    QCheckBox* checkBoxStartService;
    //srcAddService(QWidget *parent = 0, const char *name = 0);
    QString runlevel();
    QString index();
    QString status();
    QString statusChar();
    void setRunlevels(QString rs);

protected:
    QVBoxLayout* formAddServiceLayout;
    QSpacerItem* spacerForm;
    QGridLayout* layoutElementGrid;


protected slots:
    virtual void languageChange();

private:
    QPixmap image0;

};

#endif // FORMADDSERVICE_H
