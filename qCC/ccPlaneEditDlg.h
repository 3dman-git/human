#ifndef CC_PLANE_EDIT_DLG_HEADER
#define CC_PLANE_EDIT_DLG_HEADER

//Local
#include <ui_planeEditDlg.h>
#include "ccPickingListener.h"

//CCLib
#include <CCGeom.h>

//Qt
#include <QDialog>

class ccGLWindow;
class ccPlane;
class ccHObject;
class ccPickingHub;

//! Dialog to create (or edit the parameters) of a plane
class ccPlaneEditDlg : public QDialog, public ccPickingListener, public Ui::PlaneEditDlg
{
	Q_OBJECT

public:

	//! Default constructor
	explicit ccPlaneEditDlg(ccPickingHub* pickingHub, QWidget* parent);

	//! Destructor
	virtual ~ccPlaneEditDlg();

	//! Links this dialog with an existing plane
	void initWithPlane(ccPlane* plane);

	//! Updates a plane with the current parameters
	void updatePlane(ccPlane* plane);

	//! Inherited from ccPickingListener
	virtual void onItemPicked(const PickedItem& pi);

public slots:

	void pickPointAsCenter(bool);
	void onDipDirChanged(double);
	void onDipDirModified(bool);
	void onNormalChanged(double);

protected slots:

	void saveParamsAndAccept();

protected: //members

	//! Picking window (if any)
	ccGLWindow* m_pickingWin;

	//! Associated plane (if any)
	ccPlane* m_associatedPlane;

	//! Picking hub
	ccPickingHub* m_pickingHub;
};

#endif
