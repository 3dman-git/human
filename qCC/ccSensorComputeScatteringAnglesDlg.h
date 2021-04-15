#ifndef CC_SF_SCATTERING_DLG_HEADER
#define CC_SF_SCATTERING_DLG_HEADER

#include <ui_sensorComputeScatteringAnglesDlg.h>

//! Dialog for scattering angles computation
class ccSensorComputeScatteringAnglesDlg : public QDialog, public Ui::sensorComputeScatteringAnglesDlg
{
	Q_OBJECT

public:

	//! Default constructor
	explicit ccSensorComputeScatteringAnglesDlg(QWidget* parent = 0);

	//! Returns whether angles should be converted to degrees
	bool anglesInDegrees() const;

};

#endif //CC_SF_SCATTERING_DLG_HEADER
