#include "ccSensorComputeDistancesDlg.h"

ccSensorComputeDistancesDlg::ccSensorComputeDistancesDlg(QWidget* parent/*=0*/)
	: QDialog(parent, Qt::Tool)
	, Ui::sensorComputeDistancesDlg()
{
	setupUi(this);
}

bool ccSensorComputeDistancesDlg::computeSquaredDistances() const
{
	return checkSquaredDistance->checkState() == Qt::Checked;
}
