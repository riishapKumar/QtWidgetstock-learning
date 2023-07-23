
#include "About.h"
#include "ui_about.h"
#include <QShortcut>
#include <QDate>

About::About(QWidget* parent) :
    QDialog(parent),
    ui(new Ui::About)
{
    ui->setupUi(this);
    new QShortcut(QKeySequence(Qt::CTRL + Qt::Key_Q), this, SLOT(close())); // Ctrl+Q -> OK
    ui->aboutLabel->setText(ui->aboutLabel->text().replace("$CUR$", QString::number(QDate::currentDate().year())));
}

About::~About()
{
    delete ui;
}