#ifndef CC_SF_DISTANCES_DLG_HEADER
#define CC_SF_DISTANCES_DLG_HEADER

#include <ui_sensorComputeDistancesDlg.h>

//! Dialog for sensor range computation
class ccSensorComputeDistancesDlg : public QDialog, public Ui::sensorComputeDistancesDlg
{
	Q_OBJECT

public:

	//! Default constructor
	explicit ccSensorComputeDistancesDlg(QWidget* parent = 0);

	//! Returns whether computed distances should be squared or not
	bool computeSquaredDistances() const;

};

#endif //CC_SF_DISTANCES_DLG_HEADER
