#ifndef CCPLUGININFODLG_H
#define CCPLUGININFODLG_H

#include <QDialog>
#include <QList>

class QModelIndex;
class QSortFilterProxyModel;
class QStandardItem;
class QStandardItemModel;

class ccPluginInterface;

namespace Ui {
	class ccPluginInfoDlg;
}

class ccPluginInfoDlg : public QDialog
{
	Q_OBJECT
	
public:
	explicit ccPluginInfoDlg( QWidget *parent = nullptr );
	~ccPluginInfoDlg() override;
	
	void	setPluginPaths( const QStringList &pluginPaths );
	void	setPluginList( const QList<ccPluginInterface *> &pluginList );
	
private:
	enum {
		PLUGIN_PTR = Qt::UserRole + 1
	};
	
	const ccPluginInterface* pluginFromItemData( const QStandardItem* item ) const;
	
	void	selectionChanged( const QModelIndex &current, const QModelIndex &previous );
	void	itemChanged( QStandardItem* item );
	
	void	updatePluginInfo( const ccPluginInterface *plugin );
	
	Ui::ccPluginInfoDlg *m_UI;
	
	QSortFilterProxyModel	*m_ProxyModel;
	QStandardItemModel		*m_ItemModel;
};

#endif
