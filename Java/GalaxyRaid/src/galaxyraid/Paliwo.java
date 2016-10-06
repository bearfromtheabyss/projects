/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package galaxyraid;

import java.util.Random;

/**
 *
 * @author Michał
 */
public class Paliwo extends Obiekt {
    
    public Paliwo(int x, int y) {
        super(x+randomPosX(), y+randomPosY());
        initPaliwo();
    }
    private void initPaliwo() {
      wczytajObraz("fuel.png");
    }

    public static int randomPosX(){
        Random rand = new Random();
        int value = rand.nextInt(768);
        return value;
    }
    public static int randomPosY(){
        Random rand = new Random();
        int value = rand.nextInt(300);
        return value;
    }
    
    public void rusz() {
      y++;
    }
    
}
