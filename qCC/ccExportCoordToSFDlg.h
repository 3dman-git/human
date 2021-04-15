#ifndef CC_EXPORT_COORD_TO_SF_DLG_HEADER
#define CC_EXPORT_COORD_TO_SF_DLG_HEADER

#include <ui_exportCoordToSFDlg.h>

//! Dialog to choose which dimension(s) (X, Y or Z) should be exported as SF(s)
class ccExportCoordToSFDlg : public QDialog, public Ui::ExportCoordToSFDlg
{
	Q_OBJECT

public:

	//! Default constructor
	explicit ccExportCoordToSFDlg(QWidget* parent = 0);

	//! Returns whether X dimension should be exported
	bool exportX() const;
	//! Returns whether Y dimension should be exported
	bool exportY() const;
	//! Returns whether Z dimension should be exported
	bool exportZ() const;
};

#endif //CC_EXPORT_COORD_TO_SF_DLG_HEADER
