#include <QDateTime>
#include <QDebug>

#include "FileIO.h"


QString FileIO::s_applicationName;
QString FileIO::s_version;
QString FileIO::s_writerInfo;

void FileIO::setWriterInfo( const QString &applicationName, const QString &version )
{
	s_applicationName = applicationName;
	s_version = version;
	s_writerInfo = QStringLiteral( "%1 v%2" ).arg( applicationName, version );
}

QString FileIO::writerInfo()
{
	if ( s_writerInfo.isNull() )
	{
		qWarning() << "FileIO::setWriterInfo has not been called";
		
		return QStringLiteral( "(writer info not set)" );
	}
	
	return s_writerInfo;
}

QString FileIO::applicationName()
{
	return s_applicationName;
}

QString FileIO::version()
{
	return s_version;
}

QString FileIO::createdBy()
{
	return QStringLiteral( "Created by %1" ).arg( FileIO::writerInfo() );
}

QString FileIO::createdDateTime()
{
	return QStringLiteral( "Created %1" ).arg( QDateTime::currentDateTime().toString( Qt::SystemLocaleShortDate ) );
}
