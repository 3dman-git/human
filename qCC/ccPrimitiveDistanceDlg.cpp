#include "ccPrimitiveDistanceDlg.h"

//Qt
#include <QHeaderView>
#include <QMessageBox>


//System
#include <assert.h>

static bool s_signedDist = true;
static bool s_flipNormals = false;
static bool s_treatAsBounded = false;
ccPrimitiveDistanceDlg::ccPrimitiveDistanceDlg(QWidget* parent)
	: QDialog(parent, Qt::Tool)
	, Ui::primitiveDistanceDlg()
{
	setupUi(this);

	signedDistCheckBox->setChecked(s_signedDist);
	flipNormalsCheckBox->setEnabled(s_signedDist);
	flipNormalsCheckBox->setChecked(s_flipNormals);
	treatPlanesAsBoundedCheckBox->setUpdatesEnabled(false);
	treatPlanesAsBoundedCheckBox->setChecked(s_treatAsBounded);
	connect(cancelButton, &QPushButton::clicked, this, &ccPrimitiveDistanceDlg::cancelAndExit);
	connect(okButton, &QPushButton::clicked, this, &ccPrimitiveDistanceDlg::applyAndExit);
	connect(signedDistCheckBox, &QCheckBox::toggled, this, &ccPrimitiveDistanceDlg::toggleSigned);
}

void ccPrimitiveDistanceDlg::applyAndExit()
{
	s_signedDist = signedDistances();
	s_flipNormals = flipNormals();
	s_treatAsBounded = treatPlanesAsBounded();
	accept();
}

void ccPrimitiveDistanceDlg::cancelAndExit()
{
	reject();
}

void ccPrimitiveDistanceDlg::toggleSigned(bool state)
{
	flipNormalsCheckBox->setEnabled(state);
}

