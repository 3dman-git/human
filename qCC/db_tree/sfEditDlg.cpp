

#include "sfEditDlg.h"

//Local
#include "ccHistogramWindow.h"

//qCC_db
#include <ccScalarField.h>

//CCLib
#include <CCConst.h>

//system
#include <assert.h>
#include <cmath>

//! Default number of steps for spin-boxes
const int SPIN_BOX_STEPS = 1000;

sfEditDlg::sfEditDlg(QWidget* parent/*=0*/)
	: QWidget(parent)
	, Ui::SFEditDlg()
	, m_associatedSF(nullptr)
	, m_associatedSFHisto(nullptr)
{
	setupUi(this);

	//histogram window
	{
		m_associatedSFHisto = new ccHistogramWindow();
		QHBoxLayout* hboxLayout = new QHBoxLayout(histoFrame);
		hboxLayout->addWidget(m_associatedSFHisto);
		hboxLayout->setContentsMargins(0, 0, 0, 0);
		m_associatedSFHisto->setSFInteractionMode(ccHistogramWindow::SFInteractionMode::All);
		m_associatedSFHisto->xAxis->setTickLabels(false);
		//m_associatedSFHisto->xAxis->setAutoSubTicks(false);
		//m_associatedSFHisto->xAxis->setSubTickCount(0);
		m_associatedSFHisto->xAxis->setAutoTickCount(6);
		m_associatedSFHisto->yAxis->setTickLabels(false);
		//m_associatedSFHisto->yAxis->setAutoSubTicks(false);
		//m_associatedSFHisto->yAxis->setSubTickCount(0);
		m_associatedSFHisto->yAxis->setAutoTickCount(3);
	}

	connect(minValSpinBox,				static_cast<void (QDoubleSpinBox::*)(double)>(&QDoubleSpinBox::valueChanged), this,	&sfEditDlg::minValSBChanged);
	connect(maxValSpinBox,				static_cast<void (QDoubleSpinBox::*)(double)>(&QDoubleSpinBox::valueChanged), this,	&sfEditDlg::maxValSBChanged);
	connect(minSatSpinBox,				static_cast<void (QDoubleSpinBox::*)(double)>(&QDoubleSpinBox::valueChanged), this,	&sfEditDlg::minSatSBChanged);
	connect(maxSatSpinBox,				static_cast<void (QDoubleSpinBox::*)(double)>(&QDoubleSpinBox::valueChanged), this,	&sfEditDlg::maxSatSBChanged);

	connect(m_associatedSFHisto,		&ccHistogramWindow::sfMinDispValChanged,	this,	&sfEditDlg::minValHistoChanged);
	connect(m_associatedSFHisto,		&ccHistogramWindow::sfMaxDispValChanged,	this,	&sfEditDlg::maxValHistoChanged);
	connect(m_associatedSFHisto,		&ccHistogramWindow::sfMinSatValChanged,		this,	&sfEditDlg::minSatHistoChanged);
	connect(m_associatedSFHisto,		&ccHistogramWindow::sfMaxSatValChanged,		this,	&sfEditDlg::maxSatHistoChanged);

	//checkboxes
	connect(nanInGreyCheckBox,			&QCheckBox::toggled,					this,	&sfEditDlg::nanInGrayChanged);
	connect(alwaysShow0CheckBox,		&QCheckBox::toggled,					this,	&sfEditDlg::alwaysShow0Changed);
	connect(symmetricalScaleCheckBox,	&QCheckBox::toggled,					this,	&sfEditDlg::symmetricalScaleChanged);
	connect(logScaleCheckBox,			&QCheckBox::toggled,					this,	&sfEditDlg::logScaleChanged);

	show();
}

void sfEditDlg::fillDialogWith(ccScalarField* sf)
{
	m_associatedSF = sf;
	if (!sf)
	{
		assert(false);
		setEnabled(false);
		histoFrame->setVisible(false);
		return;
	}

	//options (checkboxes)
	{
		bool nanValuesInGrey	= sf->areNaNValuesShownInGrey();
		bool alwaysShowZero		= sf->isZeroAlwaysShown();
		bool symmetricalScale	= sf->symmetricalScale();
		bool logScale			= sf->logScale();
		bool absoluteScale		= sf->getColorScale() && !sf->getColorScale()->isRelative();

		nanInGreyCheckBox->blockSignals(true);
		nanInGreyCheckBox->setChecked(nanValuesInGrey);
		nanInGreyCheckBox->blockSignals(false);

		alwaysShow0CheckBox->blockSignals(true);
		alwaysShow0CheckBox->setChecked(alwaysShowZero);
		alwaysShow0CheckBox->setEnabled(!logScale);
		alwaysShow0CheckBox->blockSignals(false);

		symmetricalScaleCheckBox->blockSignals(true);
		symmetricalScaleCheckBox->setChecked(symmetricalScale);
		symmetricalScaleCheckBox->setEnabled(!absoluteScale && !logScale);
		symmetricalScaleCheckBox->blockSignals(false);

		logScaleCheckBox->blockSignals(true);
		logScaleCheckBox->setChecked(logScale);
		logScaleCheckBox->blockSignals(false);

		if (logScale)
			satLabel->setText("log sat.");
		else if (symmetricalScale)
			satLabel->setText("abs. sat.");
		else
			satLabel->setText("saturation");
	}

	//displayed and saturation values
	{
		const ccScalarField::Range& displayRange = sf->displayRange();
		const ccScalarField::Range& saturationRange = sf->saturationRange();

		//special case: no need to actiate this widget for flat scalar field
		//(worse, divisions by zero may occur!)
		bool flatSF = (displayRange.maxRange() == 0);
		slidersFrame->setEnabled(!flatSF);

		//show histogram
		histoFrame->setVisible(true);
		{
			const ccScalarField::Histogram& histogram = m_associatedSF->getHistogram();
			unsigned classNumber = static_cast<unsigned>(histogram.size());
			if (classNumber == 0)
				classNumber = 128;
			m_associatedSFHisto->fromSF(m_associatedSF, classNumber, false);
		}

		/*** spinboxes ***/

		minValSpinBox->blockSignals(true);
		minSatSpinBox->blockSignals(true);
		maxSatSpinBox->blockSignals(true);
		maxValSpinBox->blockSignals(true);

		if (!flatSF)
		{
			//Minimum displayed value
			minValSpinBox->setRange(displayRange.min(), displayRange.stop());
			minValSpinBox->setSingleStep(displayRange.maxRange() / SPIN_BOX_STEPS);
			minValSpinBox->setValue(displayRange.start());

			//Minimum color saturation value
			minSatSpinBox->setRange(saturationRange.min(), saturationRange.stop());
			minSatSpinBox->setSingleStep(saturationRange.maxRange() / SPIN_BOX_STEPS);
			minSatSpinBox->setValue(saturationRange.start());

			// Maximum color saturation value slider
			maxSatSpinBox->setRange(saturationRange.start(), saturationRange.max());
			maxSatSpinBox->setSingleStep(saturationRange.maxRange() / SPIN_BOX_STEPS);
			maxSatSpinBox->setValue(saturationRange.stop());

			// Maximum displayed value slider
			maxValSpinBox->setRange(displayRange.start(), displayRange.max());
			maxValSpinBox->setSingleStep(displayRange.maxRange() / SPIN_BOX_STEPS);
			maxValSpinBox->setValue(displayRange.stop());
		}
		else
		{
			//unique value
			double uniqueVal = displayRange.min();
			minValSpinBox->setRange(uniqueVal, uniqueVal);
			minSatSpinBox->setRange(uniqueVal, uniqueVal);
			maxSatSpinBox->setRange(uniqueVal, uniqueVal);
			maxValSpinBox->setRange(uniqueVal, uniqueVal);
		}

		minValSpinBox->blockSignals(false);
		minSatSpinBox->blockSignals(false);
		maxSatSpinBox->blockSignals(false);
		maxValSpinBox->blockSignals(false);
	}
}

void sfEditDlg::minValSBChanged(double val)
{
	if (!m_associatedSF)
		return;

	m_associatedSFHisto->setMinDispValue(val);

	emit entitySFHasChanged();

	QApplication::processEvents();

}

void sfEditDlg::maxValSBChanged(double val)
{
	if (!m_associatedSF)
		return;

	m_associatedSFHisto->setMaxDispValue(val);

	emit entitySFHasChanged();

	QApplication::processEvents();
}

void sfEditDlg::minSatSBChanged(double val)
{
	if (!m_associatedSF)
		return;

	m_associatedSFHisto->setMinSatValue(val);

	emit entitySFHasChanged();

	QApplication::processEvents();
}

void sfEditDlg::maxSatSBChanged(double val)
{
	if (!m_associatedSF)
		return;

	m_associatedSFHisto->setMaxSatValue(val);

	emit entitySFHasChanged();

	QApplication::processEvents();
}

void sfEditDlg::minValHistoChanged(double val)
{
	if (!m_associatedSF)
		return;

	minValSpinBox->blockSignals(true);
	minValSpinBox->setValue(val);
	minValSpinBox->blockSignals(false);

	emit entitySFHasChanged();

	QApplication::processEvents();
}

void sfEditDlg::maxValHistoChanged(double val)
{
	if (!m_associatedSF)
		return;

	maxValSpinBox->blockSignals(true);
	maxValSpinBox->setValue(val);
	maxValSpinBox->blockSignals(false);

	emit entitySFHasChanged();

	QApplication::processEvents();
}

void sfEditDlg::minSatHistoChanged(double val)
{
	if (!m_associatedSF)
		return;

	minSatSpinBox->blockSignals(true);
	minSatSpinBox->setValue(val);
	minSatSpinBox->blockSignals(false);

	emit entitySFHasChanged();

	QApplication::processEvents();
}

void sfEditDlg::maxSatHistoChanged(double val)
{
	if (!m_associatedSF)
		return;

	maxSatSpinBox->blockSignals(true);
	maxSatSpinBox->setValue(val);
	maxSatSpinBox->blockSignals(false);

	emit entitySFHasChanged();

	QApplication::processEvents();
}

void sfEditDlg::nanInGrayChanged(bool state)
{
	if (!m_associatedSF)
		return;

	if (m_associatedSF->areNaNValuesShownInGrey() != state)
	{
		m_associatedSF->showNaNValuesInGrey(state);
		emit entitySFHasChanged();

		//m_associatedSFHisto->refreshBars();
	}
}

void sfEditDlg::alwaysShow0Changed(bool state)
{
	if (!m_associatedSF)
		return;

	if (m_associatedSF->isZeroAlwaysShown() != state)
	{
		m_associatedSF->alwaysShowZero(state);
		emit entitySFHasChanged();

		//m_associatedSFHisto->refreshBars();
	}
}

void sfEditDlg::symmetricalScaleChanged(bool state)
{
	if (!m_associatedSF)
		return;

	if (m_associatedSF->symmetricalScale() != state)
	{
		m_associatedSF->setSymmetricalScale(state);
		fillDialogWith(m_associatedSF); //the saturation sliders may need to be updated!
		emit entitySFHasChanged();

		//Saturation might change!
		m_associatedSFHisto->refresh();
		//m_associatedSFHisto->refreshBars();
	}
}

void sfEditDlg::logScaleChanged(bool state)
{
	if (!m_associatedSF)
		return;

	if (m_associatedSF->logScale() != state)
	{
		m_associatedSF->setLogScale(state);
		fillDialogWith(m_associatedSF); //the saturation sliders + the symmetrical scale checkbox may need to be updated!
		emit entitySFHasChanged();

		//Saturation might change!
		m_associatedSFHisto->refresh();
		//m_associatedSFHisto->refreshBars();
	}
}

