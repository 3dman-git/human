#include "ccAboutDialog.h"
#include "ccApplication.h"

#include "ui_aboutDlg.h"

ccAboutDialog::ccAboutDialog(QWidget *parent)
	: QDialog(parent)
	, mUI(new Ui::AboutDialog)
{
	setAttribute(Qt::WA_DeleteOnClose);

	mUI->setupUi(this);

	QString compilationInfo;

	compilationInfo = ccApp->versionLongStr(true);
	compilationInfo += QStringLiteral("<br><i>Compiled with");

#if defined(_MSC_VER)
	compilationInfo += QStringLiteral(" MSVC %1 and").arg(_MSC_VER);
#endif

	compilationInfo += QStringLiteral(" Qt %1").arg(QT_VERSION_STR);
	compilationInfo += QStringLiteral("</i>");

	QString htmlText = mUI->labelText->text();
	QString enrichedHtmlText = htmlText.arg(compilationInfo);

	mUI->labelText->setText(enrichedHtmlText);
}

ccAboutDialog::~ccAboutDialog()
{
	delete mUI;
}
