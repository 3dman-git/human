#ifndef CC_COLOR_LEVELS_DLG_HEADER
#define CC_COLOR_LEVELS_DLG_HEADER

//Qt
#include <QColor>

#include <ui_colorLevelsDlg.h>

class ccHistogramWindow;
class ccGenericPointCloud;

//! Dialog to change the color levels
class ccColorLevelsDlg : public QDialog, public Ui::ColorLevelsDialog
{
	Q_OBJECT

public:

	//! Default constructor
	ccColorLevelsDlg(QWidget* parent, ccGenericPointCloud* pointCloud);

protected slots:

	void onChannelChanged(int);
	void onApply();

protected:

	//! Channels
	enum CHANNELS { RGB = 0, RED = 1, GREEN = 2, BLUE = 3 };

	//! Updates histogram
	void updateHistogram();

	//! Associated histogram view
	ccHistogramWindow* m_histogram;

	//! Associated point cloud (color source)
	ccGenericPointCloud* m_cloud;


};

#endif //CC_COLOR_LEVELS_DLG_HEADER
