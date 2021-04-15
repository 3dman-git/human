#ifndef CCVIEWERAPPLICATION_H
#define CCVIEWERAPPLICATION_H

//Common
#include <ccApplicationBase.h>

class ccViewer;

class ccViewerApplication : public ccApplicationBase
{
	Q_OBJECT
	
public:
	ccViewerApplication( int &argc, char **argv, bool isCommandLine );

	void  setViewer( ccViewer *inViewer );
	
protected:
	bool event( QEvent *inEvent ) override;
	
private:
	ccViewer *mViewer;
};

#endif
