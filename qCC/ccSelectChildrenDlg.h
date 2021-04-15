#ifndef CC_SELECT_CHILDREN_DLG_HEADER
#define CC_SELECT_CHILDREN_DLG_HEADER

//Qt
#include <QDialog>

//qCC_db
#include <ccObject.h>

namespace Ui {
    class SelectChildrenDialog;
}


//! Minimal dialog to pick one element in a list (combo box)
class ccSelectChildrenDlg : public QDialog
{
	Q_OBJECT

public:
	//! Default constructor
	explicit ccSelectChildrenDlg(QWidget* parent = nullptr);
	~ccSelectChildrenDlg() override;

	//! Add an element to the 'type' combo box
	void addType(QString typeName, CC_CLASS_ENUM type);

	//! Returns the selected type
	CC_CLASS_ENUM getSelectedType();
	//! Returns the selected name (if any)
	QString getSelectedName();
	//! Returns the state of the strict type checkbox
	bool getStrictMatchState() const;

	//! if the type checkbox is checked the children are filtered
	//! before checking the name for matches
	bool getTypeIsUsed() const;

	//! if the name must be considered as regex
	bool getNameIsRegex() const;

	//! if performing name-match (regex or not)
	bool getNameMatchIsUsed() const;

protected slots:
	//! Called when the dialog is accepted
	void onAccept();
	
private:
	Ui::SelectChildrenDialog	*mUI;
};

#endif //CC_SELECT_CHILDREN_DLG_HEADER
