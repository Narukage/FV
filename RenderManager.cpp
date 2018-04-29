#include "RenderManager.h"
#include "Tablero.h"

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

RenderManager *r1 = RenderManager::Instance(1);
RenderManager *r2 = r1->Instance(1);
RenderManager &refr = * RenderManager::Instance(1);

//CLASE FACHADAMOTOR2D

//Crea la ventana del juego, le paso tamanyo de la ventana, fps y si lleva o no vsync
void FachadaMotor2D::crearVentana(int frames, bool vsync, sf::RenderWindow& window) {
   window.setFramerateLimit(frames);
   window.setVerticalSyncEnabled(vsync);
}

void FachadaMotor2D::cerrarVentana(sf::RenderWindow& window){
    window.close();
}

void FachadaMotor2D::crearClock(){
    clock.restart().asSeconds();
}

int FachadaMotor2D::crearAnimacion(std::string url, float imageCountx, float imageCounty, float switchTime, int filas, int columnas){
    Animacion a;
    a.textura = new sf::Texture;
    if(!a.textura->loadFromFile(url)){
        std::cout << "Error al cargar la textura." << std::endl;
        exit(-1);
    }
    
    a.sprite = new sf::Sprite;
    
    a.sprite->setTexture(*(a.textura));
    
    a.textureSize = (*a.textura).getSize();
    a.textureSize.x = (a.textureSize.x / a.textureSize.x) * columnas;
    a.textureSize.y = (a.textureSize.y / a.textureSize.y) * filas;
    
    a.imageCount.x = imageCountx;
    a.imageCount.y = imageCounty;
    a.switchTime = switchTime;
    a.totalTime = 0.0f;
    a.currentImage.x = 0;
    
    a.uvRect.width = a.textura->getSize().x / float(a.imageCount.x);
    a.uvRect.height = a.textura->getSize().y / float(a.imageCount.y);
    
    a.id = cont2;
    cont2++;
    
    animaciones.push_back(a);
    
    return a.id;
}

void FachadaMotor2D::updateAnimacion(int id, int row,float deltaTime){
    for(unsigned int i = 0; i < animaciones.size(); i++){
        if(animaciones[i].id==id){
            animaciones[i].currentImage.y = row;
            animaciones[i].totalTime += deltaTime;

            //Si se ha sobrepasado el tiempo de un frame, se pasa al siguiente
            if(animaciones[i].totalTime >= animaciones[i].switchTime){
            animaciones[i].totalTime -= animaciones[i].switchTime;
                animaciones[i].currentImage.x++;
                
                //Si llega al final del array de sprites de la animación, vuelve al principio
                if(animaciones[i].currentImage.x >= animaciones[i].imageCount.x){
                    animaciones[i].currentImage.x = 0;
                }
            }
            
            //Se coloca el recuadro sobre el sprite indicado
            animaciones[i].uvRect.left = animaciones[i].currentImage.x * animaciones[i].uvRect.width;
            animaciones[i].uvRect.top = animaciones[i].currentImage.y * animaciones[i].uvRect.height;

            //Se coloca sobre el sprite de la animación la textura del nuevo recuadro
            animaciones[i].sprite->setTextureRect(animaciones[i].uvRect);
        }
    }
}

void FachadaMotor2D::dibujarAnimacion(int id, float positionx, float positiony, float scale, sf::RenderWindow* window){
    for(unsigned int i = 0; i < animaciones.size(); i++){
        if(animaciones[i].id==id){
            //Posicionar y escalar
            animaciones[i].sprite->setPosition(positionx, positiony);
            animaciones[i].sprite->setScale(scale, scale);
            
            //Dibujar sprite indicado
            window->draw(*(animaciones[i].sprite));
       }
    }
}

bool FachadaMotor2D::borrarAnimacion(int id){
    for(unsigned int i = 0; i < animaciones.size(); i++){
        if(animaciones[i].id==id){
            Animacion aux = animaciones[i];
            animaciones.erase(animaciones.begin()+i);
            delete aux.sprite;
            delete aux.textura;
            delete &aux;
            return true;
        }
    }
    return false;
}

//Crea un sprite, le paso la url de la textura para cargarla en memoria
int FachadaMotor2D::crearSprite(std::string url){
    Sprite s;
    //Cargamos la textura
    s.textura = new sf::Texture;
    if(!s.textura->loadFromFile(url)){
        std::cout << "Error al cargar la textura." << std::endl;
        exit(-1);
    }
    //Reservamos memoria para el sprite, ya que ahora es un puntero
    s.sprite = new sf::Sprite;
    //Asignamos la textura al sprite
    s.sprite->setTexture(*(s.textura));
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
    for(unsigned int i = 0; i < sprites.size(); i++){
        if(sprites[i].id==id){
            Sprite aux = sprites[i];
            sprites.erase(sprites.begin()+i);
            delete aux.sprite;
            delete aux.textura;
            delete &aux;
            return true;
        }
    }
    return false;
}
//Dibuja en la ventana del juego
void FachadaMotor2D::dibujar(int id, float positionx, float positiony, float scale, sf::RenderWindow& window){
    for(unsigned int i = 0; i < sprites.size(); i++){
        if(sprites[i].id==id){
            sprites[i].sprite->setPosition(positionx, positiony);
            sprites[i].sprite->setScale(scale, scale);
            window.draw(*(sprites[i].sprite));
       }
    }
}

int FachadaMotor2D::crearAudio(std::string url, int volumen){
    Audio m;
    m.buffer = new sf::SoundBuffer;
    if (!m.buffer->loadFromFile(url)){
        std::cout << "No pudo abrir el archivo de audio" << "\n";
    }
    
    m.sound = new sf::Sound;
    
    m.sound->setVolume(volumen);
    m.sound->setBuffer(*(m.buffer));
    
    m.id = cont3;
    cont3++;
    sonidos.push_back(m);
    return m.id;
}

bool FachadaMotor2D::borrarAudio(int id){
    for(unsigned int i = 0; i < sonidos.size(); i++){
        if(sonidos[i].id==id){
            Audio aux = sonidos[i];
            sonidos.erase(sonidos.begin()+i);
            delete aux.sound;
            delete aux.buffer;
            delete &aux;
            return true;
        }
    }
    return false;
}

void FachadaMotor2D::play(int id){
    for(unsigned int i = 0; i < sonidos.size(); i++){
        if(sonidos[i].id==id){
            sonidos[i].sound->play();
        }
    }
}

int FachadaMotor2D::crearTexto(std::string url){
    Texto t;
    t.font = new sf::Font;
    if(!t.font->loadFromFile(url)){
        std::cout << "Fuente no aplicada" <<std::endl;
    }
    
    t.text = new sf::Text;
    t.text->setColor(sf::Color::White);
    t.text->setFont(*(t.font));
    
    t.id = cont4;
    cont4++;
    textos.push_back(t);
    return t.id;
}
bool FachadaMotor2D::borrarTexto(int id){
    for(unsigned int i = 0; i < textos.size(); i++){
        if(textos[i].id==id){
            Texto aux = textos[i];
            textos.erase(textos.begin()+i);
            delete aux.text;
            delete aux.font;
            delete &aux;
            return true;
        }
    }
    return false;
}

void FachadaMotor2D::escribir(std::string s, int id, float positionx, float positiony, float scale, sf::RenderWindow& window){
    for(unsigned int i = 0; i < textos.size(); i++){
        if(textos[i].id==id){
            textos[i].text->setString(s);
            textos[i].text->setPosition(positionx, positiony);
            textos[i].text->setScale(scale, scale);
            window.draw(*(textos[i].text));
        }
    }
}
void FachadaMotor2D::updateTextoRojo(int id){
    for(unsigned int i = 0; i < textos.size(); i++){
        if(textos[i].id==id){
            textos[i].text->setColor(sf::Color::Red);

        }
    }
}
void FachadaMotor2D::updateTextoBlanco(int id){
    for(unsigned int i = 0; i < textos.size(); i++){
        if(textos[i].id==id){
            textos[i].text->setColor(sf::Color::Red);   

        }
    }
}