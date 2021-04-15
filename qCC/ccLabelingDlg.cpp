#include "ccLabelingDlg.h"

#include <DgmOctree.h>

ccLabelingDlg::ccLabelingDlg(QWidget* parent/*=0*/)
	: QDialog(parent, Qt::Tool)
	, Ui::LabelingDialog()
{
	setupUi(this);

	octreeLevelSpinBox->setMaximum(CCLib::DgmOctree::MAX_OCTREE_LEVEL);
}

int ccLabelingDlg::getOctreeLevel()
{
	return octreeLevelSpinBox->value();
}

int ccLabelingDlg::getMinPointsNb()
{
	return minPtsSpinBox->value();
}

bool ccLabelingDlg::randomColors()
{
	return (randomColorsCheckBox->checkState()==Qt::Checked);
}
