#include "qplik.h"

QPlik::QPlik() {}
/*!
 * \brief QPlik::open
 * \param name - nazwa danego pliku do otworzenia
 * \param mode - typ otwarcia
 * \return zawraca metode klasy QFile "open"
 * Wraper na na metode QFile::open() w celu przeprowadzenia UT
 */
bool QPlik::open(const QString &name, QIODeviceBase::OpenMode mode) {
  f.setFileName(name);
  if (!f.exists() && QIODeviceBase::ReadOnly == mode)
    return false;
  return f.open(mode);
}

/*!
 * \brief QPlik::close
 * Wraper na na metode QFile::close() w celu przeprowadzenia UT
 */
void QPlik::close() {
  f.close();
}

/*!
 * \brief QPlik::write
 * \param data
 * \return zawraca metode klasy QFile "write"
 * Wraper na na metode QFile::write() w celu przeprowadzenia UT
 */
qint64
QPlik::write(const QByteArray &data) {
  return f.write(data);
}

/*!
 * \brief QPlik::readAll
 * \return zawraca metode klasy QFile "readAll"
 * Wraper na na metode QFile::readAll() w celu przeprowadzenia UT
 */
QByteArray
QPlik::readAll() {
  return f.readAll();
}
