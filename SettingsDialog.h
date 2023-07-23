#pragma once

#include <QDialog>


namespace Ui {
	class SettingsDialog;
}

class SettingsDialog : public QDialog
{
	Q_OBJECT

		Ui::SettingsDialog* ui;

	void readTickers();
	int warnAboutEmptyTicker();

public:
	SettingsDialog(QWidget *parent = 0);
	~SettingsDialog();

public slots:
	void addTicker();
	void removeTicker();
	bool saveAndClose();


signals:
	void newTickerList();

};
