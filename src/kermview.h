/*
 * kermview.h
 *
 * Copyright (C) 2007 %{AUTHOR} <%{EMAIL}>
 */
#ifndef KERMVIEW_H
#define KERMVIEW_H

#include <QtGui/QWidget>

#include "ui_kermview_base.h"

class QPainter;
class KUrl;

/**
 * This is the main view class for kerm.  Most of the non-menu,
 * non-toolbar, and non-statusbar (e.g., non frame) GUI code should go
 * here.
 *
 * @short Main view
 * @author %{AUTHOR} <%{EMAIL}>
 * @version %{VERSION}
 */

class kermView : public QWidget, public Ui::kermview_base
{
    Q_OBJECT
public:
    /**
     * Default constructor
     */
    kermView(QWidget *parent);

    /**
     * Destructor
     */
    virtual ~kermView();

private:
    Ui::kermview_base ui_kermview_base;

signals:
    /**
     * Use this signal to change the content of the statusbar
     */
    void signalChangeStatusbar(const QString& text);

    /**
     * Use this signal to change the content of the caption
     */
    void signalChangeCaption(const QString& text);

private slots:
    void switchColors();
    void settingsChanged();
};

#endif // kermVIEW_H
