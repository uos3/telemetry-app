#include <vector>
#include <tuple>

#include <QApplication>
#include <QDebug>
#include <QFileSystemWatcher>
#include <QObject>
#include <QtNetwork>

#include <cereal/archives/json.hpp>

#include "buffer.h"
#include "cli.h"
#include "db.h"
#include "filehandler.h"
#include "topwindow.h"
#include "packet.h"
#include "secrets/secrets.h"
#include "uploader.h"

static const std::string file_path = "input.bin";
static const uint32_t packet_size = 3136;

int main (int argc, char* argv[]) {
    QApplication a(argc, argv);


    Buffer b;
    b.from_file(file_path, packet_size);


    std::cout << "buffer (" << b.get_len() << "):\n";
    for (unsigned int i = 0; i<b.get_len(); i++)
    {
        std::cout << *(b.get_buf()+i);
    } std::cout << "\n";


    Packet p;
    from_buffer(p,b);


    cereal::JSONOutputArchive archive(std::cout);
    archive(CEREAL_NVP(p));

    DB db("localhost", "cubesat");
    if (db.connect(secrets::username, secrets::password))
    {
        qDebug("DB Connected");
        db.store_packet(p);
    }


    // Display the GUI.
    topwindow w;
    w.show();


    return a.exec();
}
