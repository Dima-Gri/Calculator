#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Calc.h"
#include "Styles.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->frame->setStyleSheet("background-color: rgb(240, 240, 240)");

    ui->textEdit->setStyleSheet(style_for_text_edit);
    ui->textEdit_2->setStyleSheet(style_for_text_edit);

    ui->back->setStyleSheet(style_for_advanced_buttons);
    ui->skobka1->setStyleSheet(style_for_advanced_buttons);
    ui->skobka2->setStyleSheet(style_for_advanced_buttons);
    ui->push_C->setStyleSheet(style_for_advanced_buttons);
    ui->push_step->setStyleSheet(style_for_advanced_buttons);

    ui->botton_del->setStyleSheet(style_for_operation);
    ui->botton_minus->setStyleSheet(style_for_operation);
    ui->botton_plus->setStyleSheet(style_for_operation);
    ui->botton_proiz->setStyleSheet(style_for_operation);

    ui->botton_equiv->setStyleSheet(style_for_equiv);

    ui->push0->setStyleSheet(style_for_nums);
    ui->push1->setStyleSheet(style_for_nums);
    ui->push2->setStyleSheet(style_for_nums);
    ui->push3->setStyleSheet(style_for_nums);
    ui->push4->setStyleSheet(style_for_nums);
    ui->push5->setStyleSheet(style_for_nums);
    ui->push6->setStyleSheet(style_for_nums);
    ui->push7->setStyleSheet(style_for_nums);
    ui->push8->setStyleSheet(style_for_nums);
    ui->push9->setStyleSheet(style_for_nums);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::style_after_eq_botton() {
    ui->textEdit->setGeometry(1, 0, 311, 31);
    ui->textEdit_2->setGeometry(1, 31, 311, 101);
    ui->textEdit_2->clear();
    ui->textEdit->setStyleSheet("QTextEdit{"
                                "background-color: rgb(240, 240, 240);"
                                "border: 0px;"
                                "}"
                 );
}

void MainWindow::style_before_eq_botton() {
    ui->textEdit->setGeometry(1, 0, 311, 20);
    ui->textEdit_2->setGeometry(1, 20, 311, 101);
    ui->textEdit->setStyleSheet("QTextEdit{"
                                "background-color: rgb(240, 240, 240);"
                                "border: 0px;"
                                "color: rgb(154, 154, 154);"
                                "font-size: 15px}"
                 );
}

void MainWindow::add_number(int num) {
    QString strValue = QString::number(num);
    if (MainWindow::eq_was_pressed) {
        style_after_eq_botton();
        ui->textEdit->setText(strValue);
        MainWindow::eq_was_pressed = false;
    } else {
        ui->textEdit->setText(ui->textEdit->toPlainText() + strValue);
    }
}

void MainWindow::on_botton_plus_clicked() {
    if (ui->textEdit->toPlainText().size() != 0)
        ui->textEdit->setText(ui->textEdit->toPlainText() + " + ");
}

void MainWindow::on_botton_minus_clicked() {
    if (ui->textEdit->toPlainText().size() != 0)
        ui->textEdit->setText(ui->textEdit->toPlainText() + " - ");
}

void MainWindow::on_botton_proiz_clicked() {
    if (ui->textEdit->toPlainText().size() != 0)
        ui->textEdit->setText(ui->textEdit->toPlainText() + " * ");
}

void MainWindow::on_botton_del_clicked() {
    if (ui->textEdit->toPlainText().size() != 0)
        ui->textEdit->setText(ui->textEdit->toPlainText() + " / ");
}


void MainWindow::on_push_C_clicked()
{
    ui->textEdit->setGeometry(1, 0, 311, 31);
    ui->textEdit_2->setGeometry(1, 31, 311, 101);
    ui->textEdit->clear();
    ui->textEdit_2->clear();
}

void MainWindow::on_back_clicked(){
    QString str = ui->textEdit->toPlainText();
    str.resize(str.size() - 1);
    ui->textEdit->setText(str);
}


void MainWindow::on_push1_clicked() {
    add_number(1);
}

void MainWindow::on_push2_clicked(){
    add_number(2);
}

void MainWindow::on_push3_clicked() {
    add_number(3);
}

void MainWindow::on_push4_clicked() {
    add_number(4);
}

void MainWindow::on_push5_clicked() {
    add_number(5);
}

void MainWindow::on_push6_clicked() {
    add_number(6);
}

void MainWindow::on_push7_clicked() {
    add_number(7);
}

void MainWindow::on_push8_clicked() {
    add_number(8);
}

void MainWindow::on_push9_clicked() {
    add_number(9);
}

void MainWindow::on_push0_clicked() {
    add_number(0);
}


void MainWindow::on_botton_equiv_clicked()
{
    MainWindow::eq_was_pressed = true;
    std::string str = ui->textEdit->toPlainText().toUtf8().constData();
    if (str == "")
        return;

    Calc new_calc = Calc(str);

    QString strValue = QString::number(new_calc.result, 'f');
    int index = strValue.size() - 1;
    bool check = true;

    while (strValue[index] != '.') {
        if (strValue[index] != '0') {
            check = false;
        }
        --index;
    }
    style_before_eq_botton();
    if (!check) {
        ui->textEdit->setText(ui->textEdit->toPlainText() + " =");
        ui->textEdit_2->setText(strValue);
    } else {
        index = 0;
        QString new_strValue = "";
        while (strValue[index] != '.') {
            new_strValue += strValue[index];
            ++index;
        }
        ui->textEdit->setText(ui->textEdit->toPlainText() + " =");
        ui->textEdit_2->setText(new_strValue);
    }
}


void MainWindow::on_skobka1_clicked()
{
    if (MainWindow::eq_was_pressed) {
        style_after_eq_botton();
        ui->textEdit->setText("(");
        MainWindow::eq_was_pressed = false;
    } else {
        ui->textEdit->setText(ui->textEdit->toPlainText() + "(");
    }
}


void MainWindow::on_skobka2_clicked()
{
    if (MainWindow::eq_was_pressed) {
        style_after_eq_botton();
        ui->textEdit->setText(")");
        MainWindow::eq_was_pressed = false;
    } else {
        ui->textEdit->setText(ui->textEdit->toPlainText() + ")");
    }
}


void MainWindow::on_push_step_clicked()
{
    if (!ui->textEdit->toPlainText().contains('.') && ui->textEdit->toPlainText().size() != 0)
        ui->textEdit->setText(ui->textEdit->toPlainText() + ".");
}

