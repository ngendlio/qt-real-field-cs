#include "gamefactory.h"
namespace GameFactory{
    namespace{
        QHash<QString, game*> _games;
        QObject _root;
        Server *server;
    }

    bool exists(QString id){
        if(id == NULL){
            return false;
        }
        return _games.contains(id);
    }

    void setServer(Server *s) {
        server = s;
    }

    game* getGame(QString id){
        if(id == NULL){
            return NULL;
        }
        if(exists(id)){
            return _games.value(id);
        }else{
            game* new_game = new game(id,0,server);
            _games.insert(id, new_game);
            return new_game;
        }
    }

    QList<QString> getGameIds(){
        return _games.keys();
    }

    void destroyGame(QString gameid){
        if(gameid == NULL){
            return;
        }
        if (exists(gameid)){
        game* game = _games.value(gameid);
        game->deleteLater();
        _games.remove(gameid);
        }
    }
}
