#ifndef CC_RENDER_TO_FILE_DLG_HEADER
#define CC_RENDER_TO_FILE_DLG_HEADER

#include <QDialog>

#include <ui_renderToFileDialog.h>

//! Dialog for screen to file rendering
class ccRenderToFileDlg : public QDialog, public Ui::RenderToFileDialog
{
	Q_OBJECT

public:

	//! Default constructor
	ccRenderToFileDlg(unsigned baseWidth, unsigned baseHeight, QWidget* parent = 0);

	//! On dialog acceptance, returns requested zoom
	float getZoom() const;
	//! On dialog acceptance, returns requested output filename
	QString getFilename() const;
	//! On dialog acceptance, returns whether points should be scaled or not
	bool dontScalePoints() const;
	//! Whether overlay items should be rendered
	bool renderOverlayItems() const;


	protected slots:

		void chooseFile();
		void updateInfo();
		void saveSettings();

protected:

	unsigned w;
	unsigned h;

	QString selectedFilter;
	QString currentPath;
	QString filters;
};

#endif //CC_RENDER_TO_FILE_DLG_HEADER
