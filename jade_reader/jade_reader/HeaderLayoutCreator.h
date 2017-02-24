#pragma once
#include <QPushButton>
#include <QLayout>
#include <QWidget>
class HeaderLayoutCreator : public QObject {
  Q_OBJECT
signals:
  void refreshSignal();
  void signOutSignal();
private:
  QSharedPointer<QGridLayout> headerLayout;
  QSharedPointer<QPushButton> signOutButton;
  QSharedPointer<QPushButton> refreshButton;
public:
  HeaderLayoutCreator();
  QSharedPointer<QGridLayout> createHeaderLayout();
};
