#include "TickerRefreshThread.h"
#include <thread> // include this for std::this_thread::sleep_for
#include <chrono> // include this for std::chrono::seconds
#include <QApplication>
#include <QLabel>

[[ noreturn ]] void refreshTicker(Ui::MainWindow* ui) {

    while (1) {
        Ticker instance = Ticker::getInstance();

        ui->symbolColumn->setText(instance.symbolsToString());
        ui->priceColumn->setText(instance.priceToString());
        ui->changColumn->setText(instance.changeToString());

        std::this_thread::sleep_for(std::chrono::seconds(1)); // replace sleep(1) with this
    }

}
