#ifndef CC_SCALE_DLG_HEADER
#define CC_SCALE_DLG_HEADER

//CC_Lib
#include <CCGeom.h>

//Qt
#include <QDialog>

#include <ui_scaleDlg.h>

//! Scale / multiply dialog
class ccScaleDlg : public QDialog, public Ui::ScaleDialog
{
	Q_OBJECT

public:

	//! Default constructor
	explicit ccScaleDlg(QWidget* parent = 0);

	//! Returns scales
	CCVector3d getScales() const;

	//! Whether the entity should be 'kept in place' or not
	bool keepInPlace() const;

	//! Whether the Global shift should be rescaled as well
	bool rescaleGlobalShift() const;

	//! Saves state
	void saveState();

protected slots:

	void allDimsAtOnceToggled(bool);
	void fxUpdated(double);

protected:

};

#endif //CC_SCALE_DLG_HEADER
