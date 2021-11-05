#ifndef MYVIDEOSURFACE_H
#define MYVIDEOSURFACE_H

#include <QAbstractVideoSurface>
#include <QVideoSurfaceFormat>
class myvideosurface:public QAbstractVideoSurface
{
    Q_OBJECT

public:
    myvideosurface(QObject *parent= Q_NULLPTR);

private:

protected:
    QList<QVideoFrame::PixelFormat> supportedPixelFormats(QAbstractVideoBuffer::HandleType handleType) const;
    bool isFormatSupported(const QVideoSurfaceFormat &videoformat) const;
    bool start(const QVideoSurfaceFormat &videoformat);
    bool present(const QVideoFrame &frame);
    void stop();
signals:
    void frameAvailable(QVideoFrame);
};

#endif // MYVIDEOSURFACE_H
