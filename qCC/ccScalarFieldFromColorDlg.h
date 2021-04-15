#ifndef CC_SF_FROM_COLOR_DLG_HEADER
#define CC_SF_FROM_COLOR_DLG_HEADER

#include <ui_scalarFieldFromColorDlg.h>

class ccPointCloud;

//! Dialog to choose 2 scalar fields (SF) and one operation for arithmetics processing
class ccScalarFieldFromColorDlg : public QDialog, public Ui::scalarFieldFromColorDlg
{
	Q_OBJECT

public:

	//! Default constructor
	explicit ccScalarFieldFromColorDlg(QWidget* parent = 0);

	//! Returns if to export R channel as SF
	bool getRStatus() const;

	//! Returns if to export G channel as SF
	bool getGStatus() const;

	//! Returns if to export B channel as SF
	bool getBStatus() const;

	//! Returns if to export Alpha channel as SF
	bool getAlphaStatus() const;

	//! Returns if to export Composite channel as SF
	bool getCompositeStatus() const;

};

#endif //CC_SF_FROM_COLOR_DLG_HEADER
