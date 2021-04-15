#ifndef CC_UNROLL_DLG_HEADER
#define CC_UNROLL_DLG_HEADER

#include <ui_unrollDlg.h>

//CCLib
#include <CCGeom.h>
//qCC_db
#include <ccPointCloud.h>

//! Dialog: unroll clould on a cylinder or a cone
class ccUnrollDlg : public QDialog, public Ui::UnrollDialog
{
	Q_OBJECT

public:

	//! Default constructor
	explicit ccUnrollDlg(QWidget* parent = 0);

	ccPointCloud::UnrollMode getType() const;
	int getAxisDimension() const;
	bool isAxisPositionAuto() const;
	CCVector3 getAxisPosition() const;
	void getAngleRange(double& start_deg, double& stop_deg) const;
	double getRadius() const;
	double getConeHalfAngle() const;
	bool exportDeviationSF() const;

	void toPersistentSettings() const;
	void fromPersistentSettings();

protected slots:
	void shapeTypeChanged(int index);
	void axisDimensionChanged(int index);
	void axisAutoStateChanged(int checkState);

protected:
	bool coneMode;

};

#endif
