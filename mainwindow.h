#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QCryptographicHash>
#include <QFileDialog>
#include <QDebug>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_chooseFileButton_clicked();

    void on_hashAlgo_currentIndexChanged(const QString &arg1);

    void on_copyButton_clicked();

private:
    Ui::MainWindow *ui;
    QString filename;
};

#endif // MAINWINDOW_H
