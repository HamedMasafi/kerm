/*
 * kerm.h
 *
 * Copyright (C) 2008 %{AUTHOR} <%{EMAIL}>
 */
#ifndef KERM_H
#define KERM_H


#include <kxmlguiwindow.h>

#include "ui_prefs_base.h"

class kermView;
class QPrinter;
class KToggleAction;
class KUrl;

/**
 * This class serves as the main window for kerm.  It handles the
 * menus, toolbars, and status bars.
 *
 * @short Main window class
 * @author %{AUTHOR} <%{EMAIL}>
 * @version %{VERSION}
 */
class kerm : public KXmlGuiWindow
{
    Q_OBJECT
public:
    /**
     * Default Constructor
     */
    kerm();

    /**
     * Default Destructor
     */
    virtual ~kerm();

private slots:
    void fileNew();
    void optionsPreferences();

private:
    void setupActions();

private:
    Ui::prefs_base ui_prefs_base ;
    kermView *m_view;

    QPrinter   *m_printer;
    KToggleAction *m_toolbarAction;
    KToggleAction *m_statusbarAction;
};

#endif // _KERM_H_
