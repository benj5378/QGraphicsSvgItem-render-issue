#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsSvgItem>
#include <QPainter>
#include <QPrinter>
#include <QString>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QGraphicsScene* scene = new QGraphicsScene;

    QGraphicsSvgItem svgitem(QString("test.svg"));
    scene->addItem(&svgitem);
    QGraphicsTextItem *text = scene->addText("Lorum Ipsum", QFont(QString("Arial"), 300));
    text->setPos(0, 400);

    QPrinter printer(QPrinter::HighResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName(QString("test.pdf"));
    printer.setPageSize(QPageSize(QPageSize::PageSizeId::A4));

    QPainter painter(&printer);
    painter.setViewport(0, 0, printer.width(), printer.height());
    QRectF rect(0, 0, 10000, 10000);
    scene->render(&painter, rect, rect);

    return 0;
}


    // QSvgGenerator svgGen;

    // svgGen.setFileName( "test2.svg" );
    // svgGen.setSize(QSize(1000, 1000));
    // svgGen.setViewBox(QRect(0, 0, 10000, 10000));
    // svgGen.setTitle("SVG Generator Example Drawing");
    // svgGen.setDescription("An SVG drawing created by the SVG Generator "
    //            