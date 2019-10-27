#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void scale_img(QString img_path, QString img_name);
    ~MainWindow();

private slots:
    void on_pushButton_resize_clicked();

    void on_pushButton_location_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
