#ifndef MENU_HPP
#define MENU_HPP

#include <QMainWindow>
#include "mainwindow.hpp"

QT_BEGIN_NAMESPACE
namespace Ui { class Menu; }
QT_END_NAMESPACE

class Menu : public QMainWindow
{
    Q_OBJECT

public:
    Menu(MainWindow* w = nullptr, QWidget *parent = nullptr);
    ~Menu();

private slots:
    void on_radioButton_H_VS_H_clicked();

    void on_radioButton_H_VS_P_clicked();

    void on_radioButton_P_VS_P_clicked();

    void on_radioButton_black_clicked();

    void on_radioButton_white_clicked();

    void on_pushButton_START_clicked();

    void on_radioButton_guidance_yes_clicked();

    void on_radioButton_guidance_no_clicked();

private:
    Ui::Menu *ui;
    MainWindow* w = nullptr;
};
#endif // MENU_HPP
