#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QFile"
#include <QClipboard>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->hashAlgo->addItem("MD4",QCryptographicHash::Md4);
    ui->hashAlgo->addItem("MD5",QCryptographicHash::Md5);
    ui->hashAlgo->addItem("SHA1",QCryptographicHash::Sha1);
    ui->hashAlgo->addItem("SHA224",QCryptographicHash::Sha224);
    ui->hashAlgo->addItem("SHA256",QCryptographicHash::Sha256);
    ui->hashAlgo->addItem("SHA384",QCryptographicHash::Sha384);
    ui->hashAlgo->addItem("SHA512",QCryptographicHash::Sha512);
    ui->hashAlgo->addItem("SHA3_224",QCryptographicHash::Sha3_224);
    ui->hashAlgo->addItem("SHA3_256",QCryptographicHash::Sha3_256);
    ui->hashAlgo->addItem("SHA3_384",QCryptographicHash::Sha3_384);
    ui->hashAlgo->addItem("SHA3_512",QCryptographicHash::Sha3_512);
    ui->hashAlgo->addItem("Keccak_224",QCryptographicHash::Keccak_224);
    ui->hashAlgo->addItem("Keccak_256",QCryptographicHash::Keccak_256);
    ui->hashAlgo->addItem("Keccak_384",QCryptographicHash::Keccak_384);
    ui->hashAlgo->addItem("Keccak_512",QCryptographicHash::Keccak_512);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_chooseFileButton_clicked()
{
    filename = QFileDialog::getOpenFileName(this);
    qDebug() << filename;
    if(filename.length() > 0) {
        ui->fileNameEdit->setText(filename);
        auto fd = new QFile(filename,this);
        if(fd->open(QIODevice::ReadOnly)) {
            auto algo = QCryptographicHash::Algorithm(ui->hashAlgo->currentData().toInt());
            auto hash = new QCryptographicHash(algo);
            hash->addData(fd);
            ui->hashResultLineEdit->setText(hash->result().toHex());
            delete hash;
        }
        delete fd;
    }

}

void MainWindow::on_hashAlgo_currentIndexChanged(const QString &arg1)
{
    (void)arg1;
    if(filename.length() > 0) {
        ui->fileNameEdit->setText(filename);
        auto fd = new QFile(filename,this);
        if(fd->open(QIODevice::ReadOnly)) {
            auto algo = QCryptographicHash::Algorithm(ui->hashAlgo->currentData().toInt());
            auto hash = new QCryptographicHash(algo);
            hash->addData(fd);
            ui->hashResultLineEdit->setText(hash->result().toHex());
            delete hash;
        }
        delete fd;
    }
}

void MainWindow::on_copyButton_clicked()
{
    QClipboard  *clipboard = QApplication::clipboard();
    clipboard->setText(ui->hashResultLineEdit->text());

}
