#pragma once
#include <QPushButton>
#include <QLayout>
#include <QWidget>
class HeaderLayoutCreator {
private:
  QGridLayout* headerLayout;
  QPushButton* signOutButton;
  QPushButton* loadMoreButton;
public:
  HeaderLayoutCreator();
  ~HeaderLayoutCreator();
  QGridLayout* createHeaderLayout();
};
