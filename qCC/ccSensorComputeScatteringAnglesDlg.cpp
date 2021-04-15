#include "ccSensorComputeScatteringAnglesDlg.h"

ccSensorComputeScatteringAnglesDlg::ccSensorComputeScatteringAnglesDlg(QWidget* parent/*=0*/)
	: QDialog(parent, Qt::Tool)
	, Ui::sensorComputeScatteringAnglesDlg()
{
	setupUi(this);
}

bool ccSensorComputeScatteringAnglesDlg::anglesInDegrees() const
{
	return anglesToDegCheckbox->checkState() == Qt::Checked;
}
