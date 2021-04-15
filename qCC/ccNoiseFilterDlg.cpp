#include "ccNoiseFilterDlg.h"

ccNoiseFilterDlg::ccNoiseFilterDlg(QWidget* parent/*=0*/)
	: QDialog(parent, Qt::Tool)
	, Ui::NoiseFilterDialog()
{
	setupUi(this);
}
