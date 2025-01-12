#include "qplik.h"

QPlik::QPlik() {}

bool QPlik::open(const QString &name,QIODeviceBase::OpenMode mode){
    f.setFileName(name);
    return f.open(mode);
}
void QPlik::close(){
    f.close();
}
qint64 QPlik::write(const QByteArray &data){
    return f.write(data);
}

QByteArray	QPlik::readAll(){
    return f.readAll();
}
