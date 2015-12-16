#ifndef ASSEMBLEDIALOG_H
#define ASSEMBLEDIALOG_H

#include <QDialog>
#include <functional>
#include "Bridge.h"
#include "ValidateExpressionThread.h"

namespace Ui
{
class AssembleDialog;
}

class AssembleDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AssembleDialog(QWidget *parent = 0);
    ~AssembleDialog();
    QString editText;
    static bool bWarningShowedOnce;
    void setTextEditValue(const QString & text);

    bool bKeepSizeChecked;
    void setKeepSizeChecked(bool checked);
    void setKeepSizeLabel(const QString & text);

    bool bFillWithNopsChecked;
    void setFillWithNopsChecked(bool checked);
    void setFillWithNopsLabel(const QString & text);

    void setSelectedInstrVa(const duint va);
    void setOkButtonEnabled(bool enabled);

    void validateInstruction(QString expression);
    void hideEvent(QHideEvent *event);

private slots:
    void textChangedSlot(QString text);
    void instructionChangedSlot(dsint sizeDifference, QString error);
    void on_lineEdit_textChanged(const QString &arg1);
    void on_checkBoxKeepSize_clicked(bool checked);
    void on_checkBoxFillWithNops_clicked(bool checked);

private:
    Ui::AssembleDialog *ui;
    duint mSelectedInstrVa;
    ValidateExpressionThread *mValidateThread;

};

#endif // ASSEMBLEDIALOG_H
