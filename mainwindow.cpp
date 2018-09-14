#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMenu>
#include <QPainter>
#include <QListView>

static QIcon makeIcon(QColor c)
{
    QPixmap px(16,16);
    px.fill(Qt::transparent);
    QPainter p(&px);
    p.setRenderHint(QPainter::Antialiasing);
    p.setPen(Qt::NoPen);
    p.setBrush(c);
    p.drawEllipse(0, 0, px.width(), px.height());
    QIcon icon(px);


    QPixmap px2x(16,16);
    px2x.fill(Qt::transparent);
    QPainter p2x(&px2x);
    p2x.setRenderHint(QPainter::Antialiasing);
    p2x.setPen(Qt::NoPen);
    p2x.setBrush(c);
    p2x.drawEllipse(0, 0, px2x.width(), px2x.height());
    icon.addPixmap(px2x);

    return icon;
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QListView *view = new QListView(ui->comboBox);
    view->setAccessibleName("ComboxView");
    view->setMinimumWidth(300);
    ui->comboBox->setView(view);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButtonCommit_clicked()
{

}

void MainWindow::on_toolButtonColor_clicked()
{
    QMenu *menu = new QMenu(this);
    menu->setAccessibleName("IconMenu");
    menu->addAction(makeIcon(Qt::red), "Red");
    menu->addAction(makeIcon(Qt::green), "Green");
    QAction *action = menu->addAction(makeIcon(Qt::yellow), "Yellow");
    menu->addAction(makeIcon(Qt::blue), "Blue");
    menu->addAction(makeIcon(Qt::black), "Black");

    action->setCheckable(true);
    action->setChecked(true);

    QPoint pos = ui->toolButtonColor->mapToGlobal(QPoint(0, ui->toolButtonColor->height()));
    menu->popup(pos);
}

void MainWindow::on_toolButtonIndicatorMenu_clicked()
{
    QMenu *menu = new QMenu(this);
    menu->setAccessibleName("IndicatorMenu");
    menu->addAction("Red");
    menu->addAction("Green");
    QAction *action = menu->addAction("Yellow");
    menu->addAction("Blue");
    menu->addAction("Black");

    action->setCheckable(true);
    action->setChecked(true);

    QPoint pos = ui->toolButtonIndicatorMenu->mapToGlobal(QPoint(0, ui->toolButtonIndicatorMenu->height()));
    menu->popup(pos);
}
