#include <QtGlobal>

#ifdef Q_OS_MAC
#include <QFileOpenEvent>
#endif

#include "ccviewer.h"
#include "ccViewerApplication.h"


ccViewerApplication::ccViewerApplication( int &argc, char **argv, bool isCommandLine )
	: ccApplicationBase( argc, argv, isCommandLine, QStringLiteral( "1.39" ) )
{
	setApplicationName( "CloudCompareViewer" );
}

void ccViewerApplication::setViewer(ccViewer *inViewer)
{
	mViewer = inViewer;
}

bool ccViewerApplication::event(QEvent *inEvent)
{
#ifdef Q_OS_MAC
	switch ( inEvent->type() )
	{
		case QEvent::FileOpen:
		{			
			if ( mViewer == nullptr )
			{
				return false;
			}
			
			mViewer->addToDB( { static_cast<QFileOpenEvent *>(inEvent)->file() } );
			return true;
		}
			
		default:
			break;
	}
#endif

	return ccApplicationBase::event( inEvent );
}
