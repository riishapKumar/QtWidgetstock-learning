#pragma once

#include "About.h"
#include "SettingsDialog.h"
#include "Ticker.h"
#include <QtWidgets/QMainWindow>
#include <QMouseEvent>
#include <QPoint>
#include "ui_mainwindow.h"


namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget* parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow* ui;
    Ticker tickerInstance = Ticker::getInstance();
    QPoint mpos;


    void changeFontSize(bool increase);

protected:
    QString currentFont;
    int fontSize;
    SettingsDialog settingsDia;
    About aboutDialog;

    void mousePressEvent(QMouseEvent* event) override;
    void mouseMoveEvent(QMouseEvent* event) override;
    void mouseReleaseEvent(QMouseEvent* event) override;


public slots:
    void showContextMenu(const QPoint& pos);
    void reloadTickersFromFile();
    void increaseFontSize();
    void decreaseFontSize();
    void openSettings();
    void openAbout();
    void endProgram();
    void loadStockData();

signals:
    void customContextMenuRequested(const QPoint& pos);
    void exitProg();
    void launchSigMach();


};