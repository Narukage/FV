#include "RenderManager.h"

RenderManager* RenderManager::pinstance = 0;
    
RenderManager* RenderManager::Instance(int libreria){
    if(pinstance==0){
        pinstance = new RenderManager(libreria);
    }
    return pinstance;
}

RenderManager::RenderManager(int libreria) {
    if(libreria==1){
        motor = new FachadaMotor2D();
    }else{
        //otra libreria de graficos 2D como SDL, OpenGL...
    }
}

/*RenderManager *p1 = RenderManager::Instance(1);
RenderManager *p2 = p1->Instance(1);
RenderManager &ref = * RenderManager::Instance(1);*/

//CLASE FACHADAMOTOR2D

//Crea la ventana del juego, le paso tamanyo de la ventana, fps y si lleva o no vsync
void FachadaMotor2D::crearVentana(int width, int height, int frames, bool vsync){
    window = new sf::RenderWindow(sf::VideoMode(width,height),"Summoners");
    window->setFramerateLimit(frames);
    window->setVerticalSyncEnabled(vsync);
}

int FachadaMotor2D::crearAnimacion(std::string &url, float imageCountx, float imageCounty, float switchTime){
    if(!a.textura->loadFromFile(url)){
        std::cout << "Error al cargar la textura." << std::endl;
        exit(-1);
    }
    this->a.imageCount.x = imageCountx;
    this->a.imageCount.y = imageCounty;
    this->a.switchTime = switchTime;
    a.totalTime = 0.0f;
    a.currentImage.x = 0;
    
    a.uvRect.width = a.textura->getSize().x / float(a.imageCount.x);
    a.uvRect.height = a.textura->getSize().y / float(a.imageCount.y);
    
    animaciones.push_back(a);
    
    a.id = cont2;
    cont2++;
    
    return a.id;
}

void FachadaMotor2D::updateAnimacion(int row,float deltaTime){
    a.currentImage.y = row;
    a.totalTime += deltaTime;
    
    if(a.totalTime >= a.switchTime){
        a.totalTime -= a.switchTime;
        a.currentImage.x++;
        
        if(a.currentImage.x >= a.imageCount.x){
            a.currentImage.x = 0;
        }
    }
    
    a.uvRect.left = a.currentImage.x * a.uvRect.width;
    a.uvRect.top = a.currentImage.y * a.uvRect.height;
}

bool FachadaMotor2D::borrarAnimacion(int id){
    bool borrado = false;
    int i=0;
    for(auto it=animaciones.begin();it!=animaciones.end();++it){
        if(animaciones.at(i).id==id){
            Animacion aux = animaciones.at(i);
            animaciones.erase(it);
            delete aux.sprite;
            delete aux.textura;
            borrado=true;
        }
        i++;
    }
    return borrado;
}

//Crea un sprite, le paso la url de la textura para cargarla en memoria
int FachadaMotor2D::crearSprite(std::string &url){
    //Cargamos la textura
    if(!s.textura.loadFromFile(url)){
        std::cout << "Error al cargar la textura." << std::endl;
        exit(-1);
    }
    //Reservamos memoria para el sprite, ya que ahora es un puntero
    s.sprite = new sf::Sprite;
    //Asignamos la textura al sprite
    s.sprite->setTexture(s.textura);
    //Hacemos id++ para que el id propio del sprite cambie
    s.id = cont;
    cont++;
    //Almacenamos el sprite en una lista de sprites para poder buscarlo despues
    sprites.push_back(s);
    //Devolvemos el id propio del sprite que se ha creado
    return s.id;
}

bool FachadaMotor2D::borrarSprite(int id){
    //Busco el sprite en el array de sprites que contenga esa id y lo borro
    bool borrado = false;
    int i=0;
    for(auto it=sprites.begin();it!=sprites.end();++it){
        if(sprites.at(i).id==id){
            Sprite aux = sprites.at(i);
            sprites.erase(it);
            delete aux.sprite;
            borrado=true;
        }
        i++;
    }
    return borrado;
}
//Dibuja en la ventana del juego
void FachadaMotor2D::dibujar(int id, float positionx, float positiony, float scale){
    int i=0;
    for(auto it=sprites.begin();it!=sprites.end();++it){
        if(sprites.at(i).id==id){
            sprites.at(i).sprite->setPosition(positionx, positiony);
            sprites.at(i).sprite->setScale(scale, scale);
        }
        i++;
    }
}

int FachadaMotor2D::crearAudio(std::string& url, int volumen){    
    if (!m.buffer.loadFromFile(url)){
        std::cout << "No pudo abrir el archivo de audio" << "\n";
    }
    
    m.sound = new sf::Sound;
    
    m.sound->setVolume(volumen);
    m.sound->setBuffer(m.buffer);
    
    m.id = cont3;
    cont3++;
    sonidos.push_back(m);
    return m.id;
}

bool FachadaMotor2D::borrarAudio(int id){
    bool borrado = false;
    int i=0;
    for(auto it=sonidos.begin();it!=sonidos.end();++it){
        if(sonidos.at(i).id==id){
            Audio aux = sonidos.at(i);
            sonidos.erase(it);
            delete aux.sound;
            borrado=true;
        }
        i++;
    }
    return borrado;
}

void FachadaMotor2D::play(int id){
    int i=0;
    for(auto it=sonidos.begin();it!=sonidos.end();++it){
        if(sonidos.at(i).id==id){
            sonidos.at(i).sound->play();
        }
        i++;
    }
}

int FachadaMotor2D::crearTexto(std::string& url){
    if(!t.font.loadFromFile("fonts/FreeMono.ttf")){
        std::cout << "Fuente no aplicada" <<std::endl;
    }
    
    t.text = new sf::Text;
    
    t.text->setColor(sf::Color::Red);
    t.text->setFont(t.font);
    
    t.id = cont4;
    cont4++;
    textos.push_back(t);
    return t.id;
}

bool FachadaMotor2D::borrarTexto(int id){
    
}

