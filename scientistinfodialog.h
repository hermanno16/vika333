#ifndef SCIENTISTINFODIALOG_H
#define SCIENTISTINFODIALOG_H

#include <QDialog>
#include "service.h"


namespace Ui {
class ScientistInfoDialog;
}

class ScientistInfoDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ScientistInfoDialog(QWidget *parent = 0);
    ~ScientistInfoDialog();

private slots:
 //   void on_button_browse_image_clicked();
 //   void on_button_edit_scientist_clicked;
 //   void on_button_delete_scientist_clicked;


private:
    Ui::ScientistInfoDialog *ui;
    Service _service;
};

#endif // SCIENTISTINFODIALOG_H
