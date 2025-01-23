#ifndef QPLIK_H
#define QPLIK_H
#include <QFile>

#include "plik.h"
class QPlik : public Plik {
 private:
  QFile f;

 public:
  QPlik();
  virtual bool open(const QString &name, QIODeviceBase::OpenMode mode);
  virtual void close();
  virtual qint64 write(const QByteArray &data);
  virtual QByteArray readAll();
};

#endif  // QPLIK_H
