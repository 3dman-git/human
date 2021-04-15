#ifndef CC_PRIMITIVE_FACTORY_DLG_HEADER
#define CC_PRIMITIVE_FACTORY_DLG_HEADER

#include <ui_primitiveFactoryDlg.h>

//Qt
#include <QDialog>

class MainWindow;

//! Primitive factory
class ccPrimitiveFactoryDlg : public QDialog, public Ui::PrimitiveFactoryDlg
{
	Q_OBJECT

public:

	//! Default constructor
	explicit ccPrimitiveFactoryDlg(MainWindow* win);

protected slots:

	//! Creates currently defined primitive
	void createPrimitive();

protected:
	//! Set sphere position from clipboard
	void setSpherePositionFromClipboard();

	//! Set sphere position to origin
	void setSpherePositionToOrigin();

protected:

	//! Associated main window
	MainWindow* m_win;

};

#endif //CC_PRIMITIVE_FACTORY_DLG_HEADER
