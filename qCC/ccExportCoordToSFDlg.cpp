#include "ccExportCoordToSFDlg.h"

ccExportCoordToSFDlg::ccExportCoordToSFDlg(QWidget* parent/*=0*/)
	: QDialog(parent, Qt::Tool)
	, Ui::ExportCoordToSFDlg()
{
	setupUi(this);
}

bool ccExportCoordToSFDlg::exportX() const
{
	return xCheckBox->isChecked();
}

bool ccExportCoordToSFDlg::exportY() const
{
	return yCheckBox->isChecked();
}

bool ccExportCoordToSFDlg::exportZ() const
{
	return zCheckBox->isChecked();
}
