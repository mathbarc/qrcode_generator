#ifndef TELEPHONEFORM_HPP
#define TELEPHONEFORM_HPP

#include <QWidget>

namespace Ui
{
    class TelephoneForm;
}

class TelephoneForm : public QWidget
{
    Q_OBJECT

  public:
    explicit TelephoneForm(QWidget *parent = nullptr);
    ~TelephoneForm();
    std::string getVCardEntry() const;

  private:
    Ui::TelephoneForm *ui;
};

#endif // TELEPHONEFORM_HPP
