#ifndef CCVIEWER_LOG_HEADER
#define CCVIEWER_LOG_HEADER

//Qt
#include <QMessageBox>
#include <QMainWindow>

//qCC_db
#include <ccLog.h>

//! Minimalist logger (only displays error messages)
class ccViewerLog : public ccLog
{
public:
	//! Default constructor
	explicit ccViewerLog(QMainWindow* parentWindow = 0) : ccLog(), m_parentWindow(parentWindow) {}

protected:
	//inherited from ccLog
	virtual void logMessage(const QString& message, int level)
	{
		if (level & LOG_ERROR)
		{
			QMessageBox::warning(m_parentWindow, "Error", message);
		}
	}

	//! Associated window
	QMainWindow* m_parentWindow;
};

#endif // CCVIEWER_LOG_HEADER
