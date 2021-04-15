#ifndef CCABOUTDIALOG_H
#define CCABOUTDIALOG_H

#include <QDialog>

namespace Ui {
	class AboutDialog;
}

class ccAboutDialog : public QDialog
{
	Q_OBJECT

public:
	ccAboutDialog(QWidget *parent = nullptr);
	~ccAboutDialog();

private:
	Ui::AboutDialog   *mUI;
};

#endif // CCABOUTDIALOG_H
