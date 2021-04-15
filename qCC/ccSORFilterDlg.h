#ifndef CC_SOR_FILTER_DLG_HEADER
#define CC_SOR_FILTER_DLG_HEADER

#include <ui_sorFilterDlg.h>

//! Dialog to choose which dimension(s) (X, Y or Z) should be exported as SF(s)
class ccSORFilterDlg : public QDialog, public Ui::SorFilterDialog
{
	Q_OBJECT

public:

	//! Default constructor
	explicit ccSORFilterDlg(QWidget* parent = 0);
};

#endif //CC_SOR_FILTER_DLG_HEADER
