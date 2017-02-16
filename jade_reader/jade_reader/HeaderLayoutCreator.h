#pragma once
#include <QPushButton>
#include <QLayout>
#include <QWidget>
class HeaderLayoutCreator : public QObject {
  Q_OBJECT
signals:
  void refreshSignal(QString);
  void signOutSignal();
public slots:
  void signOutSlot();
  void refreshSlot();
private:
  QSharedPointer<QGridLayout> headerLayout;
  QSharedPointer<QPushButton> signOutButton;
  QSharedPointer<QPushButton> refreshButton;
public:
  HeaderLayoutCreator();
  QSharedPointer<QGridLayout> createHeaderLayout();
};
