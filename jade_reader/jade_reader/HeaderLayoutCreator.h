#pragma once
#include <QPushButton>
#include <QLayout>
#include <QWidget>
class HeaderLayoutCreator : public QObject {
  Q_OBJECT
public slots:
  void signOut();
  void loadMore();
private:
  QGridLayout* headerLayout;
  QPushButton* signOutButton;
  QPushButton* loadMoreButton;
public:
  HeaderLayoutCreator();
  ~HeaderLayoutCreator();
  QGridLayout* createHeaderLayout();
};
