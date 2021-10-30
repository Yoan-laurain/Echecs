/**
 * @authors Yoan Laurain ; Hugo Carricart ; Nathan Lesourd
 * @brief Header de MainWindow
 * @file mainwindow.h
 * @date 26/10/2021
 * @version 1.0
 */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStandardItemModel>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

    public:
        MainWindow(QWidget *parent = nullptr);
        ~MainWindow();
        void RefreshMatrice(QWidget *parent);

    private slots:
        void on_echiquierView_cellClicked(int row, int column);

        void on_tableViewEchiquier_clicked(const QModelIndex &index);

private:
        Ui::MainWindow *ui;
        QStandardItemModel *model;
};

#endif // MAINWINDOW_H
