#ifndef FEN_PRINCIPALE_H
#define FEN_PRINCIPALE_H
#include <QApplication>
#include <QPushButton>

#include <QtWidgets>

class Fen_principale : public QMainWindow
{
    public:
    Fen_principale();


public slots :
    void Nouvelle_partie();
    void loadSituation(QString p_path);
    private:

};

#endif
