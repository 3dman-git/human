#include "ccAskThreeDoubleValuesDlg.h"

ccAskThreeDoubleValuesDlg::ccAskThreeDoubleValuesDlg(	const QString& vName1,
														const QString& vName2,
														const QString& vName3,
														double minVal,
														double maxVal,
														double defaultVal1,
														double defaultVal2,
														double defaultVal3,
														int precision/*=6*/,
														const char* windowTitle/*=0*/,
														QWidget* parent/*=0*/)
	: QDialog(parent, Qt::Tool)
	, Ui::AskThreeDoubleValuesDialog()
{
	setupUi(this);

	checkBox->setVisible(false);

	label1->setText(vName1);
	label2->setText(vName2);
	label3->setText(vName3);
	doubleSpinBox1->setRange(minVal,maxVal);
	doubleSpinBox2->setRange(minVal,maxVal);
	doubleSpinBox3->setRange(minVal,maxVal);
	doubleSpinBox1->setValue(defaultVal1);
	doubleSpinBox2->setValue(defaultVal2);
	doubleSpinBox3->setValue(defaultVal3);
	doubleSpinBox1->setDecimals(precision);
	doubleSpinBox2->setDecimals(precision);
	doubleSpinBox3->setDecimals(precision);

	if (windowTitle)
		setWindowTitle(windowTitle);
}

void ccAskThreeDoubleValuesDlg::showCheckbox(const QString& label, bool state, QString tooltip/*=QString()*/)
{
	checkBox->setVisible(true);
	checkBox->setEnabled(true);
	checkBox->setChecked(state);
	checkBox->setText(label);
	checkBox->setToolTip(tooltip);
}

bool ccAskThreeDoubleValuesDlg::getCheckboxState() const
{
	return checkBox->isChecked();
}
