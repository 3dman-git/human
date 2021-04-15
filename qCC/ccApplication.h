#ifndef CCAPPLICATION_H
#define CCAPPLICATION_H

//Common
#include <ccApplicationBase.h>

class ccApplication : public ccApplicationBase
{
	Q_OBJECT

public:
	ccApplication( int &argc, char **argv, bool isCommandLine );
	
protected:
	bool event( QEvent *inEvent ) override;
};

#endif
