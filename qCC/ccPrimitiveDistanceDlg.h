#ifndef CC_PRIMITIVE_DISTANCE_DIALOG_HEADER
#define CC_PRIMITIVE_DISTANCE_DIALOG_HEADER

//Qt
#include <QDialog>
#include <QString>

#include <ui_primitiveDistanceDlg.h>

class ccHObject;
class ccPointCloud;
class ccGenericPointCloud;
class ccGenericMesh;

//! Dialog for cloud sphere or cloud plane comparison setting
class ccPrimitiveDistanceDlg: public QDialog, public Ui::primitiveDistanceDlg
{
	Q_OBJECT

public:

	//! Default constructor
	ccPrimitiveDistanceDlg(QWidget* parent = nullptr);

	//! Default destructor
	~ccPrimitiveDistanceDlg() = default;

	bool signedDistances() { return signedDistCheckBox->isChecked(); }
	bool flipNormals() { return flipNormalsCheckBox->isChecked(); }
	bool treatPlanesAsBounded() { return treatPlanesAsBoundedCheckBox->isChecked(); }
public slots:
	void applyAndExit();
	void cancelAndExit();


protected slots:
	void toggleSigned(bool);
};

#endif
