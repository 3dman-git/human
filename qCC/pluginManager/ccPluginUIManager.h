#ifndef CCPLUGINUIMANAGER_H
#define CCPLUGINUIMANAGER_H

#include <QActionGroup>
#include <QList>
#include <QObject>

class QAction;
class QMenu;
class QString;
class QToolBar;
class QWidget;

class ccMainAppInterface;
class ccPluginInterface;
class ccStdPluginInterface;

//! Plugin UI manager
class ccPluginUIManager : public QObject
{
	Q_OBJECT
	
public:
	ccPluginUIManager( ccMainAppInterface *appInterface, QWidget *parent );
	~ccPluginUIManager() override = default;
	
	void	init();
	
	QMenu	*pluginMenu() const;
	QMenu	*shaderAndFilterMenu() const;
	
	QToolBar *mainPluginToolbar();
	QList<QToolBar *> &additionalPluginToolbars();
	QAction *actionShowMainPluginToolbar();

	QToolBar *glFiltersToolbar();
	QAction *actionShowGLFilterToolbar();
		
	void	updateMenus();
	void	handleSelectionChanged();

	void	showAboutDialog() const;
	
private:
	void	setupActions();
	
	void	setupMenus();
	void	addActionsToMenu( ccStdPluginInterface *stdPlugin, const QList<QAction *> &actions );

	void	setupToolbars();
	void	addActionsToToolBar( ccStdPluginInterface *stdPlugin, const QList<QAction *> &actions );
	
	void	enableGLFilter();
	void	disableGLFilter();
	
	QWidget	*m_parentWidget;	// unfortunately we need this when creating new menus & toolbars
	
	ccMainAppInterface *m_appInterface;
	
	QMenu	*m_pluginMenu;
	QMenu	*m_glFilterMenu;
	
	QAction *m_actionRemoveFilter;	
	QActionGroup m_glFilterActions;
	
	QList<ccPluginInterface *> m_plugins;	
	
	QToolBar *m_mainPluginToolbar;	// if a plugin only has one action it goes here
	QList<QToolBar *> m_additionalPluginToolbars;	// if a plugin has multiple actions it gets its own toolbar
	QAction	*m_showPluginToolbar;
	
	QToolBar *m_glFiltersToolbar;
	QAction	*m_showGLFilterToolbar;
};

#endif
