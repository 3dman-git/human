#ifndef CC_ADJUST_ZOOM_DIALOG_HEADER
#define CC_ADJUST_ZOOM_DIALOG_HEADER

#include <QDialog>

#include <ui_adjustZoomDlg.h>

class ccGLWindow;

//! Dialog to set the current zoom of a 3D view (or equivalently the pixel size)
/** Orthographic mode only.
**/
class ccAdjustZoomDlg: public QDialog, public Ui::AdjustZoomDialog
{
	Q_OBJECT

public:

	ccAdjustZoomDlg(ccGLWindow* win, QWidget* parent = 0);
	virtual ~ccAdjustZoomDlg() = default;

	//! Returns requested zoom
	double getZoom() const;

protected slots:
	void onZoomChanged(double);
	void onPixelSizeChanged(double);
	void onPixelCountChanged(int);

protected:

	double m_basePixelSize;
};

#endif // CC_ADJUST_ZOOM_DIALOG_HEADER
