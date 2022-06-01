#include "menu.hpp"
#include "ui_menu.h"
#include "mainwindow.hpp"

Menu::Menu(MainWindow* window,QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Menu)
{
    ui->setupUi(this);
    this->w = window;
    setFixedSize(this->width(), this->height());
}

Menu::~Menu()
{
    delete ui;
}


void Menu::on_radioButton_H_VS_H_clicked()
{
    w->setGameMode(0);
}


void Menu::on_radioButton_H_VS_P_clicked()
{
    w->setGameMode(1);
}


void Menu::on_radioButton_P_VS_P_clicked()
{
    w->setGameMode(2);
}


void Menu::on_radioButton_black_clicked()
{
    w->setHumanSide(BLACK);
}


void Menu::on_radioButton_white_clicked()
{
    w->setHumanSide(WHITE);
}


void Menu::on_pushButton_START_clicked()
{
    w->updateBtns();
    w->show();
    w->clickToCoor();
    close();
}

void Menu::on_radioButton_guidance_yes_clicked()
{
    w->setGuidance(true);
}


void Menu::on_radioButton_guidance_no_clicked()
{
    w->setGuidance(false);
}
