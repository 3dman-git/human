#include "ccScalarFieldFromColorDlg.h"

//Qt
#include <QPushButton>

//qCC_db
#include <ccPointCloud.h>

#include <assert.h>
#ifdef _MSC_VER
#include <windows.h>
#endif

ccScalarFieldFromColorDlg::ccScalarFieldFromColorDlg(QWidget* parent/*=0*/)
	: QDialog(parent, Qt::Tool)
	, Ui::scalarFieldFromColorDlg()
{
	setupUi(this);
}

bool ccScalarFieldFromColorDlg::getRStatus() const
{
	return this->checkBoxR->isChecked();
}

bool ccScalarFieldFromColorDlg::getGStatus() const
{
	return this->checkBoxG->isChecked();
}

bool ccScalarFieldFromColorDlg::getBStatus() const
{
	return this->checkBoxB->isChecked();
}

bool ccScalarFieldFromColorDlg::getAlphaStatus() const
{
	return this->checkBoxA->isChecked();
}

bool ccScalarFieldFromColorDlg::getCompositeStatus() const
{
	return this->checkBoxComposite->isChecked();
}
