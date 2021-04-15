#ifndef CC_INTERPOLATION_DLG_HEADER
#define CC_INTERPOLATION_DLG_HEADER

#include <ui_interpolationDlg.h>

//qCC_db
#include <ccPointCloudInterpolator.h>

//! Dialog for generic interpolation algorithms
class ccInterpolationDlg : public QDialog, public Ui::InterpolationDlg
{
	Q_OBJECT

public:

	//! Default constructor
	explicit ccInterpolationDlg(QWidget* parent = 0);

	ccPointCloudInterpolator::Parameters::Method getInterpolationMethod() const;
	void setInterpolationMethod(ccPointCloudInterpolator::Parameters::Method method);

	ccPointCloudInterpolator::Parameters::Algo getInterpolationAlgorithm() const;
	void setInterpolationAlgorithm(ccPointCloudInterpolator::Parameters::Algo algo);

protected slots:

	void onRadiusUpdated(double);
};

#endif //CC_INTERPOLATION_DLG_HEADER
