/****************************************************************************
** Form interface generated from reading ui file 'formProcessRunner.ui'
**
** Created: Thu Sep 3 00:14:20 2009
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef FORMPROCESSRUNNER_H
#define FORMPROCESSRUNNER_H


#include <KDialog>

class QProcess;
class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class KLineEdit;
class KTextEdit;

class formProcessRunner : public KDialog
{
    Q_OBJECT

public:
    formProcessRunner( QWidget* parent = 0, Qt::WFlags fl = 0 );
    ~formProcessRunner();

    void execProcess();
    void setProcess(QString procName, QStringList procArgs, QString caption);

    QLabel* textLabelPrcCaption;
    QLabel* textLabel1;
    KLineEdit* lineEditProcess;
    QLabel* textLabel1_2;
    KTextEdit* textEditOutput;

public slots:
    void readFromStdout();
    void processExited();

protected:
    QVBoxLayout* formProcessRunnerLayout;
    QHBoxLayout* layout2;
    QSpacerItem* spacer1;

protected slots:
    virtual void languageChange();

private:
    QPixmap image0;
    void initProcessName();

    QString _procName;
    QStringList _procArgs;

};

#endif // FORMPROCESSRUNNER_H
