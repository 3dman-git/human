#ifndef CC_NOISE_FILTER_DLG_HEADER
#define CC_NOISE_FILTER_DLG_HEADER

#include <ui_noiseFilterDlg.h>

//! Dialog for noise filtering (based on the distance to the implicit local surface)
class ccNoiseFilterDlg : public QDialog, public Ui::NoiseFilterDialog
{
	Q_OBJECT

public:

	//! Default constructor
	explicit ccNoiseFilterDlg(QWidget* parent = 0);
};

#endif //CC_NOISE_FILTER_DLG_HEADER
