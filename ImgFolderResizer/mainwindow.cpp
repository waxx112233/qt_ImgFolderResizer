#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFile>
#include <QDir>
#include <QFileDialog>
#include <QPainter>
#include <QTextStream>

void MainWindow::scale_img(QString img_path, QString img_name){
    QImage img(img_path+img_name);

    int orgw = img.width();
    int orgh = img.height();
    //double orgmpx = (orgw * orgh) /1000000; //Mega px

    int newh = 0;

    //wybor rozmiaru
    //fotografia
    if (ui->comboBox->currentIndex() == 0) newh = 1200;
    //do artykulu
    if (ui->comboBox->currentIndex() == 1) newh = 600;
    //miniatura
    if (ui->comboBox->currentIndex() == 2) newh = 200;
    //ikona
    if (ui->comboBox->currentIndex() == 3) newh = 50;

    //obliczanie nowej szerokosci zgodnie z proporcjami obrazu
    int neww = (orgw*newh) / orgh;

    //ui->label->setText("Wysokosc:"+QString::number(orgh)+" Szerokosc:"+QString::number(orgw));

    //skalowanie
    QPixmap pixmap;
    pixmap = pixmap.fromImage(img.scaled(neww,newh,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));

    //nazwa pliku
    QString img_path_name ="";

    //jesli nadpisywac plik
    if (ui->radioButton->isChecked()){
        img_path_name = img_path+""+img_name;
    }
    //jesli robic miniatury
    else{
        img_path_name = img_path+"s_"+img_name; //dodac s_ przed nazwa jesli ma robic oddzielnie miniaturki
    }

    //stempel
    /*
    QString stempel = ui->lineEdit_stempel->text();
    QPainter painter( &pixmap );
    painter.setFont(QFont("Brittany Signature", 40));
    painter.drawText( QPoint(15, newh-70), stempel );
    */

    //QImage ima;
    //ima.load(img_path+"stamp.gif");
    //painter.drawImage(0, 0, pixmap);


    //zapis pliku
    QFile file(img_path_name);
    file.open(QIODevice::WriteOnly);
    pixmap.save(&file, "jpeg",100);
    file.close();
}


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

//skalowanie
void MainWindow::on_pushButton_resize_clicked()
{

    ui->progressBar->setValue(0);

    //start w sciezce
    QString img_path = ui->label->text();
    QDir dir(img_path);

    //filtr na pliki i brak simlinkow
    dir.setFilter(QDir::Files | QDir::NoSymLinks);
    //filtr tylko na jpg
    dir.setNameFilters(QStringList()<<"*.jpg");

    //pobranie listy plikow
    QFileInfoList list = dir.entryInfoList();
    //pobranie elementow listy
    for (int i = 0; i < list.size(); ++i) {
        QFileInfo fileInfo = list.at(i);
        QString fname = fileInfo.fileName();
        //sprawdzenie czy to miniaturka
        if (fname.contains("s_")){
            ui->plainTextEdit->insertPlainText("pomijam: "+fname+"\n");
        }
        //to nie miniaturka wiec zmniejszamy
        else {
            ui->plainTextEdit->insertPlainText("skaluje: "+fname+"\n");
            scale_img(img_path+"/",fname);
        }

        //procenty na pasek
        int proc =  ((i+1) * 100) /list.size();
        ui->progressBar->setValue(proc);
    }

}

//otwieranie okna ze wskazaniem lokalizacji
void MainWindow::on_pushButton_location_clicked()
{
    QString loc;
    //wczytanie domyslnej lokalizacji
    QFile inputFile(QDir::homePath()+"/.imgfolderresizer");
    if (inputFile.open(QIODevice::ReadOnly))
    {
       QTextStream in(&inputFile);
       while (!in.atEnd())
       {
          loc = in.readLine();
       }
       inputFile.close();
    }
    else {
     loc = "/home";
    }

    QString dir = QFileDialog::getExistingDirectory(this, tr("Open Directory"),
                                                loc,
                                                QFileDialog::ShowDirsOnly
                                                | QFileDialog::DontResolveSymlinks);


    if (dir!=""){
        //zapis lokalizacji
        QFile file(QDir::homePath()+"/.imgfolderresizer");
        file.open(QFile::WriteOnly|QFile::Truncate);
        QTextStream out(&file);
        out << dir;
        file.close();

        ui->label->setText(dir);
        ui->pushButton_resize->setEnabled(true);
    }
}
