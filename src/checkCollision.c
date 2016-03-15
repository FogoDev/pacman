#include "checkCollision.h"


// Detector de colisões quadrado / quadrado
bool checkSSCollision(SDL_Rect a[], SDL_Rect b[])
{
    // Os lados dos retângulos
    int leftA, leftB;
    int rightA, rightB;
    int topA, topB;
    int bottomA, bottomB;
    
    // Itera por todas as caixas de A
    for(int Abox = 0; Abox < 11; Abox++){
        
        // Calcula os lados do retângulo A
        leftA = a[Abox].x;
        rightA = a[Abox].x + a[Abox].w;
        topA = a[Abox].y;
        bottomA = a[Abox].y + a[Abox].h;
        
        // Itera todas as caixas de B
        for(int Bbox = 0; Bbox < 11; Bbox++){
            
            // Calcula os lados do retângulo B
            leftB = b[Bbox].x;
            rightB = b[Bbox].x + b[Bbox].w;
            topB = b[Bbox].y;
            bottomB = b[Bbox].y + b[Bbox].h;
            
            // Se nenhum lado de A está fora de B
            if(((bottomA <= topB) || (topA >= bottomB) || (rightA <= leftB) || (leftA >= rightB) ) == false )
            {
                // Uma colisão foi detectada
                return true;
            }
        }
    }
    
    // Se nenhuma das collision boxes foi tocada
    return false;
}


// Detector de colisões circulo / quadrado
bool checkCSCollision(Circle a, SDL_Rect b)
{
    // Ponto mais perto da collision boxes
    int cX, cY;
    
    // Acha a posição mais perto de X
    if(a.x < b.x){
        cX = b.x;
    } else if(a.x > b.x + b.w){
        cX = b.x + b.w;
    } else{
        cX = a.x;
    }
    
    // Acha a posição mais perto de y
    if(a.y < b.y){
        cY = b.y;
    } else if(a.y > b.y + b.h){
        cY = b.y + b.h;
    } else{
        cY = a.y;
    }
    
    // Se o ponto mais perto for dentro do circulo
    if(distanceSquared(a.x, a.y, cX, cY) < a.r * a.r){
        // Essa caixa e esse circulo colidiram
        return true;
    }
    
    // Se eles não colidiram
    return false;
}


// Detector de colisões circulo / circulo
bool checkCCCollision(Circle a, Circle b)
{
    // Calcula o raio total ao quadrado
    int totalRadiusSquared = a.r + b.r;
    totalRadiusSquared = totalRadiusSquared * totalRadiusSquared;
    
    // Se a distância entre os centros dos circulos e menor do que a soma de seus raios
    if(distanceSquared(a.x, a.y, b.x, b.y) < totalRadiusSquared){
        // Os circulos colidiram
        return true;
    }
    
    // Se não
    return false;
}


// Calcula a distância ao quadrado entre 2 pontos
double distanceSquared(int x1, int y1, int x2, int y2)
{
    int deltaX = x2 - x1;
    int deltaY = y2 - y1;
    return deltaX * deltaX + deltaY * deltaY;
}
