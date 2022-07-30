#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    bool eq_was_pressed = false;
    void style_after_eq_botton();
    void style_before_eq_botton();
    void add_number(int num);

private slots:
    void on_botton_plus_clicked();

    void on_push_C_clicked();

    void on_botton_minus_clicked();

    void on_botton_proiz_clicked();

    void on_back_clicked();

    void on_push1_clicked();

    void on_push2_clicked();

    void on_push3_clicked();

    void on_push4_clicked();

    void on_push5_clicked();

    void on_push6_clicked();

    void on_push7_clicked();

    void on_push8_clicked();

    void on_push9_clicked();

    void on_push0_clicked();

    void on_botton_equiv_clicked();

    void on_botton_del_clicked();

    void on_skobka1_clicked();

    void on_skobka2_clicked();

    void on_push_step_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
