#ifndef CC_CLIPPING_BOX_REPEAT_DIALOG_HEADER
#define CC_CLIPPING_BOX_REPEAT_DIALOG_HEADER

#include <ui_clippingBoxRepeatDlg.h>

//Qt
#include <QDialog>

//! Dialog for managing clipping box based repeated processes
class ccClippingBoxRepeatDlg : public QDialog, public Ui::ClippingBoxRepeatDlg
{
	Q_OBJECT

public:

	//! Default constructor
	ccClippingBoxRepeatDlg(bool singleContourMode = false, QWidget* parent = 0);

	//! Sets flat dimension (single contour mode only!)
	void setFlatDim(unsigned char dim);
	//! Sets repeat dimension (multiple contour mode only!)
	void setRepeatDim(unsigned char dim);

protected slots:

	//multi-contour mode
	void onDimChecked(bool);

	//single-contour mode
	void onDimXChecked(bool);
	void onDimYChecked(bool);
	void onDimZChecked(bool);

};

#endif //CC_CLIPPING_BOX_REPEAT_DIALOG_HEADER
