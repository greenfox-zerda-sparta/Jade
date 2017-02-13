#pragma once
#include <QPushButton>
#include <QLayout>
#include <QWidget>
class HeaderLayoutCreator : public QObject {
  Q_OBJECT
signals:
  void refreshSignal();
  void signOutSignal();
public slots:
  void signOutSlot();
  void refreshSlot();
private:
  QGridLayout* headerLayout;
  QPushButton* signOutButton;
  QPushButton* refreshButton;
public:
  HeaderLayoutCreator();
  ~HeaderLayoutCreator();
  QGridLayout* createHeaderLayout();
};
