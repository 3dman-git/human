#pragma once

//qCC_db
#include <ccHObject.h>

//Qt
#include <QDialog>

class Ui_EntitySelectionDialog;

//! Dialog to select one or multiple entities
class ccEntitySelectionDialog : public QDialog
{
	Q_OBJECT

public:
	//! Default constructor
	ccEntitySelectionDialog(const ccHObject::Container& entities,
							bool multiSelectionEnabled,
							int defaultSelectedIndex = 0,
							QWidget* parent = 0,
							QString label = QString());

	//! Destructor
	virtual ~ccEntitySelectionDialog();

	//! Returns the selected index (unique selection mode)
	int getSelectedIndex() const;

	//! Returns the selected indexes (multi-selection mode)
	void getSelectedIndexes(std::vector<int>& indexes) const;

	//! Static shortcut: unique selection mode
	static int SelectEntity(const ccHObject::Container& entities,
							int defaultSelectedIndex = 0,
							QWidget* parent = 0,
							QString label = QString());

	//! Static shortcut: multi-selection mode
	static bool SelectEntities(	const ccHObject::Container& entities,
								std::vector<int>& indexes,
								QWidget* parent = 0,
								QString label = QString());

public slots:

	//! Selects all entities
	void selectAll();
	//! Selects all entities
	void selectNone();

protected:

	//! Associated ui
	Ui_EntitySelectionDialog* m_ui;
};
