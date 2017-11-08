/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "ElementAlloc.h"
#include "Floor.h"
#include "Space.h"
#include <vector>

namespace state {
    
    
    ElementAlloc:: ElementAlloc() {
       for (size_t i =0; i<(Layer_int.size()); i++){
            if (Layer_int[i]==-1){
                Element* pEmpty = new Space(SpaceTypeId::EMPTY);
                Layer.add(pEmpty);
            }
            else if (Layer_int[i]==(280 or 119)){
                Element* pFull = new Floor(FloorTypeId::FULL);
                Layer.add(pFull);
            }
            
            else if (Layer_int[i]==32){
                Element* pWater = new Floor(FloorTypeId::WATER);
                Layer.add(pWater);
            }
        
        }
    }
    
    ElementTab ElementAlloc:: getLayer() {
        return Layer;
    }
    
    
}

