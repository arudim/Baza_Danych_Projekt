#ifndef PLIK_H
#define PLIK_H
#include <QIODeviceBase>
#include <QString>

class Plik {
 public:
  virtual bool open(const QString &name, QIODeviceBase::OpenMode mode) = 0;
  virtual void close() = 0;
  virtual qint64 write(const QByteArray &data) = 0;
  virtual QByteArray readAll() = 0;
  static Plik &Instancja();
};

#endif  // PLIK_H
