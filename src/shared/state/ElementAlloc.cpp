/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "ElementAlloc.h"
#include "Floor.h"
#include <vector>

namespace state {
    
    ElementAlloc:: ElementAlloc() {
        for (int i =0; i<(Layer_int.size()); i++){
            if (Layer_int[i]==-1){
                Layer.add(Space(2));
            }
            else if (Layer_int[i]==(280 or 119)){
                Layer.add(Floor(1));
            }
            
            else if (Layer_int[i]==32){
                Layer.add(Floor(2));
            }
        
        }
    }
    
    ElementAlloc:: getLayer() {
        return Layer;
    }
    
    
}

