#ifndef CC_MATCH_SCALES_DIALOG_HEADER
#define CC_MATCH_SCALES_DIALOG_HEADER

#include <ui_matchScalesDlg.h>

//Local
#include "ccLibAlgorithms.h"



//! Scales matching tool dialog
class ccMatchScalesDlg : public QDialog, public Ui::MatchScalesDialog
{
	Q_OBJECT

public:
	//! Default constructor
	ccMatchScalesDlg(	const ccHObject::Container& entities,
						int defaultSelectedIndex = 0,
						QWidget* parent = 0);

	//! Returns selected index
	int getSelectedIndex() const;

	//! Sets the selected matching algorithm
	void setSelectedAlgorithm(ccLibAlgorithms::ScaleMatchingAlgorithm algorithm);

	//! Returns the selected matching algorithm
	ccLibAlgorithms::ScaleMatchingAlgorithm getSelectedAlgorithm() const;
};

#endif //CC_ENTITY_PICKER_DIALOG_HEADER
