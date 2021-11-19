#ifndef API_H
#define API_H
#include <QOAuth2AuthorizationCodeFlow>
#include <QMainWindow>
#include <QObject>
#include <keys.h>
#include <QSettings>
#include <QListWidgetItem>
#include <QDesktopServices>
#include <QtNetworkAuth>
#include <QMessageBox>
#include <QSslSocket>



class Api: public QObject
{
    Q_OBJECT
    QMessageBox msgBox;



private:
    void granted();
    void setupConnection();
    QMap<int, QString> searchMap;
    QVector<QString> playListUrls;
    QOAuth2AuthorizationCodeFlow spotifyApi;
    bool isGranted;

public:
    Api();
    ~Api();

    // grant connection
    void grant();

    bool addToPlaylist(QString element);

    QString getStringFromSearchMap(int index);

    int getPlaylistSize();

    bool isLogged();

    QVector<QString> loadPlaylist();

    int getSearchListSize();

    QString getPlaylistItem(int index);

    int connectToSpotify();

    void search(QString searchString, QListWidget * lstSearchResults);

    bool removeFromPlaylist(int index);

    void showMessage(QString);

    void savePlaylist(QVector<QString> playlist);


};

#endif // API_H
