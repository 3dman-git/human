#ifndef CC_CC_LABELING_DLG_HEADER
#define CC_CC_LABELING_DLG_HEADER

#include <ui_labelingDlg.h>

//! Dialog to define connected components labelinng parameters
class ccLabelingDlg : public QDialog, public Ui::LabelingDialog
{
	Q_OBJECT

public:

	//! Default constructor
	explicit ccLabelingDlg(QWidget* parent = 0);

	//! Returns octree level (defines grid step)
	int getOctreeLevel();

	//! Returns min number of points per extracted CC
	int getMinPointsNb();

	//! Specifies whether each extracted CC should get a random color
	bool randomColors();
};

#endif
