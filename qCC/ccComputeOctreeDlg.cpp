#include "ccComputeOctreeDlg.h"

//Local
#include "ccBoundingBoxEditorDlg.h"

//qCC_db
#include <ccOctree.h>

ccComputeOctreeDlg::ccComputeOctreeDlg(const ccBBox& baseBBox, double minCellSize, QWidget* parent/*=0*/)
	: QDialog(parent)
	, Ui::ComputeOctreeDialog()
	, m_bbEditorDlg(nullptr)
{
	setupUi(this);

	headerLabel->setText(QString("Max subdivision level: %1").arg(ccOctree::MAX_OCTREE_LEVEL));

	//minimum cell size
	if (minCellSize > 0.0)
	{
		cellSizeDoubleSpinBox->setMinimum(minCellSize);
		cellSizeDoubleSpinBox->setMaximum(1.0e9);
	}
	else
	{
		ccLog::Warning("[ccComputeOctreeDlg] Invalid minimum cell size specified!");
		cellSizeRadioButton->setEnabled(false);	
	}

	//custom bbox editor
	if (baseBBox.isValid())
	{
		m_bbEditorDlg = new ccBoundingBoxEditorDlg(this);
		m_bbEditorDlg->setBaseBBox(baseBBox,true);
		m_bbEditorDlg->forceKeepSquare(true);
		connect(customBBToolButton, &QAbstractButton::clicked, m_bbEditorDlg, &ccBoundingBoxEditorDlg::exec);
	}
	else
	{
		ccLog::Warning("[ccComputeOctreeDlg] Invalid base bounding-box specified!");
		customBBRadioButton->setEnabled(false);
	}
}

ccComputeOctreeDlg::ComputationMode ccComputeOctreeDlg::getMode() const
{
	//defaultRadioButton
	if (cellSizeRadioButton->isChecked())
		return MIN_CELL_SIZE;
	else if (customBBRadioButton->isChecked())
		return CUSTOM_BBOX;

	assert(defaultRadioButton->isChecked());
	return DEFAULT;
}

double ccComputeOctreeDlg::getMinCellSize() const
{
	return cellSizeDoubleSpinBox->value();
}

ccBBox ccComputeOctreeDlg::getCustomBBox() const
{
	return (m_bbEditorDlg ? m_bbEditorDlg->getBox() : ccBBox());
}
