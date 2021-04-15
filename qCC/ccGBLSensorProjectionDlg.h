#ifndef CC_GBL_SENSOR_PROJECTION_DIALOG_HEADER
#define CC_GBL_SENSOR_PROJECTION_DIALOG_HEADER

#include <ui_gblSensorProjectDlg.h>

class ccGBLSensor;

//! Ground-based (lidar) sensor parameters dialog
class ccGBLSensorProjectionDlg : public QDialog, public Ui::GBLSensorProjectDialog
{
	Q_OBJECT

public:

	//! Default constructor
	explicit ccGBLSensorProjectionDlg(QWidget* parent = 0);

	void initWithGBLSensor(const ccGBLSensor* sensor);
	void updateGBLSensor(ccGBLSensor* sensor);

};

#endif //CC_GBL_SENSOR_PROJECTION_DIALOG_HEADER
